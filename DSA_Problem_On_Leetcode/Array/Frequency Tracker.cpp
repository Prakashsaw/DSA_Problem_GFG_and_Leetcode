/*
Q_Id:- 2671.
Q_Name:- Frequency Tracker.
Difficulty:- Medium
Description:- 
    Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

Implement the FrequencyTracker class.

FrequencyTracker(): Initializes the FrequencyTracker object with an empty array initially.
void add(int number): Adds number to the data structure.
void deleteOne(int number): Deletes one occurence of number from the data structure. The data structure may not contain number, and in this case nothing is deleted.
bool hasFrequency(int frequency): Returns true if there is a number in the data structure that occurs frequency number of times, otherwise, it returns false.
 

Example 1:

Input
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
Output
[null, null, null, true]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.add(3); // The data structure now contains [3, 3]
frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice

Example 2:

Input
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
Output
[null, null, null, false]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // The data structure now contains [1]
frequencyTracker.deleteOne(1); // The data structure becomes empty []
frequencyTracker.hasFrequency(1); // Returns false, because the data structure is empty

Example 3:

Input
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
Output
[null, false, null, true]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // Returns false, because the data structure is empty
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.hasFrequency(1); // Returns true, because 3 occurs once

 

Constraints:

1 <= number <= 10^5
1 <= frequency <= 10^5
At most, 2 * 10^5 calls will be made to add, deleteOne, and hasFrequency in total.
*/

/*
//Brute force 
//TC = O(N*N)
//SC = O(N)
STATUS:- TLE

class FrequencyTracker {
    unordered_map<int, int> mp;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        mp[number]++;
    }
    
    void deleteOne(int number) {
        if(mp.count(number)) {
            mp[number]--;
            if(mp[number] == 0)
                mp.erase(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        for(auto x : mp) {
            if(x.second == frequency) return true;
        }
        return false;
        
    }
};

*/
//Optimize 
//TC = O(N)
//SC = O(N)
class FrequencyTracker {
    unordered_map<int, unordered_set<int> > mp;
    vector<int> v;
public:
    FrequencyTracker() {
        v.resize(100000+1);
    }
    
    void add(int number) {
        int oldfreq = v[number];
        
        int newfreq = oldfreq + 1;
         
        v[number] = newfreq;
        mp[newfreq].insert(number);
           
        if(oldfreq > 0) {
            mp[oldfreq].erase(number);
            if(mp[oldfreq].empty()) {
                mp.erase(oldfreq);
            }
        }
    }
    
    void deleteOne(int number) {
        
        if(v.size() > number && v[number]  > 0) {
            int oldfreq = v[number];
            int newfreq = oldfreq - 1;
            
            v[number] = newfreq;
            mp[newfreq].insert(number);
            
            mp[oldfreq].erase(number);
            
            if(mp[oldfreq].empty()) {
                mp.erase(oldfreq);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        
        if(mp.count(frequency)) return true;
        return false;
        
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */