typedef list<pair<int,int>> DLL;    // DLL of (key,value) pair elements

class LFUCache {
public:
    
    // cache storing (key,iterator) pairs
    unordered_map<int,pair<int,DLL::iterator>> cache;   // (key,(freq,elem_iter)) 
    
    int max_cap;    // Maximum cache capacity
    int minf;       // Minimum frequency of cache elements
    
    // (frequency,DLL) pairs
    unordered_map<int,DLL> frequency;   

    LFUCache(int capacity) {
        max_cap=capacity;
        minf=0;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())    // 'key' exists
        {
            // Copying element attributes 
            auto it=cache[key].second;
            int freq=cache[key].first, value=it->second;
            // and deleting from DLL
            frequency[freq].erase(it);

            // Adding to DLL corresp to 'freq+1'
            DLL &dll=frequency[freq+1];
            auto temp=dll.insert(dll.end(),make_pair(key,value));

            // Saving new freq and iterator to cache
            cache[key]=make_pair(freq+1,temp);

            // Updating minf
            if(freq==minf && frequency[freq].empty())
            {
                minf++;
            }

            return(value);

        }
        return(-1);     // 'key' doesnt exist     
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            // Copying element attributes 
            auto it=cache[key].second;
            int freq=cache[key].first;
            // and deleting from DLL
            frequency[freq].erase(it);

            // Adding to DLL corresp to 'freq+1'
            DLL &dll=frequency[freq+1];
            auto temp=dll.insert(dll.end(),make_pair(key,value));

            // Saving new freq and iterator to cache
            cache[key]=make_pair(freq+1,temp);

            // Updating minf
            if(freq==minf && frequency[freq].empty())
            {
                minf++;
            }

            return;
        }

        if(cache.size()==max_cap)   // Removing LFU element
        {
            DLL &dll=frequency[minf];
            cache.erase(dll.front().first); // Deleting from cache
            dll.pop_front();                // Deleting from DLL
        }

        // Inserting new element to DLL
        DLL &dll=frequency[1];
        auto temp=dll.insert(dll.end(),{key,value});
        // Inserting new element to cache
        cache.insert({key,make_pair(1,temp)});
        // Updating minimum frequency
        minf=1;
    }
};

// T.C=O(1) FOR BOTH GET AND PUT
// S.C=O(N)

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */