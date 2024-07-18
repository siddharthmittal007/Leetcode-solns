// DLL node definition
class Node{
    public:
        int Key;
        int Value;
        Node *prev;
        Node *next;
        Node(int _Key,int _Value)
        {
            Key=_Key;
            Value=_Value;
            prev=next=NULL;
        }
};

class LRUCache {
public:
    unordered_map<int,Node*> cache;     // To store (key,value) pairs
    int max_cap;                        // Max capacity of cache
    
    Node *head, *tail;                  // 'head' and 'tail' pointers to DLL queue
    
    LRUCache(int capacity) {
        max_cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // Key exists in cache
        {
            Node *node=cache.at(key);   
            
            // Removing from current position
            node->prev->next=node->next;
            node->next->prev=node->prev;
            
            // Move to tail
            node->next=tail;
            node->prev=tail->prev;
            tail->prev->next=node;
            tail->prev=node;

            return(node->Value);          
        }
        return(-1);     // Key does not exist in cache
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())    // key exists in cache   
        {
            // Update key value
            Node *node=cache.at(key);
            node->Value=value;

            // Removing from current position
            node->prev->next=node->next;
            node->next->prev=node->prev;
            
            // Move to tail
            node->next=tail;
            node->prev=tail->prev;
            tail->prev->next=node;
            tail->prev=node;

            return;
        }
        
        if(cache.size()==max_cap)   // Evict LRU element
        {   
            Node *node=head->next;
            head->next=node->next;
            node->next->prev=head;

            cache.erase(node->Key);     // Delete from cache
            delete(node);               // Free memory
        }

        // Add key to DLL queue 'tail'
        Node *node=new Node(key,value);
        
        // Move to tail
        node->next=tail;
        node->prev=tail->prev;
        tail->prev->next=node;
        tail->prev=node;

        cache.insert({key,node});           // Add (key,node_ptr) pair to cache
    }
};

// T.C=O(1) (PUT)   ;   T.C=O(1) (GET)
// S.C=O(N)

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */