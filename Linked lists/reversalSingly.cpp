#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void append(Node*& head, int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
        return;
    } 
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}
void print(Node* head){
    Node* temp= head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(Node*& head){
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main(){
    int n;
    cin>>n;
    Node* head=nullptr;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        append(head, value);
    }
    reverse(head);
    print(head);
}