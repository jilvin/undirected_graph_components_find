// This is start of the header guard.  ADD_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <set>
#include <string>
#include <fstream>
#include <sstream>

void process_file(std::string file, void (&process_graph)(int n, std::set< std::pair <int,int> >) )
{
    // get graph as edge list from file satisfying the following specifications
    // 1) Each set of edge list is separated by a line break.
    // 2) First line of each set is <int n> <int e> such that n is the number of
    // total vertices and e is the total number of edges in the graph.
    std::ifstream infile(file);
    std::set< std::pair <int,int> > edge_list;

    std::string line;
    int a, b, count = 1, initSet = 0, n;
    // int e;
    std::pair<int, int> p;

    while(std::getline(infile, line))
    {
        std::istringstream iss(line);
        if(!(iss >> a >> b))
        {
            count++;
            initSet = 0;
        }
        else
        {
            if(initSet == 0)
            {
                if(count != 1)
                {
                    process_graph(n, edge_list);
                    printf("\n");
                }
                n = a;
                // e = b;
                edge_list.clear();
                initSet = 1;
            }
            else
            {
                p = std::make_pair(a, b);
                edge_list.insert(p);
            }
        }
    }
    process_graph(n, edge_list);
}

// This is the end of the header guard
#endif
