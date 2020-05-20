#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll mod = (ll)1e9 + 7;
const ll mxN = 200200;

// Fenwick Tree for Range Sum Point Updates
struct FT {
	ll *tree, N;
	
	FT(ll n) {
		N=n;
		tree=new ll[N+1];
		for(int i=0;i<=N;i++) tree[i]=0;
	}
	
	ll sum(ll i) {
		ll ans=0;
		for(;i>0;i-=i&(-i))
			ans+=tree[i];
		return ans;
	}

	
	void update(ll i, ll d) { 
		for(;i<=N;i+=i&(-i))
			tree[i]+=d;
	}
};
// Fenwick Tree Over

vector<ll> update_array(vector<ll>A) {
	
	vector<ll> ans(A);
	sort(all(A));
	for(int i=0;i<A.size();i++)
		ans[i]=lower_bound(all(A),ans[i])-A.begin()+1;
	return ans;

}

void solve() {
	ll n,ans=0;
	cin>>n;
	vll A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	A=update_array(A);
	FT t(*max_element(all(A)));
	for(int i=n-1;i>=0;i--){
		ans+=t.sum(A[i]-1);
		t.update(A[i],1LL);
	}
	cout<<ans<<'\n';

}


int main() {
	ll t; cin>>t; while(t--)
	solve();
}

