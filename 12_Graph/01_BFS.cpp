#include <iostream>
#include <queue>

using namespace std;

// Function to perform Breadth-First Search (BFS) traversal
void BFS(int vtx, int A[][8], int n)
{
    // Create a queue to store vertices to be visited in the order they are discovered
    queue<int> Q;

    // Array to keep track of visited vertices to avoid revisiting them
    int visited[8] = {0};

    // Mark the initial vertex as visited and print it
    cout << vtx << ", " << flush; // Visit the starting vertex
    visited[vtx] = 1;             // Mark it as visited to avoid revisiting
    Q.emplace(vtx);               // Enqueue the starting vertex to begin the traversal

    // Continue exploring until the queue is empty, meaning all reachable vertices have been visited
    while (!Q.empty())
    {
        // Dequeue the next vertex to explore from the front of the queue
        int u = Q.front();
        Q.pop(); // Remove the vertex from the queue after dequeuing

        // Explore all adjacent vertices of the current vertex
        for (int v = 1; v <= n; v++)
        {
            // Check if there is an edge between u and v (A[u][v] == 1) and if v is not visited (visited[v] == 0)
            if (A[u][v] == 1 && visited[v] == 0)
            {
                // Mark v as visited to avoid revisiting it later
                cout << v << ", " << flush; // Visit and print the adjacent vertex
                visited[v] = 1;             // Mark it as visited
                Q.emplace(v);               // Enqueue the adjacent vertex to explore it later
            }
        }
    }
    cout << endl; // New line after visiting all vertices
}

int main()
{
    // Adjacency matrix representation of the graph where A[i][j] = 1 if there is an edge between vertices i and j
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    // Perform BFS traversal starting from vertex 1
    cout << "Vertex: 1 -> " << flush; // Indicate the starting vertex for the traversal
    BFS(1, A, 8);                     // Call the BFS function with vertex 1 as the starting point

    // Perform BFS traversal starting from vertex 4
    cout << "Vertex: 4 -> " << flush; // Indicate the starting vertex for the traversal
    BFS(4, A, 8);                     // Call the BFS function with vertex 4 as the starting point

    return 0;
}