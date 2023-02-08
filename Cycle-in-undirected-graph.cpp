#include <iostream>
#include <list>
using namespace std;

class graph
{
private:
	int V;
	list<int>* adj;
	bool isCyclicUtil(int v,bool visited[],int parent)
	{
		visited[v] = true;
		list<int>::iterator itr;
		for(itr = adj[v].begin();itr != adj[v].end(); itr++)
		{
			if(visited[*itr] == false)
			{
				if(isCyclicUtil(*itr,visited,-1))
				{
					return true;
				}
			}else if(*itr != parent)
			{
				return true;
			}
		}
		return false;
	}
public:
	graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	bool isCyclic()
	{
		bool* visited = new bool[V];
		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}

		for (int i = 0; i < V; ++i)
		{
			if(visited[i] == false){
				if(isCyclicUtil(i,visited,-1)){
					return true;
				}
			}
		}
		return false;
	}
	
};


int main()
{
    return 0;
}