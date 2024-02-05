// Browser history will be implemented using a Doubly Linked List
// Defining custom class for node of DLL
class Node {
public:
    Node* prev=nullptr,*next=nullptr;
    string url;
    Node(string url, Node* prev) {
        this->prev=prev;
        this->url=url;
    }
};

class BrowserHistory {
public:
    Node* curr=nullptr;
    BrowserHistory(string homepage) {
        curr=new Node(homepage,nullptr);
    }
    void visit(string url) {
        Node* visited=new Node(url,curr);
        curr->next=visited;
        curr=curr->next;
    }
    string back(int steps) {
        while(steps) {
            if(curr->prev) curr=curr->prev;
            else break;
            steps--;
        }
        return curr->url;
    }
    string forward(int steps) {
        while(steps) {
            if(curr->next) curr=curr->next;
            else break;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */