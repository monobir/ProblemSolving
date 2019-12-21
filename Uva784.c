#include<stdio.h>
#include<string.h>
#define S 100
int N,T,M;
char Grid[S][S];

void print() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%s\n", Grid[i]);
	}
}
void fill(int x, int y) {
	Grid[x][y] = '#';
	if (x - 1 >= 0 && Grid[x - 1][y] == ' ') {
		fill(x - 1, y);
	}
	if (x + 1 < N&& Grid[x + 1][y] == ' ') {
		fill(x + 1, y);
	}
	if (y - 1 >= 0 && Grid[x][y - 1] == ' ') {
		fill(x,y-1);
	}
	if (y + 1 < M&&Grid[x][y + 1] == ' ') {
		fill(x,y+1);
	}
}
void solveCase() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Grid[i][j] == '*') {
				fill(i,j);
			}
		}
	}

	print();
	printf("%s\n", Grid[N]);
}
void readCase() {
	N = 0;
	while (gets(Grid[N])) {
		if (Grid[N][0] == '_')break;
		N++;
	}
	M = strlen(Grid[1]);
	solveCase();

}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &T);
	getchar();
	while (T--) {
		readCase();
	}

	return 0;
}