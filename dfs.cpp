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

#define V 100
#define INF 1e7
#define DFS_GRAY 2

vi visited,parent; // visited.assign(V,DFS_WHITE); parent.assign(V,0);
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

vi topoSort;

void topologicalSort(int u) {
    visited[u] = DFS_BLACK;
    for (size_t i = 0; i < AdjList[u].size(); ++i) {
        ii v = AdjList[u][i];
        if (visited[v.first] == DFS_WHITE)
            topologicalSort(v.first);
    }
    topoSort.push_back(u);
}

int noofConnectedComponents() {
    int no = 0;
    visited.assign(V, DFS_WHITE);
    for (size_t i = 0; i < V; ++i) {
        if (visited[i] == DFS_WHITE) {
            no++;
            dfs(i);
        }
    }
    return no;
}

void checkGraph(int u){
    visited[u]=DFS_GRAY;
    for (size_t i = 0; i < AdjList[u].size(); ++i) {
        ii v = AdjList[u][i];
        if (visited[v.first] == DFS_WHITE){
            parent[v.first]=u;
            checkGraph(v.first);
        }
        else if(visited[v.first]==DFS_GRAY){
            if(v.first==parent[u])
              cout<<"Bidirectional Edge\n";
            else
                cout<<"Back Edge (u,v): "<<u<<" "<<v.first<<"\n";
        }
        else if(visited[v.first]==DFS_BLACK){
            cout<<"Cross/Forward Edge (u,v): "<<u<<" "<<v.first<<"\n";
        }
    }
    visited[u]=DFS_BLACK;
}

vi dfs_low,articulationPoints;
int dfsNumber,dfsRoot,rootChildren;

/*
 *  int main(){
 *      dfsNumber = 0;
 *      visited.assign(V,DFS_WHITE);
 *      dfs_low.assign(V,0);
 *      parent.assign(V,0);
 *      articulationPoints.assign(V,0);
 *      dfsRoot= u;
 *      articulationPoint_Bridge(u);
 *  }
 *
 */

void articulationPoint_Bridge(int u ){
    dfs_low[u]= visited[u]=dfsNumber++;
    for (size_t i = 0; i < AdjList[u].size(); ++i) {
        ii v = AdjList[u][i];
        if(visited[v.first]==DFS_WHITE){
            parent[v.first]=u;
            if(u == dfsRoot) rootChildren++;
            articulationPoint_Bridge(v.first);

            if(dfs_low[v.first]>=visited[u]){
                articulationPoints[u]= true;
            }
            if(dfs_low[v.first]>visited[u])
                cout<<"Edge ("<<u<<" , "<<v.first<<" ) is a bridge";
            dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
        }
        else if(v.first!= parent[u]){
            dfs_low[u]=min(dfs_low[u],visited[v.first]);
        }
    }
}

