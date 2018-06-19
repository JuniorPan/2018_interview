#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

// M x N matrix
#define M 10
#define N 10

// queue node used in BFS
struct Node 
{
    // (x, y) represents matrix cell coordinates
    // dist represent its minimum distance from the source
    int x, y, dist;
};

// Below arrays details all 4 possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

// Function to check if it is possible to go to position (row, col) 
// from current position. The function returns false if (row, col) 
// is not a valid position or has value 0 or it is already visited
bool isValid(int mat[][N], bool visited[][N], int row, int col)
{
    return (row >= 0) && (row < M) && (col >= 0) && (col < N) 
        && mat[row][col] && !visited[row][col];
}

// Find Shortest Possible Route in a matrix mat from source 
// cell (i, j) to destination cell (x, y)
void BFS(int mat[][N], int i, int j, int x, int y)
{
    // construct a matrix to keep track of visited cells
    bool visited[M][N];
    
    // initially all cells are unvisited
    memset(visited, false, sizeof visited);
    
    // create an empty queue
    queue<Node> q;

    // mark source cell as visited and enqueue the source node
    visited[i][j] = true;
    q.push({i, j, 0});

    // stores length of longest path from source to destination
    int min_dist = INT_MAX;

    // run till queue is not empty    
    while (!q.empty()) 
    {
        // pop front node from queue and process it
        Node node = q.front();
        q.pop();
        
        // (i, j) represents current cell and dist stores its
        // minimum distance from the source
        int i = node.x, j = node.y, dist = node.dist;

        // if destination is found, update min_dist and stop
        if (i == x && j == y) 
        {
            min_dist = dist;
            break;
        }

        // check for all 4 possible movements from current cell
        // and enqueue each valid movement
        for (int k = 0; k < 4; k++) 
        {
            // check if it is possible to go to position
            // (i + row[k], j + col[k]) from current position
            if (isValid(mat, visited, i + row[k], j + col[k])) 
            {
                // mark next cell as visited and enqueue it
                visited[i + row[k]][j + col[k]] = true;
                q.push({ i + row[k], j + col[k], dist + 1 });
            }
        }
    }

    if (min_dist != INT_MAX)
        cout << "The shortest path from source to destination "
                "has length " << min_dist;
    else
        cout << "Destination can't be reached from given source";
}

// Shortest path in a Maze
int main()
{
    // input maze
    int mat[M][N] =
    {
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };

    // Find shortest path from source (0, 0) to
    // destination (7, 5)
    BFS(mat, 0, 0, 7, 5);

    return 0;
}