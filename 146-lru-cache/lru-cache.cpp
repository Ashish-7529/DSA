class LRUCache {
public:
    unordered_map<int, pair<int, int>> mp;
    int c;
    deque<int> dq;

    LRUCache(int capacity) {
        c = capacity;
    }

    int get(int key) {
        if (mp.count(key)) {
            dq.push_back(key);
            mp[dq.back()].second++;

            while (mp.size() > c) {
                mp[dq.front()].second--;
                if (mp[dq.front()].second == 0) {
                    mp.erase(dq.front());
                }
                dq.pop_front();
            }

            return mp[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        dq.push_back(key);
        mp[key].first = value;
        mp[key].second++;

        while (mp.size() > c) {
            mp[dq.front()].second--;
            if (mp[dq.front()].second == 0) {
                mp.erase(dq.front());
            }
            dq.pop_front();
        }
    }
};