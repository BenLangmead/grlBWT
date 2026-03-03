#ifndef SDSL_SUBSET_STRUCTURE_TREE_HPP
#define SDSL_SUBSET_STRUCTURE_TREE_HPP
#include <string>
namespace sdsl {
struct structure_tree_node{};
struct structure_tree {
    static structure_tree_node* add_child(structure_tree_node* v, const std::string&, const std::string&) { return v; }
};
}
#endif
