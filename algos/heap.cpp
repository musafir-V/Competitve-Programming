#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void max_heapify(int i, int n) {
    int l=2*i, r=2*i+1,largest=i;
    if(l<=n && v[l]>v[largest]) largest=l; // l<=n makes sense in case of heap sort
    if(r<=n && v[r]>v[largest]) largest=r; // r<=n makes sense in case of heap sort
    if(largest!=i) {
        swap(v[i],v[largest]);
        max_heapify(largest,n);
    }
}

void build_max_heap(int n) {
    for(int i=n/2;i>0;i--)
        max_heapify(i,n);
}
void print() {
    for(auto i: v) cout<<i<<" ";
    cout<<'\n';
}

// make value at the given index(idx, 1 based) to val
void increase_value(int idx, int val) {
    v[idx]=val;

    // to maintain the heap property
    while(idx>1 && v[idx]>v[idx/2]) {
        swap(v[idx],v[idx/2]);
        idx=idx/2;
    }
}

void insert(int val) {
    v.push_back(-1);
    increase_value(v.size()-1,val);
}

void heapsort() {
    build_max_heap(v.size()-1);
    int heap_size=v.size()-1;
    for(int i=v.size()-1;i>1;i--) {
        swap(v[1],v[i]);
        heap_size--;
        max_heapify(1,heap_size);
    }
}

int main() {
    int n;cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    heapsort();    
    print();
}
