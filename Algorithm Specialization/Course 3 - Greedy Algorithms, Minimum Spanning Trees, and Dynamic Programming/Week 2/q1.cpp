#include <bits/stdc++.h>
using namespace std;

int n, maxSpace,k=4;
struct node
{
       int n1,n2,cost;
       node *left;
       node *right;
};

bool flag=false;
void clustring(node *T, int *cluster)
{
     static int curclus=n;
     if(T!=NULL)
     {
     clustring(T->left, cluster);
     int n1=T->n1, n2=T->n2, cost=T->cost;
     if(flag)
     {
             if(cluster[n1] != cluster[n2])
             {
              maxSpace=cost;
              flag=false;
             }
     }
     if(curclus>k)
     if(cluster[n1] != cluster[n2])
     {
         int cluster_n2=cluster[n2];
         for(int i=1; i<=n; i++) 
            if(cluster[i]==cluster_n2)
                cluster[i]=cluster[n1];
                
         curclus--;
         if(curclus==k)
            flag=true;
     }
     clustring(T->right, cluster);
     }
}
int main()
{
    ifstream infile; 
	infile.open("Clustring1.txt");
	infile>>n;

    int cluster[n+1];
    for(int i=0; i<=n; i++) 
        cluster[i]=i;
    
    int n1,n2,cost;
    node *T=new node;
    infile>>n1>>n2>>cost;
    
    T->n1=n1;
    T->n2=n2;
    T->cost=cost;
    T->left=NULL;
    T->right=NULL;
    
    while(!infile.eof())
    {
            infile>>n1>>n2>>cost;
            node *nn=new node;
            nn->n1=n1;
            nn->n2=n2;
            nn->cost=cost;
            nn->left=NULL;
            nn->right=NULL;
            
            node *temp = T,*t2;
            while(temp!=NULL)
            {
                   t2=temp;
                   if(nn->cost > temp->cost)
                    temp=temp->right;
                   else
                    temp=temp->left;
            }
            if(nn->cost>t2->cost)
                t2->right=nn;
            else
                t2->left=nn;
    }
    clustring(T, cluster);
    delete T;
    cout<<"maxspace  "<<maxSpace<<endl;
    
    return 0;
}
