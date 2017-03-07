#include <bits/stdc++.h>
using namespace std;

int minKey(int key[], bool mstSet[],int V)
{
   int min = INT_MAX,i;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], i = v;
 
   return i;
}
int primMST(int graph[500][500] , int V)
{
     int parent[V];
     int key[V]; 
     bool mstSet[V];
 
     for (int i = 0; i < V; i++)
     {
        key[i] = INT_MAX;
        mstSet[i] = false;
     }
     key[0] = 0; 
     parent[0] = -1;
 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet,V);
 
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
            {     
                parent[v]  = u; 
                key[v] = graph[u][v];
            }
        }
     }
     int mst=0;
     for (int i = 1; i < V; i++)
      mst = mst + graph[i][parent[i]];
      
     return mst;
}
int main()
{
    int a,b,c,e,V;
	ifstream infile; 
	infile.open("edges.txt");
	
	infile>>V;
    
    int graph[500][500];
 
    infile>>e;
    cout<<V<<" "<<e<<endl;
    for(int i=0; i<e; i++)
    {
        infile>>a;
        infile>>b;
        infile>>c;
        cout<<a<<b<<c<<endl;
        graph[a-1][b-1] = c;
        graph[b-1][a-1] = c;
    }
    cout<<"Prim's MST"<<primMST(graph,V);
    return 0;
}