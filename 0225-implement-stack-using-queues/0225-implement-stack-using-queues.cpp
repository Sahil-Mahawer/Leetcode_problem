class MyStack {
public:
queue<int> q1;
queue<int> q2;
    MyStack() {
        
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
    
    void push(int x) {
        
        if(empty()){
            q1.push(x);
        }
        else if(q1.empty()){
            q2.push(x);  // jis queue mai elements present honge usiii queue mai push hoga
        }
        else{
            q1.push(x);  // jis queue mai elements present honge usiii queue mai push hoga
        }
    }
    
    int pop() {
        
        if(empty()){
            return 0;
        }

        else if(q1.empty()){  // agrr q1 empty hai toh q2 se saare element except last element chod kr q1 mai daaldo  

         while(q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
         }

         int element = q2.front();
         q2.pop();
         return element;

        }

        else { // agrr q2 empty hai toh q1 se saare element except last element chod kr q2 mai daaldo  

            while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
         }

        
        }

        int element = q1.front();
        q1.pop();
        return element;
    }
    
    int top() {
        
        if(empty()){
            return 0;
        }

        else if(q1.empty()){
            return q2.back();
        }

        return q1.back();
    }
    
   
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */