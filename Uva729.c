#include<stdio.h>
int testCase;
int N, H;
int a[20] = {0};
int count;
void print() {
	int j;
	for (j = 0; j < N; j++) {
		printf("%d", a[j]);
	}
	printf("\n");
}
void solve(int i) {
	int j;
	if (i == N) {
		count = 0;
		for (j = 0; j < N; j++) {
			if (1 == a[j]) {
				count++;
			}
		}
		if (count == H) {
			print();
		}
		return;
	}
	a[i] = 0;
	solve(i + 1);
	a[i] = 1;
	solve(i+1);
}

void readCase() {
	int Case;
	scanf("%d", &testCase);
	for (Case = 1; Case <= testCase; Case++) {
		getchar();
		scanf("%d %d", &N, &H);
		solve(0);
		if (Case < testCase)printf("\n");
	}
}
int main() {
	readCase();
	return 0;
}