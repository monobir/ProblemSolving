#include<stdio.h>
int N, F;
int main() {
	freopen("input10300.txt", "r", stdin);
	freopen("output10300.txt", "w", stdout);
	int i, j; int a, b, c;
	while (scanf("%d", &N) == 1) {
		for (i = 1; i <= N; i++) {
			scanf("%d", &F);
			long sum = 0;
			for (j = 0; j < F; j++) {
				scanf("%d %d %d", &a, &b, &c);
				sum += a*c;
			}
			printf("%ld\n", sum);
		}
	}
	return 0;
}