// #ifndef cp_base
// #define cp_base

#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace graph_theory {
// Breadth-First Search
void bfs(int node, vector<vector<int>>& graph);
// Depth-First Search
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
         vector<int> path);
}  // namespace graph_theory
// #endif  // cp_base
