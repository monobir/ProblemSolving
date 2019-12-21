#include<stdio.h>
int Path[202][202];
int V[202];
int T, N, M;
int C,Flag;


void initPath() {
	int i, j;
	for (i = 0; i < N; i++) {
		V[i] = 0;
		for (j = 0; j < N; j++) {
			Path[i][j] = 0;
		}
	}
}
void readCase() {
	int u, v;
	scanf("%d %d", &N, &M);
	initPath();
	while (M--) {
		scanf("%d %d", &u, &v);
		Path[u][v] = Path[v][u] = 1;
	}
}
int dfs(int node,int color) {
	int j;
	V[node] = color;
	/*if (level >= 2) {
		return 1;
	}*/
	for (j = 0; j < N; j++) {
		if (Path[node][j]) {
			if (V[j] == 0) {
					if (dfs(j, 3 - color) == 0)
						return 0;
			}
			else {
				if (V[j] == color) {
					Flag = 1;
					return 0;
				}
			}
		}
	}
	return 1;
}
void solveCase() {
	int i; C = 0,Flag=0;
	//int color = 1;
	for (i = 0; i < N; i++) {
		if (!V[i]) {
			//C++;
			dfs(i,1);
			//color = 3 - color;
		}
	}
}
void printCase() {
	if (Flag) {
		printf("-1\n");
	}
	else {

		int i,j,k;
		for (i = 0; i < N; i++) {
			if (V[i] != 0) {
				C++;
				for (j = 0; j < N; j++) {
					if (Path[i][j]) {
						V[j] = 0;
						for (k = 0; k < N; k++) {
							if (Path[j][k]) {
								V[k] = 0;
							}
						}
					}
				}
			}
		}
		printf("%d\n", C);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &T);
	while (T--) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}