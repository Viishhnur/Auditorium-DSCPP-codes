#include<iostream>
#include<map>
#include "LL.cpp"
using namespace std;

/*
Using Floyds cycle detection method(slow is increased by one step and first by 
2 steps) return the starting node of the loop 
*/ 

bool isLoopPresent(Node* head){
    if(head==NULL){
        return false;
    }
    
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL and fast!=NULL){
        slow = slow->next;
        fast = fast->next;

        if(fast!=NULL){
            fast = fast->next;
        }

        if(slow==fast){
            return true;
        }
        
    }
    return false;


}

Node* getLoopNode(Node* head){
// Get starting node of the loop
    if(isLoopPresent(head)){
        map<Node*,bool> visited;
        Node* temp = head;
        while(temp){
            if(visited[temp]==true){
                return temp; // This is the beginning of the loop
            }
            visited[temp] = true;
            temp = temp->next;
        }
        
    }
    
    return NULL;


}
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
    cout<< endl;
}

int main(){

    LinkedList ll;
    for(int i=1;i<=7;i++){
        ll.insertEnd(i);
    }
    ll.display();
    makeCircular(ll.head,2,6);
    printCircular(ll.head);
    if(getLoopNode(ll.head)!=NULL){
        cout <<"Loop starts at element : "<< getLoopNode(ll.head)->data << endl;
    }
    else{
        cout << "No loop exists in given linked list\n";
    }

    return 0;
}
