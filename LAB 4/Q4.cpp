

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
     Node(int d = 0){
        data = d;
        this->next = NULL;
     }
};

class LinkedList{
    Node* head ;
    public:

    LinkedList(){
        head = NULL;
    }
    
    void insertAtStart(int d){
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
        
    }
    
    void insertAtLast(int d){
        Node* newNode = new Node(d);

        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;

    }
    void insertAtPosition(int d, int position){

        if(position < 1){
            cout<<"InValid Position"<<endl;
        }
        else if(position == 1){
            insertAtStart(d);
        }
        else {
        Node* newNode = new Node(d);

        Node* temp = head;
        for( int i =1 ; i<position-1; i++){

            if(temp ==  NULL){
                cout<<"InValid Position"<<endl;
                break;
            }
            temp= temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }

    }
    void displayLinkedList(){

        Node *temp2 = head;

        while(temp2 != NULL){
            cout<<temp2->data;
             if(temp2->next != NULL){
               cout<<",";
            }
            temp2 = temp2->next;
           
        }
        cout<<endl;
    }


};
int main(){
    LinkedList l;

    l.insertAtStart(12);
    l.insertAtLast(7);
    l.insertAtPosition(24,1);
    cout<<"Linked List : ";
    l.displayLinkedList();

    return 0;
}

