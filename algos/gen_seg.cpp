#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;

const ll mod = (ll)1e9 + 7;
const ll mxN = (ll)1e3 + 3;



template<class T>
struct SegTree {
	ll n; vector<T> tree; T ID=mod;
	void init(ll _n) {n=_n;tree.assign(4*n,ID);}
	T comb(T L, T R) {return min(L,R);}
	void pull(ll idx) {tree[idx]=comb(tree[2*idx],tree[2*idx+1]);}
	void update(ll idx,ll val) {upd(idx,val,0LL,n-1,1LL);}
	T query(ll l, ll r) {return qry(l,r,0LL,n-1,1LL);}

	void upd(ll idx,ll val,ll L,ll R,ll pos) {
		// assert(pos<=n*2);
		if(L==R) {tree[pos]=val;return;}
		ll M=(L+R)/2;
		if(idx<=M) upd(idx,val,L,M,pos*2);
		else upd(idx,val,M+1,R,1+pos*2);
		// assert(pos<=n*2);
		pull(pos);
	}
	
	T qry(ll l,ll r,ll L,ll R,ll pos) {
		if(l>r) return ID;
		if(l==L && r==R) return tree[pos];
		ll M=(L+R)/2;
		return comb(qry(l,min(r,M),L,M,pos*2),qry(max(l,M+1),r,M+1,R,2*pos+1));
	}	
};

void solve() { 	
	ll n, q; cin>>n>>q;
	SegTree<ll> seg;seg.init(n);
	for(ll i=0,x;i<n;i++) {
		cin>>x;
		seg.update(i,x);
	} 
	while(q--) {
		ll l,r;cin>>l>>r;
		cout<<seg.query(l-1,r-1)<<"\n";
	}

 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(20);
	cout << fixed;
#ifdef LOCAL_DEFINE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	// pre();
	// ll t;cin>>t;while(t--) 
			solve();
}
