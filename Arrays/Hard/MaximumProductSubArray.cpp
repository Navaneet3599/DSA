#include<iostream>
#include<vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        long long int max = 0, prefix = 1, suffix = 1;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            prefix *= nums[i];
            suffix *= nums[n-1-i];
            max = std::max(max, std::max(prefix, suffix));
            prefix = (prefix==0) ? 1 : prefix;
            suffix = (suffix==0) ? 1 : suffix;
        }
        return (int)max;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i=0; i<n; i++) std::cin >> arr[i];

    std::cout << sln.maxProduct(arr) << std::endl;
    return 0;
}
