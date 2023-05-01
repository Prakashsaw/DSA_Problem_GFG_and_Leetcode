/*
Subtree In N-ary Tree
Given root of a n-ary tree find the number of duplicate subtree in the n-ary tree.
Two trees are duplicate if they have the same structure with the same node values.
*/

class Solution{
    string solve(Node* root, unordered_map<string, int> &mp) {
        if(root == NULL) return "";
        
        //for left
        string left_str = "";
        if(root->children.size() > 0) {
            left_str = '@' + solve(root->children[0], mp) + '@';
        }
        
        //for root
        string root_str = to_string(root->data);
        
        //for right
        int cnt = 0;
        string right_str = "";
        for(auto child : root->children) {
            if(cnt == 0) {
                cnt++;
                continue; //avoid first child means at index 0 of root bacause 
                          //if exist then we have to already cover in left
            }
            right_str = '@' + solve(child, mp) + '@';
            
        }
        
        //finally make a combined string of left, root, and right
        string final_str = left_str + root_str + right_str;
        
        mp[final_str]++;
        
        return final_str;
    }
public:
    int duplicateSubtreeNaryTree(Node *root){
        unordered_map<string, int> mp;
        
        solve(root, mp);
        
        int ans_cnt = 0;
        for(auto x : mp) {
            if(x.second > 1) ans_cnt++;
        }
        
        return ans_cnt;
    }
};