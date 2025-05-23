#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(unordered_map<char, vector<char>> &graph, char start){
    queue<char> q;
    unordered_set<char> visited;
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        if (visited.count(node)) continue;

        cout<<node<<" ";
        visited.insert(node);

        for (char neighbour: graph[node]){
            if (!visited.count(neighbour)){
                q.push(neighbour);
            }
        }
    }
}

int main(){
   unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D'}},
        {'C', {'A', 'E'}},
        {'D', {'B'}},
        {'E', {'C'}}
    };

    bfs(graph, 'A');
    return 0;
}
    
