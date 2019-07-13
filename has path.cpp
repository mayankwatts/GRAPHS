#include <iostream>
using namespace std;

bool hasPath(int** edges,int v,int a,int b,bool* visited){
    if(edges[a][b]==1 && visited[a]==false){
        return true;
    }
    
    visited[a]=true;
    bool ans=false;
    for(int i=0;i<v;i++){
        if(a==i){
            continue;
        }
        if(edges[a][i]==1 && visited[i]==false){
           ans=ans||hasPath(edges,v,i,b,visited);
        }
    }
    
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    
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
    
    bool ans=hasPath(edges,v,a,b,visited);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete [] edges;

  return 0;
}
