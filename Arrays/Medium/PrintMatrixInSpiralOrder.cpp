#include<iostream>
#include<vector>
#include<unordered_set>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        std::vector<int> ans;

        while((top<=bottom)&&(left<=right))
        {
            for(int i=left; i<=right; i++)
                ans.emplace_back(matrix[top][i]);
            top++;

            for(int i=top; i<=bottom; i++)
                ans.emplace_back(matrix[i][right]);
            right--;

            if(top<=bottom)
            {
                for(int i=right; i>=left; i--)
                    ans.emplace_back(matrix[bottom][i]);
                bottom--;
            }

            if(left<=right)
            {
                for(int i=bottom; i>=top; i--)
                    ans.emplace_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sln;
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::vector<int> out(m*n);

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            std::cin >> matrix[i][j];
    
    out = sln.spiralOrder(matrix);

    for(int i=0; i<m*n; i++) std::cout << out[i] << " ";
}
