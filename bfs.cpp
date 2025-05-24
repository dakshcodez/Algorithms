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

int shortest_path_len(unordered_map<char, vector<char>> &graph, char start, char goal) {
    queue<char> q;
    unordered_set<char> visited;
    int path_length = 0;
    q.push(start);

    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++){
            char node = q.front();
            q.pop();

            if (visited.count(node)) continue;

            if (node == goal){
                return path_length;
            }

            for (char neighbour: graph[node]) {
                if (!visited.count(neighbour)){
                    q.push(neighbour);
                }
            }
        }
        path_length++;
    }
    return -1;
}

int main(){
   unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'C'}},
        {'C', {'A', 'E'}},
        {'D', {'B'}},
        {'E', {'C', 'D'}}
    };

    bfs(graph, 'A');
    cout<<endl;
    int res = shortest_path_len(graph, 'A', 'D');
    cout<<res<<endl;
    return 0;
}
    
