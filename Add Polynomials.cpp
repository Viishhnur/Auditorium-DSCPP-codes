#include<iostream>
using namespace std;

class Node{
    public:
        int coeff;
        int exp;
        Node *next;
        Node(int c,int e){
            coeff = c;
            exp = e;
            next = nullptr;
        }
};

class Polynomial{
    public:
        Polynomial(){
            
        }
        void create(Node*&);
        Node* insert(Node*,int,int);
        void print(Node*);
        Node* polyAdd(Node*,Node*);
};

Node* Polynomial :: insert(Node* head ,int c,int e){
    Node* newnode = new Node(c,e);
    if(!head || e > head->exp){
        // insert at head
        newnode->next = head;
        head = newnode;
    }
    else{
        Node* temp = head;
        while(temp->next && e <= temp->next->exp){
            temp = temp->next;
        }
        // insert newnode after temp
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

void Polynomial :: create(Node* &head){
    int n;
    cout << "Enter number of terms in polynomial : ";
    cin >> n;
    int c,e;
    for(int i=0;i<n;i++){
        cout << "Enter coefficient and exponent : ";
        cin >> c >> e ;
        head = insert(head,c,e);
    }
}

void Polynomial :: print(Node* head){
    if(!head) cout << "Empty Polynomial\n";
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
        
            cout << temp->coeff << "x^" << temp->exp ;
            temp = temp->next;
            if(temp) cout << " + " ;
        }
        // atlast print constant term
        cout << temp->coeff << endl;    
    }
}

Node* Polynomial :: polyAdd(Node* head1 , Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = nullptr;

    while(ptr1 != nullptr && ptr2 != nullptr) {
        if(ptr1->exp == ptr2->exp){
            // add like terms ka coeff
            int sum = ptr1->coeff + ptr2->coeff;
            head3 = insert(head3,sum, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp){
            head3 = insert(head3,ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else{
            head3 = insert(head3,ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }

    // Check for remaining terms in poly1 
    while(ptr1 != nullptr){
        head3 = insert(head3,ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }

    // Check for remaining terms in poly2
    while(ptr2 != nullptr){
        head3 = insert(head3,ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return head3;
}

int main(){
    
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    Polynomial p1, p2,p3;

    cout << "Enter polynomial 1: " << endl;
    p1.create(head1);

    cout << "Enter polynomial 2: " << endl;
    p2.create(head2);

    cout << "Polynomial 1 : ";
    p1.print(head1);

    cout << "Polynomial 2 : ";
    p2.print(head2);

    Node* resHead = p1.polyAdd(head1, head2);
    cout << "Resultant Polynomial : ";
    p3.print(resHead);


    return 0;
}
