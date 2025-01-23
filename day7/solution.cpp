#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// you need to implement this function only
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
}
int main() {
    vector<vector<int>> matrix;
    int n;
    cin >> n;
    // please don't modify the main function
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << matrix[i][j];
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        if (i != n - 1) { 
            cout << endl;
        }
    }
    return 0;
}
