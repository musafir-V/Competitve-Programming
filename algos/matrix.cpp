#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<class T> struct Mat {

	ll r, c; vector<vector<T>> mat;

	Mat(ll _r, ll _c) {r = _r, c = _c; mat.assign(r, vector<T>(c));}

	Mat() {Mat(0LL, 0LL);}

	Mat(vector<vector<T>> _mat) {r=_mat.size(),c=_mat[0].size();mat=_mat;}

	Mat& operator += (const Mat &_m) {
		for(int i=0;i<r;i++) 
			for(int j=0;j<c;j++) 
				mat[i][j] += _m.mat[i][j];
		return *this;
	}

	Mat& operator -= (const Mat &_m) {
		for(int i=0;i<r;i++) 
			for(int j=0;j<c;j++) 
				mat[i][j] -= _m.mat[i][j];
		return *this;
	}

	Mat operator * (const Mat &_m) {
		cout<<1<<" ";
		Mat res = Mat(r,_m.c);
		for(int i=0;i<r;i++)
			for(int j=0;j<_m.c;j++) 
				for(int k=0;k<c;k++)
					res.mat[i][j]+=mat[i][k]*_m.mat[k][j];
		return res;

	}

	Mat operator +(const Mat &_mat) {return Mat(*this)+=_mat;}
	Mat operator -(const Mat &_mat) {return Mat(*this)-=_mat;}
	Mat operator *=(const Mat &_mat) {return (*this)=(*this)*_mat;}

	friend Mat pow(Mat m, ll p) {
		Mat res(m.r, m.c);for(int i=0;i<m.r;i++) res.mat[i][i]=1LL;
		for(;p;p/=2,m*=m) if(p&1) res*=m;
		return res;
	}

};

int main() {
	ll r,c,p;cin>>r>>c>>p;
	Mat<ll> A(r,c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>A.mat[i][j];
	A=pow(A,p);

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<A.mat[i][j]<<" ";
		cout<<"\n";
	}


}

