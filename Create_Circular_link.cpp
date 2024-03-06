// Make a loop in a Single linked list
#include<iostream>
#include "LL.cpp"
using namespace std;

void makeCircular(Node* &head ,int start,int stop){
    Node* ptr1 = head;
    Node* ptr2 = head;
    for(int i=0;i<start;i++){
        ptr1 = ptr1->next;
    }
    for(int i=0;i<stop;i++){
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1;

}
void printCircular(Node* head){
    Node* temp = head;
    for(int i=1;i<=15;i++){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "HEAD"<< endl;
}

int main(){

    LinkedList ll;
    for(int i=1;i<=5;i++){
        ll.insertEnd(i);
    }
    ll.display();
    
    makeCircular(ll.head,1,3);
    printCircular(ll.head);
   
    cout << endl;

    return 0;
}
