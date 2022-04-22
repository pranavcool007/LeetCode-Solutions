class MyHashMap {
public:
    vector<int> mpp;
    MyHashMap() {
        int siz = 1e6 + 1;
        mpp.resize(siz,-1);
    }
    
    void put(int key, int value) {
        mpp[key] = value;
    }
    
    int get(int key) {
        return mpp[key];
    }
    
    void remove(int key) {
        if(mpp[key] != -1){
            mpp[key] = -1;
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