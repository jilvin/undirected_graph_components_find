## Program to generate adjacency list of undirected graph.

### Command Line Arguments
|Order|Variable Name|Data Type|Required|Description|
|:---:|:---:|:---:|:---:|:---:|
|1|number_of_adjacency_lists_required|int|true|Number of adjacency lists to be generated.|
|2|output_file|std::string|true|File name to write generated output.|

### Compilation
g++ gen.cpp -o gen.out

### Execution
./gen <number_of_adjacency_lists_required> <output_file>

#### Example
./gen.out 3 output.txt

### Derived Work
Derived work from work of geeksforgeeks.

https://www.geeksforgeeks.org/test-case-generation-set-4-random-directed-undirected-weighted-and-unweighted-graphs/
