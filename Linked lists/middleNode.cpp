#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void append(Node*& head, int value){
    Node* newNode=new Node();
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
    if(head==nullptr){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
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
    print(head);
}