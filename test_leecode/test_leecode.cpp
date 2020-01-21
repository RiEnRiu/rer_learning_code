// test_leecode.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    class Solution 
    {
    public:
        bool isPalindrome(const string &s, int ib, int ie_1)
        {
            while (ib <= ie_1)
            {
                if (s[ib] != s[ie_1])
                {
                    return false;
                }
                ++ib;
                --ie_1;
            }
            return true;
        }

        void extendPalindrome(const string &s, int ss, int &ml, int &ib, int &ie)
        {
            if (ib == 0 || ie == ss) { return; }
            if (isPalindrome(s, ib - 1, ie - 1 + 1))
            {
                ++ie;
                ++ml;
                --ib;
                ++ml;
                return extendPalindrome(s, ss, ml, ib, ie);
            }
        }

        string longestPalindrome(string s)
        {
            int ss = s.size();
            if (ss == 0) { return ""; }
            //odd
            int odd_pre_ml = 1;
            int odd_ml = 1, odd_ib = 0, odd_ie = 1;
            while (1)
            {
                bool finish_for = true;
                for (int i = 0; i < ss - (odd_ml - 1); ++i)
                {
                    if (isPalindrome(s, i, i+ odd_ml -1))
                    {
                        odd_ib = i;
                        ie = i + odd_ml;
                        extendPalindrome(s, ss, odd_ml, odd_ib, ie);
                        if (odd_ml > odd_pre_ml)
                        {
                            odd_pre_ml = odd_ml;
                            finish_for = false;
                            break;
                        }
                    }
                }
                if (finish_for) { break; }
            }

            //even
            int even_pre_ml = 0;
            int even_ml = 0, ib = 0, ie = 0;
            while (1)
            {
                bool finish_for = true;
                for (int i = 0; i < ss - (even_ml - 1); ++i)
                {
                    if (isPalindrome(s, i, i + even_ml - 1))
                    {
                        ib = i;
                        ie = i + even_ml;
                        extendPalindrome(s, ss, even_ml, ib, ie);
                        if (even_ml > even_pre_ml)
                        {
                            even_pre_ml = even_ml;
                            finish_for = false;
                            break;
                        }
                    }
                }
                if (finish_for) { break; }
            }
            if (even_ml > odd_ml)
            {
                return s.substr(even)
            }
        }
    };

    cout << Solution().longestPalindrome("aaaabaaa") << endl;
}

