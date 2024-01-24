#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

struct singlylist
{
    node *head, *tail;
    singlylist();
    void enqueue(int x);
    void printlist();
    int dequeue(); // remove the first element
    int deletetail();
    void intsertAfterHead(int x);
    void insertBeforetail(int x);
    void insertBeforeVal(int toFind, int toAdd);
    void insertAfterval(int toFind, int toAdd);
};

singlylist::singlylist()
{
    head = tail = NULL;
    cout << "singly list is inintiated" << endl;
}

void singlylist::insertBeforeVal(int toFind, int toAdd)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Underflow!,list is empty" << endl;
        return;
    }
    node *cur = new node;
    cur->val = toAdd;
    cur->next = NULL;
    if (head == tail)
    {
        if (head->val == toFind)
        {
            head = cur;
            head->next = tail;
        }
        else
        {
            cout << "oops toFind value is not in the list" << endl;
        }
        return;
    }
    if (head->val == toFind)
    {
        cur->next = head;
        head = cur;
        return;
    }
    node *temp = head, *temp1;
    while (temp->val != toFind)
    {
        temp1 = temp;
        temp = temp->next;
    }
    if (temp->val == toFind)
    {
        temp1->next = cur;
        cur->next = temp;
    }
    else
    {
        cout << "oops toFind value is not in the list" << endl;
    }
    return;
}
void singlylist::printlist()
{
    cout << "SinglyLinkedList - Start\n";
    node *cur = head;
    if (cur == NULL)
        cout << "List Empty!\n";
    while (cur != NULL)
    {
        cout << cur->val << "\n";
        cur = cur->next;
    }
    cout << "SinglyLinkedList - End\n";
}

void singlylist::enqueue(int x)
{ // add an element after the last element of the list
    /// Overflow should be handled if free memory list available
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
    tail = tail->next; /// tail = cur;
}

int singlylist::dequeue()
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return -1;
    }
    int x = head->val;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
        head = head->next;
    cout << x << " is dequeued" << endl;
    return x;
}

int singlylist::deletetail()
{
    if (head == NULL && tail == NULL)
    {
        cout << "Underflow!" << endl;
        return -1;
    }
    if (head == tail)
    {
        head = tail = NULL;
        return head->val;
    }
    node *cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    int y = tail->val;
    cur->next = NULL;
    return y;
}

void singlylist::intsertAfterHead(int x)
{
    node *cur = new node;
    cur->val = x;
    cur->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = tail = cur;
        return;
    }
    if (head == tail)
    {
        head->next = cur;
        cur->next = NULL;
        tail = cur;
        return;
    }
    cur->next = head->next;
    head->next = cur;
}
void singlylist::insertAfterval(int toFind, int toAdd)
{
    if (head == NULL && tail == NULL)
    {
        cout << "oops !the list is empty" << endl;
        return;
    }
    node *cur = new node;
    cur->val = toAdd;
    cur->next = NULL;
    if (head == tail && head->val == toFind)
    {
        head->next = cur;
        tail = cur;
        return;
    }
}
void singlylist::insertBeforetail(int x)
{
    node *cur = new node;
    cur->val = x;
    cur->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = tail = cur;
        return;
    }
    if (head == tail)
    {
        cur->next = tail;
        head = cur;
        return;
    }
    node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = cur;
    cur->next = tail;
    delete temp;
}
int main()
{
    singlylist sl;
    // sl.insertBeforetail(1234);
    // sl.printlist();
    // sl.insertBeforetail(12345);
    // sl.printlist();
    // sl.insertBeforeVal(1234,12);
    // sl.enqueue(1);
    // sl.printlist();
    // sl.intsertAfterHead(-1);
    // sl.printlist();
    // sl.enqueue(2);
    // sl.intsertAfterHead(-2);
    // sl.printlist();
    // sl.dequeue();
    // sl.printlist();
    // sl.enqueue(3);
    // sl.intsertAfterHead(123);
    // sl.dequeue();
    // sl.printlist();
    // sl.insertBeforetail(90);
    // sl.printlist();
    // sl.deletetail();//
    // sl.printlist();
    // sl.enqueue(12);
    // sl.enqueue(3);
    sl.enqueue(4);
    sl.printlist();
    sl.insertBeforeVal(12, 100);
    sl.printlist();
    return 0;
}