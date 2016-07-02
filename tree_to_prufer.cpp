
//To produce prufer sequence from Randomly Generated Graph , 
//Max nodes allowed in graph is 10 to provide better visualisation of Gui 
//Graph can be of any type because it is randomly generated.
/*For Graphical representation of graph we have used graphic library of c++ 
	for running this code -lgraph library should be installed .
	for window turbo c++ : inbuilt    
*/

/*  
	For linux user : 1) download folder : http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
			 2)First install build-essential by typing $sudo apt-get install build-essential
			 3)Intall some additional packages by typing 
				sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 \
  				guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev \
  				libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev \
  				libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \
  				libslang2-dev libasound2 libasound2-dev
			 4)Now extract the downloaded libgraph-1.0.2.tar.gz file
			 5)Goto extracted folder and run following command
				./configure
					make
					sudo make install
					sudo cp /usr/local/lib/libgraph.* /usr/lib
			 6)Now you can use #include<graphics.h> on ubuntu platform.


			 7)To compile : g++ testdraw2.cpp -lgraph 
			 8)To run : ./a.out 



*/

//Major functions used in this graph are - (1) draww (2)dfs (3)isconnected (4)mer (5)Treetoprufer 
//Author : << Abhishek Kumar singh : Akash Bansal :>>


#include<bits/stdc++.h>
#include<iostream>
#include<graphics.h>

using namespace std;
typedef long long ll;
vector<int>adj[105];
bool visited[105];
int nodes,edges,x,y,val[105],i,j,k,a,b,c,co=0,a1,a2,a3,par[105],g,h;
int comp=0;
int con=0;
int cyc=0;
int gd=DETECT ,gm;
int cyclebreak=0;
int selfloop=0;

//This is a draw function which
//is used to draw the graph
//it take two nodes and total nodes of graph as arguments

void draww(int a,int b,int nodes)
{


for(int i=1,g=0,h=250;i<=nodes;i++,g+=50)
{
switch(i)
{
case 1:outtextxy(g,h,"1");
break;
case 2:
outtextxy(g,h,"2");circle(abs(g+3),abs(h+2),10);
break;
case 3:outtextxy(g,h,"3");

circle(abs(g+3),abs(h+2),10);
break;
case 4:outtextxy(g,h,"4");circle(abs(g+3),abs(h+2),10);
break;
case 5:outtextxy(g,h,"5");circle(abs(g+3),abs(h+2),10);
break;
case 6:outtextxy(g,h,"6");circle(abs(g+3),abs(h+2),10);
break;
case 7:outtextxy(g,h,"7");circle(abs(g+3),abs(h+2),10);
break;
case 8:outtextxy(g,h,"8");circle(abs(g+3),abs(h+2),10);
break;
case 9:outtextxy(g,h,"9");circle(abs(g+3),abs(h+2),10);
break;
case 10:outtextxy(g,h,"10");circle(abs(g+3),abs(h+2),10);
break;
}
}
int ground=50;
int h=250;
int xc1=0;
for(int q=0;q<a;q++)
xc1=xc1+ground;
xc1=xc1-50;
if(xc1<0)
xc1=0;
int yc1=h;
int xc2=0;
for(int q=0;q<b;q++)
xc2=xc2+ground;
xc2=xc2-50;
if(xc2<0)
xc2=0;
int yc2=h;
int radius=abs(xc2-xc1);
radius=radius/2;
int radiuss;
if(xc1<xc2) radiuss=xc1+radius;
else if(xc1>xc2)
radiuss=xc2+radius;
setcolor(a);
arc(radiuss,yc1,0,180,radius);
if(cyc==1)
{
setcolor(a+1);
arc(radiuss,yc1,180,0,radius);
}
if(selfloop==1)
{
setcolor(a+1);
circle(xc1,yc1,20);
}
delay(2000);

}

//This function is used to find root node of each node
//It take node as argument and return parent of it .

int root(int a3)
{
if(par[a3]<0)
return a3;
else
par[a3]=root(par[a3]);
return par[a3];
}

