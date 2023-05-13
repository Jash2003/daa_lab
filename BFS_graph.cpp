
#include<bits/stdc++.h>
using namespace std;
int mat[100][100];

int main(){
	int n,m;
	cout<<"Enter number of verties and edges: "<<endl;
	cin>>n>>m;
	int t=m;
	while(t--){
		cout<<"Enter connecting edges: "<<endl;
		int u,v;
		cin>>u>>v;
		mat[u][v]=1;
		mat[v][u]=1;
	}
	int q[n],front=0,rear=0;
	//0-indexed graph 
	q[front]=0;
	int vis[n]={0};
	vis[0]=1;
	
	cout<<"BFS traversal of graph is: "<<endl;
	while(front<=rear){
		int node=q[front++];
		cout<<node<<" ";
		for(int i=0;i<n;i++){
			if(mat[node][i]==1 && !vis[i]){
				q[++rear]=i;
				vis[i]=1;
			}
		}
	}
	
	return 142;
}
