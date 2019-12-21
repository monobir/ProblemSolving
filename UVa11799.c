#include<stdio.h>
int T, N, Case = 1;;
int main() {
	freopen("input11799.txt","r",stdin);
	int x, max,i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		max = 0;
		for (i = 0; i < N; i++) {
			scanf("%d", &x);
			if (x > max)max = x;;
		}
		printf("Case %d: %d\n",Case++, max);
	}
	return 0;
}