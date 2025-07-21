#include<iostream>

class Solution{
public:
    void reverse(int arr[], int n){
        if(arr >= (arr+n-1)) return;
        arr[n-1] = arr[n-1] + arr[0];
        arr[0] = arr[n-1] - arr[0];
        arr[n-1] = arr[n-1] - arr[0];
        reverse((arr+1), n-2);
    }
};



int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    sln.reverse(arr, n);
    for(int i = 0; i < n; i++) std::cout << arr[i] << " ";
}
