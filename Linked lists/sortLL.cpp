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
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void sortLL(Node* head){
Node* i=head;
while(i!=nullptr){
    Node* j=i->next;
    while(j!=nullptr){
        if(i->data>j->data){
            int temp=i->data;
            i->data=j->data;
            j->data=temp;
        }
        j=j->next;
    }
    i=i->next;
}
}
int main(){
    int n;
    cin>>n;
    Node* head=nullptr;
    for(int i=0; i<n;i++){
        int value;
        cin>>value;
        append(head, value);
    }
    sortLL(head);
    print(head);
    return 0;
}