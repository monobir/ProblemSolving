#include<stdio.h>
#define INF 100000
int Mat[101][101];
int arr[101];
int Case=1;
void init() {
	int i, j;
	for (i = 1; i <= 100; i++) {
		arr[i] = 0;
		for (j = 1; j <= 100; j++) {
			Mat[i][j] = INF;
		}
	}
}
int main() {
	int a, b;
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &a, &b) == 2) {
		init();
		if (a == 0 || b == 0)break;
		Mat[a][b] = 1;
		arr[a] = 1;
		arr[b] = 1;
		while (scanf("%d %d", &a, &b) == 2) {
			if (a == 0 || b == 0)break;
			Mat[a][b] = 1;
			arr[a] = 1; arr[b] = 1;
		}
		int i,max=0,num=0;
		for (i = 1; i <= 100; i++) {
			if (arr[i] == 1) {
				num++;
				if (i > max)max = i;
			}
		}
		int k,j;
		for (k = 1; k <= max; k++) {
			for (i = 1; i <= max; i++) {
				for (j = 1; j <= max; j++) {
					if (Mat[i][j] > Mat[i][k] + Mat[k][j]) {
						Mat[i][j] = Mat[i][k] + Mat[k][j];
					}
				}
			}
		}
		/*for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				printf("%d ", Mat[i][j]);
			}
			printf("\n");
		}*/
		int sum = 0;
		for (i = 1; i <= max; i++) {
			if (arr[i]) {
				for (j = 1; j <= max; j++) {
					if(Mat[i][j]!=INF&&i!=j)
					sum += Mat[i][j];
				}
			}
		}
		//printf("sum=%d\n",sum);
		//printf("num=%d\n", num);
		float Ans;
		Ans = (float)sum / (num*(num - 1));
		printf("Case %d: average length between pages = %.3f clicks\n",Case++,Ans);

	}


	return 0;
}