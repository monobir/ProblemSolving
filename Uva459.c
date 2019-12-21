#include<stdio.h>

#define SIZE 27

int T, N;
char st[5];
int Path[SIZE][SIZE];
int Visited[SIZE];
int Count;
void print() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", Path[i][j]);
		}
		printf("\n");
	}
}
void initCase()
{
	int i, j;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		Path[i][j] = 0;
	for (i = 0; i < N; i++)
		Visited[i] = 0;
}

void readCase()
{
	int x, y;
	gets(st);
	N = st[0] - 'A' + 1;
	initCase();
	while (gets(st)) {
		if (st[0] == '\0')
			break;
		x = st[0] - 'A';
		y = st[1] - 'A';
		Path[x][y] = 1;
		Path[y][x] = 1;
	}
}

void fill(int x, int y) {
	int k;
	Path[x][y] = 0;
	Path[y][x] = 0;
	Visited[x] = 1;
	Visited[y] = 1;
	for (k = 0; k < N; k++) {
		if (Path[y][k] == 1) {
			fill(y, k);
		}
	}
	for (k = 0; k < N; k++) {
		if (Path[x][k] == 1) {
			fill(x, k);
		}
	}
}
void solveCase()
{
	int i, j;
	Count = 0;
	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j++){
			if (Path[i][j] == 1) {
				Count++;
				fill(i, j);
			}
         }
	}
	for (i = 0; i < N; i++) {
		if (Visited[i] == 0)Count++;
	}
}

void printCase()
{
	printf("%d\n", Count);
	if (T)
		printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &T);
	getchar();
	getchar();
	while (T--) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}