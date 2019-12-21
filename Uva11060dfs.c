#include<stdio.h>
#include<string.h>
char Name[105][52];
int Path[105][105];
int visited[105];
int discover[105], finish[102];
int node[105];
int N, M, Case,time,ind;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 1; i <= n ; i++) 
		for (j = 1; j <= n - i; j++) {
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
				swap(&node[j],&node[j+1]);
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
		for (int j = 1; j <= N; j++) {
			printf("%d ", Path[i][j]);
		}
		printf("\n");
	}
}

void readCase() {
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%s", Name[i]);
	}
	scanf("%d", &M);
	char name1[52], name2[52];
	int x, y;
	while (M--) {
		scanf("%s %s", name1, name2);
		x = searchString(name1);
		y = searchString(name2);
		Path[x][y] = 1;
	}
	//print();
	//printf("\n");
}
void dfs(int x) {
	int j;
	visited[x] = 1;
	time++;
	discover[x] = time;
	for (j = 1; j <= N; j++) {
		if (Path[x][j] && (!visited[j])) {
			dfs(j);
		}
	}
	time++;
	finish[x] = time;
	node[ind++] = x;
}
void solveCase() {
	int i,j;
	time = 0; ind = 1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (Path[i][j] && !visited[j]) {
				dfs(i);
			}
		}
	}
	/*for (i = 1; i <= N; i++) {
		printf("%d ", finish[i]);
	}
	printf("\n");
	for (i = 1; i <= N; i++) {
		printf("%d ", node[i]);
	}
	printf("\n");*/
	bubbleSort(finish, N);
	/*for (i = 1; i <= N; i++) {
		printf("%d ", finish[i]);
	}
	printf("\n");
	for (i = 1; i <= N; i++) {
		printf("%d ", node[i]);
	}
	printf("\n");*/
}
void printCase() {
	int i;
	printf("Case #%d: Dilbert should drink beverages in this order:", Case);
	for (i = 1; i <= N; i++) {
		int z = node[i];
		printf(" %s", Name[z]);
	}
	printf(".\n\n");
}
int main() {
	freopen("input.txt", "r", stdin);
	Case = 0;
	while (1 == scanf("%d", &N)) {
		Case++;
		readCase();
		solveCase();
		printCase();
	}

	return 0;
}