#include<stdio.h>
int T, N, Case = 1;
int A[52];
int High = 0, Low = 0;
void print() {
	printf("Case %d: %d %d\n", Case++, High, Low);
}
int main() {
	freopen("input11764.txt","r",stdin);
	scanf("%d", &T);
	while (T--) {
		High = 0; Low = 0;
		int i;
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		if (N == 1) {
			print();
			continue;
		}
		else {
			for (i = 0; i < N - 1; i++) {
				if (A[i] < A[i + 1])High++;
				if (A[i] > A[i + 1])Low++;
			}
			print();
		}
	}

	return 0;
}