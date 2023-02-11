// for solution and undestanding of logic refer this :-  https://www.youtube.com/watch?v=5NdhK3tZViQ
//Q_ID:- 43.
//Q_Name:- Multiply String.
//Platform:- Leetcode

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return  "0";
        int n1 = num1.length();
        int n2 = num2.length();

        //char array banao of length n1+n2;

        vector<char> res(n1+n2, '0');

        int i = n1-1;
        int j = n2-1;

        int k;
        int res_vec_inc = 0; //this is for that k(res vector) ko kaha se start karna hai
        for(int i = n1-1; i >= 0; i--) {
            int carry = 0;
            k = n1+n2-1-res_vec_inc;
            for(int j = n2-1; j >= 0 || carry > 0; j--) {
                int j_val = j >= 0 ? num2[j]-'0' : 0;
                int i_val = num1[i]-'0';
                int prod = carry + i_val * j_val + (res[k]-'0');
                res[k] = prod%10 + '0';
                carry = prod / 10;
                k--;
            }
            res_vec_inc++;
        }
        k = 0;
        while(res[k] == '0') k++;
        string ans = "";
        for(int i = k; i < n1+n2; i++) {
            ans += res[i];
        }
        
        return ans;
        
    }
};