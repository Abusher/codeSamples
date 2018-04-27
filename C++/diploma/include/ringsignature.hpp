#ifndef RINGSIGNATURE_H
#define RINGSIGNATURE_H

#include <gmp.h>
#include <gmpxx.h>
#include <stdio.h>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <boost/uuid/sha1.hpp>
#include <rsa_elem.hpp>

class RingSignature
{
private:
   std::vector<std::shared_ptr<RSA_elem>> m_keys;
   uint16_t m_participants;
   uint16_t m_len;
   mpz_t m_module;
   mpz_t m_signature_key;

public:
   RingSignature(std::vector<std::shared_ptr<RSA_elem>> elems, uint16_t len = 1024);
   void permut(const std::string &);
   void hash(mpz_t target, const std::string &msg);
   std::string hashToNumber(char *hash);
   std::vector<std::string> sign(const std::string &_msg, uint16_t);
   bool verify(const std::string &_msg, std::vector<std::string> _signature);
   std::string E(mpz_t &_number);
   std::string g(mpz_t &_x, mpz_t &_e, mpz_t &_n);
};

#endif // RINGSIGNATURE_H
