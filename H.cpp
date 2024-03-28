#include<bits/stdc++.h>
using namespace std;
string s;
unsigned int i = 0;
struct BiTree{
	char val;
	BiTree* lchild;
	BiTree* rchild;
};
stack<char> p;//²Ù×÷·û 
stack<BiTree*> q;//²Ù×÷Êý
BiTree* createBiTree(){
	while(i < s.length()){
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')'){
			if(p.empty() || s[i] == '(') p.push(s[i]);
			else if(s[i] == ')' && p.top() == '(') p.pop();
			else if(p.top() == '(') p.push(s[i]);
			else{
				char temp = p.top();
				if((s[i] == '/' || s[i] == '*') && (temp == '+' || temp == '-')) p.push(s[i]);
				else {
					BiTree* a = q.top();
					q.pop();
					BiTree* b = q.top();
					q.pop();
					BiTree* t = (BiTree*)malloc(sizeof(BiTree));
					t->val = p.top();
					p.pop();
					t->rchild = a;
					t->lchild = b;
					q.push(t);
					i--;
				}			
			} 
		} else {
			BiTree* t = (BiTree*)malloc(sizeof(BiTree));
			t->val = s[i];
			t->lchild = NULL;
			t->rchild = NULL;
			q.push(t); 
		}
		i++;
	}
	while(!p.empty()){
		BiTree* a = q.top();
		q.pop();
		BiTree* b = q.top();
		q.pop();
		BiTree* t = (BiTree*)malloc(sizeof(BiTree));
		t->val = p.top();
		p.pop();
		t->rchild = a;
		t->lchild = b;
		q.push(t);
	}
	return q.top();
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

