#include<bits/stdc++.h>
using namespace std;
string s;
int i = -1;
struct ThrTree{
	char val;
	ThrTree* lchild;
	ThrTree* rchild;
	int ltag,rtag;
}; 
ThrTree* pre = NULL;
ThrTree* createBiTree(){
	ThrTree* t = (ThrTree*)malloc(sizeof(ThrTree));
	i++;
	if(s[i] == '#' || i >= s.length()) return NULL;
	else {
		t->val = s[i];
		t->ltag = 0;
		t->rtag = 0;
		t->lchild = createBiTree();
		t->rchild = createBiTree();
		return t;
	}
}
void createThrTree(ThrTree* T){
	if(T){
		createThrTree(T->lchild);
		if(T->lchild == NULL){
			T->ltag = 1;
			T->lchild = pre;
		}
		if(pre &&!(pre->rchild)){
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;
		createThrTree(T->rchild);
	}
}
ThrTree* nextNode(ThrTree* p){
	if(p->rtag == 0){
		p = p->rchild;
		while(p->ltag == 0) p = p->lchild;
		return p;
	} else return p->rchild;
}
void searchThrTree(ThrTree* T){
	ThrTree* t = T;
	int n = 0;
	for(t; t != NULL; t = nextNode(t)){
		cout<<t->val;
		if(t->ltag + t->rtag == 1) n++;
	}
	cout<<endl;
	cout<<n+1<<endl;
}
int main(){
	cin>>s;
	ThrTree* T = createBiTree();
	createThrTree(T);
	pre->rchild = NULL;
	pre->rtag = 1;
	ThrTree* p = T;
	while(p->ltag == 0) p = p->lchild;
	searchThrTree(p);
	return 0;
}

