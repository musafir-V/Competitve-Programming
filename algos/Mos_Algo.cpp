#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 5;
const ll M = 1e6 + 6;

struct query
{
    ll l, r, idx;
} A[M];

ll n, q, block_size, co;
ll freq[M], values[N], ans[M];

bool cmp(query A, query B)
{
    return (A.l / block_size < B.l / block_size) || ((A.l / block_size == B.l / block_size) && (A.r < B.r));
}

void add(ll x)
{
    freq[values[x]]++;
    co += (freq[values[x]] == 1);
}

void remove(ll x)
{
    co -= (freq[values[x]] == 1);
    freq[values[x]]--;
}

int main()
{
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    cin >>
        n;
    for (int i = 0; i < n; i++)
        cin >> values[i];
    cin >> q;
    block_size = n / sqrtl(q);
    for (int i = 0; i < q; i++)
    {
        cin >> A[i].l >> A[i].r;
        A[i].l--;
        A[i].r--;
        A[i].idx = i;
    }
    sort(A, A + q, cmp);
    ll start = 0, end = -1;
    for (int i = 0; i < q; i++)
    {
        while (start < A[i].l)
            remove(start), start++;
        while (start > A[i].l)
            start--, add(start);
        while (end < A[i].r)
            end++, add(end);
        while (end > A[i].r)
            remove(end), end--;
        ans[A[i].idx] = co;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << " ";
}