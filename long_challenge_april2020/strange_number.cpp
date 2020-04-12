#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> prime;

void pre()
{
    for (ll i = 2; i < 100000; i++)
    {
        bool ok = true;
        for (auto j : prime)
            if (i % j == 0)
            {
                ok = false;
                break;
            }
        if (ok)
            prime.push_back(i);
    }
}

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    for (auto i : prime)
    {
        if (i > n)
            break;
        while (n % i == 0)
            ans++, n /= i;
    }
    if (n > 1)
        ans++;
    ans >= k ? puts("1") : puts("0");
}

int main()
{
    pre();
    // for (auto i : prime)
    //     cout << i << " ";
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    ll t;
    cin >> t;
    while (t--)
        solve();
}