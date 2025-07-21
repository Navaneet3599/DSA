#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int i=m-1, j=n-1, k=m+n-1;
        while((0<=i)&&(0<=j))
            if(nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        
        while(0<=j)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    Solution sln;
    int n, m;
    std::cin >> m >> n;
    std::vector<int> arr1(m+n), arr2(n);

    for(int i=0; i<m; i++) std::cin >> arr1[i];
    for(int i=0; i<n; i++) std::cin >> arr2[i];

    sln.merge(arr1, m, arr2, n);

    for(int j=0; j<(m+n); j++) std::cout << arr1[j] << " ";
}
