#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest;
};
struct Graph
{
    int V, E;
    Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
struct sset
{
    int parent;
    int rank;
};
 // A utility function to find set of an element i
// (uses path compression technique)
int find(struct sset ssets[], int i)
{
    // find root and make root as parent of i
    // (path compression)
    if (ssets[i].parent != i)
      ssets[i].parent = find(ssets, ssets[i].parent);
 
    return ssets[i].parent;
}
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct sset ssets[], int x, int y)
{
    int xroot = find(ssets, x);
    int yroot = find(ssets, y);
 
    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (ssets[xroot].rank < ssets[yroot].rank)
        ssets[xroot].parent = yroot;
    else if (ssets[xroot].rank > ssets[yroot].rank)
        ssets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        ssets[yroot].parent = xroot;
        ssets[xroot].rank++;
    }
}
int kargerMinCut(struct Graph* graph)
{
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;

    struct sset *ssets = new sset[V];
 
    for (int v = 0; v < V; ++v)
    {
        ssets[v].parent = v;
        ssets[v].rank = 0;
    }
 
    int k = V;
 
    while (k > 2)
    {
       int i = rand() % E;
 
       int sset1 = find(ssets, edge[i].src);
       int sset2 = find(ssets, edge[i].dest);
 
       if (sset1 != sset2)
       {
          k--;
          Union(ssets, sset1, sset2);
       }
    }
 
    int cuts = 0;
    for (int i=0; i<E; i++)
    {
        int sset1 = find(ssets, edge[i].src);
        int sset2 = find(ssets, edge[i].dest);
        if (sset1 != sset2)
          cuts++;
    }
 
    return cuts;
}

int main()
{
    ifstream infile; 
	infile.open("kargerMinCut.txt");
	
	int v=200,e=5234,v1,v2;
    struct Graph* graph = createGraph(v,e);
    
    string  line;
    int i=0,flag;
    while(getline(infile, line))
    {
        stringstream linestream(line);
        linestream>>v1;
        while(!linestream.eof())
        {
            linestream>>v2;
            flag=1;
            for( int e1=0;e1<i;e1++)
            {
                if((graph->edge[i].src == v2) && (graph->edge[i].dest == v1))
                flag=0;
            }
            if(flag)
            {
            graph->edge[i].src = v1;
            graph->edge[i].dest = v2;
            i++;
            }
        }
    }
// cout<<i;
    int mincut = 200;
    for(int i=0 ; i<10000 ; i++)
    {
        srand(time(NULL));
        //cout<<"edcdcdc";
        v1 = kargerMinCut(graph);
        if(v1<mincut)
        mincut=v1;
    }
    cout<<"Min Cut :"<<mincut<<endl;
    return 0;
}