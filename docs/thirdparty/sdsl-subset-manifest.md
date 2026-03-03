# Vendored SDSL subset manifest

This repository vendors a **source-only** SDSL-compatible subset under:

- `src/thirdparty/sdsl_subset/include/sdsl/`

No `.a` or other binary artifacts are stored in the repository.

## Scope of the subset

The subset provides only the minimal API surface currently required by this codebase:

- `sdsl::bit_vector` and `sdsl::bit_vector::rank_1_type`
- `sdsl::bits::hi`
- `sdsl::util::{clear,set_to_value,class_name}`
- serialization helpers: `sdsl::{write_member,read_member,store_to_file,load_from_file}`
- structure-tree stubs: `sdsl::structure_tree_node`, `sdsl::structure_tree::add_child`
- lightweight wavelet-tree compatibility for script helpers via `sdsl::wt_huff<>` and `sdsl::construct`

## Build integration

CMake option:

- `GRLBWT_USE_LOCAL_SDSL_SUBSET=ON` (default): uses source-only subset headers above.
- `GRLBWT_USE_LOCAL_SDSL_SUBSET=OFF`: falls back to `find_package(LibSDSL)`.

