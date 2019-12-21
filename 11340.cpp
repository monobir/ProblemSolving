#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main() {
	int t;
	freopen("input.txt", "r", stdin);
	map<char, double> data;
	map<char, double>::iterator p;
	int n, m;
	double sum = 0, total,val;
	char ch;
	char word[10005];
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		scanf("%d", &n);
		while (n--) {
			cin >> ch >> val;
			data[ch] = val;
		}
		scanf("%d", &m);
		cin.ignore();
		while (m--) {
			int i;
			fgets(word, 10005, stdin);
			for (i = 0; word[i]; i++) {
				p = data.find(word[i]);
				if (p != data.end()) {
					sum += p->second;
				}
			}
		}
		sum /= 100;
		printf("%0.2lf$\n", sum);
		data.clear();
	}
	return 0;
}
