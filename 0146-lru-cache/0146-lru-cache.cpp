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
    
    void move_to_tail(Node *node)
    {
        if(node==tail)
        {
            return;     // node already at tail
        }
        
        // Removing from current position
        if(node==head)
        {
            node->next->prev=NULL;
            head=node->next;
        }
        else
        {
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
                
        // Moving to tail
        node->next=NULL;
        node->prev=tail;
        tail->next=node;
        tail=node;
    }

    void delete_head(Node *node)
    {
        // Remove from DLL queue
        if(head==tail)
        {
            head=tail=NULL;
        }  
        else
        {
            node->next->prev=NULL;
            head=node->next;
        }  

        cache.erase(node->Key);     // Delete from cache
        delete(node);               // Free memory
    }
    
    LRUCache(int capacity) {
        max_cap=capacity;
        head=tail=NULL;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // Key exists in cache
        {
            Node *node=cache.at(key);   
            move_to_tail(node);
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
            move_to_tail(node);
            return;
        }
        
        if(cache.size()==max_cap)   // Evict LRU element
        {   
            delete_head(head);
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