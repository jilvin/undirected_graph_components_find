// Derived work from work of geeksforgeeks.
// https://www.geeksforgeeks.org
// /test-case-generation-set-4-random-directed-undirected-weighted-and-unweighte
// d-graphs/

// A C++ Program to generate test cases for a graph with a possibilty of
// multiple components

#include <stdio.h>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <utility>

// Define the number of runs for the test data generated
#define RUN 10

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 40000

// Define the maximum number of edges
#define MAX_EDGES 100000

int main()
{
    std::set< std::pair<int, int> > container;
    std::set< std::pair<int, int> >::iterator it;

    // // write stdout directly to file
    if (freopen("test_cases_undirected_unweighted_graph.in", "w", stdout) == NULL)
    {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int NUM; // Number of Vertices
    int NUMEDGE; // Number of Edges

    //For random values every time
    srand(time(NULL));

    for (int i=1; i<=RUN; i++)
    {
        NUM = 1 + (rand() % MAX_VERTICES);

        if(NUM ==1)
        {
            NUMEDGE = 0;
        }
        else
        {
            // Define the maximum number of edges of the graph
            // Since the most dense graph can have N*(N-1)/2 edges
            // where N =  number of vertices in the graph
            NUMEDGE = 1 + (rand() % MAX_EDGES);

            while (NUMEDGE > ((NUM*(NUM-1))/2))
            {
                NUMEDGE = 1 + (rand() % MAX_EDGES);
            }
        }

        // print the number of vertices and edges
        printf("%d %d\n", NUM, NUMEDGE);

        // Then print the edges of the form (a b)
        // where 'a' is connected to 'b'
        for (int j=1; j<=NUMEDGE; j++)
        {
            int a = 1 + (rand() % NUM);
            int b = 1 + (rand() % NUM);
            std::pair<int, int> p = std::make_pair(a, b);
            std::pair<int, int> p_reverse = std::make_pair(b, a);

            // to make sure an edge is not repeated
            while ((container.find(p) != container.end()) || (container.find(p_reverse) != container.end()))
            {
                a = 1 + (rand() % NUM);
                b = 1 + (rand() % NUM);
                p = std::make_pair(a, b);
                p_reverse = std::make_pair(b, a);
            }

            // insert pair into the container
            container.insert(p);
        }

        for (it=container.begin(); it!=container.end(); it++)
        printf("%d %d\n", it->first, it->second);

        container.clear();
        if(i != RUN)
        {
            printf("\n");
        }
    }

    fclose(stdout);
    return(0);
}
