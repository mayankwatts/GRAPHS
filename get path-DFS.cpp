#include <iostream>
#include<vector>
using namespace std;

vector<int> vec;

bool getPath(int** edges,int v,int a,int b,bool* visited){
    
    if(a==b){
        vec.push_back(a);
        visited[a]=true;
        return true;
    }
    
    visited[a]=true;
    for(int i=0;i<v;i++){
        if(a==i){
            continue;
        }
        if(edges[a][i]==1 && visited[i]==false){
            bool ans=getPath(edges,v,i,b,visited);
            if(ans){
                vec.push_back(a);
                return ans;
            }
        }
    }
    
    return false;  
}

int main()
{
  int v, e;
  cin >> v >> e;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    
    int** edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    
    int sv;
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
        if(i==0){
            sv=f;
        }
    }
    
    int a,b;
    cin>>a>>b;
    
    bool* visited =new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    
    bool ans=getPath(edges,v,a,b,visited);
    
    if(ans){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
    
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete [] edges;

  return 0;
}
