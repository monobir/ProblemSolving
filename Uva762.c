#include<stdio.h>
#include<string.h>
#define INF 99999
char node1[4], node2[4];
int Path[1001][1001];
char Name[1001][4];
int Level[1001];
int Q[100000];
int N,Index;
int Parent[1001];
int F, R;
int Stack[1001],top;
int Case;

int searchString(char n[]) {
	int j;
	for (j = 0; j < Index; j++) {
		if (strcmp(Name[j], n) == 0)return j;
	}
	return -1;
}
void push(int node) {
	Q[R++] = node;
}
int pop() {
	return Q[F++];
}
int isEmpty() {
	if (F == R)return 1;
	return 0;
}
void initQ() {
	F = R = 0;
}
void BFS(int n) {
	initQ();
	int node,j;
	push(n);
	Level[n] = 0;
	while (!isEmpty()) {
		node = pop();
		for (j = 0; j < Index; j++) {
			if (Path[node][j] && Level[j] == INF) {
				Level[j] = Level[node] + 1;
				Parent[j] = node;
				push(j);
			}
		}
	}
}
void initPath() {
	int i, j;
	for (i = 0; i < 1001; i++) {
		for (j = 0; j < 1001; j++) {
			Path[i][j] = 0;
		}
	}
 }
void print() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", Path[i][j]);
		}
		printf("\n");
	}
}
void readCase() {
	initPath();
	int i,x,y;
	Index = 0;
	for (i = 1; i <= N; i++) {
		scanf("%s %s", node1, node2);
		 x = searchString(node1);
		if (x == -1) {
			strcpy(Name[Index], node1);
			x = Index;
			Index += 1;
		}
		 y = searchString(node2);
		if (y == -1) {
			strcpy(Name[Index], node2);
			y = Index;
			Index += 1;
		}
		Path[x][y] = Path[y][x] = 1;
	}
	scanf("%s %s", node1, node2);
	x = searchString(node1);
	y = searchString(node2);
	for (i = 0; i < Index; i++) {
		Level[i] = INF;
	}
	BFS(x);
	if (Case > 1)printf("\n");
	if (Level[y] == INF||y==-1) {
		printf("No route\n");
	}
	else {
		
		top = 0;
		Stack[top] = -1;
		while (y != x) {
			Stack[++top] = y;
			y = Parent[y];
		}
		Stack[++top] = y;
		int j;
		//("%s   ", Name[Stack[top]]);
		for (j = top; j > 1; j--) {
			printf("%s %s\n", Name[Stack[j]], Name[Stack[j - 1]]);
		}
	}
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	Case = 0;
	while (scanf("%d", &N) == 1) {
		Case++;
		//printf("%d \n", N);
		readCase();
	}
	return 0;
 }