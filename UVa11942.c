#include<stdio.h>
int T;
int A[10];
int main() {
	freopen("input11942.txt", "r", stdin);
	freopen("output11942.txt","w",stdout);
	scanf("%d", &T);
	printf("Lumberjacks:\n");
	while (T--) {
		int i;
		for (i = 0; i < 10; i++) {
			scanf("%d", &A[i]);
		}
		int max=0,min=0;
		for (i = 0; i < 9; i++) {
			if (A[i] > A[i + 1])max = 1;
			if (A[i] < A[i + 1])min = 1;
		}
		if (max + min == 1)printf("Ordered\n");
		else printf("Unordered\n");
	}
	return 0;
}