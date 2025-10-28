// Design Hashmap
class MyHashMap {
private:
    static const int SIZE = 10000;
    vector<list<pair<int,int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                p.second = value; // update
                return;
            }
        }
        table[idx].push_back({key, value}); // insert
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) return p.second;
        }
        return -1; // not found
    }
    
    void remove(int key) {
        int idx = hash(key);
        table[idx].remove_if([key](pair<int,int>& p){ return p.first == key; });
    }
};
