#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int n = 0;//表示根节点 
string s1,s2;
struct BiTree{
	char val;
	BiTree *lchild;
	BiTree *rchild;
};
BiTree* createBiTree(int head,int back){
	BiTree* T;
	int index;
	if(head > back) return NULL;
	T = (BiTree*)malloc(sizeof(BiTree));
	T->val = s1[n];
	for(int i = head; i <= back;i++){
		if(s2[i] == s1[n]){
			index = i;
			break;
		}
	}
	n++;
	T->lchild = createBiTree(head,index - 1);
	T->rchild = createBiTree(index + 1,back);
	return T;
}
int treeDepth(BiTree* T){
	if(!T) return 0;
	else {
		return 1 + max(treeDepth(T->lchild),treeDepth(T->rchild));
	}
}
//int countLeaf(BiTree* T){
//	if(!T) return 0;
//	if(T->lchild == NULL && T->rchild == NULL) return 1;
//	else {
//		return countLeaf(T->lchild) + countLeaf(T->rchild);
//	}
//}
int main(){
	cin>>s1;
	cin>>s2;
	BiTree* T = createBiTree(0,s2.length() - 1);
	cout<<treeDepth(T)<<endl;
	cout<<countLeaf(T)<<endl;
	return 0;
}

