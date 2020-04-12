#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if ((nums[i] % 2 == 0) && (nums[i] % 4 != 0))
        {
            ll left = 0, right = 0, j = i - 1;
            while (nums[j] % 2 != 0 && j >= 0)
                left++, j--;
            j = i + 1;
            while (nums[j] % 2 != 0 && j < n)
                right++, j++;
            // cout << left << " " << right << " ";
            ans += (left + 1) * (right + 1);
        }
    cout << (n * (n + 1)) / 2 - (ans) << "\n";
}

int main()
{
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
