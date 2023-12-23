#include <bits/stdc++.h>

void f(int i, long long s, vector<int> &ds, set<vector<int>> &st, vector<int> &a, long long k){
    if(i==a.size()){
        if(s==k){
            sort(ds.begin(),ds.end());
            st.insert(ds);
        }
        return;
    }
    if (s>k) return;
    ds.push_back(a[i]);
    s+=a[i];
    f(i+1,s,ds,st,a,k);
    ds.pop_back();
    s-=a[i];
    f(i+1,s,ds,st,a,k);
}

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    set<vector<int>> st;
    vector<int> ds;
    long long s=0ll;
    f(0, s, ds, st, a, k);
    vector<vector<int>> b;
    for( auto it: st){
        b.push_back(it);
    }
    return b;
}