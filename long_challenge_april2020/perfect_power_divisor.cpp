#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
const ll N = 1e6 + 1;
const ll MAXX = 1e18 + 1;
const ll invv = 166666668;

// This code snippet is taken from geeksforgeeks.com
set<ll> squares;
vector<ll> powers;
set<ll> s;
void powersPrecomputation()
{
    for (long int i = 2; i < N; i++)
    {
        squares.insert(i * i);
        if (squares.find(i) != squares.end())
            continue;
        long int temp = i;
        while (i * i <= MAXX / temp)
        {
            temp *= (i * i);
            s.insert(temp);
        }
    }

    for (auto x : s)
        powers.push_back(x);
}
// Till here

inline ll value1(ll n)
{
    return ((((((n + 1) * (2 * n + 1)) % MOD) * n) % MOD) * invv) % MOD;
}

inline ll value2(ll n)
{
    return (((((n * (n - 1)) % MOD) * (2 * n - 1)) % MOD) * invv) % MOD;
}

ll compute(ll n)
{
    ll res = 0;
    for (ll i = 1, last; i * i <= n; i = last + 1)
    {
        ll v = n / (i * i);
        last = (ll)sqrtl(n / v);
        ll x = value1(last), y = value2(i);
        res = (res + (((((x - y) % MOD) + MOD) % MOD) * v) % MOD) % MOD;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = compute(n);
    // cout << ans << " ";
    for (auto i : powers)
        if (i > n)
            break;
        else
            ans = (ans + n - n % i) % MOD;
    cout << ans << '\n';
}

int main()
{
    powersPrecomputation();
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