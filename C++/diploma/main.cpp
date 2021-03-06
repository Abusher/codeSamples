
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <ringsignature.hpp>
#include <rsa_elem.hpp>
#include <rsa_generator.hpp>

using namespace std;


char *serialize(mpz_t nums[], int num_count, int num_len)
{
   char *res = new char[num_len * num_count + 1];
   for (int i = 0; i < num_count; ++i)
   {
      char *num_s = mpz_get_str(NULL, 2, nums[i]);
      strcpy(res + i * num_len, num_s);
   }
   return res;
}

mpz_t *deserialize(char *str, int num_count, int num_len)
{
   mpz_t *nums = new mpz_t[num_count];
   for (auto i = 0; i < num_count; ++i)
   {
      mpz_init_set_str(nums[i], str + i * num_len, 2);
   }
   return nums;
}

bool is_prime(mpz_t num);


vector<int> trial_div = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void reduce(mpz_t T, uint32_t R, mpz_t N, mpz_t Np)
{
   mpz_t Tmod;
   mpz_init(Tmod);
   mpz_set(Tmod, T);
   mpz_t m;
   mpz_init(m);
   mpz_mul(m, Tmod, Np);
   mpz_t tmp;
   mpz_init(tmp);
   mpz_mul(tmp, m, N);
   mpz_t res;
   mpz_init(res);
   mpz_add(res, T, tmp);
   if (mpz_cmp(res, N) < 0)
      mpz_sub(res, res, N);
}

bool is_prime(mpz_t num)
{
   int n_it = 10;
   for (int i = 0; i < trial_div.size(); ++i)
   {
      mpz_t tmp;
      mpz_init(tmp);
      mpz_fdiv_r_ui(tmp, num, trial_div[i]);
      if (!mpz_cmp_ui(tmp, 0))
         return false;
   }
   mpz_t a;
   mpz_init(a);
   mpz_t R;
   mpz_init(R);
   string str(mpz_get_str(NULL, 2, num));
   mpz_t tmp;
   mpz_init_set_str(tmp, "2", 10);
   mpz_pow_ui(R, tmp, str.length());
   mpz_t one;
   mpz_init_set_str(one, "1", 10);
   mpz_t d;
   mpz_init(d);
   mpz_sub(d, num, one);
   int s = 0;
   mpz_div(R, num, one);

   mpz_t inv_one;
   mpz_init(inv_one);
   mpz_sub(inv_one, num, one);
   mpz_t inv;
   mpz_init(inv);
   mpz_invert(inv, num, R);
   mpz_t Np;
   mpz_init(Np);
   mpz_sub(Np, R, inv);
   for (int i = 0; i < n_it; ++i)
   {
      if (!mpz_cmp(a, one) || !mpz_cmp(a, inv_one))
         continue;
      int j = 0;
      for (; j < s - 1; ++j)
      {
         mpz_mul(a, a, a);
         reduce(a, str.length(), num, Np);
         if (!mpz_cmp(a, one))
            return false;
         else if (!mpz_cmp(a, inv_one))
            break;
      }
      if (j == s - 1)
         return false;
   }
   return true;
}

int main()
{
   std::vector<std::shared_ptr<RSA_elem>> clients;
   RSA_generator gen(1024);

   for (int i = 0; i < 3; i++)
   {
      clients.push_back(gen.gen_RSA(i * 2));
      clients[i]->print_RSA();
   }
   mpz_t hashed;
   mpz_init(hashed);

   RingSignature rs(clients);
   std::string msg = "The quick brown fox jumps over the lazy dog";
   //   rs.hash(hashed,msg);
   std::vector<std::string> v(clients.size() + 1);
   v = rs.sign(msg, 0);

   rs.verify(msg, v);

   //   std::string a =  mpz_get_str(NULL,10,hashed);


   //      std::cout<<"RSA Module:\n   "<<a<<"\n";
   return 0;
}
