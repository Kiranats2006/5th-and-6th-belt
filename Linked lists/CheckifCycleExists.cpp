#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void append(Node*& head, int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode-> next= nullptr;
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
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool checkIfCycleExists(Node* head){
    Node* slow= head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
            break;
        }
    }
    return false;
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
    int x;
    cin>>x;
    if(x>=1 && x<n){
        Node* temp=head;
        for(int i=0; i<x; i++){
            temp=temp->next;
        }
        Node* last=head;
        while(last->next!=nullptr){
            last=last->next;
        }
        last->next=temp;
    }
    if(checkIfCycleExists(head)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}