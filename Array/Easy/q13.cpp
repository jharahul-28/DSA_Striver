//brute
int largestSubArrayLength(vector <int> v, int k){
    max1=0;
    for(int i=0;i<v,size();i++){
        int s=0;
        for(int j=i;j<v.size();j++){
            s+=v[j];
            if(s==k)
            max1= max(i-j+1, max1);
        }
    }
    return max1;
}

//better
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int n=nums.size();
    map<int,int> preSum;
    int s=0, ml=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        if(s==k) ml=max(ml,i+1);
        int rem=s-k;
        if(preSum.find(rem)!=preSum.end()) ml=max(ml,i-preSum[rem]);
        if(preSum.find(s)==preSum.end()) preSum[s]=i;
    }
    return ml;
}

//optimal
int largestSubArrayLength(vector <int> v, long long k){
    int left=0, right =0, maxLength=0; long long sum=0;
    while(right < v.size()){
        while(left < right && sum> k){
            sum-=v[left];
            left++;
        }
        if(sum == k)
        maxLength = max(maxLength, right - left + 1);
        right++;
        if(right < n)
        sum+ = v[right];
    }
    return maxLength;
}