#include<bits/stdc++.h>
using namespace std;
struct treeNode{
	char val;
	struct treeNode* firstchild;
	struct treeNode* sib;
};
queue<struct treeNode*> que;
void preSearch(struct treeNode* t){
	if(t){
		cout<<t->val;
		preSearch(t->firstchild);
		preSearch(t->sib);
	} else return;
}
void beSearch(struct treeNode* t){
	if(t){
		beSearch(t->firstchild);
		cout<<t->val;
		beSearch(t->sib);
	} else {
		return;
	}
}
void degreeSearch(struct treeNode* t){
	queue<struct treeNode*> q;
	struct treeNode* p;
	q.push(t);
	while(!q.empty()){
		if(q.front()->firstchild != NULL){
			q.push(q.front()->firstchild);	
		}
		p = q.back();
		while (p->sib != NULL) {
			p = p->sib;
			q.push(p);
		}
		cout<<q.front()->val;
		q.pop();	
	}
	return;
}
int treeDepth(struct treeNode* t){
	if(!t) return 0;
	else {
		return max(treeDepth(t->firstchild) + 1,treeDepth(t->sib));
	}
}
int countLeaf(struct treeNode* t){
	if(!t) return 0;	
	if(t->firstchild == NULL) return 1 + countLeaf(t->sib);
	else return countLeaf(t->firstchild) + countLeaf(t->sib);
}
void getPath(struct treeNode* t,string s){
	if(t){
		string str = s;
		s.push_back(t->val);
		getPath(t->firstchild,s);
		if(t->sib) getPath(t->sib,str);		
	} else {
		cout<<s<<endl;
		return;
	}
}
int main(){
	char fa,ch;
	struct treeNode *head,*p,*q,*t;
	string temp;
	cin>>temp;
	fa = temp[0];
	ch = temp[2];
	while(ch != '#'){
		if(fa == '#'){
			head = (struct treeNode*)malloc(sizeof(struct treeNode));
			head->val = ch;
			head->firstchild = NULL;
			head->sib = NULL;
			que.push(head);
			cin>>temp;
			fa = temp[0];
			ch = temp[2];
		} else {
			p = que.front();
			if(fa == p->val){
				t = (struct treeNode*)malloc(sizeof(struct treeNode));
				t->val = ch;
				t->firstchild = NULL;
				t->sib = NULL;
				if(p->firstchild == NULL){
					p->firstchild = t;
					que.push(t);						
				} else {
					q = que.back();
					q->sib = t;
					que.push(t);
				}
				cin>>temp;
				fa = temp[0];
				ch = temp[2];
			} else {
				que.pop();
			}
		}
	}
	preSearch(head);
	cout<<endl;
	beSearch(head);
	cout<<endl;
	degreeSearch(head);
	cout<<endl;
	cout<<treeDepth(head)<<endl;
	cout<<countLeaf(head)<<endl;
	getPath(head,"");
	return 0;
}

