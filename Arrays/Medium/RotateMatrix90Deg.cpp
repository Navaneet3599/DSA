#include<iostream>
#include<vector>
#include<unordered_set>

class Solution
{
public:
    void rotateMatrix(std::vector<std::vector<int>>& matrix)
    {
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<i; j++)
                std::swap(matrix[i][j], matrix[j][i]);
            
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size()/2; j++)
                std::swap(matrix[i][j], matrix[i][matrix[0].size()-1-j]);
    }
};

int main()
{
    Solution sln;
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            std::cin >> matrix[i][j];

    
    sln.rotateMatrix(matrix);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}
