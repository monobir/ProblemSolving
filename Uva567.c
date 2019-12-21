#include<stdio.h>
int Path[21][21];
int V[21];
int T;
int F, R;
typedef struct Node {
	int node, dist;
}Node;

Node Q[21 * 21];
initQ() {
	F = R = 0;
	int i;
	for (i = 0; i < 21; i++) {
		V[i] = 0;
	}
}
int isEmpty() {
	if (F == R)return 1;
	return 0;
}
void initPath() {
	int i, j;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			Path[i][j] = 0;
		}
	}
}
void push(int n, int d) {
	Q[R].node = n;
	Q[R].dist = d;
	R++;
	V[n] = 1;
}

Node pop() {
	return Q[F++];
}
void BFS(int s, int d) {
	push(s, 0);
	Node q;
	while (!isEmpty()) {
		q = pop();
		if (q.node == d) {
			printf("%2d to %2d: %d\n", s, d,q.dist);
			break;
		}
		int j;
		for (j = 1; j <= 20; j++) {
			if (Path[q.node][j] && !V[j]) {
				push(j, q.dist + 1);
			}
		}
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	int x, i, y,caseno=0;
	while (scanf("%d",&x)==1) {
		initPath();
		int j;
		for (j = 1; j <= x; j++) {
			scanf("%d", &y);
			Path[1][y] = Path[y][1] = 1;
		}
		for (i = 2; i <= 19; i++)
		{
			scanf("%d", &x);
			for (j = 0; j<x; j++)
			{
				scanf("%d", &y);
				Path[i][y] = Path[y][i] = 1;
			}
		}
		int src, dest, n;
		scanf("%d", &n);
		printf("Test Set #%d\n", ++caseno);
		for (i = 0; i < n; i++) {
			scanf("%d %d", &src, &dest);
			initQ();
			BFS(src, dest);
		}
		printf("\n");
	}
	return 0;
}