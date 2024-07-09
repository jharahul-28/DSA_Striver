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

//memoization
class Solution{

	public:
	int rec(int i, int n, int s, int sum , int arr[], vector<vector<long long>>& dp){
	    if(i==n) {
	        if(s==sum) return dp[i][s]=1;
	        else return dp[i][s]=0;
	    }
	    if(dp[i][s]!=-1) return dp[i][s];
	    return dp[i][s]=(rec(i+1,n,s,sum,arr,dp)+(((s+arr[i])<= sum) ? (rec(i+1,n,s+arr[i],sum,arr,dp)) : 0))%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<long long>> dp(n+1, vector<long long> (sum+1,-1));
        return rec(0,n,0,sum,arr,dp)%1000000007;
	}
	  
};