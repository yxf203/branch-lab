#include<bits/stdc++.h>
using namespace std;
map<char, int> m;
int arcs[200][200], visited[200],vexn, arcn;
char vex[200];
int read_int(){
	char c = getchar();
	int x = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
char read_char_in_charset() {
	char c = getchar();
	while(c < 'A' || c > 'Z') c = getchar();
	return c;
}
void dfs(int index){
	visited[index] = 1;
	cout<<vex[index];
	for(int i = 0; i < vexn; i++){
		if(arcs[index][i] && !visited[i]){
			dfs(i);
		}
	}
}
int main(){
	int n, w, firstchar;
	char u,v;
	scanf("%d %d %d",&n,&vexn,&arcn);
	for(int i = 0; i < vexn; i++){
		char ch = read_char_in_charset();
		m.insert(pair<char, int>(ch, i));
		vex[i] = ch;
	}
	for(int i = 0; i < arcn; i++){
		u = read_char_in_charset();
		v = read_char_in_charset();
		if(n == 1 || n == 3) w = read_int();
		arcs[m[u]][m[v]] = 1;
		if(n == 2 || n == 3) arcs[m[v]][m[u]] = 1; 
	}
	firstchar = read_char_in_charset();
	dfs(m[firstchar]);
	for(int i = 0; i < vexn; i++){
		if(!visited[i]) dfs(i);
	}
	return 0;
}

