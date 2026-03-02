#ifndef SDSL_SUBSET_WAVELET_TREES_HPP
#define SDSL_SUBSET_WAVELET_TREES_HPP
#include <vector>
#include <array>
#include <cstddef>
#include <fstream>
#include <utility>
#include "int_vector.hpp"
namespace sdsl {
template<class Dummy=void>
class wt_huff {
public:
    using value_type = uint8_t;
    using size_type = std::size_t;
    std::vector<value_type> data;
    void swap(wt_huff& o){ data.swap(o.data); }
    size_type size() const { return data.size(); }
    value_type operator[](size_type i) const { return data[i]; }
    size_type rank(size_type idx, value_type sym) const { size_type c=0; if(idx>data.size()) idx=data.size(); for(size_type i=0;i<idx;++i) if(data[i]==sym) ++c; return c; }
    size_type select(size_type k, value_type sym) const { if(k==0) return size(); size_type c=0; for(size_type i=0;i<data.size();++i){ if(data[i]==sym && ++c==k) return i; } return size(); }
    std::pair<size_type,value_type> inverse_select(size_type idx) const { value_type s=data[idx]; return {rank(idx,s), s}; }
    void interval_symbols(size_type i, size_type j, size_type& k, std::vector<uint8_t>& symbols, std::vector<size_type>& l_ranks, std::vector<size_type>& r_ranks) const {
        std::array<bool,256> seen{}; symbols.clear(); l_ranks.clear(); r_ranks.clear();
        for(int c=0;c<256;++c){ auto sym=(uint8_t)c; auto l=rank(i,sym); auto r=rank(j+1,sym); if(r>l){ symbols.push_back(sym); l_ranks.push_back(l); r_ranks.push_back(r); }}
        k=symbols.size();
    }
    size_t serialize(std::ostream& out, void* = nullptr, std::string = "") const { size_type n=data.size(); out.write((char*)&n,sizeof(n)); if(n) out.write((char*)data.data(), n); return sizeof(n)+n; }
    void load(std::istream& in){ size_type n=0; in.read((char*)&n,sizeof(n)); data.resize(n); if(n) in.read((char*)data.data(), n); }
};

template<class WT>
inline void construct(WT& wt, const std::string& file, int){ std::ifstream in(file, std::ios::binary); wt.data.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()); }

}
#endif
