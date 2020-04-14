#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 1e5 + 4;

ll n, q;
ll weights[N], levels[N], up[N][18], dp[N];

vector<ll> Adj[N];

void dfs(ll s, ll par, ll level)
{
    up[s][0] = par;
    levels[s] = level;
    // dp[s] = ((par == -1) * weights[s]) + (weights[s] ^ dp[par]);
    dp[s] = (par == -1) * weights[s] + dp[par] ^ weights[s];
    for (ll i = 1; i < 18; i++)
        if (up[s][i - 1] != -1)
            up[s][i] = up[up[s][i - 1]][i - 1];

    for (auto child : Adj[s])
        if (child != par)
            dfs(child, s, level + 1);
}

ll LCA(ll u, ll v)
{
    if (levels[u] < levels[v])
        swap(u, v);

    ll diff = levels[u] - levels[v];

    for (ll i = 0; i < 18; i++)
        if ((1 << i) & diff)
            u = up[u][i];

    if (u == v)
        return u;

    for (ll i = 17; i >= 0; i--)
        if (up[u][i] != -1 && (up[u][i] != up[v][i]))
            u = up[u][i], v = up[v][i];

    return up[u][0];
}

void solve()
{
    memset(up, -1, sizeof up);

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        Adj[i].clear();

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }

    dfs(0, -1, 0);

    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cout << (dp[x] ^ dp[y] ^ weights[LCA(x, y)]) << "\n";
    }
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