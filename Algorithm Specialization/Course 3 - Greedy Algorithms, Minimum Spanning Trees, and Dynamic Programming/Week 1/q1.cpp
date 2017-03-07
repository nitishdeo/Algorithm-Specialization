#include <bits/stdc++.h>
using namespace std;

struct task{
	int w;
	int l;
	int diff;
	//float diff;        float for diff as ratio
	int ct;
};

long int greedy(struct task job[],int jobs)
{
	int i,j,k,ct=0;
	long int total=0;
	struct task t;
	for( i=0 ; i<jobs-1 ; i++)
	{
		for( j=i+1 ; j<jobs ;j++ )
		{
			if( job[j].diff > job[k].diff )
				k=j;
			else
			if( (job[j].diff==job[k].diff) && (job[j].w>job[k].w) )
				k=j;
			else
			    k=i;
			    
			    
		}
		
		t.w=job[i].w;
		t.l=job[i].l;
		t.diff=job[i].diff;
		
		job[i].w=job[k].w;
		job[i].l=job[k].l;
		job[i].diff=job[k].diff;
		
		job[k].w=t.w;
		job[k].l=t.l;
		job[k].diff=t.diff;
	}
	for( i=0; i<jobs; i++)
	{
		ct = ct+job[i].l;
		job[i].ct=ct;
		total+=job[i].w*job[i].ct;
	}
	return total;
}
int main()
{
    int jobs;
    ifstream infile; 
	infile.open("jobs.txt");
	infile>>jobs;
    //cout<<jobs<<endl;
	
	struct task job[jobs];
	
	for(int i=0;i<jobs;i++)
	{
	    infile>>job[i].w;
	    infile>>job[i].l;
	    
	    job[i].diff=job[i].w-job[i].l;  
	    // job[i].diff = (job[i].w/job[i].l)
	    job[i].ct=0;
	}cout<<"a ";
	cout<<greedy(job,jobs);
	return 0;
}