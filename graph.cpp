#include "graph.hh"

#include <iostream>
#include <stack>
#include <queue>
#include <memory>

void graph::addVertex(void)
{
    char index = getLexicalIndex(vertices.size());

    std::unique_ptr<node> newNode(new node(index));
    vertices.push_back(*newNode);
}

void graph::addEdge(char leftVertex, char rightVertex)
{
    for(unsigned i=0; i < vertices.size(); i++)
    {
        if(vertices[i].index == leftVertex)
        { vertices[i].adjVertices.push_back(rightVertex); }
    }

    for(unsigned i=0; i < vertices.size(); i++)
    {
        if(vertices[i].index == rightVertex)
        { vertices[i].adjVertices.push_back(leftVertex); }
    }
}

const bool graph::findInVector(std::vector<node> vec, node n)
{
    for(const auto &it : vec)
    {
        if(it.index == n.index)
        { return true; }
    }

    return false;
}

void graph::depthFirstSearch(void)
{
    std::stack<node> stack;
    std::vector<node> visited;
    node vertex;

    stack.push(vertices[0]);

    while(!stack.empty())
    {
        vertex = stack.top();
        stack.pop();

        if(!findInVector(visited, vertex))
        { visited.push_back(vertex); }

        for(const auto &it : vertex.adjVertices)
        { 
            for(const auto &jt : vertices)
            {
                if(it == jt.index && !findInVector(visited,jt))
                { stack.push(jt); }
            }
        }
    }

    for(const auto &it : visited)
    { std::cout << it.index << "\n"; }
}

void graph::breadthFirstSearch(void)
{
    std::queue<node> queue;
    std::vector<node> visited;
    node vertex;

    queue.push(vertices[0]);

    while(!queue.empty())
    {
        vertex = queue.front();
        queue.pop();

        if(!findInVector(visited,vertex))
        { visited.push_back(vertex); }

        for(const auto &it : vertex.adjVertices)
        {
            for(const auto &jt : vertices)
            {
                if(it == jt.index && !findInVector(visited,jt))
                {
                    queue.push(jt);
                    visited.push_back(jt);
                }
            }
        }
    }

    for(const auto &it : visited)
    { std::cout << it.index << "\n"; }
}