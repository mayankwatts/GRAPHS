#include <iostream>
#include<climits>
using namespace std;


int main()
{
  int v, e;
  cin >> v >> e;
    
    bool* visited=new bool[v];
    int* distance = new int[v];
    distance[0]=0;
    for(int i=1;i<v;i++){
        distance[i]=INT_MAX;
    }
    
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
    
    int s,d,w;
    
    for(int i=0;i<e;i++){
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }
    int i=0;
    int size=v-1;
    while(size>=0){
        for(int j=0;j<v;j++){
            if(edges[i][j]!=0 && visited[j]==false){
                if(distance[j]>distance[i]+edges[i][j]){
                    distance[j]=distance[i]+edges[i][j];
                } 
            }
        }
        int minvertex=-1;
        for(int k=0;k<v;k++){
            if(visited[k]==false &&(minvertex==-1 || distance[k]<distance[minvertex])){
                minvertex=k;
            }
        }
        i=minvertex;
        visited[minvertex]=true;
        size--;
    }
    
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

  return 0;
}
