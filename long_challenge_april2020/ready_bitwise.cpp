#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;

string s;
ll M[1000001], dp[1000001][2], p[4000002];

ll rec(ll idx, bool res)
{
    // cout << idx << " ";
    if (dp[idx][(ll)res] != -1)
        return dp[idx][(ll)res];
    if (s[idx] == '#')
        return dp[idx][(ll)res] = 2;
    ll oid = M[idx];
    ll left_true = rec(idx + 1, true), right_true = rec(oid + 1, true);
    ll left_false = rec(idx + 1, false), right_false = rec(oid + 1, false);
    switch (s[oid])
    {
    case '|':
        if (res)
            return dp[idx][(ll)res] = (((left_true * right_true) % MOD) + ((left_true * right_false) % MOD) + ((left_false * right_true) % MOD)) % MOD;
        else
            return dp[idx][(ll)res] = (left_false * right_false) % MOD;
        break;
    case '&':
        if (!res)
            return dp[idx][(ll)res] = (((left_false * right_false) % MOD) + ((left_true * right_false) % MOD) + ((left_false * right_true) % MOD)) % MOD;
        else
            return dp[idx][(ll)res] = (left_true * right_true) % MOD;
        break;
    case '^':
        if (res)
            return dp[idx][(ll)res] = (((left_true * right_false) % MOD) + ((right_true * left_false) % MOD)) % MOD;
        else
            return (((left_false * right_false) % MOD) + ((left_true * right_true) % MOD)) % MOD;
    default:
        break;
    }
    return 0;
}

ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

ll bin_pow(ll x, ll p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mult(x, bin_pow(x, p - 1));
    return bin_pow(mult(x, x), p / 2);
}

ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}

void solve()
{
    cin >> s;
    ll c = 0;
    memset(M, -1, sizeof(M));
    memset(dp, -1, sizeof(dp));
    for (auto i : s)
        if (i == '#')
            c++;
    stack<ll> S;
    for (ll i = 0; i < s.length(); i++)
        if (s[i] == '(')
            S.push(i);
        else if (s[i] == '&' || s[i] == '|' || s[i] == '^')
            M[S.top()] = i;
        else if (s[i] == ')')
            S.pop();
    ll a = rec(0, true), b = ((p[2 * c] - a) % MOD + MOD) % MOD;
    cout << (((b * b) % MOD) * rev(p[4 * c])) % MOD << " ";
    cout << (((a * a) % MOD) * rev(p[4 * c])) % MOD << " ";
    cout << (((a * b) % MOD) * rev(p[4 * c])) % MOD << " ";
    cout << (((a * b) % MOD) * rev(p[4 * c])) % MOD << "\n";
}

int main()
{
    for (int i = 0; i < 4000002; i++)
        if (i == 0)
            p[i] = 1;
        else
            p[i] = (p[i - 1] * 2) % MOD;
    ll t;
    cin >> t;
    while (t--)
        solve();
}