#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

int solve(char Graph[][MAXN],int i, int j,bool** visited,string s,int N,int M){
    if(s[0]=='\0'){
        return 1;
    }
    int a=0;
    
    if(i-1>=0 && j-1>=0 && visited[i-1][j-1]==false && Graph[i-1][j-1]==s[0]){
        visited[i-1][j-1]=true;
        a=solve(Graph,i-1,j-1,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i-1][j-1]=false;
        }
    }
    
    if(i-1>=0 && visited[i-1][j]==false && Graph[i-1][j]==s[0]){
        visited[i-1][j]=true;
        a=solve(Graph,i-1,j,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i-1][j]=false;
        }
    }
    
    if(i-1>=0 && j+1<M && visited[i-1][j+1]==false && Graph[i-1][j+1]==s[0]){
        visited[i-1][j+1]=true;
        a=solve(Graph,i-1,j+1,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i-1][j+1]=false;
        }
    }
    
    if(j+1<M && visited[i][j+1]==false && Graph[i][j+1]==s[0]){
        visited[i][j+1]=true;
        a=solve(Graph,i,j+1,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i][j+1]=false;
        }
    }
    
    if(i+1<N && j+1<M && visited[i+1][j+1]==false && Graph[i+1][j+1]==s[0]){
        visited[i+1][j+1]=true;
        a=solve(Graph,i+1,j+1,visited,s.substr(1),N,M);
        
        if(a==1){
            return a;
        }
        else{
            visited[i+1][j+1]=false;
        }
    }
    
    if(i+1<N && visited[i+1][j]==false && Graph[i+1][j]==s[0]){
        visited[i+1][j]=true;
        a=solve(Graph,i+1,j,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i+1][j]=false;
        }
    }
    
    if(i+1<N && j-1>=0 && visited[i+1][j-1]==false && Graph[i+1][j-1]==s[0]){
        visited[i+1][j-1]=true;
        a=solve(Graph,i+1,j-1,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i+1][j-1]=false;
        }
    }
    
    if(j-1>=0 && visited[i][j-1]==false && Graph[i][j-1]==s[0]){
        visited[i][j-1]=true;
        a=solve(Graph,i,j-1,visited,s.substr(1),N,M);
        if(a==1){
            return a;
        }
        else{
            visited[i][j-1]=false;
        }
    }
    
    return a;
}

int solve(char Graph[][MAXN],int N, int M){

    string s="CODINGNINJA";
    
    bool** visited=new bool*[N];
    for(int i=0;i<N;i++){
        visited[i]=new bool[M];
        for(int j=0;j<M;j++){
            visited[i][j]=false;
        }
    }
    
    int a=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Graph[i][j]==s[0]){
                visited[i][j]=true;
                a=solve(Graph,i,j,visited,s.substr(1),N,M);
                if(a==1){
                    return a;
                }
                else{
                    visited[i][j]=false;
                }  
            }
        }
    }
    
    return a;  
}

int main(){

	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
  
  return 0;
}
