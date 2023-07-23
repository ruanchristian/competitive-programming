#include <bits/stdc++.h>

// Representação de Grafos

using namespace std;

#define MAXN 6

typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> edges;

// 1º Matriz de Adjacência - Complexidade: O(V^2)
// Onde V é o número de vértices
void mat_adjacencia() {
    int mat_adj[MAXN][MAXN];
    mat_adj[1][2] = mat_adj[2][1] = 2;
    mat_adj[2][4] = mat_adj[4][2] = 1;
    mat_adj[4][5] = mat_adj[5][4] = 3;
    mat_adj[3][4] = mat_adj[4][3] = 7;

    for (int u = 1; u <= 5; u++) {
        for (int v = 1; v <= 5; v++)
            cout << "Aresta: (" << u << " -> " << v << ") Peso: " << mat_adj[u][v] << '\n';
    }
}

// 2º Lista de Adjacência - Complexidade O(V+E)
// Onde E é o número de vértices
void list_adjacencia() {
    vector<pii> g[MAXN];

    g[1].emplace_back(2, 2);
    g[2].emplace_back(1, 2);
    g[2].emplace_back(4, 1);
    g[4].emplace_back(2, 1);
    g[4].emplace_back(5, 3);
    g[5].emplace_back(4, 3);
    g[3].emplace_back(4, 7);
    g[4].emplace_back(3, 7);

    for (int i = 1; i <= 5; i++) {
        cout << "Vértice " << i << '\n' << "Ligado a: ";
        for (auto p : g[i])
            cout << "(Vértice = " << p.first << " Peso: " << p.second << ")";
        cout << "\n\n";
    }
}

// 3º Vetor de Arestas
// {w, {u, v}}
void vetor_arestas() {
    vector<edges> v;

    v.push_back({2, {1, 2}});
    v.push_back({2, {2, 1}});
    v.push_back({1, {2, 4}});
    v.push_back({1, {4, 2}});
    v.push_back({3, {4, 5}});
    v.push_back({3, {5, 4}});
    v.push_back({7, {3, 4}});
    v.push_back({7, {4, 3}});

    cout << "Vetor de Arestas:" << '\n';

    for (auto edge : v) {
        cout << "(" << edge.second.first << " -> " << edge.second.second <<  ") Peso: " << edge.first << "\n";
    }
}

int main() {
    mat_adjacencia();
    cout << "-------------------------\n";
    list_adjacencia();
    cout << "-------------------------\n";
    vetor_arestas();
}
