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
        head=tail=NULL;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // Key exists in cache
        {
            Node *node=cache.at(key);   // 'key' node in DLL queue
            
            if(node!=tail)              // Move node to tail
            {
                // Removing node from current position 
                if(node->prev!=NULL)
                {
                    node->prev->next=node->next;
                }
                if(node->next!=NULL)
                {
                    node->next->prev=node->prev;
                }
                // Setting head
                if(node==head)
                {
                    head=node->next;
                }
                
                // Moving to tail
                node->next=NULL;
                node->prev=tail;
                tail->next=node;
                tail=node;
            }
            
            return(node->Value);          // Return value corresp. to key
        }
        
        return(-1);     // Key does not exist in cache
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())    // key exists in cache   
        {
            // Update key value
            Node *node=cache.at(key);
            node->Value=value;
            return;
        }
        
        if(cache.size()==max_cap)   // Evict LRU element
        {
            Node *node=head;        // LRU element at DLL queue 'head'
            
            // Delete from DLL queue
            if(node==tail)
            {
                head=tail=NULL;
            }
            else
            {
                node->next->prev=NULL;
                head=node->next;
            }
            
            cache.erase(node->Key); // Delete from cache
            delete(node);           // Free memory
        }

        // Add key to DLL queue 'tail'
        Node *node=new Node(key,value);
        if(head==NULL && tail==NULL)
        {
            head=tail=node;
        }
        else
        {
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        
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