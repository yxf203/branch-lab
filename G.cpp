#include<bits/stdc++.h>
using namespace std;
string s;
int i = 0;
struct BiTree{
	char val;
	BiTree* lchild;
	BiTree* rchild;
};
BiTree* createBiTree(){
	if(i >= s.length()) return NULL;
	BiTree *T = (BiTree*)malloc(sizeof(BiTree));
	if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
		T->val = s[i++];
		T->lchild = createBiTree();
		T->rchild = createBiTree();	
	} else {
		T->val = s[i++];
		T->lchild = NULL;
		T->rchild = NULL;
	}
	return T;
}
void preSearch(BiTree* T){
	if(!T) return;
	cout<<T->val;
	preSearch(T->lchild);
	preSearch(T->rchild);
}
void midSearch(BiTree* T){
	if(!T) return;
	midSearch(T->lchild);
	cout<<T->val;
	midSearch(T->rchild);
}
void behSearch(BiTree* T){
	if(!T) return;
	behSearch(T->lchild);
	behSearch(T->rchild);
	cout<<T->val;
}
int main(){
	cin>>s;
	BiTree* T = createBiTree();
	preSearch(T);
	cout<<endl;
	midSearch(T);
	cout<<endl;
	behSearch(T);
	cout<<endl;
	return 0;
}

