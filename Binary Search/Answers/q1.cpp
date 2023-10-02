int floorSqrt(long long n)
{
    if (n==1 || n==2 || n==3) return 1;
    long long low=2, high=n/2;
    int ans;
    while(low<=high){
        long long mid= (low+high)/2;
        if (mid*mid == n) return ((int)mid);
        if(mid*mid <n){
            ans=(int)mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}