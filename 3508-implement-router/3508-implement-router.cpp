class Router {
public:

    int MAX_SIZE;
    unordered_map<string, vector<int>> packet_store;  // key -> {S,D,T}
    unordered_map<int, vector<int>> destination_timestamp; // D -> {T1,T2,T3}

    queue<string> que;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        if(packet_store.find(key) != packet_store.end()){
            return false; // found duplicate key 
        }

        if(que.size() >= MAX_SIZE){
            forwardPacket();
        }


        packet_store[key] = {source,destination,timestamp};

        que.push(key);

        destination_timestamp[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        
        if(packet_store.empty()){
            return {};
        }

        string key = que.front();
        que.pop();

        vector<int> packet = packet_store[key];  // {Source, Destination, Timestamp}
        packet_store.erase(key);

        int D = packet[1];

        destination_timestamp[D].erase(destination_timestamp[D].begin());

        return packet;


    }
    
    int getCount(int destination, int startTime, int endTime) {
        
        auto it = destination_timestamp.find(destination);  // D -> {}

        if(it == destination_timestamp.end() || it->second.empty()){
            return 0;
        }

        vector<int> time = it->second; // {T1, T2, T3}

        int i = lower_bound(begin(time), end(time), startTime) - begin(time);
        int j = upper_bound(begin(time), end(time), endTime) - begin(time);

        return j - i;
       
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */