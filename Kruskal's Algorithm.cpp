#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    
    int sor;
    int des;
    int wet;
};

bool compare(edge e1,edge e2){
    return e1.wet<e2.wet;
}

int main()
{
  int v, e ;
  cin >> v >> e;
    
    edge* input = new edge[e];
    edge* output = new edge[v-1];

    int s,d,w;
    
    for(int i=0;i<e;i++){
        
        cin>>s>>d>>w;
        input[i].sor=s;
        input[i].des=d;
        input[i].wet=w; 
    }
    
    sort(input,input+e,compare);
    
    int* parent = new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    
    int count=0;
    int i=0;
    
    while(count<v-1){
        s=input[i].sor;
        d=input[i].des;
        w=input[i].wet;
        
        while(s!=parent[s] || d!=parent[d]){
            if(s!=parent[s]){
                s=parent[s];
            }
            if(d!=parent[d]){
                d=parent[d];
            }
        }
        
        if(s!=d){
            output[count]=input[i];
            count++;
            parent[s]=d;
        }
        i++;
        
    }
    
    for(int i=0;i<v-1;i++){
        cout<<min(output[i].sor,output[i].des)<<" ";
        cout<<max(output[i].sor,output[i].des)<<" ";
        cout<<output[i].wet<<endl;
    }
    

  return 0;
}
