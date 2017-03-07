#include <boost/config.hpp>
#include <bits/stdc++.h>
#include <boost/graph/strong_components.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/foreach.hpp>

using namespace std;

const int nb_vars = 100000;

int var_to_node(int var)
{
    if(var < 0)
        return (-var + nb_vars);
    else
        return var;
}

int main(int argc, char ** argv)
{
    ifstream infile; 
	infile.open("2sat1.txt");
	int num,a,b;
	infile>>num;
	
    vector< pair<int, int> > pairs;
    for( int i=0 ; i<num ; i++)
    {
        infile>>a>>b;
        pairs.push_back( pair<int, int>(a,b) );
    }

    boost::adjacency_list<> g(nb_vars * 2);
    pair<int,int> c;
    BOOST_FOREACH( c, pairs)
    {
        int v1 = c.first;
        int v2 = c.second;
        boost::add_edge(
                var_to_node(-v1),
                var_to_node(v2),
                g);

        boost::add_edge(
                var_to_node(-v2),
                var_to_node(v1),
                g);
    }

    vector<int> component(nb_vars * 2);
    cout << strong_components(g, &component[0]) << endl;

    bool satisfied = true;
    for(int i=0; i<nb_vars; i++)
    {
        if(component[i] == component[i+nb_vars])
            satisfied = false;
    }
    if(satisfied)
        cout << "Satisfied!" << endl;
    else
        cout<<"Not Satisfied"<<endl;
}