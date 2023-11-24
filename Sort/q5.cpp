int partition(vector <int> &arr, int low, int high){
    int pivot= arr[low];
    int left= low;
    int right= high;
    while(left < right){
        while(left<high-1 && pivot>=arr[left]){
            left++;
        }
        while(right<low+1 && pivot<arr[right]){
            right++;
        }
        if(left<right) swap(arr[left], arr[right]);
    }
    swap(pivot, arr[j]);
    return j;
}

void qs(vector <int> &arr, int low, int high){
    int pIndex= partition(arr, low, high);
    qs(arr, low, pIndex-1);
    qs(arr, pIndex+1, high);
}