#include<stdio.h>
#define size 52
int N, M;
int Ans;
char Grid[size][size];
int Used[size][size];
void print() {
	int i;
	for (i = 0; i < N; i++) {
		printf("%s\n", Grid[i]);
	}
}
void fill(int x, int y) {
	if (Grid[x][y] == '#' || Used[x][y]) {
		return;
	}
	if (Grid[x][y] == 'G') {
		Ans++;
	}
	Used[x][y] = 1;
	if (Grid[x - 1][y] == 'T' || Grid[x + 1][y] == 'T' || Grid[x][y - 1] == 'T' || Grid[x][y + 1] == 'T') {
		return;
	}
	fill(x+1,y);
	fill(x-1,y);
	fill(x,y+1);
	fill(x,y-1);
}
	
void solveCase() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if ('P' == Grid[i][j]) {
				Ans = 0;
				fill(i, j);
				break;
			}
		}

	}
	printf("%d\n", Ans);
}
void readCase() {
	int i;
	while (scanf("%d %d", &M, &N) == 2) {
		for (i = 0; i < N; i++) {
			scanf("%s", Grid[i]);
		}
		memset(Used,0,sizeof(Used));
		solveCase();
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	readCase();
	return 0;
}