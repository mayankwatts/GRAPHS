#include <bits/stdc++.h>
using namespace std;


int main()
{
  int v, e;
  cin >> v >> e;
    
    bool* visited=new bool[v];
    
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    visited[0]=true;
    
    int** edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    
    int* parent = new int[v];
    int* weight = new int[v];
    
    for(int i=0;i<v;i++){
        parent[i]=-1;
        weight[i]=INT_MAX;
    }
    
    int s,d,w;
    
    for(int i=0;i<e;i++){
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }
    
    int count=0;
    int i=0;
    int minvertex;
    int minvalue;
    while(count<v-1){
        minvertex=-1;
        minvalue=INT_MAX;
        for(int j=0;j<v;j++){
            if(i==j){
                continue;
            }
            if(edges[i][j]>0 && visited[j]==false){
                if(weight[j]>edges[i][j]){
                    parent[j]=i;
                    weight[j]=edges[i][j];
                } 
            }
        }
        
        for(int i=0;i<v;i++){
            if(weight[i]<minvalue && visited[i]==false){
                minvalue=weight[i];
                minvertex=i;
            } 
        }
        
        cout<<min(parent[minvertex],minvertex)<<" "<<max(parent[minvertex],minvertex)<<" "<<minvalue<<endl;
        count++;
        visited[minvertex]=true;
        i=minvertex;
    }

  return 0;
}
