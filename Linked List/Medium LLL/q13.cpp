class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans=nullptr;
        ListNode* p=headA;
        while(headA!=nullptr){
            headA->val=-1*headA->val;
            headA=headA->next;
        }
        int f=0;
        while(headB!=nullptr){
            if(!f && headB->val<0) {
                ans=headB;
                f=1;
            }
            headB->val=(headB->val<0)? (-1*headB->val):headB->val;
            headB=headB->next;
        }
        headA=p;
        while(headA!=ans){
            headA->val=-1*headA->val;
            headA=headA->next;
        }
        return ans;
    }
};