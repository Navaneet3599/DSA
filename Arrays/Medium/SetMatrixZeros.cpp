#include<iostream>
#include<vector>
#include<unordered_set>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        int block_00 = matrix[0][0];
        for(int i=0; i<matrix.size(); i++) if(matrix[i][0]==0) block_00 = 0;
        for(int i=0; i<matrix[0].size(); i++) if(matrix[0][i]==0) matrix[0][0] = 0;
        
        for(int i=1; i<matrix.size(); i++)
        {
            for(int j=1; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<matrix[0].size(); i++)
            if(matrix[0][i]==0)
                for(int j=1; j<matrix.size(); j++)
                    matrix[j][i] = 0;
        
        for(int i=0; i<matrix.size(); i++)
            if(matrix[i][0]==0)
                for(int j=1; j<matrix[0].size(); j++)
                    matrix[i][j] = 0;
        
        if(block_00==0)
            for(int i=0; i<matrix.size(); i++) matrix[i][0] = 0;
    }
};

int main()
{
    Solution sln;
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> nums(m, std::vector<int>(n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            std::cin >> nums[i][j];

    
    sln.setZeroes(nums);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            std::cout << nums[i][j] << " ";
        std::cout << std::endl;
    }
}
