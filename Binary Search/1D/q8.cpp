class Solution {
public:
    int search(vector<int>& a, int k) {
        int low=0, high=a.size()-1;
        while(low <= high){
            int mid=(low+high)/2;
            if (a[mid]==k) return mid;
            if(a[mid]<= a[high]){
                if(a[mid]<k && k<=a[high]) 
                {low=mid+1;
                }
                else high=mid-1;
            }
            else{
                if(a[low]<=k && k<a[mid]) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};