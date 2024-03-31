#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int len=1;
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>v.back()){
            len++;
            v.push_back(arr[i]);
        }
        else{
            int ind=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            v[ind]=arr[i];
        }
    }
    return len;
}
