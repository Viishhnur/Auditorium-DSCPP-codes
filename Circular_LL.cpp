#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* prev;
        Node* next;

        // Parametrised constructor
        Node(int val){
            data = val;
            prev = NULL;
            next = NULL;
        }

};


class CircularLinkedList{
    int size;
    public:
        Node* head;
        CircularLinkedList(){
            head = NULL;
            size = 0;
            
        }

        void insertHead(int);
        void insertTail(int);
        void insertAtIndex(int,int);
        bool isempty();
        void DeleteEnd();
        void DeleteHead();
        void deleteAtIndex(int);
        int len();
        void display();
        void printCircular();

};

int CircularLinkedList :: len(){
    return size;
}
bool CircularLinkedList :: isempty(){
    return (head==nullptr);
}
void CircularLinkedList :: insertHead(int val){
    size++;
    Node* newnode = new Node(val);
    // Node newnode(val);
    if(isempty()){

        head = newnode;
        newnode->next = head; // Circular linked list connection
    }

    else{
        
        Node* temp = head;
        while(temp->next!=head){

            temp = temp->next;

        }

        // Now temp->next is pointing to head
        // InsertHead a newnode
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
        
    }
}

void CircularLinkedList :: insertTail(int val){
    size++;
    Node* newnode = new Node(val);
    if(isempty()){
        head  = newnode;
        newnode->next = head;
    }
    else{
        // Insert at end 
        // Traverse till end and insert at end
        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        // Now temp ka next ko kardo newnode and newnode ka next mai head daldo
        temp->next = newnode;
        newnode->next = head;
    }

}

void CircularLinkedList :: insertAtIndex(int pos , int val){

    // Same as single linked list
    if(pos==0){
        insertHead(val);
    }
    else if(pos==len()-1){
        insertTail(val);
    }
    else if(pos<0 || pos>=len()){
        cout << "Index out of range, can't insert\n";
        return;
    }
    else{
        size++;
        int curr_pos = 0 ;
        Node* temp = head;
        while(temp and curr_pos<pos-1){
            curr_pos++;
            temp = temp->next;
        }
        if(temp==NULL){
            cout << "Index out of range , can't insert\n";
            return ;
        }
        else{
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next = newnode;

        }
        
    }
            
}

         
void CircularLinkedList :: DeleteHead(){

    if(isempty()){
        cout << "Not to delete , empty Linked list\n";
        return ;
    }
    
    else if(head->next==NULL){
        Node* nodeToBeDeleted = head;
        head = NULL;
        delete nodeToBeDeleted;
        size--;
    }
    else{
        Node* nodeToBeDeleted = head;

        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }

        temp->next = head->next;
        head = head->next;
        delete nodeToBeDeleted;
        size--;
        
    }
}
    

void CircularLinkedList :: DeleteEnd(){
    if(isempty()){
        cout << "Not to delete , empty Linked list\n";
        return ;
    }
    
    else if(head->next==NULL){
        size--;
        Node* nodeToBeDeleted = head;
        head =  NULL;
        delete nodeToBeDeleted;

    }
    else{
        size--;
        Node* temp = head;
        while(temp->next->next!=head){
            temp = temp->next;
        }
        temp->next = head;
        

        

    }
}

void CircularLinkedList :: deleteAtIndex(int pos){

    // Same as single linked list
    if(head==NULL){
        cout << "Nothing to delete, Linked list is empty";
        return ;
    }
    else if(pos==0){
        DeleteHead();
    }
    else if(pos==len()-1){
        DeleteEnd();
    }
    else{
        // Delete at arbitrary index
        size--;
        int curr_pos = 0 ;
        Node* temp = head;
        while(temp and curr_pos<pos-1){
            curr_pos++;
            temp = temp->next;
        }   

        if(temp == NULL) {
            cout << "Index out of range, can't delete\n";
            return;
        }
    
       Node* nodeToBeDeleted = temp->next;
       temp->next = temp->next->next;
       delete nodeToBeDeleted;
    
    }


}
    
void CircularLinkedList :: display(){
    if(isempty()){
        cout << "Linked list is empty , nothing to display\n";

    }

    else{
        Node* temp = head;
        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp!=head); // skipping checking the first node
        
        cout << "HEAD\n\n";
    }
}

void CircularLinkedList :: printCircular(){
    Node* temp = head;
    for(int i=1;i<=15;i++){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "HEAD"<< endl;
}
int main(){

    CircularLinkedList cll;

    for(int i=1;i<=5;i++){
        cll.insertTail(i);
    }

    cll.display();

    cll.insertAtIndex(2,121);
    cll.display();

    cll.DeleteHead();
    cll.display();

    cll.DeleteEnd();
    cll.display();

    cll.deleteAtIndex(2);
    cll.display();

    cll.printCircular();


    return 0;
}
