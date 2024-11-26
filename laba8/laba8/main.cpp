#include <iostream>
#include <locale>
#include <queue>
#include <string>

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

void BFS(int** G, int size, int s, int* vis) {
    cout << "Порядок прохода:" << endl;
    Q.push(s);
    vis[s] = 1;
    cout << s << " ";

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        for (int i = 0; i < size; i++) {
            if (G[s][i] == 1 && vis[i] == 0) {
                Q.push(i);
                vis[i] = 1;
                cout << i << " ";
            }
        }
    }
}

void main(void) {
    setlocale(LC_ALL, "Russian");

    int** G = NULL;
    int nG, s;

    cout << "Введите размер графа: ";
    cin >> nG;
    cout << endl;

    G = createG(nG);

    printG(G, nG);

    cout << "Вершина старта: ";
    cin >> s;
    cout << endl;

    int* vis = NULL;
    vis = (int*)malloc(nG * sizeof(int));

    for (int i = 0; i < nG; i++) {
        vis[i] = 0;
    }

    BFS(G, nG, s, vis);
}