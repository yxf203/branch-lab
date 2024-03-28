#include<bits/stdc++.h>
using namespace std;
int visited[200], n, m, arcs[200][200];
queue<int> q;
int bfs(int index){
	int count = 1, i, t;
	while(!q.empty()){
		t = q.front();
		q.pop();
		for(i = 1; i <= n; i++){
			if(arcs[t][i] && !visited[i]){
				visited[i] = 1;
				q.push(i);
				count++;
			}
		}
	}
	return count;
}
int main(){
	int u, v, count = 0, depth[200];
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		arcs[u][v] = 1;
		arcs[v][u] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]) {
			q.push(i);
			visited[i] = 1;
			int num = bfs(i);
			if(num >= 2){
				depth[count] = num;
				count++;	
			}
		}
	}
	cout<<count<<endl;
	sort(depth, depth+count);
	for(int i = 0; i < count; i++){
		cout<<depth[i]<<" ";
	}
	cout<<endl;
	return 0;
}

