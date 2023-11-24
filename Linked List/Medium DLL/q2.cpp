#include <bits/stdc++.h>
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector <pair<int,int>> ans;
    set <int> st;
    while(head!=NULL){
        if(st.find(k-(head->data))!=st.end()){
            ans.push_back({head->data,k-(head->data)});
        }
        else{
            st.insert(head->data);
        }
        head=head->next;
    }
    return ans;
}