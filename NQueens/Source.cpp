#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> res;

// Function to check if placing a queen at position (r, c) is valid
bool valid(int r, int c, vector<pair<int, int>>& queens)
{
    if (queens.empty()) // If there are no queens placed yet, it is always valid
        return true;
    for (auto i : queens)
    {
        // Check if the new queen conflicts with any existing queen
        if (i.first == r || i.second == c || i.first - i.second == r - c || i.first + i.second == r + c)
            return false;
    }
    return true;
}

// Function to solve the N-Queens problem using backtracking
void solve(int r, vector<pair<int, int>> queens)
{
    // If all queens are placed, add the solution to the result and return
    if ((int)queens.size() == n)
    {
        res.push_back(queens);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int j = 0; j < n; ++j)
    {
        if (valid(r, j, queens))
        {
            // If placing a queen at (r, j) is valid, add it to the queens vector
            pair<int, int> p;
            p.first = r, p.second = j;
            queens.push_back(p);

            // Recursively solve for the next row
            solve(r + 1, queens);

            // Backtrack by removing the last placed queen
            queens.pop_back();
        }
    }
}

int main()
{
    // Read the value of N from input
    cin >> n;

    // Solve the N-Queens problem starting from the first row and an empty queens vector
    solve(0, {});

    // Print the solutions
    for (auto i : res) {
        // Create a grid of size N*N and initialize all cells with '.'(empty cells)
        vector<vector<char>> grid(n, vector<char>(n, '.'));

        // Place queens on the grid based on the current solution
        for (auto j : i)
            grid[j.first][j.second] = 'Q';

        // Print the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
