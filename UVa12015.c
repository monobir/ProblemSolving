#include<stdio.h>
char str[11][102];
int val[11];
int T, Case = 1;
int main() {
	freopen("input12015.txt","r",stdin);
	scanf("%d", &T);
	while (T--) {
		int i;
		int max = 0;
		for (i = 0; i < 10; i++) {
			scanf("%s %d", str[i], &val[i]);
			if (val[i] > max)max = val[i];
		}
		printf("Case #%d:\n", Case++);
		for (i = 0; i < 10; i++) {
			if (val[i] == max) {
				printf("%s\n", str[i]);
			}
		}
	}
	return 0;
}