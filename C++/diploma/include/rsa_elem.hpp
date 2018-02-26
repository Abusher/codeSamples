#ifndef RSA_ELEM_H
#define RSA_ELEM_H
#include <iostream>
#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <ctime>
#include <cstring>
#include <chrono>
#include <vector>
#include <memory>

class RSA_elem
{
public:
   RSA_elem(mpz_t n, mpz_t e, mpz_t d);
   ~RSA_elem();

   mpz_t* get_public_key();
   mpz_t* get_private_key();
   mpz_t* get_n();
   void print_RSA();
private:
   mpz_t m_n;
   mpz_t m_e;
   mpz_t m_d;
};

#endif // RSA_ELEM_H
