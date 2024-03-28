#include <stdio.h>
void output(int d[], int v0, int n){
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] <= 6) count++;
	}
	printf("%d: %.2f%%\n", v0, 100.0 * count / n);
}
void Dijkstra(int path[][110], int v0, int n){
	int d[110]={0},final[110] = {0};
	int k = 1;
	// ��ʼ��final���� 
	for(int i = 1; i <= n; i++){
		if(i != v0){
			if(path[v0][i]) d[i] = path[v0][i];
			else d[i] = 9999;	
		}
	}
	d[v0] = 0;
	final[v0] = 1;
	while(k <= n){
		int min = 9999;
		int index = 0;
		// ��ȡδ�����ʵ�Ŀǰ������С��ֵ 
		for(int i = 1; i <= n; i++){
			if(!final[i] && d[i] < min){
				min = d[i];
				index = i;
			}
		}
		// ���¾���d����
		final[index] = 1;
		for(int i = 1; i <= n; i++){
			if(!final[i]){
				if(path[index][i] && d[index] + path[index][i] < d[i]){
					d[i] = path[index][i] + d[index];
				}
			}
		} 
		k++;
	}
	// �����������
	 output(d, v0, n);
}
int main(){
	int n, m, i, p1, p2, path[110][110]={0};
	scanf("%d %d",&n, &m);
	for(i = 0; i < m; i++){
		scanf("%d %d",&p1, &p2);
		path[p1][p2] = 1;
		path[p2][p1] = 1;
	}

	//����ÿһ���ڵ�
	for(i = 1; i <= n; i++){
		Dijkstra(path, i, n);
	} 
	
	return 0;
}
