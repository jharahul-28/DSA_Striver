/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    //Write your code here
private:
    Node* head=nullptr;

public:
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        //Write your code here
        int len=0;
        Node* n=head;
        while(n!=nullptr){
            len++;
            n=n->next;
        }
        return len;
    }

    bool isEmpty()
    {
        //Write your code here
        return (head==nullptr);
    }

    void push(int data)
    {
        //Write your code here
        Node* n=new Node;
        n->data=data;
        if(head==nullptr){
            head=n;
        }
        else{
            n->next=head;
            head=n;
        }
    }

    void pop()
    {
        //Write your code here
        if(head!=nullptr){
            head=head->next;
        }
    }

    int getTop()
    {
        //Write your code here
        if(head!=nullptr){
            return(head->data);
        }
        return -1;
    }
};