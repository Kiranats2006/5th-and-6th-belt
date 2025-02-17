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
Node* addingLL(Node* l1, Node* l2){
    Node* result=nullptr;
    Node* tail=nullptr;
    int carry=0;
    while(l1 || l2 || carry>0){
        int sum=carry;
        if(l1){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->data;
            l2=l2->next;
        }
        carry=sum/10;
        sum=sum%10;
        Node* newNode= new Node();
        newNode->data=sum;
        newNode->next=nullptr;
        if(result==nullptr){
            result=newNode;
            tail=result;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }
    return result;
}
int main() {
    int n, m;
    cin >> n; // Input the number of elements in the first list

    Node* head1 = nullptr;
    // Create the first linked list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        append(head1, value);
    }

    cin >> m; // Input the number of elements in the second list

    Node* head2 = nullptr;
    // Create the second linked list
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        append(head2, value);
    }

    // Add the two lists
    Node* result = addingLL(head1, head2);

    // Print the result
    print(result);
}