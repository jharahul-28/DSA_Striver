class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,tw=0;
        for(auto it: bills){
            if(it==5) f++;
            else if(it==10){
                t++;
                if(f==0) return false;
                f--;
            }
            else {
                tw++;
                if(f==0) return false;
                if(t!=0){
                    t--;
                    f--;
                }
                else if(t==0 && f<3) return false;
                else f-=3;
            }
        }
        return true;
    }
};