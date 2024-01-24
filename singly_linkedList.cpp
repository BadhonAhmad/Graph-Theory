#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

struct SinglyLinkedList
{
    node *head, *tail;
    SinglyLinkedList();
    void enqueue(int x); // add x at the end
    int dequeue();       // remove the first element
    void printList();
    /// Implement the following functions
    void search(int x);
    void insertAfterHead(int x);
    void insertBeforeTail(int x);
    void insertBeforeVal(int toFind, int toAdd);
    void insertBeforePos(int pos, int val);
    void insertAfterVal(int toFind, int toAdd);
    void insertAfterPos(int pos, int val);
    int deleteAtPos(int pos);
    int deleteHead();
    int deleteTail();
    int deleteValAfterHead();
    int deleteValBeforeTail();
};

int SinglyLinkedList::deleteTail(){
    if(head == NULL && tail == NULL){
        cout<<"underflow"<<endl;
        return -1;
    }
    int x=tail->val;
    
    

}
int SinglyLinkedList::deleteHead(){
     int x=head->val;
    if(head == NULL && tail == NULL){
        cout<<"underflow"<<endl;
        return -1;
    }
    if(head == tail){
        head=tail=NULL;
        cout<<x<<"is deleted"<<endl;
        return x;
    }

    cout<<x<<"is deleted"<<endl;
    node *temp = head->next;
    head=temp;
    return x;
}

void SinglyLinkedList::insertAfterHead(int x){
    node *cur=new node;
    if(head == NULL && tail == NULL ){
        head->next=cur;
        head=cur;
        return;
    }
   
    cur->val=x;
    if(head == tail){
        head->next=cur;
        head=cur;
        return ;
    }
    head->next=cur;
    head=cur;
    return ;
}
void SinglyLinkedList::search(int x)
{

    node *cur = head;
    if (head == NULL && tail == NULL)
        cout << "List empty\n";

    while (cur != NULL)
    {
        if (cur->val == x)
        {
            cout << "yes! you find the value" << endl;
        }
        cur = cur->next;
    }
    cout << "oops ! there is no such value" << endl;
}

int SinglyLinkedList::dequeue()//remove the first element
{

    if (head == NULL && tail == NULL)
    {
        cout << "Underflow" << endl;
        return -1;
    }
    node *cur = head;
    int x = cur->val;
    cout << x << "is dequeued" << endl;
    if (head == tail)
    {
        head = tail = NULL;
        return x;
    }
    else
        head = head->next;
    delete cur;
    return x;
}

void SinglyLinkedList::enqueue(int x)
{
    node *cur = new node;
    cur->val = x;
    cur->next = NULL;
    cout << x << " is enqueued!\n";
    if (head == NULL && tail == NULL)
    {
        head = tail = cur;
        return;
    }
    tail->next = cur;
    tail = tail->next;
}

void SinglyLinkedList::printList()
{
    cout << "the list start!\n";
    node *cur = head;
    if (cur == NULL && tail == NULL)
        cout << "List empty\n";

    while (cur != NULL)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << "the list end\n";
}

SinglyLinkedList::SinglyLinkedList()
{
    head = tail = NULL;
    cout << "singly linked list initiated\n";
}

int main()
{
    SinglyLinkedList sl;
    sl.printList();
    sl.dequeue();
    sl.search(2);
    sl.printList();
    sl.enqueue(12);
    sl.search(12);
    sl.printList();
    sl.deleteHead();
    //sl.insertAfterHead(123);
    sl.printList();
    sl.enqueue(103);
    sl.printList();
    sl.enqueue(11);
    sl.search(112);
    sl.printList();
    sl.deleteHead();
    sl.printList();
}