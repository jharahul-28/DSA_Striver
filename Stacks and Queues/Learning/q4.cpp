/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    // Write Your Code Here
    Node* n=new Node(x);
    if(front==nullptr){
        front=rear=n;
    }
    else{
        rear->next=n;
        rear=n;
    }
}

int Queue::pop() {
    // Write Your Code Here
    Node* temp=front;
    if(temp==nullptr) return -1;
    int ans=temp->data;
    if(temp->next!=nullptr){
        temp=temp->next;
        front=temp;
    }
    else{
        front=rear=nullptr;
    }
    return ans;
}