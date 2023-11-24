Node* sortList(Node *head){
    Node* curr=head;
    Node* p0;
    Node* p1;
    Node* p2;
    Node* sp0;    
    Node* sp1;
    Node* sp2;
    int f0=0,f1=0,f2=0;
    while(curr!=NULL){
        if(curr->data==0 && !f0) {
            sp0=curr;
            p0=curr;
            f0=1;
        }
        else {
            if(curr->data==0 && f0) {
                p0->next=curr;
                p0=p0->next;
            }
        }
        if(curr->data==1 && !f1) {
            p1=curr;
            sp1=curr;
            f1=1;
        }
        else {if(curr->data==1 && f1) {
            p1->next=curr;
            p1=p1->next;
        }}
        if(curr->data==2 && !f2) {
            p2=curr;
            sp2=curr;
            f2=1;
        }
        else {if(curr->data==2 && f2) {
            p2->next=curr;
            p2=p2->next;
        }}
        curr=curr->next;
    }
    head=sp0;
    p0->next=sp1;
    p1->next=sp2;
    p2->next=NULL;
    return head;
}