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
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void removeDuplicates(Node* head){
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
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
    removeDuplicates(head);
    print(head);
return 0;
}
