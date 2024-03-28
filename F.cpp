#include<bits/stdc++.h>
using namespace std;
int i = 0;
string s;
struct BiTNode{
	char val;
	BiTNode* left;
	BiTNode* right;
};
stack<BiTNode*> q;
BiTNode* CreateBiTree(){
	BiTNode *T;
	i++;
	if(i > s.length()) return NULL;
	if(s[i - 1] == '#') {
		return NULL;
	}
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->val = s[i - 1];
		T->left = CreateBiTree();
		T->right = CreateBiTree();
		return T;
	}
}
void beforeSearch(BiTNode *T){
	if(T){
		cout<<T->val;
		beforeSearch(T->left);
		beforeSearch(T->right);		
	} else return;
}
void middleSearch(BiTNode *T){
	if(T){
		middleSearch(T->left);
		cout<<T->val;
		middleSearch(T->right);		
	} else return;	
}
void afterSearch(BiTNode *T){
	if(T){
		afterSearch(T->left);
		afterSearch(T->right);
		cout<<T->val;		
	} else return;	
}
int leavesNum(BiTNode *T){
	if(!T) return 0;
	if(!(T->left) && !(T->right)) return 1;
	else{
		return leavesNum(T->left) + leavesNum(T->right);
	}
}
int treeDepth(BiTNode *T){
	if(!T) return 0;
	else{
		return max(treeDepth(T->left),treeDepth(T->right)) + 1;
	}
}
void middleStack(BiTNode *T){
	q.push(T);
	while(!q.empty()){
		while(T->left) {
			T = T->left;
			q.push(T);
		}
		T = q.top();
		q.pop();
		cout<<T->val;
		if(T->right){
			T = T->right;	
			q.push(T);
		}
	}
}
int main(){
	BiTNode *T;
	cin>>s;
	T = CreateBiTree();
	beforeSearch(T);
	cout<<endl;
	middleSearch(T);
	cout<<endl;
	afterSearch(T);
	cout<<endl;
	cout<<leavesNum(T)<<endl;
	cout<<treeDepth(T)<<endl;
	middleStack(T);
	return 0;
}

