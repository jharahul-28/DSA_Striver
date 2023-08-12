void mergeSort(int arr[], int low, int high){
    if(low>=high) return ;
    int mid=(low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void merge(int arr[], int low, int mid, int high){
    int left=low;
    int right= mid+1;
    vector <int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    if(left< mid){
        while (left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
    }
     if(right< high){
        while (right<=mid)
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    for(int i=low; i<=high;i++){
        arr[i]= temp[i-low];
    }
}