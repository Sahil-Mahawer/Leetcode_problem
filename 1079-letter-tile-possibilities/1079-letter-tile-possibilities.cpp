class Solution {
public:
int n;

void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string& curr) {
    // Add the current permutation to the result (it’s a new possibility)
    result.insert(curr);

    // Try all possible tiles
    int n = tiles.length(); // Ensure we have n = tiles.length()
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue; // Skip if tile is already used
        }

        // Mark this tile as used
        used[i] = true;
        curr.push_back(tiles[i]);

        // Recurse to form the next subset
        solve(tiles, used, result, curr);

        // Backtrack: undo the choice
        used[i] = false;
        curr.pop_back();
    }
}

    int numTilePossibilities(string tiles) {
        n = tiles.length();
    vector<bool> used(n, false); // Track if a tile is used
    unordered_set<string> result; // Store distinct permutations
    string curr = ""; // To build the current permutation

    // Start recursion
    solve(tiles, used, result, curr);

    // Subtract 1 to exclude the empty string from the result
    return result.size() - 1;
    }
};