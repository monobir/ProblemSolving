#include<stdio.h>
#define SIZE 101
int Case;
int n, m, i, j, x, coin[SIZE];
int min, total;

int dp[101][50001];
void readCase() {
	scanf("%d", &m);
	total = 0;
	for (i = 0; i < m; i++) {
		scanf("%d", &coin[i]);
		total += coin[i];
	}
}
int solve(int i, int sum1) {
	int sum2, dif, left, right;
	if (i == m) {
		sum2 = total - sum1;
		dif = sum2 - sum1;
		if (dif < 0)
		{
			dif = dif*(-1);
		}
		return dif;
	}
	if (dp[i][sum1] != -1)
	{
		return dp[i][sum1];
	}
	else
	{
		left = solve(i + 1, sum1);
		right = solve(i + 1, sum1 + coin[i]);
		if (left < right)
		{
			return dp[i][sum1] = left;
		}
		else
		{
			return dp[i][sum1] = right;
		}
	}
}
void solveCase() {
	int j, k;
	for (j = 0; j < 101; j++) {
		for (k = 0; k < 50001; k++) {
			dp[j][k] = -1;
		}
	}
	min = solve(0, 0);
}

void printCase() {
	printf("%d\n", min);
}
int main() {
	int j, k;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (Case = 0; Case < n; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}