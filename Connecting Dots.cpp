#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int solve(char board[][MAXN],int n,int m,bool** visited,int i,int j,int k,int ri,int rj){
    if(i-1>=0 && k==0 && i-1==ri && j==rj){
        return 1;
    }
    if(j+1<m && k==0 && i==ri && j+1==rj){
        return 1;
    }
    if(i+1<n && k==0 && i+1==ri && j==rj){
        return 1;
    }
    if(j-1>=0 && k==0 && i==ri && j-1==rj){
        return 1;
    }
    
    
    int a=0;
    if(i-1>=0 && visited[i-1][j]==false && board[i-1][j]==board[i][j]){
        visited[i-1][j]=true;
        int p=k;
        if(p!=0){
            p--;
        }
        a=solve(board,n,m,visited,i-1,j,p,ri,rj);
        if(a==1){
            return a;
        }
        visited[i-1][j]=false;
    }
    if(j+1<m && visited[i][j+1]==false && board[i][j+1]==board[i][j]){
        visited[i][j+1]=true;
        int p=k;
        if(p!=0){
            p--;
        }
        a=solve(board,n,m,visited,i,j+1,p,ri,rj);
        if(a==1){
            return a;
        }
        visited[i][j+1]=false;
    }
    if(i+1<n && visited[i+1][j]==false && board[i+1][j]==board[i][j]){
        visited[i+1][j]=true;
        int p=k;
        if(p!=0){
            p--;
        }
        a=solve(board,n,m,visited,i+1,j,p,ri,rj);
        if(a==1){
            return a;
        }
        visited[i+1][j]=false;
    }
    if(j-1>=0 && visited[i][j-1]==false && board[i][j-1]==board[i][j]){
        visited[i][j-1]=true;
        int p=k;
        if(p!=0){
            p--;
        }
        a=solve(board,n,m,visited,i,j-1,k,ri,rj);
        if(a==1){
            return a;
        }
        visited[i][j-1]=false;
        
    }
    return a;
}


int solve(char board[][MAXN],int n, int m){
    int a=0;
    
     bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    int k=3;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=true;
            a=solve(board,n,m,visited,i,j,k,i,j);
            if(a==1){
                return a;
            }
            visited[i][j]=false;
        }
    } 
    return a;
}

int main(){

	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
  
  return 0;
}
