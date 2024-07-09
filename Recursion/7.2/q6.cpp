bool fn(int i, int n, int k, vector<int> &a, int s, bool& f){
    if(i==n){
        if(k==s) return true;
        else  return false;
    }
    if (f)
    return true;
    s+=a[i];
    bool l=fn(i+1,n,k,a,s,f);
    s-=a[i];
    bool r=fn(i+1,n,k,a,s,f);
    f=(l||r);
    return f;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    bool f=false;
    return fn(0,n,k,a,0,f);
}

//memoize
int rec(int i, int n, int s, int sum , vector<int>& arr, vector<vector<long long>>& dp){
	    if(i==n) {
	        if(s==sum) return dp[i][s]=1;
	        else return dp[i][s]=0;
	    }
	    if(dp[i][s]!=-1) return dp[i][s];
	    return dp[i][s]=(rec(i+1,n,s,sum,arr,dp) || (((s+arr[i])<= sum) ? (rec(i+1,n,s+arr[i],sum,arr,dp)) : 0))%1000000007;
	}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<long long>> dp(n+1, vector<long long> (k+1,-1));
    return rec(0,n,0,k,a,dp)%1000000007;
}