#include "rsa_generator.hpp"

RSA_generator::RSA_generator(int len): m_len(len){}

std::shared_ptr<RSA_elem> RSA_generator::gen_RSA(int i)
{
   mpz_t p; mpz_init(p);
   mpz_t q; mpz_init(q);
   mpz_t n; mpz_init(n);
   mpz_t fi; mpz_init(fi);
   mpz_t fi_coef; mpz_init(fi_coef);
   mpz_t e; mpz_init(e);
   mpz_t d; mpz_init(d);
   mpz_t my_gcd; mpz_init(my_gcd);

   gmp_randstate_t state;
   gmp_randinit_default(state);
   gmp_randseed_ui(state, i);
   mpz_urandomb(p, state, m_len);

   next_prime(p, p);
   next_prime(q,p);
   mpz_mul(n,p,q);
   mpz_sub_ui(p,p,1);
   mpz_sub_ui(q,q,1);
   mpz_mul(fi,q,p);

   int e_len = 100;
   if(e_len >=m_len)
   {
      e_len = m_len;
   }

   mpz_urandomb(e,state,e_len);
   next_prime(e,e);
   mpz_gcdext(my_gcd,d,fi_coef,e,fi);

   if(mpz_sgn(d)<0)
   {
      mpz_add(d,n,d);
   }
   return  std::make_shared<RSA_elem>(n,e,d);
}
void RSA_generator::next_prime(mpz_t prime, mpz_t num){
    mpz_nextprime(prime, num);
}
