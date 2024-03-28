#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j,k,indexi = 0,indexj = 0,m,max=0;
	string s[1000];
	string s0;
	cin>>n;
	for(i = 0; i < n; i++) {
		cin>>s[i];
	}
	cin>>s0;
	k = 0;
	for(i = 0; i < n; i++){
		k = 0;
		for (j = 0; j < s[i].length();j++) {
			if(s[i][j] == s0[k]){
				if(k == 0) m = j;
				k++;
			} else {
				if(max < k) {
					max = k;
					indexi = i;
					indexj = m;
				}
				k = 0;
			}
		}
		if(max < k) {
			max = k;
			k = 0;
			indexi = i;
			indexj = m;
		}		
	}
	if (max == 0) printf("0 0 0.00%%");
	else printf("%d %d %.2lf%%",indexi + 1, indexj + 1,1.0*max/s0.length() * 100);
	return 0;
}

