#include <bits/stdc++.h>
using namespace std;
 
class Graph
{
    int V;
    list<int> *adj;

    void fillOrder(int v, bool visited[], stack<int> &Stack);

    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    void printSCCs();

    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    Stack.push(v);
}
 

void Graph::printSCCs()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
 
    // Create a reversed graph
    Graph gr = getTranspose();
 
    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}
 
// Driver program to test above functions
int main()
{
    int V=875714;
    
    Graph g(V);
    ifstream infile; 
	infile.open("SSC.txt");
    int a,b;
    while(!infile.eof())
    {
        infile>>a;
        infile>>b;
        //cout<<a<<b<<c<<endl;
        g.addEdge(a,b);
    }
 
    g.printSCCs();
 
    return 0;
}
