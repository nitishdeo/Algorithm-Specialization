#include<bits/stdc++.h>
using namespace std;

long long int max(long long int a,long long int b) 
{ 
    return (a > b)? a : b;
}
 
int main()
{
    ifstream infile; 
	infile.open("two.txt");
	long long int W;
	infile>>W;
	int n;
	infile>>n;
    //cout<<"a"<<endl;
    long long int val[n];
    long long int wt[n];
    for( int i=0 ; i<n ; i++)
    {
        infile>>val[i];
        infile>>wt[i];
    }
    
    long long *K[2];
    for(int j=0; j<2; j++) K[j]=new long long[W+1];
    for(long long j=0; j<=W; j++)
        K[0][j]=0;
    for(int i=1; i<=n; i++)
    {
          for(long long x=0; x<=W; x++)
             if(x>=wt[i])
                K[1][x]=max(K[0][x],K[0][x-wt[i]]+val[i]);
             else
                K[1][x]=K[0][x];
          for(long long j=0; j<=W; j++)
             K[0][j]=K[1][j];
             
    //cout<<"b"<<i<<endl;
    }
    cout<<K[1][W]<<endl;
    
    return 0;
}