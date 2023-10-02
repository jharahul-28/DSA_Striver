class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1=s.size();
        int len2=goal.size();
        if(len1!=len2) return false;
        char c=s[0];
        int pivot=0;
        while(pivot<=len1){
            for(int i=pivot;i<len2;i++){
                if(goal[i]==c) {
                    pivot=i;
                    break;
                }
            }
            int f=1;
            for(int i=0;i<len1;i++){
                if(s[i]==goal[(pivot+i)%len1])
                f=1;
                else{ 
                    f=0;
                    break;
                }
            }
            if(f) return true;
            pivot++;
        }
        return false;
    }
};