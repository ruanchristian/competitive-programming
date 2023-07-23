#include <bits/stdc++.h>

// Algoritmos de Busca em Grafos = DFS e BFS

using namespace std;

#define MAX 50 

vector<int> g[MAX];
bool visitado[MAX];

void dfs(int x) {
    visitado[x] = 1;

    for (auto v : g[x]) {
        if (!visitado[v]) dfs(v);
    }
}

void bfs(int x) {
    memset(visitado, 0, sizeof visitado);

    queue<int> fila;
    visitado[x] = 1;
    fila.push(x);

    while (fila.size()) {
        int u = fila.front();
        fila.pop();
        
      //  cout << u << " ";

        for (int v : g[u]) {
            if (!visitado[v]) {
                visitado[v] = 1;
                fila.push(v);
            }
        }
    }
}

int main() {
    g[1].push_back(2);
    g[2].push_back(1);
    g[2].push_back(3);
    g[2].push_back(2);
    g[3].push_back(1);

    // 1 <-> 2
    // 2 <-> 3
    // 3 -> 1

    dfs(1);
    bfs(1);
}