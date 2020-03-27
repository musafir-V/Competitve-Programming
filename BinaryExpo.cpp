#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = (ll)1e9 + 7;


// Suppose 5^(11) = 5^(1011) = 5^(1000) * 5^(10) * 5^(1)
// Expressing the power in binary form is the basic key here
 
ll bin_pow(ll base, ll exp)
{
    ll ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp = exp >> 1;
    }
    return ans;
}

int main()
{
    ll base, exp;
    cin >> base >> exp;
    cout << bin_pow(base, exp) << "\n";
}