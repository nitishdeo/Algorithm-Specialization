#include <bits/stdc++.h>
#define SIZE 200

using namespace std;

struct edge
{
       int node;
       int w;
       edge *next;
};

void dijkstra(edge **g, long *dist, int s)
{
     bool visited[SIZE+1];
     
     for(int i=1; i<=SIZE; i++);
     {
         visited[i++]=false
     }
     visited[s]=true;
     dist[s]=0;
     for(int i=2; i<=SIZE; i++)
     {
             int node, sdist=1000000;
             for(int i=1; i<=SIZE; i++)
             {
                     if(visited[i])
                     {
                             edge *temp=g[i];
                             while(temp!=NULL)
                             {
                                     if(!visited[temp->node] && (dist[i]+temp->w)< sdist )
                                     {
                                             node = temp->node;
                                             wt = (dist[i]+temp->w);
                                     }
                                     temp = temp->next;
                             }
                     }
             }
             visited[node]=true;
             dist[node]=wt;
     }
}
int main()
{
    edge **g=new edge*[SIZE+1];
    long dist[SIZE+1];
    FILE *f=fopen("dijkstraData.txt","r");
    for(int i=1; i<=SIZE; i++)
    {
            g[i]=NULL;
            dist[i]=1000000;
    }
    char *a=new char[500];
    while( fgets(a,500,f) )
    {
            int n1=atoi(a);
            while(a[0]!='\t') a++;
            a++;
            while(true)
            {
                    int node=atoi(a);
                    while(a[0]!=',') a++;
                    a++;
                    int wt=atoi(a);
                    edge *temp=new edge;
                    temp->node=node;
                    temp->w=wt;
                    temp->next=g[n1];
                    g[n1]=temp;
                    while(a[0]!='\t' && strlen(a)>=3)
                        a++;
                    if(strlen(a)<3)
                        break;
                    a++;
            }
            delete a;
            char *a=new char[500];
    }
    
    dijkstra(g,dist,1);
    
    cout<<dist[7]<<endl<<dist[37]<<endl<<dist[59]<<endl<<dist[82]<<endl<<dist[99]<<endl<<dist[115]<<endl<<dist[133]<<endl<<dist[165]<<endl<<dist[188]<<endl<<dist[197]<<endl;
}