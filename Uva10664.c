#include<stdio.h>
int N,cnt,total;
int a[50];
int solve(int i,int sum1) {
	int sum2, diff;
	int left, right;
	if (i == cnt) {
		sum2 = total - sum1;
		diff = sum2 - sum1;
		if (diff < 0)diff = diff*(-1);
		return diff;
	}
	left = solve(i + 1, sum1);
	right = solve(i + 1, sum1 + a[i]);
	if (left < right)return left;
	else return right;
}
void solvecase() {
	int min;
	min = solve(0,0);
	if (min == 0)printf("YES\n");
	else printf("NO\n");

}
int main() {
	char ch;
	scanf("%d", &N);
	int i,Case;
	for (Case = 1; Case <= N; Case++) {
		cnt = 0; total = 0;
		while (1) {
			scanf("%d", &a[cnt]);
			ch = getchar();
			total += a[cnt];
			cnt++;
			if (ch == '\n')break;
		}
		cnt--;
		solvecase();
	}
	return 0;
}