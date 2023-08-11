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
int largestSubArrayLength(vector <int> v, long long k){
    int maxLen=0;
    map <int, int> preSum;
    long long sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum==k){
            maxLength= max(maxLength, i+1);
        }
        long long rem= sum-k;
        if (preSum.find(rem) =! v.end()){
            int len= i-preSum[rem];
            maxLength= max(maxLength, len);
        }
        if(preSum.find(sum) == v.end())
        preSum[sum]=i;
    }
    return maxLen;
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