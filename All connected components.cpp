#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void allcc(int** edges,int v,int sv,vector<int>* ve,bool* visited){
    visited[sv]=true;
    ve->push_back(sv);
   for(int i=0;i<v;i++){
       if(sv==i){
           continue;
       }
       if(edges[sv][i]==1 && visited[i]==false){
           allcc(edges,v,i,ve,visited);
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
    
    vector<vector<int>> vec;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> ve;
            allcc(edges,v,i,&ve,visited); 
            vec.push_back(ve);
        }
    }
    
    for(int i=0;i<vec.size();i++){
        sort(vec[i].begin(),vec[i].end());
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i].at(j)<<" ";
        }
        cout<<endl;
    }
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete [] edges;

  return 0;
}
