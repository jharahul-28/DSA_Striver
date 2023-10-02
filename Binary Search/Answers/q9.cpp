int cnt(vector<int>& arr, int n, int m, int mid){
    int s=arr[0];
    int c=1;
    for(int i=1;i<n;i++){
        s+=arr[i];
        if(s>mid) {
            c++;
            s=arr[i];
        }  
    }
    return c;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low=arr[0];
    int high=0;
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>low) low=arr[i];
        if(arr[i]>maxi) maxi=arr[i];
        high+=arr[i];           
    }
    while(low<=high){
        int mid= (low+high)/2;
        int c=cnt(arr, n, m, mid);
        if(c<=m){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}