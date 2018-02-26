#include "rsa_elem.hpp"

RSA_elem::RSA_elem(mpz_t n, mpz_t e, mpz_t d)
{
   mpz_init_set(m_n, n);
   mpz_init_set(m_e, e);
   mpz_init_set(m_d, d);
}

mpz_t* RSA_elem::get_public_key()
{
   return &m_e;
}
mpz_t* RSA_elem::get_n()
{
   return &m_n;
}

mpz_t* RSA_elem::get_private_key()
{
   return &m_d;
}

void RSA_elem::print_RSA()
{
   std::string number = mpz_get_str(NULL,10,m_n);
   std::cout<<"RSA Module:\n   "<<number<<"\n";

   number = mpz_get_str(NULL,10,m_e);
   std::cout<<"RSA Public Key:\n    "<<number<<"\n";

   number = mpz_get_str(NULL,10,m_d);
   std::cout<<"RSA Private Key:\n   "<<number<<"\n\n";

}
RSA_elem::~RSA_elem()
{
   mpz_clear(m_n);
   mpz_clear(m_e);
   mpz_clear(m_d);
}
