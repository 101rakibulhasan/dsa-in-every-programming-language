#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

vector<ll> allWindowMaxSums(vector<ll>& arr, int k) {
    vector<ll> result;
    
    ll windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    result.push_back(windowSum);
    
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        result.push_back(windowSum);
    }
    
    return result;
}

int main()
{
    vector<ll> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    // Find all window sums
    vector<ll> windowSums = allWindowMaxSums(arr, k);
    cout << "All window sums: ";
    for (ll sum : windowSums) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}