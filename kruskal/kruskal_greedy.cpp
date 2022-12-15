#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maximum = 1e6-1;
int root[maximum];
const int nodes = 4, edges = 5;

pair <long long, pair<int, int> > p[maximum];

int parent(int node)
{
    while(root[node] != node)
    {
        root[node] = root[root[node]];
        node = root[node];
    }
    return node;
}

void get_union(int num1, int num2)
{
    int root_of_num1 = parent(num1);
    int root_of_num2 = parent(num2);
    root[root_of_num1] = root[root_of_num2];
}

long long kruskal()
{
    int num1, num2;
    long long cost, minimum_cost = 0;
    for(int i = 0 ; i < edges ; ++i)
    {
        num1 = p[i].second.first;
        num2 = p[i].second.second;
        cost = p[i].first;
        if(parent(num1) != parent(num2))
        {
            minimum_cost += cost;
            get_union(num1, num2);
        }
    }
    return minimum_cost;
}

int main()
{
    int num1, num2;
    long long weight, cost, minimum_cost;
    for(int i = 0;i < maximum;++i)
    {
        root[i] = i;
    }
    p[0] = make_pair(15, make_pair(0, 1));
    p[1] = make_pair(33, make_pair(1, 2));
    p[2] = make_pair(51, make_pair(2, 3));
    p[3] = make_pair(70, make_pair(0, 2));
    p[4] = make_pair(42, make_pair(1, 3));
    sort(p, p + edges);
    minimum_cost = kruskal();
    cout << "Minimum cost is: "<< minimum_cost << endl;

    return 0;
}
