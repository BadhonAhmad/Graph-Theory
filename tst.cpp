#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};

struct SinglyLinkedList{
    node *head, *tail;
    /**
     * This function initializes head and tail.
     */
    SinglyLinkedList();
    /**
     * This function takes and integer as parameter
     * and add it after the last position of singly
     * linked list.
     * @return void - nothing
     * @param x - value to be added in the list
     */
    void enqueue(int x);
    /**
     * This function removes the first element from
     * the singly linked list.
     * @return int - the removed value from the list
     */
    int dequeue();
    /**
     * This function prints the whole singly linked
     * list.
     */
    void printList();
    /// Implement the following functions
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

void SinglyLinkedList::printList(){
    cout << "SinglyLinkedList - Start\n";
    node *cur = head;
    if(cur==NULL) cout << "List Empty!\n";
    while(cur!=NULL){
        cout << cur->val << "\n";
        cur = cur->next;
    }
    cout << "SinglyLinkedList - End\n";
}

int SinglyLinkedList::dequeue(){  //remove the first element
    if(head == NULL && tail == NULL){
        cout << "Underflow!\n";
        return -1;
    }
    node *cur = head;
    int x = cur->val;
    cout << x << " is dequeued!\n";
    if(head == tail) head = tail = NULL;
    else head = head->next;
    delete cur;
    return x;
}

void SinglyLinkedList::enqueue(int x){ //add an element after the last element of the list
    /// Overflow should be handled if free memory list available
    node *cur = new node;
    cur->val = x;
    cur->next = NULL;
    cout << x << " is enqueued!\n";
    if(head == NULL && tail == NULL){
        head = tail = cur;
        return;
    }
    tail->next = cur;
    tail = tail->next; /// tail = cur;
}
int SinglyLinkedList::deleteTail(){
    if(head == NULL && tail == NULL){
        cout<<"Underflow!"<<endl;
        return -1;
    }
    if(head == tail){
        head=tail=NULL;
        return head->val;
    }
    node *cur=head;
    while (cur->next != tail)
    {
        cur=cur->next;
    }
    int y=tail->val;
    cur->next=NULL;
    return y;

}
SinglyLinkedList::SinglyLinkedList(){
    head = tail = NULL;
    cout << "Singly Linked List initiated\n";
}

int main()
{
    SinglyLinkedList sl;
    sl.enqueue(1);
    sl.enqueue(2);
    sl.enqueue(3);
    sl.printList();
    sl.deleteTail();
    sl.printList();
    return 0;
}
