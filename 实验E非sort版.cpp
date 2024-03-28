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
// 比较函数 
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
// 二分查找要插入的数字在前面序列中的位置 
int binarySearch(struct student s[], int n, struct student key){
	int l = 0, r = n - 1, m;
	while(l <= r){
		m = (l + r) / 2;
		if(cmp(s[m], key)) l = m + 1;
		else r = m - 1;
	}
	return l;
}
// 插入排序 
void binarySort(struct student s[], int n){
	for(int i = 1; i < n; i++){
		int index = binarySearch(s, i, s[i]);
		struct student t = s[i];
		for(int j = i - 1; j >= index; j--){
			s[j + 1] = s[j];
		}
		s[index] = t; 
	}
}
int main(){
	int n, i;
	struct student s[100010];
	cin>>n>>c;
	for(i = 0; i < n; i++){
		cin>>s[i].id>>s[i].name>>s[i].score;
	}
	binarySort(s, n);
	for(i = 0; i < n; i++){
		cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	return 0;
}

