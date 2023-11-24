Node *addOne(Node *head)
{
    // Write Your Code Here.
    Node* dummy=head;
    Node* p=NULL;
    Node* n;
    while(dummy!=NULL){
        n=dummy->next;
        dummy->next=p;
        p=dummy;
        dummy=n;
    }
    Node* u=p;
    u->data++;
    int c=(u->data)/10;
    u->data=(u->data)%10;
    Node* l=u;
    Node* m=u;
    u=u->next;
    while(c){
        if(u==nullptr){
            Node* x=new Node(c%10);
            c=c/10;
            l->next=x;
            l=l->next;
        }
        else{
            u->data++;
            c=(u->data)/10;
            u->data=(u->data)%10;
            l=u;
            u=u->next;
        }
    }
    u=m;
    p=NULL;
    while(u!=NULL){
        n=u->next;
        u->next=p;
        p=u;
        u=n;
    }
    return p;
}