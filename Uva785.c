#include<stdio.h>
#define row 40
#define col 100
int N, M;
char Grid[row][col];
int used[row][col] = { 0 };
void printCase() {
	int i;
	for (i = 0; i < N; i++) {
		puts(Grid[i]);
	}
	puts(Grid[N]);
}
void fill(int x, int y, char ch) {
	if (used[x][y])return;
	if (Grid[x][y] == 'X')return;

	used[x][y] = 1; Grid[x][y] = ch;
	fill(x + 1, y, ch);
	fill(x - 1, y, ch);
	fill(x, y + 1, ch);
	fill(x, y - 1, ch);
}

int main() {
	int i, j;
	while (1) {
		N = 0;
		while (1) {
			if (!gets(Grid[N]))return 0;
			if (Grid[N][0] == '_') {
				break;
			}
			N++;
		}
		memset(used, 0, sizeof(used));
		for (i = 0; i < N; i++) {
			for (j = 0; Grid[i][j]; j++) {
				if (Grid[i][j] != 'X'&&Grid[i][j] != ' ') {
					fill(i, j, Grid[i][j]);
				}
			}
		}
		printCase();
	}
	return 0;
}