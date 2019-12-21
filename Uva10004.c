#include<stdio.h>
int Node;
int Path[201][201];
int Edge;
int color[201];
void initPath() {
	int i, j;
	for (i = 0; i < Node; i++)for (j = 0; j < Node; j++)Path[i][j] = 0;
}
void readCase() {
	scanf("%d", &Edge);
	int i,u,v;
	initPath();
	for (i = 0; i < Edge; i++) {
		scanf("%d %d", &u, &v);
		Path[u][v] = Path[v][u] = 1;
	}
}
void initColor() {
	int i;
	for (i = 0; i < Node; i++)color[i] = 0;
}
void printPath() {
	int i, j;
	for (i = 0; i < Node; i++)for (j = 0; j < Node; j++) {
		printf("%d ", Path[i][j]);
	}
	printf("\n");
}
int biColor(int i, int c) {
	int j;
	color[i] = c;
	for (j = 0; j < Node; j++) 
		if (1 == Path[i][j]) {
			if (0 == color[j]) {
				if (0 == biColor(j, 3 - c))
					return 0;
			}
			else if (color[j] == c)
				return 0;
	}
	return 1;
}
int main() {
	freopen("input.txt","r",stdin);
	while (1 == scanf("%d", &Node)) {
		if (Node == 0)break;
		readCase();
		initColor();
		if (1==biColor(0, 1))
		printf("BICOLORABLE.\n");
		else
		printf("NOT BICOLORABLE.\n");
	}
		return 0;
}