class MyHashMap {
public:
    vector<list<pair<int,int>>> mpp;
    int siz;
    MyHashMap() {
        siz = 1000;
        mpp.resize(1000);
    }
    // extra functions
    int hash(int key){
        return key%siz;
    }
    list<pair<int,int>> :: iterator search(int key){
        // as we have {key,value} pair we cannot use find to find the iterator as value we 
        // dont know
        int i = hash(key);
        auto it = mpp[i].begin();      // list ka begin pointer of m[i]
        while(it != mpp[i].end()){
            if(it->first == key){
                return it;
            }
            it++;
        }
        return it;                     // if key is not found it will return m[i].end();
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto it = search(key);
        if(it != mpp[i].end()){
            it->second = value;
        }
        else{
            mpp[i].push_back({key,value});
        }
        
    }
    
    int get(int key) {
        int i = hash(key);
        auto it = search(key);
        if(it != mpp[i].end()){
            return it->second;
        }else{
            return -1;
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = search(key);
        if(it != mpp[i].end()){
            mpp[i].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */