/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonal_traversal(Node* root, vector<vector<int>> &result) {
    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();
            while(curr) {
                v.push_back(curr->data);
                if(curr->left != NULL) {
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
        result.push_back(v);
        v.clear();
    }
}
vector<int> diagonal(Node *root)
{
   vector<vector<int>> result;
   diagonal_traversal(root, result);
   vector<int> ans;
   for(int i = 0; i < result.size(); i++) {
       for(int j = 0; j < result[i].size(); j++) {
           ans.push_back(result[i][j]);
       }
   }
   return ans;
   
}