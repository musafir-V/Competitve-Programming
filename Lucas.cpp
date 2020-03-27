#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll md = 1000003;

vector<ll> fact(1000003), ifact(1000003);

ll bin_pow(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    else
    {
        ll x = bin_pow(base, exp >> 1);
        x = (x * x) % md;
        if (exp & 1)
            x = (x * base) % md;
        return x;
    }
}

void pre()
{
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < md; i++)
    {
        fact[i] = (i * fact[i - 1]) % md;
        ifact[i] = bin_pow(fact[i], md - 2);
    }
    //  for (int i = 1; i < md; i++){
    //      cout<<fact[i]<<" ";
    //  }
}

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    return (((ifact[r] * ifact[n - r]) % md) * fact[n]) % md;
}

ll lucas(ll n, ll r)
{
    if (r == 0)
        return 1;
    else
        return (lucas(n / md, r / md) * ncr(n % md, r % md)) % md;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout << fixed;

    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        cout << lucas(n, r) << "\n";
    }
}