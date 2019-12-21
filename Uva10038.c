#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
int main() {
	int a[3005];
	int b[3005];
	int n;
	int flag;
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d", &n) == 1) {
		int i; flag = 1;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int k = 1;
		for (i = 1; i < n; i++) {
			b[k++] = abs(a[i] - a[i - 1]);
		}
		qsort(b+1, k-1, sizeof(int), compare);
		for (i = 1; i < k; i++) {
			if (b[i] != i) {
				flag = 0; break;
			}
		}
		if (flag)printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}