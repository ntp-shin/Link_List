#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev; // previous
};

void insert(Node** head_r, int x){//tail
    Node* cur = *head_r;
    if(cur == NULL){
        *head_r = new Node{x, NULL, NULL};
        return;
    }
    while (cur->next != NULL){
        cur = cur->next;
    }
    Node* temp = new Node{x, NULL, cur};
    cur->next = temp;
    return;
}

Node* add_tail(Node* head, int x){
    if(head == NULL)
        return new Node{x, NULL, NULL};
    else{
        head->next = add_tail(head->next, x);
        head->next->prev = head;
    }
    return head;
}

void addtail(Node* head, int x){
    Node* cur = head;
    if(cur == NULL){
        head = new Node{x, NULL, NULL};
        return;
    }
    while (cur->next != NULL){
        cur = cur->next;
    }  
    Node* temp = new Node{x, NULL, cur};
    cur->next = temp;
    return; 
}

Node* add_head(Node* head, int x){
    if(head == NULL)
        return new Node{x, NULL, NULL};
    Node* temp = new Node{x, head, NULL};
    head->prev = temp;
    return temp;
}

void addhead(Node* &head, int x){
    if(head == NULL){        
        head = new Node{x, NULL, NULL};
        return;
    }    
    Node* temp = new Node{x, head, NULL};
    head->prev = temp;
    head = temp;
    return;
}

void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
}

void print(Node* head){
    if(head != NULL){
        cout << head->data << " - " ;
        print(head->next);
    }
}
void Delete(Node* &head, int x){
    if(head == NULL){
        return;
    }       
    if(head->data == x){
        Node* temp = head->next;
        if(temp != NULL)            temp->prev = NULL;
        delete head;
        head = temp;
        return;
    }
    Node* cur = head->next;
    while (cur->data != x && cur->next != NULL)
        cur = cur->next;
    if(cur == NULL)
        return;
    
    if(cur->next == NULL)
        cur->prev->next = NULL;
    else{
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    delete cur;
}

Node* Del_(Node* head, int x){
    if(head == NULL)
        return head;
    if(head->data != x)
        head->next = Del_(head->next, x);
    else{
        Node* cur = head->next;
        if(head->prev == NULL){
            cur->prev = NULL;
        }
        else{
            head->prev->next = cur;
            cur->prev = head->prev;
        }
        delete head;
        return cur;
    }
    return head;
}
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    head = add_tail(head, 5);
    head = add_tail(head, 9);
    head = add_tail(head, 10);
    head = add_tail(head, 2);
    head = add_tail(head, 3);

    head = Del_(head, 9);
    printList(head);
    return 0;
}