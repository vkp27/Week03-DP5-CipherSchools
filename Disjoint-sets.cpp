#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    int *parent;
    int N;

public:
    DisjointSet(int N)
    {
        this->N = N;
        this->parent = new int[this->N];
        for (int i = 0; i < N; i++)
            this->parent[i] = i;
    }

    //returns true,if A and B are connected, else it will return false.
    bool Find(int A, int B)
    {
        return (this->parent[A] == this->parent[B]);
    }

    void Union(int A, int B)
    {
        int temp = this->parent[A];
        for (int i = 0; i < this->N; i++)
        {
            if (this->parent[i] == temp)
                this->parent[i] = this->parent[B];
        }
    }
};
