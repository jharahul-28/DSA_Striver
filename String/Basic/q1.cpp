class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int cnt=0;
        for(auto i:s){
            if(i=='('){
                if(cnt>0){
                    result.push_back(i);
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};