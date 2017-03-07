#include <bits/stdc++.h>
#define SIZE 10000
using namespace std;
int merge(int a[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int cnt = 0;
 
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      temp[k++] = a[i++];
    }
    else
    {
      temp[k++] = a[j++];
 
      cnt = cnt + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = a[i++];
 
  while (j <= right)
    temp[k++] = a[j++];
 
  for (i=left; i <= right; i++)
    a[i] = temp[i];
 
// for (i=left; i <= right; i++)
//   cout<<a[i];
 
  return cnt;
}
int _mergeSort(int a[], int temp[], int left, int right)
{
  int mid, cnt = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    return( _mergeSort(a, temp, left, mid) + _mergeSort(a, temp, mid+1, right) + merge(a, temp, left, mid+1, right));
  }
  return 0;
}
int mergeSort(int a[], int sz)
{
    int *temp = (int *)malloc(sizeof(int)*sz);
    return _mergeSort(a, temp, 0, sz - 1);
}

 
int main(int argv, char** args)
{
    ifstream infile; 
	  infile.open("input.txt");
	  
    int a[SIZE+1];
    for(int i=1; i<=SIZE; i++)
    {
        infile>>a[i];
    }
    cout<<mergeSort(a, SIZE)<<endl;
    return 0;
}