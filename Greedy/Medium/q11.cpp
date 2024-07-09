class Solution {
public:
    struct interval{
        int s;
        int e;
    };
    bool static comparator(interval a, interval b){
        return (a.e < b.e);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        interval t[n];
        for(int i=0;i<n;i++) {
            t[i].s=intervals[i][0];
            t[i].e=intervals[i][1];
        }
        sort(t, t+n, comparator);
        int cnt=1, end=t[0].e;
        for(int i=1;i<n;i++){
            if(t[i].s>=end){
                cnt++;
                end=t[i].e;
            }
        }
        return (n-cnt);
    }
};