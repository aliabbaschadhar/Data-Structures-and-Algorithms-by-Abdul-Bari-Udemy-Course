#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Function to find the vertex with the minimum key value that is not included in MST yet
int minKey(vector<int> &key, vector<bool> &mstSet, int V)
{
    int min = INT_MAX, minIndex;

    // Iterate through all vertices to find the minimum key
    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the constructed MST stored in parent[]
void printMST(vector<int> &parent, vector<vector<int>> &graph, int V)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

// Function to implement Prim's algorithm to find the minimum spanning tree
void primMST(vector<vector<int>> &graph, int V)
{
    // Array to store constructed MST
    vector<int> parent(V);

    // Key values used to pick minimum weight edge in cut
    vector<int> key(V, INT_MAX);

    // To represent set of vertices included in MST
    vector<bool> mstSet(V, false);

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as first
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        // Only update the key if the graph[u][v] is smaller than the current key[v]
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

int main()
{
    // Number of vertices in the graph
    int V = 5;

    // Graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    // Call the function to calculate and print the MST
    primMST(graph, V);

    return 0;
}
