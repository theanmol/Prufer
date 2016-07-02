#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
	//vector<ll>graph[1000],temp[1000];
		ll nodes,edges,par[1000];
		vector<ll>span,seq,span1;
		static ll numberspan=0;
		
ll root(ll f)
{
//	cout<<f<<" hi";
	if(par[f]<0)
	{
	//cout<<par[f]<<" helo";
	return f;
    }
	else
	par[f]=root(par[f]);
	return par[f];
}
ll merge(ll u,ll v)
{
	//for(ll i=1;i<=nodes;i++)
    //  cout<<par[i]<<" hi"; 
    //cout<<u<<" "<<v<<" ";
	if((u=root(u))==(v=root(v)))
	{
	//cout<<u<<" "<<v<<" ";
	return 1;
   }
	if(par[v]<par[u])
	swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	return 0;
}

bool isconn(vector<ll>graph[])
{
	for(ll i=0;i<1000;i++)
    par[i]=100;

	for(ll i=0;i<edges;i++)
	{
		if(graph[i][0]!=-1)
		{
			par[graph[i][0]]=-1;
			par[graph[i][1]]=-1;
		}
	}


for(ll i=0;i<edges;i++)
{
	if(graph[i][0]!=-1)
	merge(graph[i][0],graph[i][1]);
}

ll co=0;
for(ll i=1;i<=nodes;i++)
{
	if(par[i]<0)
	co++;
}
if(co>1)
return false;
else 
return true;

}




void kruskal(vector<ll>graph[])    //kruskal func
{
	span.clear();
	ll w,u,v,cyc=0;
	 for(ll i=1;i<=nodes;i++)
      par[i]=-1; 
	//cout<<edges<<endl;
	for(ll i=0;i<edges;i++)
	{
	
	w=1;
	if(graph[i][0]!=-1)
	{
	
	u=graph[i][0];
	v=graph[i][1];
   
    //cout<<u<<v<<" "<<endl;
	//	cout<<edges<<endl;
	cyc=merge(u,v);
	//	cout<<cyc<<endl;
	if(cyc==0)
	span.push_back(i);
//	cout<<span[0]<<" ";
    }
	}
}

