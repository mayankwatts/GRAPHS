#include <iostream>
#include<queue>
using namespace std;

void connected(int** edges,int v,int sv,bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(x==i){
                continue;
            }
            if(edges[x][i]==1 && visited[i]==false){
                    q.push(i);
                    visited[i]=true;
            }
        }
    }
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
    
    bool* visited =new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    connected(edges,v,sv,visited);
    
    bool ans=true;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            ans=false;
        }
    }
    
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
