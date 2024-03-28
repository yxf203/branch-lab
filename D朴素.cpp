#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i, j, k, maxi,index, max_num;
	string s[100];
	string s0;
	cin>>n;
	for(i = 1; i <= n ;i++){
		cin>>s[i];
	}
	cin>>s0;
	max_num = 0;
	for(i = 1; i <= n; i++){
		j = 0;
		k = 0;
		while(j < s[i].length() && k < s0.length()){
			if(s[i][j] == s0[k]){
				j++;
				k++;
			} else {
				if(max_num < k){
					max_num = k;
					maxi = i;
					index = j - k + 1;
				}
				j = j - k + 1;
				k = 0;
			}
		}
		if(max_num < k){
			max_num = k;
			maxi = i;
			index = j - k + 1;
		}
	}
	if(max_num == 0) printf("0 0 0.00%%");
	else printf("%d %d %.2lf%%", maxi, index, 100.0*max_num/(s0.length()));	
	return 0;
}

