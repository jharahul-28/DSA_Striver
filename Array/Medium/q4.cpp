//brute
int maxSubarraySum(vector <int> v){
    int maxSum=0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            int sum=0;
            for (int k = 0; k < v.size(); k++)
            {
                sum+=v[k];
            }
            maxSum= max(maxSum, sum);
        }
        
    }
    return maxSum;
}

//better
int maxSubarraySum(vector <int> v){
    int maxSum=0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum=0;
        for (int j = i; j < v.size(); j++)
        {
            sum=sum+v[j];
            maxSum= max(maxSum, sum);
        }
        
    }
    return maxSum;
}

//optimal Kadane Algo
//returning sum
int maxSubarraySum(vector <int> v){
    long long maxSum= LONG_MIN;
    int sum=0;
    for (int i = 0; i < v.size(); i++)
    {
        sum+= v[i];
        maxSum= max(maxSum, sum);
        if (sum<0) sum=0;
    }
    return maxSum;
}

//printing subarray
void maxSubarraySum(vector <int> v){
    long long maxSum= LONG_MIN;
    int sum=0;
    int start, end;
    for (int i = 0; i < v.size(); i++)
    {
        if (sum==0) start=i;
        sum+= v[i];
        if (sum>maxSum){
            maxSum=sum;
            end=i;
        }
        if (sum<0) sum=0;
    }
    for(int i=start; i<=end;i++){
        cout<< v[i]<< " ";
    }
}