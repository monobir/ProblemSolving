#include<stdio.h>
#define Size 10
int K,Ans,Max;
int Map[Size][Size];
int Used[Size][Size];
int check(int a, int b) {
	int k;
		for (k = 0; k < a; k++) {
		if (1 == Used[k][b])return 0;
	}
		for (k = 1; a - k >= 0 && b - k >= 0; k++) {
		if (1 == Used[a - k][b - k])return 0;
	}
	for (k = 1; a - k >= 0 && b + k < 8; k++) {
		if (1 == Used[a - k][b + k])return 0;
	}
		return 1;
}
void solve(int i) {
	int j;
	if (i == 8) {
		if (Ans > Max) {
			Max = Ans;
			}
		return;
	}
	for (j = 0; j < 8; j++) {
		if (1 == check(i, j)) {
			Used[i][j] = 1;
			Ans+= Map[i][j];
			solve(i + 1);
			Used[i][j] = 0;
			Ans -= Map[i][j];

		}
	}
}
void readCase() {
	int i,j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%d",&Map[i][j]);
		}
	}
}
void printCase() {
	printf("%5d\n", Max);
}
void solveCase() {
	Ans = 0;
	Max = 0;
	solve(0);
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &K);
	while (K--) {
		readCase();
		solveCase();
		printCase();
	}
	
	return 0;
}