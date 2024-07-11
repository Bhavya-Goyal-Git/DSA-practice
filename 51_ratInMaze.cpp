#include <iostream>
#include <vector>
using namespace std;

// Problem : Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the maze matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the maze matrix represents that rat can travel through it.
//  Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell at all.

// Approach: we make a recursive function that accepts-> a maze(vector of vector passed as reference), 2 integers x&y for keeping track of current position of the rat, a visited(vector of vectors passed as reference to keep track of visited blocks by the rat, necesary to avoid stack overflows... this is same size as of our maze, initialized with all zeros at beginning), a string called path that will store the operations taken to reach current cell, and finally a vector of strings ans(passed by ref), in which we will push our path if we arrive at desired position.
// We will firstly check if current call can be discarded, ie x or y have gone out of the maze matrix, or the cell is non traversable (maze[x][y]==0) or it is already visited (visited[x][y]==1) in all such cases, we plainly return. next we check if we have reached our destiny ie (n-1,n-1), then we push back the path into ans vector and return.
// Normal case: For a normal visitable cell, we first set visited[x][y]=1 to mark it visited. then we make 4 recursive calls, trying to go down, right, left, up respectively. prior to each call we pushback corresponding alphabet into path string and after the call we pop it back to backtrack. at end of all 4 calls, we set the visited[x][y]=0 for backtracking.

void solve(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &visited, string path, vector<string> &ans)
{
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 0 || visited[x][y] == 1)
    {
        return;
    }
    else if (x == maze.size() - 1 && y == maze[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // try going down
    path.push_back('D');
    solve(maze, x + 1, y, visited, path, ans);
    path.pop_back();
    // try going right
    path.push_back('R');
    solve(maze, x, y + 1, visited, path, ans);
    path.pop_back();
    // try going left
    path.push_back('L');
    solve(maze, x, y - 1, visited, path, ans);
    path.pop_back();
    // try going up
    path.push_back('U');
    solve(maze, x - 1, y, visited, path, ans);
    path.pop_back();
    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
    int x = 0, y = 0;
    string path = "";
    vector<string> ans;
    solve(maze, x, y, visited, path, ans);
    for (string s : ans)
    {
        cout << s << ", ";
    }
}