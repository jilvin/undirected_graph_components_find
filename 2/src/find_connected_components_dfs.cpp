// Implement an algorithm for finding connected components in a graph based on
// graph traversal (DFS).

#include <stdio.h>
#include <set>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>

void processGraph(int n, std::set< std::pair <int,int> > edge_list)
{
    std::set< std::pair<int, int> >::iterator it;

    std::deque <int> graph(n, 0);

    for (it=edge_list.begin(); it!=edge_list.end(); it++)
    {
        printf("%d %d\n", it->first, it->second);
    }
}

int main(int argn, char** args)
{
    std::set< std::pair <int,int> > edge_list;

    // get graph as edge list from file satisfying the following specifications
    // 1) Each set of edge list is separated by a line break.
    // 2) First line of each set is <int n> <int e> such that n is the number of
    // total vertices and e is the total number of edges in the graph.
    std::ifstream infile(args[1]);

    std::string line;
    int a, b, count = 1, initSet = 0, n, e;
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
                processGraph(n, edge_list);
                if(count != 1)
                {
                    printf("\n");
                }
                n = a;
                e = b;
                printf("Set %d found with %d vertices and %d edges.\n", count, n, e);
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
    processGraph(n, edge_list);
}
