#include<stdio.h>
#define S 102
int inDegArray[S];
int TopSortedNode[S];
int Path[S][S];
int N, M;
int ind;
int count;

void initDegree() {
	memset(inDegArray, 0, sizeof(inDegArray));
	memset(Path, 0, sizeof(Path));
}
void print() {
	int i;
	for (i = 1; i <= N; i++) {
		printf("%d ", inDegArray[i]);
	}
	printf("\n");
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
void readCase() {
	int x, y;
	int i;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		inDegArray[y]++;
		Path[x][y] = 1;
	}
	//print();
	//printPath();
}
void printCase() {
	int i;
	for (i = 0; i < ind; i++) {
		printf("%d ", TopSortedNode[i]);
	}
	printf("\n");
}
void degDec(int n) {
	int j;
	for (j = 1; j <= N; j++) {
		if (Path[n][j] == 1) {
			inDegArray[j]--;
		}
	}
}
void solveCase() {
	int i;
	for (i = 1; i <= N; i++) {
		if (inDegArray[i] == 0) {
			TopSortedNode[ind] = i;
			inDegArray[i] = -1;
			ind++;
		}
	}
	if (count < ind) {
		degDec(TopSortedNode[count++]);
		solveCase();
	}
		
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (2 == scanf("%d %d", &N, &M) && (N + M)) {
		initDegree();
		readCase();
		ind = 0;
		count = 0;
		solveCase();
		printCase();
	}
	return 0;
}