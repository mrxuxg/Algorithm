/*
    题目：
        输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
        例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
    思路：

*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        string ans;
        for (int i = 0; i < numbers.size(); i++)
            strs.push_back(to_string(numbers[i]));
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});
        for (int i = 0; i < strs.size(); i++)
            ans += strs[i];
        return ans;
    }
};