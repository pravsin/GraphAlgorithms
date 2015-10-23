#include<bits/stdc++.h>

using namespace std;
/*
 * DFS - Depth First Seacrh to search "deeper" in the graph whenever possible.
 *
 * Depth-first search explores edges out of the most recently discovered vertex that still has unexplored edges leaving it.
 * Once all of ’s edges have been explored, the search “backtracks” to explore edges
 * leaving the vertex from which was discovered. This process continues until we
 * have discovered all the vertices that are reachable from the original source vertex.
 * If any undiscovered vertices remain, then depth-first search selects one of them as
 * a new source, and it repeats the search from that source. The algorithm repeats this
 * entire process until it has discovered every vertex.
 *
 * Running time - V- no of vertices , E - No of edges
 * In case of Adjacency List - O(V+E)
 * In case of Adjacency matrix - O(V^2)
 */
typedef pair<long long, long long> ll;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vi visited;
vector<vii> AdjList;

void dfs_recursion(int u) {
    visited[u] = DFS_BLACK;
    for (size_t i = 0; i < AdjList[u].size(); ++i) {
        ii v = AdjList[u][i];
        if (visited[v.first] == DFS_WHITE)
            dfs_recursion(v.first);
    }
}

void dfs(int u) {
    stack<int> s;
    s.push(u);
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (visited[top] == DFS_WHITE) {
            for (size_t i = 0; i < AdjList[top].size(); ++i) {
                s.push(AdjList[top][i].first);
            }
            visited[top] = DFS_BLACK;
        }
    }
}


