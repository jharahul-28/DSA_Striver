class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
         return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;
        while(even->next!=nullptr){
            odd->next=even->next;
            odd=odd->next;
            if(odd->next==nullptr)
            break;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        if(even!=nullptr)
        even->next=nullptr;
        return head;
    }
};