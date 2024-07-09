void stsort(stack<int> &s){
    if(s.empty()) return;
    int top=s.top();
    s.pop();
    if(s.empty()) {
        s.push(top);
        return;
    }
    if(s.top()>top){
        int t=s.top();
        s.pop();
        s.push(top);
        stsort(s);
        s.push(t);
    }
    else{
        stsort(s);
        s.push(top);
    }
}

void SortedStack :: sort()
{
   //Your code here
  for(int i=0;i<s.size();i++)
   stsort(s);
   
}