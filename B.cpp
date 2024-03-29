// 这里也要重写不一样的！！哈哈哈！！ 
// 这里也是为了作业做的修改！！ 
// 这里是手动解决冲突的部分！ 
#include <stdio.h>
#include <string.h>
int main(){
	char s[10000];
	char *p,*q;
	scanf("%s",s);
	p = s;
	q = s + strlen(s) - 1;
	while(p<q){
		if(*p != *q )break;
		p++;
		q--;
	}
	if(p >= q) printf("1");
	else printf("0");
	return 0;
}

