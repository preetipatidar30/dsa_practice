class LRUCache {
public:
class Node{
    public:
    int key,val;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        prev=next=nullptr;

    }
};
Node*head=new Node(-1,-1);
Node*tail=new Node(-1,-1);
unordered_map<int,Node*> m;
int limit;
    LRUCache(int capacity) {
         limit =capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void delNode(Node* oldNode){
        Node* oldprev=oldNode->prev;
        Node* oldNext=oldNode->next;
        oldprev->next=oldNext;
        oldNext->prev=oldprev;

    }
    void addNode(Node* newnode){
        Node* nextnode=head->next;
        head->next=newnode;
        nextnode->prev=newnode;
        newnode->next=nextnode;
        newnode->prev=head;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansNode=m[key];
        int ans=ansNode->val;
        delNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;
        return ans;

        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node*oldnode=m[key];
            delNode(oldnode);
            m.erase(key);
            delete oldnode;

        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
      
        }
              Node*newNode=new Node(key,value);
            addNode(newNode);
            m[key]=newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */