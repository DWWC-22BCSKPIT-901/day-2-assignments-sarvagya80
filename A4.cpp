
#include <iostream>
#include <algorithm> 
using namespace std;
int maxCherries(int** grid, int rows, int cols) { 
    int dp[rows][cols][cols];  // DP table to store max cherries at each step     // Initialize the DP table with -1 for non-visited states     for (int i = 0; i < rows; i++) {         for (int j1 = 0; j1 < cols; j1++) {             for (int j2 = 0; j2 < cols; j2++) {                 dp[i][j1][j2] = -1;  
            

    dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];  
    for (int i = 1;
    i < rows;
    i++) {  for (int j1 = 0;j1 < cols;j1++) { 
        for (int j2 = 0;j2 < cols;j2++) { 
        if (dp[i - 1][j1][j2] != -1) {  // If this state was reachable from the previous row  
                    for (int dj1 = -1;dj1 <= 1;dj1++) {  
                        for (int dj2 = -1;dj2 <= 1;dj2++) { 
                            int newJ1 = j1 + dj1;
                    int newJ2 = j2 + dj2;  
  
                            if (newJ1 >= 0 && newJ1 < cols && newJ2 >= 0 && newJ2 < cols) {  int cherries = grid[i][newJ1] + grid[i][newJ2];  
                                if (newJ1 == newJ2) cherries -= grid[i][newJ1]; // If both robots are at the same cell, only one picks cherries  
                                dp[i][newJ1][newJ2] = max(dp[i][newJ1][newJ2], dp[i - 1][j1][j2] + cherries);  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }      int maxCherries = 0;  
    for (int j1 = 0; j1 < cols; j1++) {
        for (int j2 = 0;j2 < cols; j2++) {
            maxCherries = max(maxCherries, dp[rows - 1][j1][j2]);  
        }  
    }  
    return maxCherries;  
}  
  
int main() {  
    int rows,
    cols; 
    cout << "Enter the number of rows and columns: ";   
    cin >> rows >> cols;  
  
    int** grid = new int*[rows];  
    cout << "Enter the grid (cherry counts):\n";  
    for (int i = 0; i < rows; i++) { grid[i] = new int[cols];  
    for (int j = 0; j < cols; j++) {  cin >> grid[i][j];  
        }  
    }  
  
    int result = maxCherries(grid, rows, cols);  
    cout << 
"Maximum cherries collected: " << result << endl; 
for (int i = 0; i < rows; i++) { delete[] grid[i];  
    }     delete[] grid;  
  
    return 0;  
}
