#include<bits/stdc++.h>
using namespace std;
 
const int V=1000;
#define INF 99999
 
void floydWarshall (int graph[V][V],int V)
{
    int dist[V][V], i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    int min = 99999;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if ( min > dist[i][j] )
            {
                min = dist[i][j];
            }
        }
    }
    cout<<"SSP "<<min<<endl;
}
 
int main()
{
    int a,b,c,e,ver;
	ifstream infile; 
	infile.open("g3.txt");
	
	infile>>ver;
    
    int graph[V][V];
    for( int i=0 ; i<V ; i++)
        for( int j=0 ; j<V ; j++)
            graph[i][j] = INF;
            
    infile>>e;
    //cout<<V<<" "<<e<<endl;
    for(int i=0; i<e; i++)
    {
        infile>>a;
        infile>>b;
        infile>>c;
       // cout<<a<<b<<c<<endl;
        graph[a-1][b-1] = c;
    }
 
    floydWarshall(graph,V);
    return 0;
}