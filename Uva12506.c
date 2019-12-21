#include<stdio.h>
#include<malloc.h>

#define CHARtoINT(c) ((int)c-(int)'a')


typedef struct trieStruct {
	struct trieStruct *child[26];
	int isLeaf;
	int count;
}TRIE;


TRIE *createNode() {
	TRIE *newNode;
	newNode = (TRIE *)malloc(sizeof(TRIE));
	int i;
	for (i = 0; i < 26; i++) {
		newNode->child[i] = NULL;
	}
	newNode->isLeaf = 0;
	newNode->count = 0;
	return newNode;
}

void insert(TRIE *root, char word[]) {
	int i, index;
	TRIE *curNode = root;
	for (i = 0; word[i]; i++) {
		index = CHARtoINT(word[i]);
		if (NULL == curNode->child[index]) {
			curNode->child[index] = createNode();
		}
		curNode->count++;
		curNode = curNode->child[index];

	}
	curNode->isLeaf = 1;
}

int search(TRIE *root, int c) {
	int index;
	TRIE *node;
	for (index = 0; index < 26; index++) {
		if (root->child[index] != NULL) {
			if (root->child[index]->count == 1) {
				c += 1;
			}
			else {
				c += search(root->child[index], c + root->child[index]->count);
			}
		}
	}
	return c;
}

void print(TRIE *root, char word[], int len) {
	int index, i;
	if (root->isLeaf) {
		word[len] = '\0';
		printf("%s\n", word);
	}

	for (index = 0; index < 26; index++) {
		if (root->child[index]) {
			word[len] = 'a' + index;
			print(root->child[index], word, len + 1);
		}
	}
}

int main() {
	TRIE *root;
	char s[1000001];
	char word[1000001];
	root = createNode();
	int t, n,i;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", s);
			insert(root, s);
		}
		print(root, word, 0);
		//int ans = search(root, 0);
		//printf("%d\n", ans);
	}
	return 0;
}