class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int n=arr.size();
        int high= n-1;
        int mid, missing;
        while(low<=high){
            mid = (low+high)/2;
            missing= arr[mid]-(mid+1);
            if(k>missing){
                low= mid+1;
            }
            else high= mid-1;
        }
        return high+k+1;
    }
};