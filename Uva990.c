#include<stdio.h>
int T, W, N;
int d[100], val[100], a[100];
int res[100];
int max;
int sum;
int spidentifier = 0;
void readCase() {
		scanf("%d", &N);
		int j, x, y;
		for (j = 0; j < N; j++) {
			scanf("%d %d", &x, &y);
			d[j] = x*W * 3;
			val[j] = y;
		}
}
void print() {
	int i;
	for (i = 0; i < N; i++)printf("%d ", a[i]); printf("%d %d", max, sum);
	printf("\n");
}
int solve(int i, int air, int sum) {
	int j;
	if (i == N) {
		if (sum > max) {
			max = sum;
			for (j = 0; j < N; j++) {
				res[j] = a[j];
			}
		}
		return sum;
	}
	int l = 0, r = 0;
	a[i] = 0;
	l = solve(i + 1, air, sum);
	if (air - d[i] >= 0) {
		a[i] = 1;
		r = solve(i + 1, air - d[i], sum+val[i]);
	}
	if (l>r)sum = l;
	else sum = r;
	return sum;
}
void solveCase() {
	max = 0;
	solve(0, T, 0);
}
void printCase() {
	int j;
	int count = 0;
	printf("%d\n", max);
	for (j = 0; j < N; j++) {
		if (res[j] == 1)count++;
	}
	spidentifier += 1;
	printf("%d\n", count);
	for (j = 0; j < N; j++) {
		if (res[j] == 1) {
			printf("%d %d", d[j]/(W*3), val[j]);
			printf("\n");
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d %d", &T, &W) != EOF) {
		readCase();
		solveCase();
		if (spidentifier > 0)printf("\n");
		printCase();
	}
	return 0;
}