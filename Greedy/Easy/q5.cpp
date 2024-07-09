class Solution {
public:
    bool checkValidString(string s) {
        int min=0, max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            min= min<=0 ? 0 : min;
            if(max<0) return false;
        }
        cout<<"*";
        return min==0;
    }
};