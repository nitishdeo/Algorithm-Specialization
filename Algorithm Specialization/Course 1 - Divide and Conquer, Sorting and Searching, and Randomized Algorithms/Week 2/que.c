#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000

long long int helpinversion(long int *a, long int left, long int right)
{
    long int *b = new long int[right-left+2];
     
    long int i=left, j, k;
    
    j=(right-left)/2+left+1;
    long long int cnt=0;
     
    for( k=1 ; (k<=right-left+1) && (i<=(right-left)/2+left) && (j<=right) ; k++)
    {
          if(a[i]<a[j]) 
          {
              b[k]=a[i++];
          }
          else
          {
              b[k]=a[j++];
              cnt = cnt+((right-left)/2+left-i+1);
          }
    }
    for(; k<=right-left+1 && i<=(right-left)/2+left; k++)
    {
        b[k]=a[i++];
    }
    for(; k<=right-left+1 && j<=right; k++)
    {  
        b[k]=a[j++];
    }
    for(k=1, i=left ; k<=right-left+1 && i<=right; k++, i++)
    {
        a[i]=b[k];
    }
    delete b;
    return cnt;
}

long long int inversion(long int *a, long int left, long int right)
{
    if(right>left)
    {
        return inversion(a, left, (right-left)/2+left) + inversion(a, (right-left)/2+left+1, right) + helpinversion(a, left, right);
    }
    
    return 0;
}

int main ()
{
    long int *a=new long int[SIZE+1];
    fstream fp;
    fp.open("input.txt");
    
    long int k;

    for(long int i=1; i<=SIZE; i++)
    {
            fp>>k;
            a[i]=int(k);
    }
    
    cout<<"Number of inversionersions: "<<inversion(a,1,SIZE)<<endl;
    delete a;
}