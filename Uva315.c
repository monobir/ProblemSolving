#include<stdio.h>

#define SIZE 101

int N;
int Path[SIZE][SIZE];
int Pre[SIZE];
int IsCut[SIZE];
int pos[SIZE];
int DfsClock;
int Ans;

void initCase()
{
	int i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++)
		Path[i][j] = 0;
	for (i = 1; i <= N; i++)
		Pre[i] = 0;
	for (i = 1; i <= N; i++)
		IsCut[i] = 0;
	DfsClock = 0;
}

void readCase()
{
	int x, y;
	char ch;
	while (1 == scanf("%d", &x)) {
		if (0 == x)
			break;
		while (2 == scanf("%d%c", &y, &ch)) {
			Path[x][y] = 1;
			Path[y][x] = 1;
			if (ch == '\n')
				break;
		}
	}
}
void printPath() {
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%d ", Path[i][j]);
		}
		printf("\n");
	}
}
void fill(int x, int y) {
	int l;
	IsCut[x] = 1;
	IsCut[y] = 1;
	for (l = 1; l <= N; l++) {
		if (1 == Path[y][l]&&(!IsCut[l])) {
			fill(y,l);
		}
	}
}
void solveCase()
{
	Ans = 0;
	//printPath();
	int i, j; int k = 0;
	for (i = 1; i <= N; i++) {
		int sum=0;
		for (j = 1; j <= N; j++) {
			sum += Path[i][j];
		}
		if (sum > 1) {
			pos[k++] = i;
		}
	}
	//for (i = 0; i < k; i++)printf("%d ", pos[i]);
	//printf("\n");
	int l;
	for (i = 0; i < k; i++) {
		memset(IsCut, 0, sizeof(IsCut));
		for (j = 1; j <= N; j++) {
			if (1 == Path[pos[i]][j]) {
				fill(pos[i], j);
				for (l = 1; l <= N; l++) {
					if (IsCut[l] == 0) {
						Ans++;
						break;
					}
				}
				break;
			}
			
		}
	}
}

void printCase()
{
	printf("%d\n", Ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	while (1 == scanf("%d", &N) && N) {
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}