#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        ll M[k + 1] = {0};
        for (int j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            M[x]++;
        }
        ll max = -1, val;
        for (int j = 0; j < k + 1; j++)
        {
            if (max < M[j])
                max = M[j], val = j;
        }
        cout << val << " ";
    }
    cout << '\n';
}

int main()
{
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    ll t;
    cin >> t;
    while (t--)
        solve();
}