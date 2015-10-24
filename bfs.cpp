#include<bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> ll;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<int> vi;

#define V 100
#define INF 1e7
vi distance(V, (int)INF);
vi parent;
vector<vii> AdjList;

/*
 * BFS - O(V+E) - adjacency list
 * Bipartite Graph properties
 * 1. A bipartite graph is a graph that does not contain any odd-length cycles
 * 2. If a bipartite graph is not connected, it may have more than one bipartition
 * 3. If |U|=|V|, that is, if the two subsets have equal cardinality, then G is called a balanced bipartite graph
 * 4. If all vertices on the same side of the bipartition have the same degree, then G is called biregular.
 * 5.
 */
void bfs(int s){
    distance[s]=0;
    queue<int> q;
    q.push(s);
    parent.assign(V,-1);
    bool isBipartite =true;

    while(!q.empty()){
        int u = q.front();q.pop();
        for (size_t i = 0; i <AdjList[u].size() ; ++i) {
            ii v= AdjList[u][i];
            if(distance[v.first]==INF){
                distance[v.first]=distance[u]+1;
                parent[v.first]=u;
                q.push(v.first);
            }
            else if(distance[v.first]%2==distance[u]%2)
                isBipartite=false;
        }
    }
}