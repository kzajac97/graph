#pragma once

#include <vector>

struct node
{
    char index;
    //vector storing adjecent nodes
    std::vector<char> adjVertices;

    node(void) = default;
    node(char initIndex) : index(initIndex) {}; 
};

class graph 
{
    //vector of graphs vertices
    std::vector<node> vertices;

    public:
    graph(void) = default;
    ~graph(void) {};

    //public methods
    void AddVertex(void) { addVertex(); }
    void AddEdge(char left, char right) { addEdge(left,right); }
    void DepthFirstSearch(void) { depthFirstSearch(); }
    void BreadthFirstSearch(void) { breadthFirstSearch(); }

    private:
    /*adds new vertex with index of 
    great characters added in lexical order
    create new node and add it to vertices vector */ 
    void addVertex(void);
    /*adds right vertex to adjecentcy vector 
    of left vertex and than other way round*/
    void addEdge(char leftVertex, char rightVertex);
    /*traverse using a stack
    method pushes first element onto a stack
    and than marks it as visited(using other stack)
    than pushes all adjecent vertices onto stack
    if top is visited it pops it and if not pushes
    all adjecent values until stack is empty*/
    void depthFirstSearch(void);
    /**/
    void breadthFirstSearch(void);

    //utility
    const char getLexicalIndex(unsigned index) { return (char) 0x41 + index; }
    const int getNumericIndex(char index) { return (int) index - 0x41; }
    const bool findInVector(std::vector<node> vec, node n);
};