#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;


int T, N, M;

vector<int>Path[100001];

void readCase() {
	int u, v;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &u, &v);
		Path[u].push_back(v);
	}
}
int main() {
	freopen("input.txt","r",stdin);
	scanf("%d", &T);
	while (T--) {
		readCase();
		//solveCase();
		//printCase();
	}
	return 0;
}
