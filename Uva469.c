#include<stdio.h>
#include<string.h>
#define SIZE 101

int T, N, M;
char Map[SIZE][SIZE];
int Used[SIZE][SIZE] = {0};
int Ans;

void readCase()
{
	N = 0;
	while (gets(Map[N])) {
		if (Map[N][0] != 'L' && Map[N][0] != 'W')
			break;
		N++;
	}
	M = strlen(Map[N-1]);
}
void fill(int x, int y) {
	Map[x][y] = 'L';
	Used[x][y] = 1;
	Ans++;
	if (x - 1 >= 0 && y - 1 >= 0 && 'W' == Map[x - 1][y - 1]) {
		fill(x - 1, y - 1);
	}
	if (x - 1 >= 0 && 'W' == Map[x-1][y]) {
		fill(x-1,y);
	}
	if (x - 1 >= 0 && y + 1 < M&&'W' == Map[x - 1][y + 1]) {
		fill(x - 1, y + 1);
	}
	if (y - 1 >= 0 && 'W' == Map[x][y - 1]) {
		fill(x,y-1);
	}
	if (y + 1 < M&& 'W' == Map[x][y + 1]) {
		fill(x,y+1);
	}
	if (x + 1 < N&&y - 1 >= 0 && 'W' == Map[x + 1][y - 1]) {
		fill(x+1,y-1);
	}
	if (x + 1 < N&&'W' == Map[x + 1][y]) {
		fill(x+1,y);
	}
	if (x + 1 < N&&y + 1 < M&&'W' == Map[x + 1][y + 1]) {
		fill(x + 1, y + 1);
	}
}

void resetUsed() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Used[i][j] == 1) {
				Map[i][j] = 'W';
				Used[i][j] = 0;
			}
		}
	}
}
void solveCase()
{
	int i, x, y;
	while (Map[N][0] != '\0') {
		i = x = y = 0;
		while (Map[N][i] != ' ') {
			x = x * 10 + Map[N][i] - '0';
			i++;
		}
		i++;
		while (Map[N][i] != '\0') {
			y = y * 10 + Map[N][i] - '0';
			i++;
		}
		
		x--;
		y--;
		Ans = 0;
		fill(x, y);
		printf("%d\n", Ans);
		resetUsed();
		if (!gets(Map[N]))
			break;
	}
	if (T)
		printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	scanf("%d ", &T);
	while (T--) {
		readCase();
		solveCase();
	}
	return 0;
}