#include<stdio.h>
int N, CD;
int cdSize[22];
int max;
int a[22];
int storePath[22];
void print() {
	int j;
	for (j = 0; j < CD; j++) {
		printf("%d ", cdSize[j]);
	}
	printf("\n");
}

int solve(int i, int sum) {
	if (i == CD) {
		if (sum >= max) {
			max = sum;
			int j;
			for (j = 0; j < CD; j++) {
				storePath[j] = a[j];
			}
		}
		return;
	}
	int j, l=0, r=0;
	a[i] = 0;
	l=solve(i + 1, sum);
	if (sum + cdSize[i] <= N) {
		a[i] = 1;
		r = solve(i + 1, sum + cdSize[i]);
	}
	if (l > r)sum = l;
	else sum = r;
	return sum;
}
void solveCase() {
	int j;
	for (j = 0; j < CD; j++) {
		storePath[j] = 0;
	}
	max = 0;
	solve(0, 0);
	for (j = 0; j < CD; j++) {
		if (storePath[j] == 1) {
			printf("%d ", cdSize[j]);
		}
	}
	printf("sum:%d\n", max);
}
void readCase() {
	int j;
	while (scanf("%d %d", &N, &CD) != EOF) {
		for (j = 0; j < CD; j++) {
			scanf("%d", &cdSize[j]);
		}
		solveCase();
	}
}

int main() {
	readCase();
	return 0;
}