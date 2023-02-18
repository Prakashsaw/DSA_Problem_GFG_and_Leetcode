/*
Apple Sequences
There is a string of size n containing only 'A' and 'O'. 'A' stands for Apple, and 'O' stands for Orange. We have m number of spells, each spell allows us to convert an orange into an apple.

Find the longest sequence of apples you can make, given a string and the value of m.


*/
class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        //sliding appraoch or two pointer approach
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j < n) {
            // if(m > 0) {
            //     if(arr[j] == 'O') {
            //         m--;
            //     }
            // } else {
            //     if(arr[j] == 'O') {
            //         while(i <= j && arr[i] != 'O') {
            //             i++;
            //         }
            //         i++;
            //     }
            // }
            
            // ans = max(ans, j-i+1);
            // j++;
            
            
            if(arr[j] == 'A') {
                ;
            } else { //if(arr[j] == 'O') {
                if(m > 0) {
                    m--;
                } else {
                    while(i <= j && arr[i] != 'O') {
                        i++;
                    }
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
        
    }
};