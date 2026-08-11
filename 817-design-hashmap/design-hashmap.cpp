class MyHashMap {
public:
    vector<int> mp;
    MyHashMap() {
        vector <int> v(1e6+7,-1);
        mp=v;
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        int ans=mp[key];
        return ans;
    }
    
    void remove(int key) {
        mp[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */