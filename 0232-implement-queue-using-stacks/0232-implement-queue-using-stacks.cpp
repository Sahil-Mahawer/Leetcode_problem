class MyQueue {
public:
stack<int> st1; //push
stack<int> st2; // pop
    MyQueue() {
        
    }
    
    void push(int x) {
         st1.push(x);
    }
    
    int pop() {
         if(empty()){
            return 0;
        }

        else if(!st2.empty()){

            int element = st2.top();
            st2.pop();
            return element;
        }
        
        else{  // agr stack2 empty hai .. toh frr stack1 se saare element nikal krr stack2 mai daaldo

            while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            }
           
        }
         int element  = st2.top();
         st2.pop();
        return element;
    }
    
    int peek() {
        if(empty()){
            return 0;
        }

        else if(!st2.empty()){
            return st2.top();
        }

        else{  

            while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            }
           
        }
        return st2.top(); 
    }
    
    bool empty() {
         if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */