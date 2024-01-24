
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct SinglyLinkedList
{
    node *head, *tail;

    SinglyLinkedList();
    void enqueue(int x);
    int dequeue();
    void printList();
    /// Implement the following functions
    void insertAfterHead(int x);//done
    void insertBeforeTail(int x);//done
    void insertBeforeVal(int toFind, int toAdd);//done
    void insertBeforePos(int pos, int val);//done
    void insertAfterVal(int toFind, int toAdd);//done
    void insertAfterPos(int pos, int val);//done
    int deleteAtPos(int pos);//done
    int deleteHead();//done
    int deleteTail();//done
    int deleteValAfterHead();//done
    int deleteValBeforeTail();//done
};

SinglyLinkedList::SinglyLinkedList()
{
    head = tail = NULL;
    cout << "Link list has been initiated" << '\n';
}

int SinglyLinkedList::deleteValAfterHead()
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no node in the linkedlist\n";
        return -1;
    }
    if(head==tail)
    {
        cout<<"There is only one node!\n";
        return -1;
    }
    node *temp;
    int x;
    if(head->next==tail)
    {
        x=tail->val;
        delete tail;
        tail=head;
        tail->next=head->next=NULL;
        cout<<x<<" has been deleted after head!"<<endl;
        return x;
    }
    temp=head->next;
    x=temp->val;
    head->next=temp->next;
    delete temp;
    cout<<x<<" has been deleted after head!\n";
    return x;

}

int SinglyLinkedList:: deleteValBeforeTail()
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no node in the linkedlist\n";
        return -1;
    }
    if(head==tail)
    {
        cout<<"There is only one node\n";
        return -1;
    }
    int x;
    node *temp=head,*temp1;

    if(head->next==tail)
    {
        x=head->val;
        head=tail;
        cout<<x<<" has been deleted before tail!\n";
        delete temp;
        return x;
    }
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    while(temp->next!=tail)
    {
        temp1=temp;
        temp=temp->next;
    }
    x=temp->val;
    temp1->next=tail;
    delete temp;
    cout<<x<<" has been deleted before tail\n";

    return x;
}

void SinglyLinkedList::insertAfterVal(int toFind, int toAdd)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no node in the linkedlist!\n";
        return;
    }
    node *cur=new node;
    cur->val=toAdd;
    
    node *temp=head;
    if(temp->val==toFind)
    {
        cur->next=temp->next;
        temp->next=cur;
        cout<<toAdd<<" has been inserted after the value "<<toFind<<endl;
        return;
    }
    
    bool test=false;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        if(temp->val==toFind)
        {
            test=true;
            break;
        }
    }
    if(test)
    {
        
        cur->next=temp->next;
        temp->next=cur;
        
        cout<<toAdd<<" has been inserted after the value "<<toFind<<endl;
    }
    else
    {
        cout<<toFind<<" is not in the linkedlist!"<<endl;
    }
    return;

}

void SinglyLinkedList::insertBeforeVal(int toFind, int toAdd)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no node!\n";
        return;
    }

    node *cur=new node;
    cur->val=toAdd;
    if(head==tail && head->val==toFind)
    {
        cur->next=head;
        head=cur;
        tail->next=NULL;
        cout<<toAdd<<" has been inserted before the value "<<toFind<<endl;
        return;
    }
    
    node *temp2=head,*temp1;
    if(temp2->val==toFind)
    {
        cur->next=head;
        head=cur;
        cout<<toAdd<<" has been inserted before the value "<<toFind<<endl;
        return;
    }
    bool test=false;
    while(temp2->next!=NULL)
    {
        temp1=temp2;
        temp2=temp2 -> next;
        if(temp2->val == toFind)
        {
            test=true;
            break;
        }
    }
    if(test)
    {
        cur->next=temp2;
        temp1->next=cur;
        cout<<toAdd<<" has been inserted before the value "<<toFind<<endl;
    }
    else
    {
        cout<<toFind<<" is not in the linkedlist!\n";
    }
    return;
}

void SinglyLinkedList::insertAfterPos(int pos, int val)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no position to insert!\n";
        return;
    }
    node *cur = new node;
    cur->val = val;
    node *test=head;
    int cnt=1,i=1;
    while(test->next!=NULL)
    {
        test=test->next;
        cnt++;
    }
    if(pos>cnt)
    {
        cout<<"Invalid position! Because maximum position is "<<cnt<<endl;
        return;
    }

    if(pos==cnt)
    {
    
        tail->next=cur;
        cur->next=NULL;
        cout<<val<<" has been inserted after position(Maximum) "<<pos<<endl;
        tail=cur;
        return;
    }

    if(pos==1)
    {
        cur->next=head->next;
        head->next=cur;
        cout<<val<<" has been inserted after position "<<pos<<endl;
        return;
    }
    node *temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    cur->next=temp->next;
    temp->next=cur;
    cout<<val<<" has been inserted after position "<<pos<<endl;
    return;
}

