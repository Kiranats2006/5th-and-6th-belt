#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};
void append(Node*& head, int value){
Node* newNode=new Node();
newNode->data=value;
newNode->next=nullptr;
newNode->prev=nullptr;
if(head==nullptr){
  head=newNode;
  return;
}
Node* temp=head;
while(temp->next!=nullptr){
  temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
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
Node* temp=nullptr;
Node* current=head;
while(current!=nullptr){
  temp=current->prev;
  current->prev=current->next;
  current->next=temp;
  current=current->prev;
}
if(temp!=nullptr){
  head=temp->prev;
}
}
int main() 
{
  int n;
  cin>>n;
  Node* head=nullptr;
  for (int i=0; i<n; i++){
    int value;
    cin>>value;
    append(head,value);
  }
  reverse(head);
  print(head);
  return 0;
}