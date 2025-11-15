#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

// Function to find maximum sum of k consecutive elements using sliding window DP
ll maxSumSubarray(vector<ll>& arr, int k) {
    ll windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    ll maxSum = windowSum;

    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];  
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}

int main()
{
    vector<ll> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    ll maxSum = maxSumSubarray(arr, k);
    cout << "Maximum sum of " << k << " consecutive elements: " << maxSum << endl;
    
    return 0;
}