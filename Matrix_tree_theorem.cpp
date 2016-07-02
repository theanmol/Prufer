#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nodes,edges,x,y,d=0;
vector<int>a;
int mmat[11][11],tmat[11][11],final[11][11],finalx[10][10];


int det(int n, int mat[10][10])
{

    int c, subi, i, j, subj;

    int submat[10][10];  

    if (n == 2) 
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }

    else

    {  
        for(c = 0; c < n; c++)
        {  
            subi = 0;  
            for(i = 1; i < n; i++)
            {  
                subj = 0;
                for(j = 0; j < n; j++)
                {    
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }

        d = d + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
        }
    }
    return d;
}




int main()
{
	cout<<"Enter number of nodes"<<endl;
	cin>>nodes;
	edges=nodes-1;
	
	cout<<"Enter number of edges"<<endl;
    cin>>edges;
	
	if(edges!=nodes-1)
	{
		cout<<" Resulting Matrix won't be a square matrix... so determinant is 0";
		return 0;
	}
	
	for(int i=1;i<edges+1;i++)
	{
	//	cout<<"i--> "<<i<<endl;
		cin>>x>>y;
		mmat[x][i]=-1;
		mmat[y][i]=1;
	}
	
	cout<<endl<<"------REDUCED INCIDENCE MATRIX------"<<endl<<endl;
	for(int i=1;i<nodes;i++)
	{
		for(int j=1;j<nodes;j++)
		{
			cout<<mmat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	for(int i=1;i<nodes;i++)
	{
		for(int j=1;j<nodes;j++)
		{
			tmat[i][j]=mmat[j][i];
		}
		//cout<<endl;
	}

cout<<endl<<"------TRANSPOSED REDUCED INCIDENCE MATRIX------"<<endl<<endl;
	for(int i=1;i<nodes;i++)
	{
		for(int j=1;j<nodes;j++)
		{
			cout<<tmat[i][j]<<" ";
		}
		cout<<endl;
	}
	

    for(int i=1;i<nodes;i++)
    {
    	for(int j=1;j<nodes;j++)
    	{
    		final[i][j]=0;
    		
    		for(int k=1;k<nodes;k++)
    		{
    			final[i][j]=final[i][j] + mmat[i][k]*tmat[k][j];
			}
		}
	}
	
	
	cout<<"---------FINAL MULTIPLIED MATRIX---------"<<endl<<endl;
	 	for(int i=1;i<nodes;i++)
	{
		for(int j=1;j<nodes;j++)
		{
		  finalx[i-1][j-1]=final[i][j];
		}
		//cout<<endl;
	}
	
	//cout<<endl;
	 	for(int i=0;i<nodes-1;i++)
	{
		for(int j=0;j<nodes-1;j++)
		{
		  cout<<finalx[i][j]<<" ";
		}
		cout<<endl;
	}

	int ans=det(nodes-1,finalx);
	cout<<endl<<"Determinant of Multiplied Matrix---->"<<ans<<endl<<endl;
	if(ans==1)
	{
		cout<<"Since determinant is 1, so MATRIX TREE THEOREM holds true for tree"<<endl;
	}
	
	
}











