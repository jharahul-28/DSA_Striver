class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int> ans(queries);
       for(int i=0;i<queries;i++){
           int cur= arr[indices[i]];
           int r=n-1, c=0;
           while(r>indices[i]){
               if(cur<arr[r]) c++;
               r--;
           }
           ans[i]=c;
       }
       return ans;
    }

};