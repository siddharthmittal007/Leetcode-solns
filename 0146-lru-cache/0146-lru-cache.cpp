class LRUCache {
public:
    unordered_map<int,int> cache;   // To store (key,value) pairs
    int max_cap;                    // Max capacity of cache
    
    queue<int> q;                   // FIFO queue of 'key' use(put/get)
    
    unordered_map<int,int> cnt;     // Store number of entries in FIFO queue
                                    // corresponding to key 'key'
    
    
    LRUCache(int capacity) {
        max_cap=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // Key exists in cache
        {
            q.push(key);                    // Add key to FIFO queue
            cnt[key]++;                     // Increment number of entries in FIFO queue
            return(cache.at(key));          // Return key value
        }
        return(-1);     // Key does not exist in cache
    }
    
    void put(int key, int value) {
        if(cache.find(key)==cache.end() && cache.size()==max_cap)
        {
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                cnt[temp]--;
                if(cnt[temp]==0)
                {
                    cnt.erase(temp);
                    cache.erase(temp);
                    break;
                }
            }
        }

        cache[key]=value;           // Add/Update (key,value) pair to cache
        q.push(key);                // Add key to FIFO queue
        cnt[key]++;                 // Increment number of entries of key 
                                    // in FIFO queue
    }
};

// T.C=O(1) (PUT AND GET OPERATIONS)
// S.C=O(N)

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */