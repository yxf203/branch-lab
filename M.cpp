#include<bits/stdc++.h>
using namespace std;
int vexn, arcn, arcs[100][100] = {0},visited[100] = {0};
char vex[100];
void dfs(int index){
	visited[index] = 1;
	cout<<vex[index]; 
	for(int i = 0; i < vexn; i++){
		if(!visited[i] && arcs[index][i]) dfs(i);
	}
}
int main(){
	int graphType, u, v, w, firstIndex;
	char firstvex;
	cin>>graphType>>vexn>>arcn;
	for(int i = 0; i < vexn; i++){
		char ch;
		cin>>ch;
		if(ch == ' ') i--;
		else vex[i] = ch;
	}
	for(int i = 0; i < arcn; i++){
		fflush(stdin);
		char ch = getchar();
		w = 1;
		for(int j = 0; j < vexn; j++){
			if(ch == vex[j]) {
				u = j;
				break; 
			}
		}
		getchar();
		ch = getchar();
		for(int j = 0; j < vexn; j++){
			if(ch == vex[j]) {
				v = j;
				break; 
			}
		}
		if(graphType == 1 || graphType == 3) cin>>w;
		arcs[u][v] = w;
		if(graphType == 2 || graphType == 3) arcs[v][u] = w;
	}
	cin>>firstvex;
	for(int j = 0; j < vexn; j++){
		if(firstvex == vex[j]) {
			firstIndex = j;
			break; 
		}
	}
//	for(int i = 0; i < vexn; i++){
//		for(int j = 0; j < vexn; j++){
//			cout<<arcs[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	dfs(firstIndex);
	for(int i = 0; i < vexn; i++){
		if(!visited[i]) dfs(i);	
	}
	return 0;
}

