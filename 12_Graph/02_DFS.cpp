#include <iostream>
#include <stack>

using namespace std;

// Function to perform Depth-First Search (DFS) traversal using recursion
void DFS(int u, int A[][8], int n)
{
    // Use a static array to keep track of visited vertices across recursive calls
    static int visited[8]{0};

    // Check if the current vertex has not been visited yet
    if (visited[u] == 0)
    {
        // Print the current vertex and mark it as visited
        cout << u << ", " << flush;
        visited[u] = 1;

        // Explore all adjacent vertices of the current vertex
        for (int v = 1; v < n; v++)
        {
            // Check if there is an edge between u and v and if v is not visited
            if (A[u][v] == 1 && visited[v] == 0)
            {
                // Recursively call DFS on the adjacent vertex
                DFS(v, A, n);
            }
        }
    }
}

// Function to perform Depth-First Search (DFS) traversal using a stack
void dfs(int u, int A[][8], int n)
{
    // Initialize an array to keep track of visited vertices
    int visited[8]{0};

    // Create a stack to manage the vertices to be visited
    stack<int> stk;
    stk.emplace(u); // Push the starting vertex onto the stack

    // Continue exploring until the stack is empty
    while (!stk.empty())
    {
        // Pop the top vertex from the stack
        u = stk.top();
        stk.pop();

        // Check if the popped vertex has not been visited yet
        if (visited[u] != 1)
        {
            // Print the vertex and mark it as visited
            cout << u << ", " << flush;
            visited[u] = 1;

            // Explore all adjacent vertices of the current vertex in reverse order
            // This is done to maintain the Last-In-First-Out (LIFO) property of the stack,
            // ensuring that vertices are visited in the correct order for DFS traversal.
            for (int v = n - 1; v >= 0; v--)
            {
                // Check if there is an edge between u and v and if v is not visited
                if (A[u][v] == 1 && visited[v] == 0)
                {
                    // Push the adjacent vertex onto the stack to visit later
                    stk.emplace(v);
                }
            }
        }
    }
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

    // Perform DFS traversal starting from vertex 4 using recursion
    cout << "DFS Vertex: 4 -> " << flush;
    DFS(4, A, 8);
    cout << endl;

    // Perform DFS traversal starting from vertex 5 using a stack
    int u = 5;
    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs(u, A, 8);
    cout << endl;

    return 0;
}