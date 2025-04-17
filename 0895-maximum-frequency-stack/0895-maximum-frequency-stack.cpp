class FreqStack {
public:

unordered_map<int,int> freq;
priority_queue<tuple<int,int,int>> pq;
int time=0; 
    FreqStack() {
        
    }
    
    void push(int val) {
        
        freq[val]++;
        pq.push({freq[val],time, val});
        time++;
    }
    
    int pop() {
        
    //     tuple<int,int,int> tup = pq.top();
    //     int f = get<0>(tup); // freq
    //     int t = get<1>(tup); // time :- most recently added
    //     int v = get<2>(tup); // value 

        auto [f,t,val] = pq.top();
        pq.pop();
        freq[val]--;
        return val;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */