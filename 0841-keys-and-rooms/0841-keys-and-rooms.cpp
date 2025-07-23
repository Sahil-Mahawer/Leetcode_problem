class Solution {
public:

void dfs(vector<vector<int>>& rooms, int room, vector<bool> &visited)
{

    visited[room] = true;

    for(int i = 0; i<rooms[room].size(); i++){

        int key = rooms[room][i];

        if(visited[key] == false){

            dfs(rooms, key, visited);
        }
    }


}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();

        vector<bool> visited(n,0);

        dfs(rooms, 0, visited);

        for(int i=0; i<n; i++){

            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }
};