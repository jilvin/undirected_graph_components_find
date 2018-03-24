// Implement an algorithm for finding connected components in a graph based on
// graph traversal (DFS).

#include <stdio.h>
#include <set>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <stack>

struct graph_node
{
    int visited = 0;
    int pushedToStack = 0;
};

int findFirstUnvisitedNode(std::deque <graph_node> graph)
{
    std::deque <graph_node>::iterator it;
    int unvisitedNode = -1;
    int currentNode = 0;

    // for(it = graph.begin(); it != graph.end(); it++)
    // {
    //     currentNode++;
    //     printf("Node is %d\n", currentNode);
    //     printf("Visited is %d\n", (*it).visited);
    //     printf("pushedToStack is %d\n", (*it).pushedToStack);
    // }
    // currentNode = 0;

    it = graph.begin();
    while((it != graph.end()) && (unvisitedNode == -1))
    {
        currentNode++;
        // printf("Node is %d\n", currentNode);
        // printf("Visited is %d\n", (*it).visited);
        // printf("pushedToStack is %d\n", (*it).pushedToStack);
        if((*it).visited == 0)
        {
            unvisitedNode = currentNode;
            // printf("Unvisited node %d\n", unvisitedNode);
        }
        it++;
    }

    // printf("leaves findFirstUnvisitedNode\n");
    return unvisitedNode;
}

std::pair<int, std::deque <graph_node>> plotComponent(int firstUnvisitedNode, int currentComponent, std::set< std::pair <int,int> > edge_list, std::deque <graph_node> graph)
{
    std::pair<int, std::deque <graph_node>> returnPair;
    int currentNode;
    std::stack <int> dfs_stack;
    std::set< std::pair<int, int> >::iterator it;

    currentNode = firstUnvisitedNode;

    currentComponent++;
    // printf("currentComponent is %d\n", currentComponent);

    dfs_stack.push(currentNode);
    // printf("Pushed %d\n", currentNode);
    graph.at((currentNode) - 1).pushedToStack = 1;

    while(dfs_stack.size() != 0)
    {
        currentNode = dfs_stack.top();
        // printf("Current node is %d.\n", currentNode);
        dfs_stack.pop();
        // printf("Stack size is %lu.\n", dfs_stack.size());

        // mark currentNode as visited and belonging to the currentComponent
        graph.at((currentNode) - 1).visited = currentComponent;

        // find all edges of current node and push it->second to stack
        for(it = edge_list.begin(); it != edge_list.end(); it++)
        {
            // find edges starting or ending at the currentNode
            if(it->first == currentNode)
            {
                if(graph.at((it->second)-1).pushedToStack == 0)
                {
                    dfs_stack.push(it->second);
                    // printf("Pushed %d\n", it->second);
                    graph.at((it->second) - 1).pushedToStack = 1;
                }
            }
            else if(it->second == currentNode)
            {
                if(graph.at((it->first)-1).pushedToStack == 0)
                {
                    dfs_stack.push(it->first);
                    // printf("Pushed %d\n", it->first);
                    graph.at((it->first) - 1).pushedToStack = 1;
                }
            }
        }
    }
    returnPair = std::make_pair(currentComponent, graph);
    return returnPair;
}

void processGraph(int n, std::set< std::pair <int,int> > edge_list)
{
    int currentComponent = 0;

    std::deque <graph_node> graph(n);

    if(edge_list.empty())
    {
        // No edges. Each vertex belong to a different component.
        // printf("Number of components: %d\n", n);
        currentComponent = currentComponent + n;
    }
    else
    {
        int firstUnvisitedNode = findFirstUnvisitedNode(graph);
        std::pair<int, std::deque <graph_node>> returnPair;
        while(firstUnvisitedNode > 0)
        {
            returnPair = plotComponent(firstUnvisitedNode, currentComponent, edge_list, graph);
            currentComponent = returnPair.first;
            graph = returnPair.second;
            firstUnvisitedNode = findFirstUnvisitedNode(graph);
        }
    }

    printf("Number of components found is %d.\n", currentComponent);
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
                    processGraph(n, edge_list);
                    printf("\n");
                }
                n = a;
                // e = b;
                // printf("Set %d found with %d vertices and %d edges.\n", count, n, e);
                edge_list.clear();
                initSet = 1;
            }
            else
            {
                // to support index starting from 0 -- remove after testing -- start
                // a++;
                // b++;
                // to support index starting from 0 -- remove after testing -- end
                p = std::make_pair(a, b);
                edge_list.insert(p);
            }
        }
    }
    processGraph(n, edge_list);
}
