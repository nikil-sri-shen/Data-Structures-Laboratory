#include<iostream>
using namespace std;
class CDFS
{
	int noOfVertices;
	int noOfEdges;
	int* visited;
	int** adjMatrix;
public:
	CDFS(int, int);
	void performDFS(int);
	void createGraph();
};
CDFS::CDFS(int n,int e)
{
	noOfVertices = n;
	noOfEdges = e;
	visited = new int[noOfVertices+1];
	adjMatrix = new int*[noOfVertices+1];
	for (int i = 1; i < noOfVertices+1; i++)
	{
		adjMatrix[i] = new int[noOfVertices+1];
		visited[i] = 0;
		for (int j = 1; j < noOfVertices+1; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}
void CDFS::createGraph()
{
	int no, a, b;
	cout << "\nEnter the vertices for which they have common edges:";
	for (int i = 1; i <= noOfEdges; i++)
	{
		cout << "\nEnter the adjacent vertices of the edge " << i << ":\n";
		cin >> a >> b;
		adjMatrix[a][b] = adjMatrix[b][a] = 1;
	}
}
void CDFS::performDFS(int i)
{
	cout << i << "\t";
	visited[i] = 1;
	for (int j = 1; j < noOfVertices+1; j++)
	{
		if (adjMatrix[i][j] == 1)
			if (!visited[j])
				performDFS(j);
	}
}
int main()
{
	int ch, n, e;
	cout << "\nEnter the no.of Vertices:";
	cin >> n;
	cout << "\nEnter the no.of Edges:";
	cin >> e;
	CDFS obj(n, e);
	obj.createGraph();
	while (1)
	{
		cout << "\n1.DFS.";
		cout << "\n2.Exit.";
		cout << "\nEnter your choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int x;
			cout << "Enter the Vertice at which the dfs has to be performed: ";
			cin >> x;
			obj.performDFS(x);
			break;
		}
		case 2:
		{
			exit(0);
			break;
		}
		}
	}
}
