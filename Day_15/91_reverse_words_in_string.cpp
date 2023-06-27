#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> store;
        int left = 0, right = 0;
        while(right<s.length())
        {
            if(s[right]!=' ')
                right++;
            else
            {
                if(left!=right)
                    store.push_back(s.substr(left,right-left));
                right++;
                left = right;
            }
        }
        if(left!=right)
            store.push_back(s.substr(left,right-left));
        string ans;
        for(int i=store.size()-1; i>=0; i--)
        {
            ans+=store[i];
            ans+=' ';
        }
        while(ans.back()==' ')
            ans.pop_back();
        return ans;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         int left = 0;
//         int right = s.length()-1;

//         string temp="", ans="";
//         while(left<=right)
//         {
//             if(s[left] != ' ')
//                 temp += s[left];
//             else
//             {
//                 if(temp!="")
//                     if(ans!="")
//                         ans = temp + ' ' + ans;
//                     else
//                         ans = temp;
//                 temp="";
//             }
//             left++;
//         }
//         if(temp!="")
//             if(ans!="")
//                 ans = temp + ' ' + ans;
//             else
//                 ans = temp;
//         return ans;
//     }
// };