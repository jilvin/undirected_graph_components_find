// Implement an algorithm for finding connected components in a graph based on
// disjoint sets.

#include <iostream>
#include <set>

#include "../../required/generic/process_file/process_file.h"
#include "./classes/disjoint_set/disjoint_set.h"

void process_edge(disjoint_set disjoint_set, std::pair <int,int> edge)
{
    // process the edge
    std::cout << "the edge is " << edge.first << " " << edge.second << std::endl;

    if(disjoint_set.find(edge.first) == 0)
    {
        // a set with the element does not exist
        disjoint_set.make_set(edge.first);
    }

    if(disjoint_set.find(edge.second) == 0)
    {
        // a set with the element does not exist
        disjoint_set.make_set(edge.second);
    }
}

void process_graph(int n, std::set< std::pair <int,int> > edge_list)
{
    int componentsCount = 0;
    disjoint_set disjoint_set;

    // process each edge from the edge_list
    std::set< std::pair <int,int> >::iterator edge_list_iterator;

    for(edge_list_iterator = edge_list.begin(); edge_list_iterator != edge_list.end(); edge_list_iterator++)
    {
        process_edge(disjoint_set, *edge_list_iterator);
    }

    std::cout << componentsCount;
}

int main(int argn, char** args)
{
    process_file(args[1], process_graph);
}
