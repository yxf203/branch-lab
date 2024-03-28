#include<bits/stdc++.h>
using namespace std;
void getIndex(string s, int index[]){
	int i, j, max;
	index[0] = 0;
	for(i = 1; i < s.length(); i++){
		max = 0;
		for(j = 1; j < i; j++){
			if(s.substr(0, j) == s.substr(s.length() - j, j)){
				max = j;
			}
		}
		index[i] = max;
	}
}
int main(){
	int n,index[200] = {0},i, j, k, max_num = 0, maxi, maxj;
	string s[100], s0;
	cin>>n;
	for(i = 0; i < n; i++){
		cin>>s[i];
	}
	cin>>s0;
	getIndex(s0, index);
	printf("%d\n",s0.length());
	for(i = 0; i < s0.length(); i++){
		printf("111 ");
		printf("%d\n",index[i]);
	}
	for(i = 0; i < n; i++){
		k = 0;
		for(j = 0; j < s[i].length() && k < s0.length(); j++){
			if(s[i][j] == s0[k]){
				k++;
			} else {
				if(max_num < k){
					maxi = i + 1;
					maxj = j - k + 1;
					max_num = k;
				}
				k = index[k];
				j--;
			}
		}
	}
	if(max_num == 0) printf("0 0 0.00%%");
	else printf("%d %d %lf%%",maxi, maxj, 100.0*max_num/s0.length());
	return 0;
}

