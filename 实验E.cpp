#include <cstdio>
#include <iostream> 
#include <algorithm>
using namespace std;
int c; 
// 学生结构体 
struct student{
	string id;
	string name;
	int score;
};
int cmp(struct student s1, struct student s2){
	if(c == 1){
		if(s1.id < s2.id) return 1;
	} else if(c == 2){
		if(s1.name < s2.name) return 1;
		else if(s1.name == s2.name){
			if(s1.id < s2.id) return 1;
		} 
	} else if (c == 3){
		if(s1.score < s2.score) return 1;
		else if(s1.score == s2.score){
			if(s1.id < s2.id) return 1;
		}
	}
	return 0;
}
int main(){
	int n, i;
	struct student s[100010];
	cin>>n>>c;
	for(i = 0; i < n; i++){
		cin>>s[i].id>>s[i].name>>s[i].score;
	}
	sort(s, s+n, cmp);
	for(i = 0; i < n; i++){
		cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	return 0;
}

