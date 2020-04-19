#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = (ll)1e5 + 1;

struct node
{
    ll sum, mxpre, mxsuff, ans;
};
node t[N << 2];
ll A[N], n;
node make_node(ll s, ll max_pre, ll max_suff, ll ans)
{
    node n;
    n.sum = s;
    n.mxpre = max_pre;
    n.mxsuff = max_suff;
    n.ans = ans;
    return n;
}

node combine(node a, node b)
{
    node n;
    n.sum = a.sum + b.sum;
    n.mxpre = max(a.mxpre, a.sum + b.mxpre);
    n.mxsuff = max(b.mxsuff, b.sum + a.mxsuff);
    n.ans = max(max(a.ans, b.ans), a.mxsuff + b.mxpre);
    return n;
}

void build(ll tl = 0, ll tr = n - 1, ll v = 1)
{
    if (tl == tr)
        t[v] = make_node(A[tl], A[tl], A[tl], A[tl]);
    else
    {
        ll mid = (tl + tr) >> 1;
        build(tl, mid, v << 1);
        build(mid + 1, tr, v << 1 | 1);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void update(ll pos, ll value, ll tl = 0, ll tr = n - 1, ll v = 1)
{
    // cout << pos << " ";
    if (tl == tr)
        t[v] = make_node(value, value, value, value);
        // cout <<[v].sum << "HH\n";
    else
    {
        ll mid = (tl + tr) >> 1;
        if (pos <= mid)
            update(pos, value, tl, mid, v << 1);
        else
            update(pos, value, mid + 1, tr, v << 1 | 1);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

node query(ll l, ll r, ll tl = 0, ll tr = n - 1, ll v = 1)
{
    if (l > r)
        return make_node(-1e18, -1e18, -1e18, -1e18);
    else if (tl == l && tr == r)
        return t[v];
    else
    {
        ll mid = (tl + tr) >> 1;
        return combine(query(l, min(r, mid), tl, mid, v << 1), query(max(mid + 1, l), r, mid + 1, tr, v << 1 | 1));
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    build();
    ll q;
    cin >> q;
    while (q--)
    {
        ll a, l, r;
        cin >> a >> l >> r;
        if (a == 0)
            update(l - 1, r);
        else
            cout << query(l - 1, r - 1).ans << "\n";
    }
}