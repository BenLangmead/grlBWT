#ifndef SDSL_SUBSET_INT_VECTOR_HPP
#define SDSL_SUBSET_INT_VECTOR_HPP

#include <vector>
#include <cstddef>
#include <cstdint>

namespace sdsl {

template<uint8_t t_width>
class int_vector {
public:
    using value_type = uint64_t;
    using size_type = std::size_t;

private:
    std::vector<value_type> d;

public:
    int_vector() = default;
    explicit int_vector(size_type n): d(n, 0) {}

    void resize(size_type n){ d.resize(n, 0); }
    size_type size() const { return d.size(); }

    value_type operator[](size_type i) const { return d[i]; }
    value_type& operator[](size_type i) { return d[i]; }
};

}

#endif
