#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

/* Generates a prefix sum array from the given example vector */
vector<ll> genRangeSumDP(vector<ll> example)
{
    vector<ll> prefixSum;
    for(ll i = 0; i < example.size(); i++)
    {
        if(i == 0)
            prefixSum.push_back(example[i]);
        else
            prefixSum.push_back(prefixSum[i - 1] + example[i]);
    }

    return prefixSum;
}


int main()
{
    vector<ll> example = {1, 2, 13, 14, 5};
    vector<ll> prefixSum = genRangeSumDP(example);
    
    ll l = 3;
    ll r = 4;
    ll result;
    if(l == 0)
        result = prefixSum[r];
    else
        result = prefixSum[r] - prefixSum[l - 1];

    cout << "The sum from index 3 to 4 is: " << result << endl; // Output should be 19
    return 0;
}