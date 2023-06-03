#include <iostream>
#include "Graph.h"
#include <fstream>
using namespace std;

void F(Graph& Tree, int* colour, int n, int next)
{
	bool flag = 1;
	int i=0;
	while (flag && i < n)
	{
		if (Tree.check_edge(next, next) == colour[i])
			flag = 0;
		i++;
	}
	if (flag)
		cout << "-1 ";
	else 
		cout << i << " ";
	colour[next] = Tree.check_edge(next, next);
	for (int i = next+1; i < n; i++)
		if (Tree.check_edge(next, i) == 1)
			F(Tree, colour, n, i);
	colour[next] = 0;
}

int main()
{
	int n, c, m;
	cout << "Kolichestvo vershin: ";
	cin >> n; //вершины
	Graph Tree(n);
	int* colour = new int [n];
	cout << "\n Kolichestvo cvetov: ";
	cin >> c; //цвета
	for (int i = 1; i < n; ++i)
	{
		cout << "Vvedite nomer vershini, soedennennoy s " << i+1 << ": ";
		cin >> m;
		Tree.add_edge(m-1, i);
	}
	for (int i = 0; i < n; ++i)
	{
		int k=0;
		while (k<1 || k>c)
		{
			cout << "Vvedite nomer cveta vershini " << i+1 << ": ";
			cin >> k;
		}
		colour[i] = 0;
		Tree.add_edge(i,i,k);
	}
	F(Tree, colour, n, 0);
}