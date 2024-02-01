// Defining Node class for the Linked List
class Node {
public:
    Node* next=nullptr;
    int val;
    Node(int val) {
        this->val=val;
    }
    Node(int val, Node* next) {
        this->val=val;
        this->next=next;
    }
};

class MyLinkedList {
public:
    Node* head;
    int get(int index) {
        if(!head) return -1;
        Node* tmp=head;
        for(int i=0;i<index;i++) {
            tmp=tmp->next;
            if(!tmp) return -1;
        }
        return tmp->val;
    }
    void addAtHead(int val) {
        if(!head) {
            head=new Node(val);
            head->next=nullptr;
        }
        else {
            Node* x=new Node(val,head);
            head=x;
        }
    }
    void addAtTail(int val) {
        if(!head) head=new Node(val);
        else {
            Node* x=new Node(val),*tmp=head,*prev=tmp;
            while(tmp) {
                prev=tmp;
                tmp=tmp->next;
            }
            prev->next=x;
        }
    }
    void addAtIndex(int index, int val) {
        if(!index) {
            addAtHead(val);
            return;
        }
        if(!head) return;
        Node* tmp=head,*x=new Node(val);
        for(int i=0;i<index-1;i++) {
            tmp=tmp->next;
            if(!tmp) return;
        }
        Node* succ=tmp->next;
        tmp->next=x;
        x->next=succ;
    }
    void deleteAtIndex(int index) {
        Node* prev=head,*tmp=head;
        if(!index) {
            head=head->next;
            delete(prev);
            return;
        }
        while(index--) {
            prev=tmp;
            tmp=tmp->next;
            if(!tmp) return;
        }
        prev->next=tmp->next;
        delete(tmp);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */