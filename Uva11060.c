#include<stdio.h>
#include<string.h>
char Name[102][52];
int Path[102][102];
int indegree[102];
int index;
int Node[102];
int N, M, Case,ptr;
void initDegree() {
	int i;
	for (i = 1; i <= N; i++) {
		indegree[i] = 0;
	}
}
int searchString(char s[]) {
	int i;
	for (i = 1; i <= N; i++) {
		if (strcmp(Name[i], s) == 0) {
			return i;
		}
	}
	return 0;
}
void print() {
	for (int i = 1; i <= N; i++) {
		printf("%d ", indegree[i]);
	}
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", Path[i][j]);
		}
		printf("\n");
	}
}

void readCase() {
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%s", Name[i]);
	}
	initDegree();
	scanf("%d", &M);
	char name1[52], name2[52];
	int x, y;
	while (M--) {
		scanf("%s %s", name1, name2);
		x = searchString(name1);
		y = searchString(name2);
		Path[x][y] = 1;
		indegree[y]++;
	}
	getchar();
}
void degDec(int x) {
	int j;
	for (j = 1; j <= N; j++) {
		if (1 == Path[x][j]) {
			indegree[j]--;
		}
	}
}
void solveCase(){
	int i;
	for (i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Node[index] = i;
			indegree[i] = -1;
			index++;
		}
	}
	for (i = ptr; i <index; i++) {
		degDec(Node[i]);
	}
	ptr = index;
	if (index <= N) {
		solveCase();
	}
}
void printCase() {
	int i;
	printf("Case #%d: Dilbert should drink beverages in this order:",Case);
	for (i = 1; i <= N; i++) {
		printf(" %s", Name[Node[i]]);
	}
	printf(".\n\n");
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	Case = 0;
	while (1==scanf("%d",&N)) {
		index = 1;
		ptr = 1;
		Case++;
		readCase();
		solveCase();
		printCase();
	}

	return 0;
}