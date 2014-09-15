#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAXN 100*2+10

map<string, int> node;
vector<int> G[MAXN];
int color[MAXN];

void create_node(string s)
{
    if (!node.count(s))
    {
        int t = node.size() + 1;
        node[s] = t;
    }
}

bool bipartite(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (color[v] == color[u])  return false;
        if (!color[v])
        {
            color[v] = 3 - color[u];
            if (!bipartite(v))  return false;
        }
    }
    return true;
}
int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);
    freopen("A-small-2-attempt0.in", "r", stdin);
    freopen("A-small-2.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        int n;
        scanf("%d", &n);
        node.clear();
        for (int i = 0; i < MAXN; i++)
            G[i].clear();
        for (int i = 0; i < n; i++)
        {
            string name1, name2;
            cin >> name1 >> name2;
            create_node(name1);
            create_node(name2);
            G[node[name1]].push_back(node[name2]);
            G[node[name2]].push_back(node[name1]);
        }
        memset(color, 0, sizeof(color));
        color[1] = 1;
        if (bipartite(1))  printf("Case #%d: Yes\n", kase);
        else  printf("Case #%d: No\n", kase);
    }
    return 0;
}