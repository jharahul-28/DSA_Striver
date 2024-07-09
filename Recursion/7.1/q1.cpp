class Solution {
public:
    int sum=0;
    void f(int ind, string s, int n){
        if (ind == n) return;
        if (!(s[ind] - '0' >= 0 && s[ind] - '0' <= 9)) return;
        int d = s[ind] - '0';
        if (sum > (INT_MAX - d) / 10) {
            sum = INT_MAX;
            return;
        }
        sum = sum * 10 + d;
        f(ind + 1, s, n);
    }
    int myAtoi(string s) {
        if(s=="-2147483647") return -2147483647;
        int n=s.size(),nf=0,i;
        for(i=0;i<n;i++){
            if(s[i]==' ') continue;
            else if(s[i]=='-') {
                nf=1;
                if (i<(n-1) && !(s[i+1] - '0' >= 0 && s[i+1] - '0' <= 9)) return 0;
                continue;
            }
            else if(s[i]=='+') {
                nf=0;
                if (i<(n-1) && !(s[i+1] - '0' >= 0 && s[i+1] - '0' <= 9)) return 0;
                continue;
            }
            else if(!(s[i]-'0'>=0 && s[i]-'0'<=9)) return 0;
            else break;
        }
        f(i,s,n);
        return (nf==1) ? (sum==INT_MAX) ? INT_MIN : -1*sum : sum;
    }
};