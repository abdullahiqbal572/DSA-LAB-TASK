
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
        head = NULL;
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

    l.insertAtStart(8);
    l.insertAtLast(10);
    l.insertAtLast(15);
    cout<<"Linked List : ";
    l.displayLinkedList();
    
}

