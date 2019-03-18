#include "graph.hh"
#include <iostream>

int main(void)
{
    graph g;
    for(int i=0; i < 9; i++)
        { g.AddVertex(); }

    g.AddEdge('A','B');
    g.AddEdge('A','D');
    g.AddEdge('B','C');
    g.AddEdge('B','E');
    g.AddEdge('C','F');
    g.AddEdge('D','G');
    g.AddEdge('E','G');
    g.AddEdge('G','H');
    g.AddEdge('H','I');

    
    g.DepthFirstSearch();
    std::cout << "\n\n";
    g.BreadthFirstSearch();
}