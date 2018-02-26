#include <ringsignature.hpp>

RingSignature::RingSignature(std::vector<std::shared_ptr<RSA_elem> > elems, int len): m_keys(elems), m_participants(elems.size()),m_len(len)
{
   mpz_init(m_module);
   gmp_randstate_t state;
   gmp_randinit_default(state);
   gmp_randseed_ui(state, m_participants);
   mpz_rrandomb(m_module, state, m_len);
}
int RingSignature::permut(std::string msg)
{
   boost::uuids::detail::sha1 s;
   s.process_bytes(msg.c_str(),msg.size());
   unsigned int digest[5];
   s.get_digest(digest);

   for(auto i:digest)
   {
      std::cout<<i<<"   \n";
   }
}
