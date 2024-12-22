#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // Create a row with all elements initialized to 1
        for (int j = 1; j < i; ++j) {
            row[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
        pascalTriangle.push_back(row);
    }

    return pascalTriangle;
}

int main() {
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);

    cout << "Output: " << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
