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