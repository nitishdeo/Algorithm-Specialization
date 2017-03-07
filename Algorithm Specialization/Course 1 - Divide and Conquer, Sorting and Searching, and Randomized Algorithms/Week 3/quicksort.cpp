#include <bits/stdc++.h>
#define SIZE 10000

using namespace std;

void swap(int *x, int *y)
{
     int temp=*x;
     *x=*y;
     *y=temp;
}

void getPivot(int *a, int low, int high)
{
    int m=low+(high-low)/2;
    if(a[low]>=a[m] && a[low]>=a[high])
    {
        if(a[m]>=a[high]) swap(&a[m], &a[low]);
        else swap(&a[high],&a[low]);
    }
    else if(a[m]>=a[low] && a[m]>=a[high])
    {
        if(a[high]>=a[low]) swap(&a[high], &a[low]);
    }
    else if(a[m]>=a[low]) swap(&a[m], &a[low]);
}

int partition(int *a, int low, int high)
{
    int i=low+1, j, p=a[low];
    for(j=low+1; j<=high; j++)
    {
          if(a[j]<p)
          {
                      swap(&a[j], &a[i]);
                      i++;
          }
    }
    swap(&a[i-1], &a[low]);
    return i-1;
}

long long quicksort(int *a, int low, int high)
{
     if(high<=low) return 0;
     long long comp=high-low;
     swap(&a[low], &a[high]);
     //getPivot(a, low, high);
     int j=partition(a, low, high);
     comp+=quicksort(a, low, j-1);
     comp+=quicksort(a, j+1, high);
     return comp;
}

int main()
{
    ifstream infile;
	infile.open("input.txt");
    int a[SIZE+1];
    for(int i=1; i<=SIZE; i++)
    {
        infile>>a[i];
    }
    cout<<quicksort(a,1,SIZE)<<endl;
    return 0;
}
