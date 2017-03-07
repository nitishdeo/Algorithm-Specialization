#include<iostream>
#include<unordered_set>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("2Sum.txt");
	unordered_set<long long int> st;
	for(int i = 1; i <= 1000000; ++i)
	{
		long long int x;
		in>>x;
		//cout<<x;
		st.insert(x);
	}	
	long long int cnt = 0;
	for(long long int i = -10000; i<=10000; ++i)
	{
		for(long long int val : st)
		{
			//cout<<i - val;
			if(st.find(i - val) != st.end())
			{
				++cnt;
				break;
			}	
		}
	}
	cout<<cnt;
}