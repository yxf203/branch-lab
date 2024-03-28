#include <stdio.h>
#include <malloc.h>
struct nums{
	int val; 
	int ex;
	struct nums* next;
};
int main(){
	int a,b,k;
	struct nums *head,*p,*q;
	head = (struct nums*)malloc(sizeof(struct nums));
	head->next = NULL; 
	while(scanf("%d %d",&a,&b) != EOF){
		if(!head->next){
			p = (struct nums*)malloc(sizeof(struct nums));
			p->val = a;
			p->ex = b;
			p->next = NULL;
			head->next = p;
		} else {
			q = p;
			p = (struct nums*)malloc(sizeof(struct nums));
			p->val = a;
			p->ex = b;
			p->next = NULL;
			q->next = p;			
		}
	}
	p = head->next;
	while(p){
		if(p->ex == 0) p->val = 0;
		else {
			p->val = p->val * p->ex;
			p->ex = p->ex - 1;
		}
		p = p->next;
	}
	p = head->next;
	printf("%d %d",p->val,p->ex);
	if(p->ex == 0||!p->next) return 0;
	else p = p->next;
	while(p){
		if(p->val == 0 && p->ex ==0) break;
		printf(" %d %d",p->val,p->ex);
		p = p->next;
	}
	return 0;
}

