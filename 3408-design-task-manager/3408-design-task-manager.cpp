class TaskManager {
public:

    typedef pair<int,int> P;

    priority_queue<P> max_heap; // (priority, taskid)

    unordered_map<int,int> task_priority_mp;  // stores taskid and its priority ... taskid -> priority
    unordered_map<int,int> task_owner_mp; // stores taskid with its userid   ..... taskid -> userid


    TaskManager(vector<vector<int>>& tasks) {
        
        for(auto &task : tasks){

            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        max_heap.push({priority, taskId});

        task_priority_mp[taskId] = priority;

        task_owner_mp[taskId] = userId;

    }
    
    void edit(int taskId, int newPriority) {
        
        max_heap.push({newPriority, taskId});

        task_priority_mp[taskId] = newPriority;

    }
    
    void rmv(int taskId) {
        
        task_priority_mp[taskId] = -1;
    }
    
    int execTop() {
        
        while(!max_heap.empty()){

            auto[priority , taskid] = max_heap.top();
            max_heap.pop();

            if(priority == task_priority_mp[taskid]) // fresh hai ...  purani priority vaali nhi hai 
            {

                task_priority_mp[taskid] = -1;

                return task_owner_mp[taskid];
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */