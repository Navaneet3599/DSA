#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
  public:
    bool Is1LessThan2(std::vector<int> first, std::vector<int> second)
    {
        if(first[0]<second[0]) return true;
        else return false;
    }
    bool Is1LessThanOrEqualTo2(std::vector<int> first, std::vector<int> second)
    {
        if(first[0]<=second[0]) return true;
        else return false;
    }
    int rearrange(std::vector<std::vector<int>>& nums, int low, int high)
    {
        int i=low+1, j=high;
        while(true)
        {
            while((i<=high)&&(Is1LessThanOrEqualTo2(nums[i], nums[low]))) i++;
            while((j>=low)&&(Is1LessThan2(nums[low], nums[j]))) j--;
            if(i>=j) break;
            else std::swap(nums[i], nums[j]);
        }
        std::swap(nums[low], nums[j]);
        return j;
    }
    void quickSort(std::vector<std::vector<int>>& nums, int low, int high)
    {
        if(low >= high) return;
        int pivot = rearrange(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }
    std::vector<std::vector<int>> mergeOverlap(std::vector<std::vector<int>>& arr) {
        std::vector<std::vector<int>> out;
        quickSort(arr, 0, arr.size()-1);
        out.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++)
        {
            if((out.back())[1] >= arr[i][0])
                (out.back())[1] = std::max((out.back())[1], arr[i][1]);
            else
                out.push_back(arr[i]);
        }
        return out;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> nums(n), out;

    for(int i=0; i<n; i++)
    {
        std::vector<int> temp(2);
        for(int j=0; j<2; j++)
        {
            std::cin >> temp[j];
        }
        nums[i] = temp;
    }

    out = sln.mergeOverlap(nums);

    for(int i=0; i<out.size(); i++)
    {
        for(int j=0; j<2; j++)
        {
            std::cout << out[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
