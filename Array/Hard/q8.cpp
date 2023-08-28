// optimal-1
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int left= m-1;
    int right=0;
    while(left>=0 && right<n){
        if(nums1[left]> nums2[right]) {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort (nums1.begin(), nums1.end());
    sort (nums2.begin(), nums2.end());
    for(int i=m+1;i<m+n;i++){
        nums1[i]=nums2[i-m-1];
    }
}

//optimal-2
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge (long long arr1[], lonmg long arr2[], int n, int m){
    int len= n+m;
    int gap= (len/2) + (len%2);
    while(gap > 0){
        int left = 0;
        int right[ left+gap ];
        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(arr1,arr2, left, right-n);
            }
            else if(left>=n){
                swapIfGreater(arr2,arr2, left-n,right-n);
            }
            else{
                swapIfGreater(arr1,arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap= (gap/2) + (gap%2);
    }
}