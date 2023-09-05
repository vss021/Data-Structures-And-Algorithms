#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
// constructure
    Node(int data){
        this->data = data;
        this ->next = NULL;
    }
// destructure
    ~Node(){
        int value = this->data;
        if(this->data != NULL){
            delete next;
        }
        cout<< "Memory is free : " << value << endl;
    }
};

void InsertAtHead(Node* &head, int d){
    // creat a new Node
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node * &tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}


void InsertAtPosition(Node* &head, Node* &tail, int d, int p){

    if(p == 1 ){
        InsertAtHead(head, d);
        return;
    }
    Node *temp = new Node(d);
    Node *curr =head;
    int cnt = 1;
    while(cnt < p-1){
        // demmy = demmy
        curr = curr->next;
        cnt++;
    }  

    if(curr -> next == NULL){
        InsertAtTail(tail, d);
        return;
    }
    // curr -> next = temp;
    temp -> next = curr -> next;
    curr ->next = temp;

}





void deleteNode(Node* &head, int p){

// deleting fist
    if(p == 1){
    Node* temp = head;
    head = head->next; 
    temp -> next = NULL;
    delete temp;       
    }
    else{
        // medial ans last
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < p){

            prev = curr;
            curr =curr->next;
            cnt++;

        }

        prev -> next = curr -> next;
        curr ->next = NULL;
        delete curr;

    }
}





void printlist(Node* &head){

    Node * temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;

}
int main()
{
    Node* node1 = new Node(10);
    Node * head = node1;
    Node * tail = node1;
    InsertAtHead(head, 8);
    InsertAtHead(head, 5);
    InsertAtHead(head, 3);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 20);


    printlist(head);

    cout<< "Head data => "<< head->data << endl;
    cout<< "Tail Data is :" << tail->data << endl;

    // cout<< "TC : "<< endl;
    // int tc;
    // cin >> tc;
    // while(tc--){
    //     cout<< " \n Enter the Data Positions " << endl;
    //     int data, p;
    //     cin>> data >> p;
    //     InsertAtPosition(head, tail, data, p);
    //     cout << " \n result is " << endl;
    //     printlist(head);
    // }
    deleteNode(head, 1);
    

    printlist(head);
    cout<< "Head data => "<<head->data << endl;
    cout<< "tail data =>" <<tail->data << endl;


    return 0;
}