class Solution {
public:

int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<bool> &visited ,unordered_set<int> &boxes_found)
{

    if(visited[box] == true){
        return 0;
    }

    if(status[box] == 0){  // this box status is close we can't take any keys 

        boxes_found.insert(box);  // store the boxes which you are finding so whenever in future you find the key .. you can open the box with the key and take candies

        return 0;

    }

    // neither the box is previously visited  nor it is close ... so we get into the box

    visited[box] = true; // means you have now visit this box , so mark it true


    int candies_collected =  candies[box]; // candies of current box

    for(int i=0; i<containedBoxes[box].size(); i++){

        int inside_box = containedBoxes[box][i];

        candies_collected += dfs(inside_box, status , candies, keys, containedBoxes, visited, boxes_found);
    }

    for(int i=0; i<keys[box].size(); i++){

        int boxkey = keys[box][i];

        status[boxkey] = 1; // mark the status of box which key we have found so in future if we have that box we can easily open it. 

        if(boxes_found.find(boxkey) != boxes_found.end()){

            candies_collected += dfs(boxkey,  status , candies, keys, containedBoxes, visited, boxes_found);
        }

    }


    return candies_collected;


}



    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int candies_collected = 0;

        vector<bool> visited(status.size(), false);  // initialyy we haven't visitied any box

        unordered_set<int> boxes_found;

        for(int i=0;i<initialBoxes.size(); i++){

            int box = initialBoxes[i];

            candies_collected += dfs(box, status , candies, keys, containedBoxes, visited, boxes_found);
        }

        return candies_collected;
    }
};