void kruskal1(vector<ll>graph[])
{
	span1.clear();
	ll w,u,v,cyc=0;
	 for(ll i=1;i<=nodes;i++)
      par[i]=-1; 
	//cout<<edges<<endl;
	for(ll i=0;i<edges;i++)
	{
	
	w=1;
	if(graph[i][0]!=-1)
	{
	
	u=graph[i][0];
	v=graph[i][1];
   
    //cout<<u<<v<<" "<<endl;
	//	cout<<edges<<endl;
	cyc=merge(u,v);
	//	cout<<cyc<<endl;
	if(cyc==0)
	span1.push_back(i);
//	cout<<span[0]<<" ";
    }
	}
}
	

 bool isconn1(vector<ll>graph[],ll numnodes)    // check if graph obtained after deleting an edge is connected or not
{
	kruskal1(graph);                     // use kruskal
	ll i=span1.size();                  // if no. of edges of spanning tree of a graph is equal to nodes-1 
if(i!=numnodes-1)                        // the it is connected othrwise not
return false;
else 
return true;

}
 
 
 void del( vector<ll>graph[],ll a)     // func to delete edges
 {
 	
 	graph[a][0]=-1;
 	graph[a][1]=-1;
 //	cout<<graph[3][0]<<" hello"<<endl;
 
 }
  void del1( vector<ll>graph[],ll a)
 {
 	
 	graph[a][0]=-1;
 	graph[a][1]=-2;
 //	cout<<graph[3][0]<<" hello"<<endl;
 
 }
 
 void shrink(vector<ll>graph[],ll a)            // func to shrink edges
 {
ll x=graph[a][0];
ll y=graph[a][1];
 del(graph,a);
 for(ll i=0;i<edges;i++)
 {
 	if((graph[i][0]==x && graph[i][1]==y) || (graph[i][0]==y && graph[i][1]==x))
 	del(graph,i);                                                                    
 	else if(graph[i][0]==y)
 	graph[i][0]=x;
     else if(graph[i][1]==y)
	 graph[i][1]=x;
 	
 }
 
 	
 }
 void copy2(vector<ll>agraph[],vector<ll>bgraph[])    // This function will copy one graph to another if it is not defined
 {
 	for(ll i=0;i<edges;i++)
 	{
 		ll x=agraph[i][0];
 		ll y=agraph[i][1];
 		bgraph[i].push_back(x);
 		bgraph[i].push_back(y);
		 	}
 }
 void copy(vector<ll>agraph[],vector<ll>bgraph[])       // This function will copy one graph to another if it is already defined
 {
 	for(ll i=0;i<edges;i++)
 	{
 		ll x=agraph[i][0];
 		ll y=agraph[i][1];
 		bgraph[i][0]=x;
 		bgraph[i][1]=y;
		 	}
 }
 void prinsol(vector<ll>graph[])        // This program will print the solution
 {
 	for(ll i=0;i<edges;i++)
 	{
 		
 		ll x=graph[i][0];
 		ll y=graph[i][1];
 		if(x!=-1 && y!=-1)                          // Since the deleted and shrinked edges are -1, so they have been ignored while printing
		 cout<<i<<"  "<<x<<"--->"<<y<<endl; 
	 }
 }
 
 
 void prog(vector<ll> graph[])
{	// cout << "recursion";

	ll seqsize=seq.size();                     
	vector<ll> lgraph[1000];
	vector<ll>tempspan;
	vector<ll>tempseq;
	copy2(graph,lgraph);                           // Copying main graph to temp graph. copy2 is used as lgraph is recently defined graph
	// prinsol( graph);
	 kruskal(lgraph);                              // calling kruskal function to find a spanning tree of temp graph
	 ll num_loop=span.size();

//cout << "recursion after krusk";
//	 for(ll i=0;i<span.size();i++)
//	 cout<<span[i]<<" ";
	 
	 for(ll i=0;i<num_loop;i++)                         // Initial loop that will run according to algorithm..          
	 {
	 	 copy(graph,lgraph);                            // copying graph into lgraph.. copy is used as lgrapg has been already defined
//	 cout << "in loop"<<i<<endl;

ll j;
	 	for( j=1;j<num_loop-i;j++)                   // These are the shrink operations performed on temp graph..
	 	{
	 		shrink(lgraph,span[j]);                   // edge shrinked has been saved in sequence so to print spanning trees at the end
	 //		cout<<"Trees with"<<span[j];
	
			 seq.push_back(span[j]);
		 }
	
		 if(i!=0)
		 {
		 
		 	set<ll>curnodes;                         // using set to find out the nodes left in the graph obtained after shrinking edges
		 	curnodes.clear();
		 for(ll k=0;k<edges;k++)
		 {
		 	if(lgraph[k][0]!=-1)
		 	{
		 		curnodes.insert(lgraph[k][0]);
		 		curnodes.insert(lgraph[k][1]);
			 }
		}
		 del(lgraph,span[j]);                         // delete edges
		 // prinsol(lgraph);
	     
		 if(!isconn1(lgraph,curnodes.size())){       // program call to check if after deleting the edge, the graph becomes disconnected or not
//		 cout << "not connectd"<<endl;
		 continue;                                   // if graph becomes disconnected then, no tree is possible
		}
		
	     }
//	     cout<<"shrink aur delete ke baad"<<endl;
		
		 set<ll>conodes;                       // code to count no. of nodes left after every operation.. i.e. shrink and delete
		 for(ll k=0;k<edges;k++)
		 {
		 	if(lgraph[k][0]!=-1)
		 	{
		 		conodes.insert(lgraph[k][0]);
		 		conodes.insert(lgraph[k][1]);
			 }
		}
			 if(conodes.size()==2)                // if size of nodes is 2, then we will print the sequence obtained with the edges between the nodes
			 {
			 	for(ll k=0;k<edges;k++)
		         {
		         	if(lgraph[k][0]!=-1)
		            	{numberspan++;
		 	         	for(ll i=0;i<seq.size();i++)
		 	         	cout<<seq[i];                        // printing sequence
		 	         	cout<<k <<endl;                    // printing edges between the nodes
			            }
	           	}
	           //	seq.clear();
	           seq.erase(seq.begin()+seqsize,seq.end());          // erasing sequence for recursion purpose
			 copy(graph,lgraph);	                           
			 }
			 else if(conodes.size()>2)                              // if nodes>3. we have to recurse the grapg we obtained
			 {
			 	tempspan=span;
			//cout <<"hello";
			//prinsol(lgraph);
			prog(lgraph); 
//			cout << "back again";
			seq.erase(seq.begin()+seqsize,seq.end());
			span.clear();
			span=tempspan;
				//	prinsol(graph);
							 copy(graph,lgraph);	
//				cout << i << " " << num_loop << endl;
			 }		 	 	
	 }
}
 
 int main()
 {
 vector<ll>graph[1000];

                                            // taking number of nodes and edges and making a vector pair of graph (Adjacency list)
	cout<<"Enter number of nodes and edges"<<endl;
 	cin>>nodes>>edges;
 	
 	cout<<"Enter information about each edge"<<endl;    // Taking two nodes of an edge as input
 	for(ll i=0;i<edges;i++)
 	{
 		ll x,y;
 		cout << "enter src and destination for edge " << i << endl; 
 		cin>>x>>y;
 		
 		graph[i].push_back(x);                          
 		graph[i].push_back(y);
	 }
	 if(!isconn1(graph,nodes) )
	 {
	        cout << "Disconnected graph "<< endl<< "No spanning trees possible" << endl;
	 }
	 else
	 {
	 cout << "spanning tree sequences are" << endl;
	 prog(graph);      // calling function to find spanning tree
	 cout << "number of spanning tree sequences are" << endl; 
	 cout << numberspan << endl;
        }

}


