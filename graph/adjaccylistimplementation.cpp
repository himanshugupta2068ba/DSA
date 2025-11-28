#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph; // undirected & unweighted
int v;

void add_edge(int src, int dest, bool bl_dir = true) {
    graph[src].push_back(dest);
    if (bl_dir) {
        graph[dest].push_back(src);
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "-> ";
        for (auto el : graph[i]) {
            cout << el << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> v;
    graph.resize(v);
    
    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;  // FIXED: input the edge
        add_edge(s, d);
    }

    display();
    return 0;
}
