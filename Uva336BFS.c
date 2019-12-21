#include<stdio.h>
#define S 35
#define INF 99999
int N[S];
int Path[S][S];
int NC,i;
int F, R;
int Q[S*S];
int Level[S];
int Count;
int sc, ttl;
int Case;
void initQ() {
	F = R = 0;
}
void push(int node) {
	Q[R++] = node;
}
int pop() {
	return Q[F++];
}
int isEmpty() {
	if (R == F)return 1;
	return 0;

}
void initLevel() {
	int j;
	for (j = 0; j < i; j++) {
		Level[j] = INF;
	}
}
void BFS(int src) {
	initQ();
	int u, j;
	push(src);
	Level[src] = 0;
	while (!isEmpty()) {
		u = pop();
		for (j = 0; j < i; j++) {
			if (Path[u][j] && Level[j] == INF) {
				Level[j] = Level[u] + 1;
				push(j);
			}
		}
	}
}

typedef struct Node {
	int node, index;
}Node;
Node X[S];

int search(int n) {
	int j;
	for (j = 0; j < i; j++) {
		if (N[j] == n)return j;
	}
	return -1;
}
void initPath() {
	int j, k;
	for (j = 0; j < S; j++ ) {
		Level[j] = INF;
		for (k = 0; k < S; k++) {
			Path[j][k] = 0;
		}
	}
}
void readCase() {
	int u, v, x, y;
	initPath();
	i = 0;
	while (NC--) {
		scanf("%d %d", &u, &v);
		x = search(u);
		if (x == -1) {
			N[i++] = u;
			x = i - 1;
			X[x].node = u;
			X[x].index = x;
		}
		y = search(v);
		if (y == -1) {
			N[i++] = v;
			y = i - 1;
			X[y].node = v;
			X[y].index = y;
		}
		Path[x][y] = Path[y][x] = 1;
	}
}
void printCase() {
	printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case, Count, sc, ttl);
}
void solveCase() {
	int z;
	while (scanf("%d %d", &sc, &ttl)==2) {
		if (sc==0&&ttl==0)
			break;
		else {
			Case++;
			z = search(sc);
			if (z != -1) {
				initLevel();
				BFS(X[z].index);
				int j; Count = 0;
				for (j = 0; j < i; j++) {
					if (Level[j] > ttl)Count++;
				}
				printCase();
			}
			else {
				Count = i;
				printCase();
			}
		}
	}
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	Case = 0;
	while (scanf("%d", &NC) == 1 && NC) {
		readCase();
		solveCase();
	}
	return 0;
}