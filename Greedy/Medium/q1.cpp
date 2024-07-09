class Solution
{
    public:
    struct data
    {
        //start, end, position
        int s;
        int e;
        int p;
    };
    bool static comparator(data v1, data v2){
        return (v1.e < v2.e);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        data d[n];
        for(int i=0;i<n;i++){
            d[i].s=start[i];
            d[i].e=end[i];
            d[i].p=i+1;
        }
        sort(d, d+n, comparator);
        int cnt=1, freeTime=d[0].e;
        for(int i=1;i<n;i++){
            if(d[i].s>freeTime){
                cnt++;
                freeTime=d[i].e;
            }
        }
        return cnt;
    }
};