#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
	int V;
	list<int>* adj;
	bool isCycle(int v,bool * visited,bool * recursive)
	{
		if(visited[v] == false)
		{
			visited[v] = true;
			recursive[v] = true;
			list<int>::iterator itr;
			for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
			{
				if(!visited[*itr] && isCycle(*itr,visited,recursive))
					return true;
				else if(recursive[*itr] == true)
					return true;
			}
		}
		recursive[v] = false;
		return false;
	}
public:
	Graph(int V)
	{
		this->V  = V;
		adj = new list<int>[V];
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}
	bool isCycle()
	{
		bool *visited = new bool[V];
		bool *recursive = new bool[V];
		for(int i = 0;i<V;i++)
		{
			visited[i] = false;
			recursive[i] = false;
		}
		for(int i = 0;i<V;i++)
		{
			if(isCycle(i,visited,recursive))
				return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}