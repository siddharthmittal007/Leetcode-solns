class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> cache; // To store (key,value)
                                                            // pairs
    int max_cap;                                            // Max capacity of cache
    
    list<pair<int,int>>  q;                                 // DLL queue
    
    LRUCache(int capacity) {
        max_cap=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // Key exists in cache
        {
            auto it=cache.at(key);
            
            // Removing from current position
            pair<int,int> elem=make_pair(it->first,it->second);
            q.erase(it);

            // Move to back
            q.push_back(elem);   
            
            return(elem.second);          
        }
        return(-1);     // Key does not exist in cache
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())    // key exists in cache   
        {
            // Update key value
            auto it=cache.at(key);
            it->second=value;

            // Removing from current position
            pair<int,int> elem=make_pair(it->first,it->second);
            q.erase(it);

            // Move to back
            q.push_back(elem);

            return;
        }
        
        if(cache.size()==max_cap)   // Evict LRU element(at queue front)
        {   
            // Remove from DLL queue
            pair<int,int> elem=make_pair(q.front().first,q.front().second);
            q.pop_front();

            cache.erase(elem.first);     // Delete from cache
        }

        // Add key to DLL queue back
        auto it=q.insert(q.end(),make_pair(key,value));

        cache.insert(make_pair(key,it));           // Add (key,iterator) pair to cache
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