#include<bits/stdc++.h>
using namespace std;
#define NMAX 55

int solve(int n,char cake[NMAX][NMAX],bool** visited,int i,int j){
    int a=1;
    if(i-1>=0 && visited[i-1][j]==false && cake[i-1][j]=='1'){
        visited[i-1][j]=true;
        a+=solve(n,cake,visited,i-1,j);
    }
    if(i+1<n && visited[i+1][j]==false && cake[i+1][j]=='1'){
        visited[i+1][j]=true;
        a+=solve(n,cake,visited,i+1,j);
    }
    if(j-1>=0 && visited[i][j-1]==false && cake[i][j-1]=='1'){
        visited[i][j-1]=true;
        a+=solve(n,cake,visited,i,j-1);
    }
    if(j+1<n && visited[i][j+1]==false && cake[i][j+1]=='1'){
        visited[i][j+1]=true;
        a+=solve(n,cake,visited,i,j+1);
    }
    
    return a;
    
}

int solve(int n,char cake[NMAX][NMAX])
{
    int max=INT_MIN;
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]=='1'){
                visited[i][j]=true;
                int a=solve(n,cake,visited,i,j);
                if(max<a){
                    max=a;
                }
                visited[i][j]=false;
            }
        }
    }
    
    return max;
}

char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
  
  return 0;
}
