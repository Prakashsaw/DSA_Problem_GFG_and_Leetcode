/*
 Q_ID:- 1305
 Q_Name:- All Elements in Two Binary Search Trees.
 Platform:- Leetcode
 Difficulty:- Medium
 Description:- 
    Given two binary search trees root1 and root2, return a list containing 
    all the integers from both trees s  orted in ascending order.
Constraints:- 
    The number of nodes in each tree is in the range [0, 5000].
    -10^5 <= Node.val <= 10^5
 */
class Solution {
    void inorder_traversal(TreeNode* root, vector<int> &v) {
        if(root == NULL) return;
        inorder_traversal(root->left, v);
        v.push_back(root->val);
        inorder_traversal(root->right, v);
    }

    void merge_kar_do(vector<int> &v1, vector<int> &v2, vector<int> &ans) {

        int n1 = v1.size();
        int n2 = v2.size();

        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(v1[i] < v2[j]) {
                ans.push_back(v1[i]);
                i++;
            } else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i < n1) {
            ans.push_back(v1[i]);
            i++;
        }
        while(j < n2) {
            ans.push_back(v2[j]);
            j++;
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // //brute forcr approach
        // //N = root1.size;
        // //M = root2.size;
        // //TC = O((N+M)log(N+M)) = O(NlogN)
        // //SC = O(2N) = O(N)
        // vector<int> v1, v2;
        // inorder_traversal(root1, v1);
        // inorder_traversal(root2, v2);
        // vector<int> ans;
        // for(int i = 0; i < v1.size(); i++) {
        //     ans.push_back(v1[i]);
        // }
        // for(int i = 0; i < v2.size(); i++) {
        //     ans.push_back(v2[i]);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;


        // //Optimize further
        // //instead of inserting all elements into ans array and then sort them use the concept of 
        // //merting two sorted array
        //  //N = root1.size;
        // //M = root2.size;
        // //TC = O(N) + O(M) + O((N+M) = O(M+N)
        // //SC = O(2N) = O(N)
        // vector<int> v1, v2;
        // inorder_traversal(root1, v1);
        // inorder_traversal(root2, v2);
        // vector<int> ans;
        // merge_kar_do(v1, v2, ans);
        // return ans;


        //Third appraoch
        //iterative approach of inorder traversal
        //This is called morris traversal
        //Iterative version of inorder travesal method
        //N = root1.size;
        //M = root2.size;
        //H = Height of the teee
        //TC = O(N) + O(M) + O((N+M) = O(M+N)
        //SC = O(2H) = O(H)
        //space optimization
        stack<TreeNode*> st1, st2;
        vector<int> ans;
        while(root1 || root2 || !st1.empty() || !st2.empty()) {
            while(root1) {
                st1.push(root1);
                root1 = root1->left;
            }
            
            while(root2) {
                st2.push(root2);
                root2 = root2->left;
            }

            if(st1.size() == 0 && st2.size() != 0) {
                ans.push_back(st2.top()->val);
                root2 = st2.top()->right;
                st2.pop();
            } else if(st1.size() != 0 && st2.size() == 0) {
                ans.push_back(st1.top()->val);
                root1 = st1.top()->right;
                st1.pop();
            } else {
                if(st1.top()->val > st2.top()->val) {
                    ans.push_back(st2.top()->val);
                    root2 = st2.top()->right;
                    st2.pop();

                } else {
                    ans.push_back(st1.top()->val);
                    root1 = st1.top()->right;
                    st1.pop();
                }
            }
            
        }
        return ans;
    }
};