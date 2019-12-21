#include<stdio.h>
#define S 1001
int G[S][S];
int R, C, T;
int dr, dc;
int F, Ro;
typedef struct Node {
	int x, y, dist;
}Node;
Node Q[S*S];
void push(int x, int y, int d) {
	G[x][y] = 1;
	Q[Ro].x = x;
	Q[Ro].y = y;
	Q[Ro].dist = d;
	Ro++;
}
Node pop() {
	return Q[F++];
}
int isEmpty() {
	if (F == Ro)return 1;
	return 0;
}
void initGrid() {
	F = 0; Ro = 0;
	int i, j;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			G[i][j] = 0;
		}
	}
}

void BFS(int x, int y) {
	push(x, y, 0);
	Node q;
	while (!isEmpty()) {
		q = pop();
		if (q.x == dr&&q.y == dc) {
			printf("%d\n", q.dist);
			break;
		}
		if (q.x + 1<R && !G[q.x + 1][q.y]) {
			push(q.x + 1, q.y, q.dist + 1);
		}
		if (q.y + 1 <C && !G[q.x][q.y + 1]) {
			push(q.x, q.y + 1, q.dist + 1);
		}
		if (q.x - 1 >= 0 && !G[q.x - 1][q.y]) {
			push(q.x - 1, q.y, q.dist + 1);
		}
		if (q.y - 1 >= 0 && !G[q.x][q.y - 1]) {
			push(q.x, q.y - 1, q.dist + 1);
		}
	}
}
void solveCase(int x, int y) {
	BFS(x, y);
}
int main() {
	while (scanf("%d %d", &R, &C) == 2 && (R + C)) {
		scanf("%d", &T);
		int t, r, c, i, sr, sc;
		initGrid();
		while (T--) {
			scanf("%d %d", &r, &t);
			for (i = 1; i <= t; i++) {
				scanf("%d", &c);
				G[r][c] = 1;
			}
		}
		scanf("%d %d", &sr, &sc);
		scanf("%d %d", &dr, &dc);
		solveCase(sr, sc);
	}
	return 0;
}