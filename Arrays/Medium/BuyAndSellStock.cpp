#include<iostream>
#include<vector>

class Solution
{
public:
    int stockBuySell(std::vector<int> arr, int n)
    {
        int maxProfit = 0, minPrice = arr[0];
        for(int i=1, profit=0; i<arr.size(); i++)
        {
            profit = arr[i]-minPrice;
            if(profit>maxProfit) maxProfit = profit;
            if(arr[i]<minPrice) minPrice = arr[i];
        }
        return maxProfit;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];
    std::cout << sln.stockBuySell(nums, n) << std::endl;
}
