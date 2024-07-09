/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,int>> a(n);
        for(int i=0;i<n;i++){
            double avg= static_cast<double>(arr[i].value*1.000000)/arr[i].weight;
            a[i]={avg,i};
        }
        sort(a.rbegin(), a.rend());
        double ans=0.000000;
        for(int i=0;i<n && w>0;i++){
            int pos=a[i].second;
            double av=a[i].first;
            if(arr[pos].weight < w) {
                ans+=arr[pos].value;
                w-=arr[pos].weight;
            }
            else {
                ans+=arr[pos].value* static_cast<double>(w) /arr[pos].weight;
                break;
            }
        }
        return ans;
    }
};