#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;
    int E;
    vector<vector<pair<int, int>>> adjList;

public:
    // constructor
    Graph(int V = 0, int E = 0) {
        this->V = V;
        this->E = E;
        adjList.resize(V);
    }

    // constructor that reads in a graph from a file
    Graph(string filename) {
        ifstream fin(filename);
        fin >> V >> E;
        adjList.resize(V);

        for (int i = 0; i < E; i++) {
            int u, v, w;
            fin >> u >> v >> w;
            addEdge(u, v, w);
        }

        fin.close();
    }

    // add edge to the graph
    void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w)); // assuming undirected graph
        E++;
    }

    // Kruskal's Minimum Spanning Tree Algorithm
    void minimumSpanningTree() {
        vector<pair<int, pair<int, int>>> edges;

        // create a vector of all edges
        for (int i = 0; i < V; i++) {
            for (auto j : adjList[i]) {
                int v = j.first;
                int w = j.second;
                edges.push_back(make_pair(w, make_pair(i, v)));
            }
        }

        // sort edges by weight
        sort(edges.begin(), edges.end());

        // initialize disjoint set data structure
        vector<int> parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0;
        vector<pair<int, int>> mstEdges;

        // iterate through all edges and add to MST if they don't create a cycle
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            int setU = find(parent, u);
            int setV = find(parent, v);

            if (setU != setV) {
                mstWeight += w;
                mstEdges.push_back(make_pair(u, v));
                Union(parent, setU, setV);
            }
        }

        // print MST weight and edges
        cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
        cout << "Edges in Minimum Spanning Tree:" << endl;
        for (auto edge : mstEdges) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }

private:
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, int u, int v) {
        int setU = find(parent, u);
        int setV = find(parent, v);
        parent[setU] = setV;
    }
};