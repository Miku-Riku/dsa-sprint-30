/*
Title: Spiral Matrix
// Link: https://leetcode.com/problems/spiral-matrix/description/
// Date: 28-06-2025
// Tags: #Array #Matrix #SpiralOrder #Leetcode #Medium

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

Solution : 
PS - Given an m x n matrix, return all elements of the matrix in spiral order.

Sol -  we can traverse the matrix in a spiral order by maintaining four boundaries: left, right, 
top, and bottom.
// We will iterate through the matrix in a spiral manner, adjusting these boundaries as we go.

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) for the output vector, as we are not using any


*/



#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = n-1, top = 0, bottom = m-1;
    
    vector<int> ans;
    while(left <= right && top <= bottom){
        //left to right
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
            
        }
        top++;
        //top to bottom
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
            
        }
        right--;
        //right to left
        if(top <= bottom){
            // we use this condition other than left <= right, because below for loop already checks it.
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
                
            }
            bottom--;
        }
        //bottom to top
        if(left <= right){
            // same reason as above.
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);               

            }
            left++;
        }
    }
    return ans;
}

int main(){
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
