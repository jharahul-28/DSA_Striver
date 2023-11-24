/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr && l2==nullptr) return nullptr;
        int s,c=0;
        ListNode* ans;
        if(l1!=nullptr && l2!=nullptr){
            s=l1->val+l2->val+c;
            c=s/10;
            s=s%10;
            ans= new ListNode(s);
        }
        ListNode* b=ans;
        l1=l1->next;
        l2=l2->next;
        while(l1!=nullptr && l2!=nullptr){
            s=l1->val+l2->val+c;
            c=s/10;
            s=s%10;
            ListNode* a=new ListNode(s);
            b->next=a;
            b=a;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            s=l1->val+c;
            c=s/10;
            s=s%10;
            ListNode* a=new ListNode(s);
            b->next=a;
            b=a;
            l1=l1->next;
        }
        while(l2!=nullptr){
            s=l2->val+c;
            c=s/10;
            s=s%10;
            ListNode* a=new ListNode(s);
            b->next=a;
            b=a;
            l2=l2->next;
        }
        if(c){
            ListNode* a=new ListNode(c);
            b->next=a;
            b=a;
        }
        return ans;
    }
};