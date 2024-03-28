// 是为了作业！做的修改！ 
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);	
	while(n){
		if(n % k < 10) s.push(n % k + '0');
		else s.push(n % k + 'A' - 10); 
		n /= k;
	}
	while(!s.empty()){
		printf("%c",s.top());
		s.pop();
	}
	return 0;
}

