#include<bits/stdc++.h>
using namespace std;
struct martrixDot{
	int x;
	int y;
	int val;
};
int cmp(martrixDot m,martrixDot n){
	return m.x<n.x;
}
int main(){
	martrixDot m[1000];
	int a,b,c,i = 0,t,k=0,min,index,d[1000]={0};
	scanf("%d %d %d",&a,&b,&c);
	for(i = 0; i < c;i++){
		scanf("%d %d %d",&m[i].x,&m[i].y,&m[i].val);
	}
	for(i = 0; i < c; i++){
		t = m[i].x;
		m[i].x = m[i].y;
		m[i].y = t;
	}
	t = a;
	a = b;
	b = t;
	printf("%d %d %d\n",a,b,c);
	while(k<c){
		min = 1e6;
		index = 0;
		for(i = 0; i < c;i++){
			if(!d[i] && m[i].x < min ){
				index = i;
				min = m[i].x;
			}
		}
		d[index] = 1;
		printf("%d %d %d\n",m[index].x,m[index].y,m[index].val);
		k++;
	}
	return 0;
}

