class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr)
        return nullptr;
        vector <pair<ListNode*,ListNode*>> v;
        ListNode* node=head;
        while(node!=nullptr){
            v.push_back({node, node->next});
            node=node->next;
        } 
        int s=v.size();
        if(s==n) head=head->next;
        else{
            node=v[s-n-1].first;
            node->next=v[s-n].second;
        }
        return head;
    }
};