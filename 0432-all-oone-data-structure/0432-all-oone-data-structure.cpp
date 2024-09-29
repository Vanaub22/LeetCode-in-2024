// Using a DLL to maintain order and a HashMap for O(1) storage and retrieval
// DLL node structure keeps all nodes having a particular frequency together inside a set
// The HashMap will link keys to their corresponding nodes in the DLL

// DLL node structure
class Node {
public:
    Node* prev,*next;
    unordered_set<string> keys;
    int freq;
    Node(int f) {
        freq=f;
        prev=next=nullptr;
    }
};

class AllOne {
private:
    Node *dhead,*dtail;
    unordered_map<string,Node*> ref;
    void removeNode(Node* node) {
        Node* prevNode=node->prev,*nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        delete node;
    }
public:
    AllOne() {
        dhead=new Node(0),dtail=new Node(0);
        dhead->next=dtail,dtail->prev=dhead;
    }

    void inc(string key) {
        if(ref.find(key)==ref.end()) {
            Node* nextNode=dhead->next;
            if(nextNode==dtail || nextNode->freq>1) {
                Node* node=new Node(1);
                node->keys.insert(key);
                node->prev=dhead,node->next=nextNode;
                dhead->next=node,nextNode->prev=node;
                ref[key]=node;
            }
            else {
                nextNode->keys.insert(key);
                ref[key]=nextNode;
            }
        }
        else {
            Node* node=ref[key];
            int f=node->freq;
            node->keys.erase(key);
            Node* nextNode=node->next;
            if(nextNode==dtail || nextNode->freq!=f+1) {
                Node* newNode=new Node(f+1);
                newNode->keys.insert(key);
                newNode->prev=node,newNode->next=nextNode;
                node->next=newNode,nextNode->prev=newNode;
                ref[key]=newNode;
            }
            else {
                nextNode->keys.insert(key);
                ref[key]=nextNode;
            }
            if(node->keys.empty()) removeNode(node);
        }
    }
    
    void dec(string key) {
        Node* node=ref[key];
        node->keys.erase(key);
        int f=node->freq;
        if(f==1) ref.erase(key);
        else {
            Node* prevNode=node->prev;
            if(prevNode==dhead || prevNode->freq!=f-1) {
                Node* newNode=new Node(f-1);
                newNode->keys.insert(key);
                newNode->prev=prevNode,newNode->next=node;
                prevNode->next=newNode;
                node->prev=newNode;
                ref[key]=newNode;
            }
            else {
                prevNode->keys.insert(key);
                ref[key]=prevNode;
            }
        }
        if(node->keys.empty()) removeNode(node);
    }
    
    string getMaxKey() {
        return dtail->prev==dhead || dtail->prev->keys.empty()?"":*(dtail->prev->keys.begin());
    }
    
    string getMinKey() {
        return dhead->next==dtail || dhead->next->keys.empty()?"":*(dhead->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */