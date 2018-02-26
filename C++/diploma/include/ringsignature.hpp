#ifndef RINGSIGNATURE_H
#define RINGSIGNATURE_H

#include <rsa_elem.hpp>
#include <boost/uuid/sha1.hpp>

class RingSignature
{
private:
   std::vector<std::shared_ptr<RSA_elem>> m_keys;
   int m_participants;
   int m_len;
   mpz_t m_module;
public:
      RingSignature(std::vector<std::shared_ptr<RSA_elem>> elems, int len = 1024);
      int permut(std::string);
};

#endif // RINGSIGNATURE_H
