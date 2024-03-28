#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
set<string> file[200];
// 把读入的字符都转化为小写 
void lowerCase(string& s){
	for(int i = 0; i < s.length();i++){
		if(s[i] >= 'A' && s[i] <= 'Z' ) s[i] += 32;
	}
}
// 读入字符串 并存入到set种 
void read_file(int index){
	int k;//记录读入了多少个字符 
	char c = getchar();
	string s;
	while(c!='#'){
		s.clear();
		k = 0;
		while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			if(k<10){
				s += c;
				k++; 
			}
			c = getchar(); 
		}
		if(s.length() > 0 && k >= 3){
			lowerCase(s);
			file[index].insert(s);			
		}
		c = getchar();
	}
}
// 计算重复率并输出 
void countRepeat(int n1, int n2){
	set<string> temp;
	for(set<string>::iterator it = file[n1].begin(); it != file[n1].end(); ++it){
		temp.insert(*it);
	}
	for(set<string>::iterator it = file[n2].begin(); it != file[n2].end(); ++it){
		temp.insert(*it);
	}
	int sum = file[n1].size() + file[n2].size();
	double rate = 1.0 * (sum - temp.size()) / temp.size();
	printf("%.1lf%%\n", rate * 100);
}
int main(){
	int n, m, i, n1, n2;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		read_file(i);
	}
	scanf("%d",&m);
	for(i = 0; i < m; i++){
		scanf("%d %d", &n1, &n2);
		countRepeat(n1 - 1, n2 - 1);
	}
	return 0;
}

