#ifndef SDSL_SUBSET_BITS_HPP
#define SDSL_SUBSET_BITS_HPP
#include <cstdint>
namespace sdsl { namespace bits {
inline uint8_t hi(uint64_t x){
    if(x==0) return 0;
    return static_cast<uint8_t>(63u - __builtin_clzll(x));
}
}}
#endif
