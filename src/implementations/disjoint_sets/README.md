# Disjoint Sets based Implementation
Implementation using disjoint set datastructure.

### Warning
This implementation uses a disjoint_set which is implemented using an array. Hence this program cannot consider as any number < 1 as a valid node identification number.

The optimal performance can be obtained with numbering starting 1 (optimal use of arrays with 1 mapped to index 0 and so on).

#### Workaround
Shift the input range to a range that starts from 1.

## Compilation
g++ find_connected_components_disjoint_sets.cpp -std=c++11 -o find_connected_components_disjoint_sets.out
