#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

unordered_map<int,int> map;

bool getPath(int** edges,int v,int a,int b,bool* visited){
    
    queue<int> q;
    q.push(a);
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        visited[front]=true;
        for(int i=0;i<v;i++){
            if(i==front){
                continue;
            }
            if(edges[front][i]==1 && visited[i]==false){
                q.push(i);
                //visited[i]=true;
                map[i]=front;
                if(i==b){
                    return true;
                }
            }
            
        }
    }
    
    return false;
    
}

int main()
{
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
    
    
    bool ans=getPath(edges,v,a,b,visited);
    
    if(ans){
        int i=b;
        while(i!=a){
            cout<<i<<" ";
            int x=i;
            i=map[x];
        }
        cout<<a;
    }
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete [] edges;

  return 0;
}
