#include<stdio.h>

int N, Ans, Case;
char Name[101][35];
char sortedName[101][35];
int Path[101][101];
int Pre[101];
int V[101];

void initGraph()
{
	int i, j;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			Path[i][j] = 0;
		}
	}
	for (i = 0; i<N; i++)
	{
		Pre[i] = 0;
	}
}

void initVis()
{
	int i;
	for (i = 0; i<N; i++)
	{
		V[i] = 0;
	}
}

int stringSearch(char s[])
{
	int i, j, flag;
	for (i = 0; i<N; i++)
	{
		flag = 1;
		for (j = 0; Name[i][j] && s[j]; j++)
		{
			if (Name[i][j] != s[j])
			{
				flag = 0;
				break;
			}
		}
		if (Name[i][j] != s[j])
		{
			flag = 0;
		}
		if (flag)
		{
			return i;
		}
	}
	return -1;
}

void stringSwap(int i, int j)
{
	char s[100];
	int k;
	for (k = 0; sortedName[i][k]; k++)
	{
		s[k] = sortedName[i][k];
	}
	s[k] = '\0';
	for (k = 0; sortedName[j][k]; k++)
	{
		sortedName[i][k] = sortedName[j][k];
	}
	sortedName[i][k] = '\0';
	for (k = 0; s[k]; k++)
	{
		sortedName[j][k] = s[k];
	}
	sortedName[j][k] = '\0';
}

int stringCompare(int i, int j)
{
	int k;
	for (k = 0; sortedName[i][k] && sortedName[j][k]; k++)
	{
		if (sortedName[i][k]<sortedName[j][k])
		{
			return 0;
		}
		else if (sortedName[i][k]>sortedName[j][k])
		{
			return 1;
		}
	}
}

void stringCopyToSorted(int i, char s[])
{
	int j;
	for (j = 0; s[j]; j++)
	{
		sortedName[i][j] = s[j];
	}
	sortedName[i][j] = '\0';
}

void stringCopy(int i, char s[])
{
	int j;
	for (j = 0; s[j]; j++)
	{
		Name[i][j] = s[j];
	}
	Name[i][j] = '\0';
}

void sortString()
{
	int i, j, k;
	char s[101];
	for (i = 0; i<Ans; i++)
	{
		for (j = 0; j<Ans - 1; j++)
		{
			if (stringCompare(j, j + 1))
			{
				stringSwap(j, j + 1);
			}
		}
	}
}

void readCase()
{
	char s[35];
	char s1[35];
	int i, x, y, m;
	for (i = 0; i<N; i++)
	{
		scanf("%s", &s);
		stringCopy(i, s);
	}
	scanf("%d", &m);
	for (i = 0; i<m; i++)
	{
		scanf("%s %s", &s, &s1);
		x = stringSearch(s);
		y = stringSearch(s1);
		Path[x][y] = Path[y][x] = 1;
	}
}

void solve(int i)
{
	V[i] = 1;
	int j;
	for (j = 0; j<N; j++)
	{
		if (Path[i][j] == 1 && V[j] == 0)
		{
			solve(j);
		}
	}
}

void solveCase()
{
	int i, j, cnt, flag, a;
	for (i = 0; i<N; i++)
	{
		cnt = 0;
		for (j = 0; j<N; j++)
		{
			if (Path[i][j] == 1)
			{
				cnt++;
			}
		}
		if (cnt>1)
		{
			Pre[i] = 1;
		}
	}
	for (i = 0; i<N; i++)
	{
		if (Pre[i] == 1)
		{
			initVis();
			V[i] = 1;
			for (j = 0; j<N; j++)
			{
				if (Path[i][j] == 1)
				{
					solve(j);
					flag = 0;
					for (a = 0; a<N; a++)
					{
						if (Path[i][a] == 1 && V[a] == 0)
						{
							flag = 1;
							break;
						}
					}
					break;
				}
			}
			if (flag == 0)
			{
				Pre[i] = 0;
			}
		}
	}
	Ans = 0;
	for (i = 0; i<N; i++)
	{
		if (Pre[i] == 1)
		{
			stringCopyToSorted(Ans, Name[i]);
			Ans++;

		}
	}

	sortString();
}

void printCase()
{
	int i;
	if (Case)
	{
		printf("\n");
	}
	printf("City map #%d: %d camera(s) found\n", ++Case, Ans);
	for (i = 0; i<Ans; i++)
	{
		printf("%s\n", sortedName[i]);
	}
}

int main()
{

	Case = 0;
	while (scanf("%d", &N) == 1)
	{
		if (N == 0)
		{
			break;
		}
		initGraph();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
