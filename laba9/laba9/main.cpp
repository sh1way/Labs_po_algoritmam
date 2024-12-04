#include <iostream>
#include <locale>
#include <queue>
#include <string>
#include <climits>

using namespace std;

queue <int> Q;

int** createG(int nG) {
    int** G = (int**)malloc(nG * sizeof(int*));
    for (int i = 0; i < nG; i++) {
        G[i] = (int*)malloc(nG * sizeof(int));
    }

    for (int i = 0; i < nG; i++) {
        for (int j = i; j < nG; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int** G, int size, int s, int* dist) {
    Q.push(s);
    dist[s] = 0;

    cout << "Level vartex:" << endl;

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        for (int i = 0; i < size; i++) {
            if (G[s][i] == 1 && dist[i] == INT_MAX) {
                Q.push(i);
                dist[i] = dist[s] + G[s][i];
                cout << dist[i] << " ";
            }
            
        }
    }
}

void main(void) {
    setlocale(LC_ALL, "Russian");

    int** G = NULL;
    int nG, s;

    cout << "Enter size graph: ";
    cin >> nG;
    cout << endl;

    G = createG(nG);

    printG(G, nG);

    cout << "Start vertex: ";
    cin >> s;
    cout << endl;

    int* dist = NULL;
    dist = (int*)malloc(nG * sizeof(int));

    for (int i = 0; i < nG; i++) {
        dist[i] = INT_MAX;
    }

    BFS(G, nG, s, dist);
}