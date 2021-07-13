/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num_word = words.size(), len_word = words[0].length(), count_word=0;
        bool* word_recorder = new bool[num_word], found = false;
        vector<int> result = vector<int>();
        for (int i = 0; i < num_word; i++)word_recorder[i] = false;
        for(int i=0; i<s.length(); i++){
            if(num_word*len_word > s.length()-i)break;
            count_word=0;
            for (int k = 0; k < num_word; k++)word_recorder[k] = false;
            while(count_word < num_word){
                found = false;
                for(int m=0; m< num_word; m++){
                    if(!word_recorder[m] && s[i+count_word*len_word]==words[m][0] && checkSubString(s, i+count_word*len_word, words[m], len_word)){
                        word_recorder[m] = true;
                        count_word++;
                        found = true;
                        break;
                    }
                }
                if(!found)break;
            }
            if(found)result.push_back(i);
        }
        delete[] word_recorder;
        return result;
    }

    bool checkSubString(string& s, int index, string& word, int len_word){
        for (int i=0; i<len_word; i++){
            if(s[index+i] != word[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