void SinglyLinkedList::insertBeforePos(int pos, int val)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"There is no position to insert!\n";
        return;
    }
    node *cur = new node;
    cur->val=val;
    node *test=head;
    int cnt=1,i=1;
    while(test->next!=NULL)
    {
        test=test->next;
        cnt++;
    }
    if(pos>cnt)
    {
        cout<<"Invalid position! Because maximum position is "<<cnt<<endl;
        return;
    }
    if(pos==1)
    {
        cur->next=head;
        head=cur;
        cout<<val<<" has been inserted before position "<<pos<<endl;
        return;
    }
    node *temp1,*temp2=head;
    while(i<pos)
    {
        temp1=temp2;
        temp2=temp2->next;
        i++;
    }
    cur->next=temp2;
    temp1->next=cur;
    cout<<val<<" has been inserted before position "<<pos<<endl;
    return;

}

int SinglyLinkedList::deleteHead()
{
    dequeue();
}

void SinglyLinkedList::printList()
{
    cout << "SinglyLinkedList - Start\n";
    node *cur = head;
    if (cur == NULL)
        cout << "The list is empty" << '\n';
    while (cur != NULL)
    {
        cout << cur->val << '\n';
        cur = cur->next;
    }
    cout << "SinglyLinkedList - END\n";
}

void SinglyLinkedList::enqueue(int x)
{
    node *cur = new node;
    cur->val = x;
    cur->next = NULL;
    cout << x << "- is enqueued!\n";
    if (head == NULL)
    {
        head = tail = cur;
        return;
    }
    tail->next = cur;
    tail = cur;
}

int SinglyLinkedList::dequeue()
{
    if (head == NULL & tail == NULL)
    {
        cout << "Underflow!\n";
        return -1;
    }
    node *cur = head;
    int x = cur->val;
    cout << x << " is dequeued!\n";
    if (head == tail)
        head = tail = NULL;
    else
        head = head->next;
    delete cur;
    return x;
}

void SinglyLinkedList::insertAfterHead(int x)
{
    if (head == NULL)
    {
        cout << "No head node\n";
        return;
    }

    node *cur = new node;
    cur->val = x;
    cout << x << " has been inserted after head!\n";
    if (head == tail)
    {
        cur->next = NULL;
        tail = cur;
    }
    else
        cur->next = head->next;
    head->next = cur;
    
    return;
}
void SinglyLinkedList::insertBeforeTail(int x)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"Insufficient nodes\n";
        return;
    }
    node *cur=new node;
    cur->val=x;
    cout<<x<<" has been inserted before tail!\n";
    if(head == tail)
    {
        cur->next = head;
        head = cur;
        return;
    }
    node *temp = head;
    while(temp->next != tail)
        temp = temp->next;
    cur->next = tail;
    temp->next = cur;
    return;
}

int SinglyLinkedList::deleteAtPos(int pos)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"Underflow! There is no node to delete\n";
        return -1;
    }
    int cnt=1;
    node *cur=head,*temp,*other=head;
    while(other->next!=NULL)
    {
        other=other->next;
        cnt++;
    }
    if(pos>cnt)
    {
        cout<<"Invalid position! because maximum position is "<<cnt<<".\n";
        return -1;
    }
    int x,i=1;
    
    if(pos==1 && pos!=cnt)
    {
        head=head->next;
        x=cur->val;
        cout<<x<<" has been deleted from position "<<pos<<"!\n";
        delete cur;
        return x;
    }
    
    if(pos==1  && pos==cnt)
    {
        x=tail->val;
        cout<<x<<" has been deleted from position "<<pos<<"!\n";
        delete tail;
        head=tail=NULL;
        return x;
    }
    
    while(i<pos-1)
    {
        cur=cur->next;
        i++;
    }
    temp=cur->next;
    x=temp->val;
    cout<<x<<" has been deleted from position "<<pos<<"!\n";
    cur->next=temp->next;
    if(pos==cnt)
    {
        tail=cur;
        tail->next=NULL;
    }
    temp->next=NULL;
    delete temp;
    return x;
}

int SinglyLinkedList::deleteTail()
{
    node *cur,*temp=head;
    int x;
    if(head==NULL && tail==NULL)
    {
        cout<<"No node to delete tail\n";
        return -1;
    }
    if(head==tail)
    {
        cur=head;
        x=cur->val;
        cout<<x<<" has been deleted from tail!\n";
        delete cur;
        head=tail=NULL;
        return x;
    }
    while(temp->next!=NULL)
    {
        cur=temp;
        temp=temp->next;
    }
    cur->next=NULL;
    x=temp->val;
    cout<<x<<" has been deleted from tail!\n";
    tail=cur;
    delete temp;
    return x;
}

int main()
{
    SinglyLinkedList sl;
    sl.printList();
    // sl.enqueue(78);sl.printList();
    // sl.enqueue(54);sl.printList();
    // sl.enqueue(85);sl.printList();
    
    // cout<<"\n\n\n";
    // sl.dequeue();sl.printList();
    // sl.dequeue();sl.printList();
    // sl.dequeue();sl.printList();
    // sl.dequeue();sl.printList();
    // sl.insertAfterHead(23);sl.printList();

    // cout<<"\n\n\n";
    // sl.insertBeforeTail(21);sl.printList();
    // sl.enqueue(12);sl.printList();
    // sl.insertBeforeTail(21);sl.printList();
    // sl.insertAfterHead(26);sl.printList();
    // sl.enqueue(46);sl.printList();
    // sl.enqueue(63);sl.printList();
    // sl.insertAfterHead(23);sl.printList();
    // sl.insertBeforeTail(39);sl.printList();
    

    // cout<<"\n\n\n";
    // sl.deleteAtPos(4);sl.printList();
    // sl.deleteAtPos(4);sl.printList();
    // sl.deleteAtPos(1);sl.printList();
    // sl.deleteAtPos(4);sl.printList();
    // sl.deleteAtPos(4);sl.printList();
    // sl.deleteAtPos(3);sl.printList();
    // sl.deleteAtPos(2);sl.printList();
    // sl.deleteAtPos(1);sl.printList();
    // sl.deleteAtPos(1);sl.printList();

    // cout<<"\n\n\n";
    // sl.enqueue(28);sl.printList();
    // sl.enqueue(47);sl.printList();
    // sl.enqueue(50);sl.printList();
    // sl.deleteTail();sl.printList();
    // sl.deleteTail();sl.printList();
    // sl.deleteTail();sl.printList();
    // sl.deleteTail();sl.printList();

    // cout<<"\n\n\n";
    // sl.deleteHead();sl.printList();
    // sl.enqueue(22);sl.printList();
    // sl.deleteHead();sl.printList();
    // sl.enqueue(23);sl.printList();
    // sl.enqueue(24);sl.printList();
    // sl.enqueue(25);sl.printList();
    // sl.deleteHead();sl.printList();
    // sl.deleteHead();sl.printList();
    // sl.deleteHead();sl.printList();
    // cout<<"\n\n\n";
    // sl.insertBeforePos(2,3);sl.printList();
    // sl.enqueue(5);sl.printList();
    // sl.insertBeforePos(2,3);sl.printList();
    // sl.insertBeforePos(1,2);sl.printList();
    // sl.insertBeforePos(2,3);sl.printList();
    // sl.insertBeforePos(3,4);sl.printList();

    // cout<<"\n\n\n";
    // sl.insertAfterPos(1,1);sl.printList();
    // sl.enqueue(1);sl.printList();
    // sl.insertAfterPos(1,2);sl.printList();
    // sl.insertAfterPos(2,3);sl.printList();
    // sl.insertAfterPos(3,6);sl.printList();
    // sl.insertAfterPos(3,4);sl.printList();
    // sl.insertAfterPos(4,5);sl.printList();

    // cout<<"\n\n\n";
    // sl.insertBeforeVal(11,10);sl.printList();
    // sl.enqueue(12);sl.printList();
    // sl.insertBeforeVal(12,9);sl.printList();
    // sl.insertBeforeVal(20,21);sl.printList();
    // sl.insertBeforeVal(11,10);sl.printList();
    // sl.insertBeforeVal(9,8);sl.printList();
    // sl.insertBeforeVal(12,11);sl.printList();

    // cout<<"\n\n\n";
    // sl.insertAfterVal(1,2);sl.printList();
    // sl.enqueue(1);sl.printList();
    // sl.insertAfterVal(1,4);sl.printList();
    // sl.insertAfterVal(1,2);sl.printList();
    // sl.insertAfterVal(2,3);sl.printList();
    // sl.insertAfterVal(4,5);sl.printList();
    // sl.insertAfterVal(6,7);sl.printList();

    // cout<<"\n\n\n";
    // sl.deleteValBeforeTail();sl.printList();
    // sl.enqueue(6);sl.printList();
    // sl.deleteValBeforeTail();sl.printList();
    // sl.enqueue(7);sl.printList();
    // sl.deleteValBeforeTail();sl.printList();
    // sl.deleteValBeforeTail();sl.printList();
    // sl.enqueue(8);sl.printList();
    // sl.enqueue(9);sl.printList();
    // sl.enqueue(10);sl.printList();
    // sl.deleteValBeforeTail();sl.printList();
    // sl.deleteValBeforeTail();sl.printList();

    cout<<"\n\n\n";
    sl.deleteValAfterHead();sl.printList();
    sl.enqueue(6);sl.printList();
    sl.deleteValAfterHead();sl.printList();
    sl.enqueue(7);sl.printList();
    sl.deleteValAfterHead();sl.printList();
    sl.enqueue(8);sl.printList();
    sl.enqueue(9);sl.printList();
    sl.enqueue(10);sl.printList();
    sl.deleteValAfterHead();sl.printList();

    return 0;
}