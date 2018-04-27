#include <ringsignature.hpp>

RingSignature::RingSignature(std::vector<std::shared_ptr<RSA_elem>> elems, uint16_t len)
   : m_keys(elems), m_participants(elems.size()), m_len(len)
{
   mpz_init(m_module);
   mpz_t op1;
   mpz_init_set_ui(op1, 1);
   mpz_mul_2exp(m_module, op1, m_len - 1);
}

void RingSignature::hash(mpz_t target, const std::string &msg)
{
   boost::uuids::detail::sha1 s;
   char hash[20];
   s.process_bytes(msg.c_str(), msg.size());
   unsigned int digest[5];
   s.get_digest(digest);
   for (int i = 0; i < 5; ++i)
   {
      const char *tmp = reinterpret_cast<char *>(digest);
      hash[i * 4] = tmp[i * 4 + 3];
      hash[i * 4 + 1] = tmp[i * 4 + 2];
      hash[i * 4 + 2] = tmp[i * 4 + 1];
      hash[i * 4 + 3] = tmp[i * 4];
   }

   std::string sh = hashToNumber(hash);
   //   std::cout << "hash hex " << sh << "\n";

   mpz_set_str(target, sh.c_str(), 16);
}
std::string RingSignature::hashToNumber(char *hash)
{
   int a;
   int b;
   std::stringstream ss;
   ss << std::hex;

   for (int i = 0; i < 20; ++i)
   {
      a = ((hash[i] & 0x000000F0) >> 4);
      b = (hash[i] & 0x0000000F);
      ss << a << b;
   }

   std::string str = ss.str();
   return str;
}

void RingSignature::permut(const std::string &msg)
{
   mpz_init(m_signature_key);
   hash(m_signature_key, msg);
}

std::vector<std::string> RingSignature::sign(const std::string &_msg, uint16_t _signerNumber)
{
   permut(_msg);

   std::vector<mpz_t> s(m_participants);
   for (uint16_t i = 0; i < s.size(); i++)
   {
      mpz_init(s[i]);
   }
   mpz_t u;
   mpz_init(u);

   gmp_randstate_t state;
   gmp_randinit_default(state);
   gmp_randseed_ui(state, m_participants);
   mpz_urandomm(u, state, m_module);
   std::string b;
   b = mpz_get_str(NULL, 10, m_module);
   //   std::cout << "1<< 1024:\n   " << b << "\n";
   std::string test = E(u);

   mpz_t c;
   mpz_init_set_str(c, test.c_str(), 10);
   mpz_t v;
   mpz_init_set_str(v, test.c_str(), 10);
   for (int i = (_signerNumber + 1) % m_participants; i != _signerNumber; i++)
   {
      mpz_urandomm(s[i], state, m_module);
      mpz_t e;
      mpz_init_set_str(e, g(s[i], *(m_keys[i]->get_public_key()), *(m_keys[i]->get_n())).c_str(), 10);

      mpz_t xorElem;
      mpz_init(xorElem);
      mpz_xor(xorElem, v, e);
      mpz_set_str(v, E(xorElem).c_str(), 10);
      if ((i + 1) % m_participants == 0)
      {
         i = -1;
         b = mpz_get_str(NULL, 10, c);
         std::cout << "RSA ASDASDASD:\n   " << b << "\n";
         mpz_set(c, v);
         b = mpz_get_str(NULL, 10, c);
         std::cout << "RSA AFTER:\n   " << b << "\n";
      }
   }
   mpz_t xorElem;
   mpz_init(xorElem);
   mpz_xor(xorElem, v, u);

   mpz_set_str(s[_signerNumber], g(xorElem, *(m_keys[_signerNumber]->get_private_key()), *(m_keys[_signerNumber]->get_n())).c_str(), 10);
   //   b = mpz_get_str(NULL, 10, s[_signerNumber]);
   //   std::cout << "RSA MAIN:\n   " << b << "\n";
   std::vector<std::string> result(m_participants + 1);
   result[0] = mpz_get_str(NULL, 10, c);
   for (uint16_t i = 0; i < s.size(); i++)
   {
      result[i + 1] = mpz_get_str(NULL, 10, s[i]);
   }
   std::cout << result.size();
   //   for (uint16_t i = 0; i < result.size(); i++)
   //   {
   //      std::cout << i << "   =   " << result[i] << std::endl << std::endl;
   //   }
   return result;
}

bool RingSignature::verify(const std::string &_msg, std::vector<std::string> _signature)
{
   permut(_msg);

   std::cout << _signature.size() << m_participants << "\n\n";
   std::vector<mpz_t> numbers(m_participants);
   for (uint16_t i = 0; i < numbers.size(); i++)
   {
      mpz_init_set_str(numbers[i], _signature[i + 1].c_str(), 10);
      std::cout << _signature[i + 1] << std::endl;
   }
   std::vector<mpz_t> y(m_participants);
   for (uint16_t i = 0; i < y.size(); i++)
   {
      mpz_init_set_str(y[i], g(numbers[i], *(m_keys[i]->get_public_key()), *(m_keys[i]->get_n())).c_str(), 10);
   }

   mpz_t res;
   std::string b;
   mpz_init_set_str(res, _signature[0].c_str(), 10);
   for (uint16_t i = 0; i < m_participants; i++)
   {
      mpz_t xorRes;
      mpz_init(xorRes);
      mpz_xor(xorRes, res, y[i]);
      mpz_init_set_str(res, E(xorRes).c_str(), 10);
      b = mpz_get_str(NULL, 10, res);
   }

   std::cout << "RSA MAIN:\n   " << b << "\n";
   std::cout << "asdasdasdSADADS:\n   " << _signature[0] << "\n";
   if (b == _signature[0])
      return true;
   else
      return false;
}

std::string RingSignature::E(mpz_t &_number)
{
   std::string number = mpz_get_str(NULL, 10, _number);
   std::string msg = mpz_get_str(NULL, 10, m_signature_key);
   number += msg;

   mpz_t result;
   mpz_init(result);
   hash(result, number);

   return mpz_get_str(NULL, 10, result);
}

std::string RingSignature::g(mpz_t &_x, mpz_t &_e, mpz_t &_n)
{
   mpz_t q;
   mpz_init(q);
   mpz_t r;
   mpz_init(r);
   mpz_cdiv_qr(q, r, _x, _n);

   mpz_t lvalue;
   mpz_init(lvalue);
   mpz_add_ui(lvalue, q, 1);
   mpz_mul(lvalue, lvalue, _n);

   mpz_t rvalue;
   mpz_init(rvalue);
   mpz_t op1;
   mpz_init_set_ui(op1, 1);
   mpz_mul_2exp(rvalue, op1, m_len);
   mpz_sub_ui(rvalue, rvalue, 1);

   mpz_t result;
   mpz_init(result);
   if (mpz_cmp(lvalue, rvalue) <= 0)
   {
      mpz_mul(result, q, _n);
      mpz_t power;
      mpz_init(power);
      mpz_powm(power, r, _e, _n);
      mpz_add(result, result, power);
   }
   else
   {
      mpz_add(result, result, _x);
   }
   return mpz_get_str(NULL, 10, result);
}
