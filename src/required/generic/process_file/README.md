# Input File Processor
Program to process the input file.

## Functions

### process_file
Function to read the input file and initiate process_graph function sent to the function as argument as each adjacency list is read.

#### Signature
void process_file(std::string file, void (&process_graph)(int n, std::set< std::pair <int,int> >) )

#### Arguments
|Sl. No|Name|Data Type|Description|
|:---:|:---:|:---:|:---:|
|1|file|std::string|Path to file to be read.|
|2|process_graph|(&process_graph)(int n, std::set< std::pair <int,int> >) )|Reference to process_graph. The function is executed when an adjacency_list is available for processing after reading from the input file.|
