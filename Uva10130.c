#include<stdio.h>
#define SIZE 1001

int N, T, G, p[SIZE], w[SIZE], mw[SIZE];
int dp[1010][300];
void input() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &p[i], &w[i]);
	}
	scanf("%d", &G);
	for (i = 0; i < G; i++) {
		scanf("%d", &mw[i]);
	}
}

int solve(int l, int capacity) {
	int right = 0, left = 0;
	if (dp[l][capacity] != -1)return dp[l][capacity];
	if (l == N) return 0;
	if (capacity - w[l] >= 0) {
		right = p[l] + solve(l + 1, capacity - w[l]);
	}
	left = solve(l + 1, capacity);

	if (left > right) return dp[l][capacity] = left;
	else return dp[l][capacity] = right;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	int Case, j, x, k, p;
	for (Case = 1; Case <= T; Case++) {
		input();
		int sum = 0;
		for (j = 0; j < G; j++) {
			for (k = 0; k < 1001; k++) {
				for (p = 0; p < 31; p++) {
					dp[k][p] = -1;
				}
			}
			x = solve(0, mw[j]);
			sum += x;
		}
		printf("%d\n", sum);
	}

	return 0;
}