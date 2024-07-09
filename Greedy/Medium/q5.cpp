// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    bool static comparator(Job a, Job b){
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comparator);
        int cnt=0, p=0;
        int mx=arr[0].profit;
        for(int i=1;i<n;i++){
            mx=max(mx, arr[i].profit);
        }
        vector<int> dpr(mx+1,-1);
        for(int i=0;i<n;i++){
            int d=arr[i].dead;
            for(int j=d;j>0;j--){
                if(dpr[j]<arr[i].profit){
                    cnt++;
                    p+=(dpr[j]!=-1) ? arr[i].profit-dpr[j] : arr[i].profit;
                    dpr[j]=arr[i].profit;
                    break;
                }
            }
        }
        return {cnt,p};
    } 
};