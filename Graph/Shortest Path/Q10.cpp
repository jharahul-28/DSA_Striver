class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        int mod=1e5;
        queue<pair<int,int>> q;
        vector<int> dist(1e5,1e9);
        q.push({0,start});
        while(!q.empty()){
            int steps=q.front().first;
            int value=q.front().second;
            q.pop();
            for(auto it: arr){
                int val=(value*it)%mod;
                if(steps+1 < dist[val]){
                    dist[val]=steps+1;
                    if(val==end) return (steps+1);
                    q.push({steps+1,val});
                }
            }
        }
        return -1;
    }
}