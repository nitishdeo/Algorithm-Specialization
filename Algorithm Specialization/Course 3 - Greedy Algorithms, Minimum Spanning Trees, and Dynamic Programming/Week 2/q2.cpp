#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,b;
    ifstream infile; 
	infile.open("Clustring2.txt");
	infile>>n>>b;
    
    int nodes[n][b];
    int nodeclus[n];
    for(int i=0; i<n; i++)
    {
        for( int k=0 ; k<b ; k++)
        {
              infile>>nodes[i][k];
        }
        nodeclus[i]=i;
    }
    int cluster=n;
    for(int i=0; i<n; i++)
    {
        int curr_clus = nodeclus[i];
        for( int j=0 ; j<n; j++)
            if( nodeclus[j]!=curr_clus)
            {
                int count=0;
                for( int k=0; k<b && (count<3); k+=2)
                    if(nodes[i][k]!=nodes[j][k])
                        count++;
                if(count<3)
                {
                    int old_clus=nodeclus[j];
                    for(int t=0; t<n; t++)
                        if(nodeclus[t] == old_clus)
                            nodeclus[t]=curr_clus;
                                cluster--;
                }
            }
    }
    cout<<"cluster: "<<cluster<<endl;
}