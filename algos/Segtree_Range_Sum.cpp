#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = (ll)1e5 + 3;

ll n, t[4 * N], A[N], q; // Here A is 0 Based indexing and tree is 1 based indexing

void build(ll tl, ll tr, ll v)
{
    if (tl == tr)
    {
        t[v] = A[tl];
        return;
    }
    ll mid = (tl + tr) >> 1;
    build(tl, mid, v << 1);
    build(mid + 1, tr, v << 1 | 1);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

// Further the function for answering sum queries is also a recursive function,
// which receives as parameters information about the current vertex/segment (i.e.
// the index v and the boundaries tl and tr) and also the information about the
// boundaries of the query, l and r. In order to simplify the code, this function
// always does two recursive calls, even if only one is necessary - in that case
// the superfluous recursive call will have l>r, and this can easily be caught
// using an additional check at the beginning of the function.

ll sum(ll tl, ll tr, ll v, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    ll mid = (tl + tr) >> 1;
    return sum(tl, mid, v << 1, l, min(mid, r)) + sum(mid + 1, tr, v << 1 | 1, max(l, mid + 1), r);
}

void update(ll tl, ll tr, ll v, ll pos, ll value) // pos is the 0 based index of values to be updates
{
    if (tl == tr)
    {
        t[v] = value;
        return;
    }
    ll mid = (tl + tr) >> 1;
    if (pos <= mid)
        update(tl, mid, v << 1, pos, value);
    else
        update(mid + 1, tr, v << 1 | 1, pos, value);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    build(0, n - 1, 1);
    ll l, r;
    while (cin >> l >> r)
    {
        l--, r--;
        cout << sum(0, n - 1, 1, l, r) << "\n";
    }
}