//This funtion is used to merge two nodes ;
int mer(int a1,int a2)
{
if((a1=root(a1))==(a2=root(a2)))
return 1;
if(par[a2]<par[a1])
swap(a1,a2);
par[a1]+=par[a2];
par[a2]=a1;
return 0;
}

void dfs(int v)
{
visited[v]=true;
for(int j=0;j<adj[v].size();j++)
{
if(visited[adj[v][j]]==false)
dfs(adj[v][j]);

}//end of adj[j].size()

}//end of dfs function

//This is used to check connectivity of graph
int isconnectedcomponents(int nodes,int edges)
{
comp=0;
for(int i=1;i<nodes+1;i++)
visited[i]=false;

for(int i=1;i<nodes+1;i++)
{
if(visited[i]==false)
{
dfs(i);
cout<<"comp"<<comp<<endl;
comp++;
}
return comp;
}
//cout << "the connected components are " << comp<< endl;
//return comp;
}//end of connected function


//This is hive of code , it prints prufer sequence of graph
void Treetoprufer(int nodes,int edges)
{

for(int i=1;i<nodes+1;i++)
{
//cout<<i<<endl;
val[i]=0;
//cout<<"yo"<<endl;
}
for(int i=0;i<edges;i++)
{
x=rand()%nodes+1;
y=rand()%nodes+1;

cout << x << " -->" << y <<endl;
draww(x,y,nodes);
if(x==y)
{

outtextxy(10,50,"It is containing  self loop ");

cout << "prufer sequence is not possible because it is containing self loop at  : "<<  i  <<  "iteration " << endl;
selfloop=1;
break;
}
cout<< endl;
adj[x].push_back(y);
adj[y].push_back(x);
cyc=mer(x,y);

cout<<"cycle-->"<<cyc<<endl;
if(cyc==1)
{
outtextxy(10,50,"this is cycle");




cout<<"This is cycle"<<endl;
cyclebreak=1;

break;
}
val[x]++;
val[y]++;

}
//cout<<"self"<<selfloop<<" "<<"cycbreak"<<cyclebreak;
if(selfloop==0 && cyclebreak==0)
{
comp=isconnectedcomponents(nodes,edges);
if(comp==1)
{

for(int j=1;j<nodes+1;j++)
{
for(int k=1;k<nodes+1;k++)
{
if(val[k]==1)
{

if(j==1)
a=adj[k][0];

else
{
for(int i=0;i<adj[k].size();i++)
{
if(adj[k][i]!=-1)
a=adj[k][i];
}
}


for(int i=1;i<nodes+1;i++)
{
	if(val[i]==1)
	co++;
}

cout<<a<<" ";


val[k]=10001;
val[a]--;
for(int i=0;i<adj[a].size();i++)
{
if(adj[a][i]==k)
adj[a][i]=-1;
}

}
}
}
cout<<endl;
}//end of isconnected components
else
{
outtextxy(10,50,"disconnected components");

cout << "disconnected components"<<endl;
}
} //end of checking self loop

draww(x,y,nodes);
}

int randnodes()
{
srand(time(NULL));
return rand()%10+1; //limit to 100

}
/*
int randedges()
{
return rand()%10 ; //limit to 100

}
*/
int main()
{
int nodes=randnodes();
for(int i=1;i<nodes+1;i++)
par[i]=-1;
//int randomedges=randedges();
edges=nodes-1;

initgraph(&gd,&gm," ");
setbkcolor(12);
cout << "Nodes-->"<<nodes <<  endl;
cout  <<"Edges-->"<<edges << endl;
if(nodes>1)
{
//cout<<nodes<<endl;
Treetoprufer(nodes,edges);
}
else
{

outtextxy(10,50,"The randomly generated nodes have value 0 so edges will be -1 so no graph is possible");

cout <<"The randomly generated nodes have value 0 so edges will be -1 so no graph is possible" << endl;
}
delay(4000);
}

