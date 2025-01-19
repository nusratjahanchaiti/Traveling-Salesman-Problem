#include <bits/stdc++.h>
using namespace std;

const int INF = 1999;

// Function to solve the Traveling Salesman Problem (TSP) using Dynamic Programming
int tspDP(vector<vector<int>>& graph, int s)
{
    int V = graph.size();
    int n = (1 << V); // Total number of subsets (2^V)

    // dp[mask][i] stores the minimum cost to visit all nodes in 'mask' and end at node 'i'
    vector<vector<int>> dp(n, vector<int>(V, INF));
    dp[1 << s][s] = 0;   // Starting at 's'

    // Iterate over all subsets of vertices
    for (int mask = 0; mask < n; mask++) {
        for (int u = 0; u < V; u++) {
            if (mask & (1 << u)) { // If u is in the current subset
                for (int v = 0; v < V; v++) {
                    if (!(mask & (1 << v))) { // If v is not in the current subset
                        int nextMask = mask | (1 << v);
                        dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + graph[u][v]);
                    }
                }
            }
        }
    }

    // Find the minimum cost to complete the tour and return to the starting vertex
    int min_cost = INF;
    for (int u = 0; u < V; u++) {
        if (u != s) {
            min_cost = min(min_cost, dp[n - 1][u] + graph[u][s]);
        }
    }

    return min_cost;
}

int main()
{
    int V;
    cout << "Enter the number of vertices (cities): ";
    cin >> V;

    // Validate the number of vertices
    if (V <= 1) {
        cout << "Number of vertices must be greater than 1." << endl;
        return 1;
    }

    // Initialize the graph
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "\nEnter the adjacency matrix (enter 0 for no self-loops):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                graph[i][j] = 0; // Ensure no self-loops
                continue;
            }
            cout << "Edge weight from vertex " << i << " to vertex " << j << ": ";
            cin >> graph[i][j];
            if (graph[i][j] < 0) {
                cout << "Edge weight cannot be negative. Please re-enter." << endl;
                j--; // Repeat input for the same edge
            }
        }
    }

    cout << "\nThe adjacency matrix is:\n";
    for (const auto& row : graph) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << endl;
    }

    int s;
    cout << "\nEnter the starting vertex: ";
    cin >> s;

    // Validate starting vertex
    if (s < 0 || s >= V) {
        cout << "Invalid starting vertex. Must be between 0 and " << V - 1 << "." << endl;
        return 1;
    }

    // Solve TSP and print the result
    int result = tspDP(graph, s);
    cout << "\nThe minimum cost of the Traveling Salesman Problem is: " << result << endl;

    return 0;
}
