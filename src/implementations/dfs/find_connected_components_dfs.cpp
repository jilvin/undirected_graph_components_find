// Implement an algorithm for finding connected components in a graph based on
// graph traversal (DFS).

#include <deque>
#include <stack>
#include <set>

#include "../../required/generic/process_file/process_file.h"

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

    it = graph.begin();
    while((it != graph.end()) && (unvisitedNode == -1))
    {
        currentNode++;
        if((*it).visited == 0)
        {
            unvisitedNode = currentNode;
        }
        it++;
    }

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

    dfs_stack.push(currentNode);

    graph.at((currentNode) - 1).pushedToStack = 1;

    while(dfs_stack.size() != 0)
    {
        currentNode = dfs_stack.top();
        dfs_stack.pop();

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
                    graph.at((it->second) - 1).pushedToStack = 1;
                }
            }
            else if(it->second == currentNode)
            {
                if(graph.at((it->first)-1).pushedToStack == 0)
                {
                    dfs_stack.push(it->first);
                    graph.at((it->first) - 1).pushedToStack = 1;
                }
            }
        }
    }
    returnPair = std::make_pair(currentComponent, graph);
    return returnPair;
}

void process_graph(int n, std::set< std::pair <int,int> > edge_list)
{
    int currentComponent = 0;

    std::deque <graph_node> graph(n);

    if(edge_list.empty())
    {
        // No edges. Each vertex belong to a different component.
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
    process_file(args[1], process_graph);
}
