class Solution {
public:
    string largestOddNumber(string num) {
        int i=0;
        for(i=num.size()-1;i>=0;i--){
          if((num[i]-'0')%2!=0)
          break;
        }
        if(i<0)
        return "";
        return num.substr(0,i+1);
    }
};