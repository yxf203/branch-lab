#include<bits/stdc++.h>
using namespace std;
struct bestTNode{
	int id,weight,parent,lchild,rchild;
	string path;
};
bestTNode t[100];
int checkT(int num){
	int sum = 0;
	for(int i = 1; i < num; i++){
		if(t[i].parent == 0) sum++;
	}
	if(sum == 1) return 0;
	else return 1;
}
int computeSum(int n,string s){
	string s1,s2;
	s1 = s;
	s2 = s;
	if(t[n].lchild == 0 && t[n].rchild == 0){
		t[n].path = s;
		return t[n].weight * s.length();
	} else {
		return computeSum(t[n].lchild,s1.append("0")) + computeSum(t[n].rchild,s2.append("1"));
	}
}
int main(){
	string s;
	int tong[26] = {0},k = 1,num;
	getline(cin,s);
	for(int i = 0; i < s.length();i++){
		if(s[i] >= 'a' && s[i] <= 'z') tong[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(tong[i]) {
			t[k].weight = tong[i];
			t[k].id = i;
			t[k].lchild = 0;
			t[k].rchild = 0;
			t[k].parent = 0;
			k++;
		}
	}
	num = k;
	while(checkT(num)){
		int s1,s2,min = 0xffffff;
		for(int i = 1; i < num; i++){
			if(t[i].weight < min && t[i].parent == 0){
				s1 = i;
				min = t[i].weight;
			} 
		}
		t[s1].parent = num;
		min = 0xffffff;
		for(int i = 1; i < num; i++){
			if(t[i].weight < min && t[i].parent == 0){
				s2 = i;
				min = t[i].weight;
			} 
		}
		t[s2].parent = num;
		t[num].lchild = s1;
		t[num].rchild = s2;
		t[num].weight = t[s1].weight + t[s2].weight;
		t[num].parent = 0;
		num++;	
	}
	int sum = computeSum(num - 1, "");
	for(int i = 1; i < k; i++){
		cout<<char(t[i].id + 'a')<<"("<<t[i].weight<<")"<<t[i].path<<endl;
	}
	cout<<sum<<endl;
	return 0;
}

