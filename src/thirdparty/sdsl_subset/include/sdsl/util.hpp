#ifndef SDSL_SUBSET_UTIL_HPP
#define SDSL_SUBSET_UTIL_HPP
#include <string>
#include <typeinfo>
#include <cstddef>
namespace sdsl {
class bit_vector;
namespace util {
template<class T> inline void clear(T& x){ x = T(); }
template<class T, class V> inline void set_to_value(T& x, const V& v){ for(std::size_t i=0;i<x.size();++i) x[i]=v; }
template<class T> inline std::string class_name(const T&){ return typeid(T).name(); }
}}
#endif
