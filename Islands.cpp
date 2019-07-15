#include<iostream>
#include<vector>
using namespace std;

void helper(int** edges,int sv,int n,bool* visited){
    visited[sv]=true;
    for(int i=1;i<=n;i++){
        if(sv==i){
            continue;
        }
        if(edges[sv][i]==1 && visited[i]==false){
            helper(edges,i,n,visited);
        }
    }
}

int solve(int n,int m,vector<int>u,vector<int>v){
	
    int** edges = new int*[n];
    for(int i=1;i<=n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    
    bool* visited=new bool[n];
    
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            helper(edges,i,n,visited);
            count++;
        }
    }
    
    return count;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
  
  return 0;
}
