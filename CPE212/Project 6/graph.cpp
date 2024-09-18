#include "graph.h"

using namespace std;

Graph::Graph()
{
    vertices = NULL; // empty vertices linked list
}

Graph::~Graph()
{
    VertexNode* temp; // temporary pointers
    EdgeNode* edgeTemp;

    while (vertices != NULL) // while the list is not empty
    {
        temp = vertices; // set temp to first node
        
        while (vertices->edgePtr != NULL) // while the edges
        {
            edgeTemp = vertices->edgePtr;
            vertices->edgePtr = edgeTemp->nextPtr;
            delete edgeTemp;
        }
        
        vertices = vertices->nextVertex; //make the first node the next node in list
        delete temp; //delete the node
    }
}

void Graph::AddVertex(string v)
{
    if (vertices == NULL)
    {
        vertices = new VertexNode;

        vertices->vname = v;
        vertices->nextVertex = NULL;
        vertices->edgePtr = NULL;
    }
    else
    {
        VertexNode* temp = new VertexNode;
        VertexNode* temp2 = vertices;

        temp->vname = v;
        temp->nextVertex = temp2;
        temp->edgePtr = NULL;

        vertices = temp;
    }
}

void Graph::AddEdge(string s, string d, int w)
{
    try
    {
        VertexNode* tempPtr = WhereIs(s); // find source node
        VertexNode* tempPtr2 = WhereIs(d); // find destination node
        EdgeNode* edgeTemp = new EdgeNode; // create an empty edge node
        
        edgeTemp->weight = w; // assign weigh variable
        edgeTemp->destination = tempPtr2; // assign destination node
        
        EdgeNode* edgeTemp2 = tempPtr->edgePtr; // temp pointer for the first in the list of edges
        edgeTemp->nextPtr = edgeTemp2; // set the new edge's next node to the frst in list
        tempPtr->edgePtr = edgeTemp; // set the new edge to the frist in the list
    }
    catch ( std::bad_alloc ) // see if list if full
    {
        throw GraphFull(); // error class
    }
}

bool Graph::IsPresent(string v)
{
    VertexNode* temp;
    temp = vertices;

    while (temp->vname != v)
    {
        if (temp->nextVertex == NULL)
        {
            return false;
        }
        else
        {
            temp = temp->nextVertex;
        }
    }

    return true;
}

VertexNode* Graph::WhereIs(string v)
{
    VertexNode* tempPtr;
    tempPtr = vertices;

    if(IsPresent(v))
    {
        while (tempPtr->vname != v)
        {
            if (tempPtr->nextVertex == NULL)
            {
                throw GraphVertexNotFound();
                return NULL;
            }
            else
            {
                tempPtr = tempPtr->nextVertex;
            }
        }

        return tempPtr;
    }
    else
    {
        throw GraphVertexNotFound();
    }
}

int Graph::WeightIs(string s, string d)
{
    VertexNode* temp = WhereIs(s);
    VertexNode* temp2 = WhereIs(d);
    EdgeNode* edgeTemp = temp->edgePtr;
    
    while (edgeTemp->nextPtr != NULL)
    {
        if (edgeTemp->destination == temp2)
        {
            return edgeTemp->weight;
        }
        else
        {
            edgeTemp = edgeTemp->nextPtr;
        }
    }

    throw GraphEdgeNotFound();
}

void Graph::ClearMarks()
{
    VertexNode* temp = vertices;
    
    while (temp != NULL)
    {
        temp->mark = false;
        temp = temp->nextVertex;
    }
}

void Graph::MarkVertex(string v)
{
    VertexNode* temp = WhereIs(v);
    temp->mark = true;
}

bool Graph::IsMarked(string v)
{
    VertexNode* temp = WhereIs(v);
    return temp->mark;
}

void Graph::GetToVertices(string V, queue<string>& q)
{
    VertexNode* srcPtr = WhereIs(V);
    VertexNode* tempPtr;
    EdgeNode* edge = srcPtr->edgePtr;

    while (edge != NULL)
    {
        tempPtr = edge->destination;
        q.push(tempPtr->vname);
        edge = edge->nextPtr;
    }
}

void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
{
    stack<string> s; // establish stack
    queue<string> vertexQ; // establish vertex queue
    bool found = false; // flag for if a path is found
    string vertex; // string varable for the current vertex
    string item; // string variable for vertexq's vertex
    VertexNode* temp = WhereIs(startVertex); // check that vertex exists;
    VertexNode* temp2 = WhereIs(endVertex); // check that vertex exists;
    
    ClearMarks(); // clear all marks
    
    s.push(startVertex); // push first value onto stack
    
    do
    {
        vertex = s.top(); // set vertex equal to top value
        s.pop(); // remove top value
        
        if (vertex == endVertex) // see if we've finished the path
        {
            path.push(vertex); // push the vertex onto the path
            found = true; // flag to kill loop
        }
        else
        {
            if (!IsMarked(vertex)) // see if we've already visited this vertex
            {
                MarkVertex(vertex); // mark it
                path.push(vertex); // push the vertex onto the path
                GetToVertices(vertex, vertexQ); // get a queue of adjacent vertex's
                
                while (!vertexQ.empty()) // iterate through queue
                {
                    item = vertexQ.front(); // set the item to the first item in queue
                    vertexQ.pop(); // remove first in queue
                    
                    if (!IsMarked(item)) // see if this vertex isn't marked
                    {
                        s.push(item); // push that onto the stack
                    }
                }
            }
        }
    } while (!s.empty() && !found); // terminate do-while loop
    
    if(s.empty())
    {
        while (!path.empty())
        {
            path.pop();
        }
    }
}