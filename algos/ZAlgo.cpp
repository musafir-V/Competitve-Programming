#include<bits/stdc++.h>

using namespace std;

#define ll long long

// Linear Time Algorithm for calculating Z Function
vector<ll> z_function(string s) {
	ll n=s.length();
	vector<ll> z(n);
	for(int i=1,l=0,r=0;i<n;i++) {
		if(i<=r) 
			z[i]=min(z[i-l],r-i+1LL);
		while(i+z[i] < n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	return z;
}

void solve() {
	string s; 
	cin>>s;
	vector<ll> z = z_function(s);
	for(auto i:z) cout<<i<<" ";cout<<"\n";
}


int main() {
	ll t; cin>> t; while(t--)
		solve();
}
