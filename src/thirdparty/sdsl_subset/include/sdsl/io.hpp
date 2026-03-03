#ifndef SDSL_SUBSET_IO_HPP
#define SDSL_SUBSET_IO_HPP
#include <fstream>
#include <string>
#include "structure_tree.hpp"
namespace sdsl {
template<class T>
inline size_t write_member(const T& v, std::ostream& out, structure_tree_node* = nullptr, const std::string& = ""){
    out.write(reinterpret_cast<const char*>(&v), sizeof(T)); return sizeof(T);
}
template<class T>
inline void read_member(T& v, std::istream& in){ in.read(reinterpret_cast<char*>(&v), sizeof(T)); }

template<class T>
inline bool store_to_file(const T& obj, const std::string& file){ std::ofstream out(file, std::ios::binary); if(!out.good()) return false; obj.serialize(out,nullptr,""); return true; }

template<class T>
inline bool load_from_file(T& obj, const std::string& file){ std::ifstream in(file, std::ios::binary); if(!in.good()) return false; obj.load(in); return true; }
}
#endif
