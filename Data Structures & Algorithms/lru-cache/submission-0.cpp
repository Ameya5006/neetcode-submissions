class LRUCache {
    int cap;
    list<pair<int,int>> cache;
    unordered_map<int , list<pair<int,int>>::iterator> pos;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!pos.count(key)) return -1;
        int value = pos[key] -> second;
        cache.erase(pos[key]);
        cache.push_front({key,value});
        pos[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(pos.count(key)) cache.erase(pos[key]);
        else if(cache.size() == cap){
            int oldkey = cache.back().first;
            cache.pop_back();
            pos.erase(oldkey);
        }
        cache.push_front({key,value});
        pos[key] = cache.begin();
    }
};
