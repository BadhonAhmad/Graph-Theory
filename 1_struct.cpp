#include<iostream>
using namespace std;
struct node {
    int x;
    node(){
        x=0;
        cout<<"x is initialized by "<<x<<endl;
    }
    void hello();
    node(int k){
        x=k;//don't redeclare a variable
        cout<<"x is initialized by "<<x<<endl;
    }
    ~node(){
        cout<<"Bye Bye!"<<"x->"<<x<<endl;
    }
};
void node::hello(){
    x+=35;
    cout<<"x is incremented by "<<35<<"and x="<<x<<endl;
}
void hello(){
    node(66);
}
int main()
{
    node a,b(5000) , *p;//bye bye will be printed 2 times because for a and b
    cout<<"what happened"<<endl;
    a.x = 47;
    a.hello();
    p = new node(790);
    p->x=99;
    p->hello();
    delete p;
    return 0;  
}