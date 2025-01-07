class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> operations(boxes.size(),0);

        vector<int> ball_position;

        for(int i=0;i<boxes.size();i++){
            
            if(boxes[i]=='1'){
                ball_position.push_back(i);
            }
        }

        for(int i=0;i<boxes.size();i++){

            int total_operation = 0;

            for(int j=0;j<ball_position.size();j++){

                total_operation += abs(i-ball_position[j]);
            }

            operations[i] = total_operation;
        }

        return operations;
    }
};