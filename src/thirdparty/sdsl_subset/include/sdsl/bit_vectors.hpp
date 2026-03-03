#ifndef SDSL_SUBSET_BIT_VECTORS_HPP
#define SDSL_SUBSET_BIT_VECTORS_HPP
#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include "structure_tree.hpp"
namespace sdsl {
class bit_vector {
public:
    using size_type = std::size_t;
    std::vector<uint8_t> d;
    bit_vector()=default;
    explicit bit_vector(size_type n, uint8_t v=0): d(n, v?1:0) {}
    void resize(size_type n){ d.resize(n,0); }
    size_type size() const { return d.size(); }
    uint8_t operator[](size_type i) const { return d[i]; }
    uint8_t& operator[](size_type i) { return d[i]; }
    void swap(bit_vector& o){ d.swap(o.d); }
    size_type serialize(std::ostream& out, structure_tree_node* = nullptr, std::string = "") const {
        size_type n=d.size(); out.write(reinterpret_cast<const char*>(&n), sizeof(n));
        if(n) out.write(reinterpret_cast<const char*>(d.data()), n);
        return sizeof(n)+n;
    }
    void load(std::istream& in){ size_type n=0; in.read(reinterpret_cast<char*>(&n), sizeof(n)); d.resize(n); if(n) in.read(reinterpret_cast<char*>(d.data()), n); }

    class rank_1_type {
        const bit_vector* bv{nullptr};
    public:
        rank_1_type()=default;
        explicit rank_1_type(const bit_vector* b): bv(b){}
        void set_vector(const bit_vector* b){ bv=b; }
        size_type operator()(size_type i) const {
            size_type c=0;
            if(!bv) return 0;
            if(i>bv->d.size()) i=bv->d.size();
            for(size_type k=0;k<i;++k) c += (bv->d[k]!=0);
            return c;
        }
    };
};
}
#endif
