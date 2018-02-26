#ifndef RSA_GENERATOR_H
#define RSA_GENERATOR_H

#include <rsa_elem.hpp>

class RSA_generator
{
public:
   RSA_generator(int);
   std::shared_ptr<RSA_elem> gen_RSA(int i);

private:
   int m_len;
   void next_prime(mpz_t prime, mpz_t num);
};

#endif // RSA_GENERATOR_H
