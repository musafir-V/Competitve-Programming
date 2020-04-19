#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = (ll)1e5 + 7;

ll n, q;

ll t[N >> 2 + 5], A[N];

void build(ll tl = 0, ll tr = n - 1, ll v = 1)
{
    if (tl == tr)
        t[v] = A[tl];
    else
    {
        ll mid = (tl + tr) >> 1;
        build(tl, mid, v << 1);
        build(mid + 1, tr, v << 1 | 1);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void update(ll pos, ll value, ll tl = 0, ll tr = n - 1, ll v = 1)
{
    if (tl == tr)
        t[v] = value;
    else
    {
        ll mid = (tl + tr) >> 1;
        if (pos <= mid)
            update(pos, value, tl, mid, v << 1);
        else
            update(pos, value, mid + 1, tr, v << 1 | 1);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

ll query(ll l, ll r, ll tl = 0, ll tr = n - 1, ll v = 1)
{
    if (l > r)
        return 1e18;
    else if (tl == l && tr == r)
        return t[v];
    else
    {
        ll mid = (tl + tr) >> 1;
        ll x = query(l, min(r, mid), tl, mid, v << 1);
        ll y = query(max(l, mid + 1), r, mid + 1, tr, v << 1 | 1);
        return min(x, y);
    }
}
int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    build();
    while (q--)
    {
        char ch;
        ll l, r;
        cin >> ch >> l >> r;
        l--, r--;
        if (ch == 'u')
            update(l, r + 1);
        else
            cout << query(l, r) << "\n";
    }
}