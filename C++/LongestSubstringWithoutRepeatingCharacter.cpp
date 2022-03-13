// 3. Longest Substring Without Repeating Characters
// Medium

// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        
        queue<char> q;
        unordered_map<char, int> m;
        int mx = 0;
        
        for(int i = 0; i < s.length(); i++){
            m[s[i]] = 0;
        }
        
        for(int i = 0; i < s.length(); i++){ 
            if(m[s[i]] == 0){
                q.push(s[i]);
                m[s[i]]++;
                mx = max(mx, (int)q.size());
            } else if(m[s[i]] > 0){
                mx = max(mx, (int)q.size());
                while(q.front() != s[i] and q.size() > 0){
                    m[q.front()]--;
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
                mx = max(mx, (int)q.size());
            }
            mx = max(mx, (int)q.size());
        }
		
        return mx;
    }
};