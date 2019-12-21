#include<stdio.h>
#include<math.h>
int N,K;
int Prime[1160] = {0};
int PrimesList[1160];
int index;
int dp[1160][17][193];
void sieve() {
	int i, j;
	int sqr = sqrt(1160);
	for (i = 2; i <= sqr; i++) {
		if (!Prime[i]) {
			for (j = i*i; j <= 1160; j += i) {
				Prime[j] = 1;
			}
		}
	}
}

void print() {
	int j;
	for (j = 0; j < index; j++) {
		printf("%d ", PrimesList[j]);
	}
	printf("\n");
}
int solve(int n, int k, int ind) {
	if (!k || n <= 0 || PrimesList[ind] > N) {
		if (!n && !k)return 1;
		return 0;
	}
	if (n >0 && !k) return 0;
	if (dp[n][k][ind] != -1)return dp[n][k][ind];
	dp[n][k][ind] = solve(n - PrimesList[ind], k - 1, ind + 1) + solve(n, k, ind + 1);
	return dp[n][k][ind];
}
int main() {
	sieve();
	index = 0;
	int i;
	for (i = 2; i < 1160; i++) {
		if (!Prime[i])
			PrimesList[index++] = i;
	}
	while (scanf("%d %d", &N, &K) == 2) {
		memset(dp, -1, sizeof(dp));
		if (!N && !K)break;
		int ans = solve(N, K, 0);
		printf("%d\n", ans);
	}
	return 0;
}