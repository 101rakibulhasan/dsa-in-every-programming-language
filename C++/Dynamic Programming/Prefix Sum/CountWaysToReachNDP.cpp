#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

/*
Statement:
You start at step 0.
You can jump 1, 2, …, K steps at a time.
How many ways are there to reach step N?

let N = 5, K = 2
Valid paths:
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
2+1+1+
2+2+1
2+1+2
1+2+2
Total = 8 ways.
*/

vector<ll> genCountWaysDP(ll n, ll k)
{
    vector<ll> prefixSum;
    prefixSum.push_back(1);
    
    vector<ll> dp;
    dp.push_back(1); 

    for(ll i = 1; i <= n; i++)
    {
        ll l = max(0LL, i - k);
        ll r = i - 1;

        ll rangeSum = prefixSum[r];
        if(l > 0)
            rangeSum -= prefixSum[l - 1];

        dp.push_back(rangeSum);
        prefixSum.push_back(prefixSum[i - 1] + rangeSum);
    }
    return dp;
}


int main()
{
    vector<ll> dp = genCountWaysDP(5, 2);
    ll result = dp[5];
    cout << "Number of ways to reach step 5 with jumps up to 2 steps: " << result << endl;
    
    return 0;
}