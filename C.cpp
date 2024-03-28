#include<bits/stdc++.h>
using namespace std;
stack<char> op;
stack<int> n;
int calc(char o,int a,int b){
	if(o == '*') return a*b;
	else if(o == '/') return a/b;
	else if(o == '+') return a + b;
	else if(o == '-') return a-b;
}
int cmp(char a,char b){
	if((a == '#' && (b == '+' || b == '-' || b == '*' || b == '/'|| b == '('))){
		return -1;
	} else if(a == '+' && (b == '*' || b == '/'|| b == '(')) {
		return -1;
	} else if(a == '-' && (b == '*' || b == '/'|| b == '(')){
		return -1;
	} else if((a == '/'|| a == '*') && b == '(') {
		return -1;
	} else if((a == '(' && (b == '+' || b == '-' || b == '*' || b == '/'|| b == '('))){
		return -1;
	}
	else if ((a == '(' && b == ')')) return 0;
	else return 1;
}
int main(){
	string s;
	int i,num = 0;
	cin>>s;
	op.push('#');
	for(i = 0; i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num = num * 10 + s[i] - '0';
		} else {
			if(num) {
				n.push(num);
				num = 0;
			}
			if(cmp(op.top(),s[i]) == -1) op.push(s[i]);
			else if(cmp(op.top(),s[i]) == 0) op.pop();
			else if (cmp(op.top(),s[i]) == 1){
				int a = n.top();
				n.pop();
				int b = n.top();
				n.pop();
				n.push(calc(op.top(),b,a));
				op.pop();
				i--;
			} 
		}
	}
	if(num) {
		int a = n.top();
		n.pop();
		n.push(calc(op.top(),a,num));
		op.pop();
	}
	while(op.top() != '#'){
		int a = n.top();
		n.pop();
		int b = n.top();
		n.pop();
		n.push(calc(op.top(),b,a));
		op.pop();
	}
	cout<<n.top()<<endl;
	return 0;
}

