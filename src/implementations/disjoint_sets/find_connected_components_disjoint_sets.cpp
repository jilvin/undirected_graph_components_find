// Implement an algorithm for finding connected components in a graph based on
// disjoint sets.

#include <iostream>
#include <set>

#include "../../required/generic/process_file/process_file.h"
#include "./classes/disjoint_set/disjoint_set.h"

void process_edge(disjoint_set *disjoint_set, std::pair <int,int> edge)
{
    // translate input range > 0 to > 1
    edge.first--;
    edge.second--;
    // process the edge
    // std::cout << "the edge is " << edge.first << " " << edge.second << std::endl;

    if(disjoint_set->find(edge.first) == -1)
    {
        // a set with the element does not exist
        disjoint_set->make_set(edge.first);
    }

    if(disjoint_set->find(edge.second) == -1)
    {
        // a set with the element does not exist
        disjoint_set->make_set(edge.second);
    }

    disjoint_set->union_sets_based_on_representative(disjoint_set->find(edge.first), disjoint_set->find(edge.second));
}

void process_graph(int n, std::set< std::pair <int,int> > edge_list)
{
    disjoint_set disjoint_set(n);

    // process each edge from the edge_list
    std::set< std::pair <int,int> >::iterator edge_list_iterator;

    for(edge_list_iterator = edge_list.begin(); edge_list_iterator != edge_list.end(); edge_list_iterator++)
    {
        process_edge(&disjoint_set, *edge_list_iterator);
    }

    std::cout << "Number of components found is " << disjoint_set.returnComponentsCount() << "." << std::endl;
}

int main(int argn, char** args)
{
    process_file(args[1], process_graph);
}
