class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) 
        return head;
        ListNode* curr=head;
        int cnt=0;
        while(curr!=nullptr){
            cnt++;
            curr=curr->next;
        }
        k=k%cnt;
        while(k--){
            ListNode* last=head;
            ListNode* prev=nullptr;
            while(last->next!=nullptr){
                prev=last;
                last=last->next;
            }
            prev->next=nullptr;
            last->next=head;
            head=last;
        }
        return head;
    }
};