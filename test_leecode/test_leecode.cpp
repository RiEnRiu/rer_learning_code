// test_leecode.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<numeric>
#include<math.h>
#include<exception>
#include<bitset>
using namespace std;





double log(double a, double x)
{
	return log(x) / log(a);
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};




struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class MinStackNode
{
public:
	int val;
	int min;
	MinStackNode *next;
	MinStackNode *pre;
	MinStackNode(int _val, int _min, MinStackNode * _next = NULL, MinStackNode * _pre = NULL)
	{
		val = _val;
		min = _min;
		next = _next;
		pre = _pre;
	}
};


template <typename T>
void print_vector(vector<T> a)
{
	for (auto p = a.begin(); p != a.end(); ++p)
	{
		cout << *p << "    ";
	}
	cout << endl;
	return;
}
//
//namespace std 
//{
//	template <> //function-template-specialization
//	class hash<vector<int>> 
//	{
//	public:
//		size_t operator()(const vector<int> &keys) const
//		{
//			int *ikeys = new int[keys.size()];
//			for (int i = 0; i < keys.size(); ++i)
//			{
//				ikeys[i] = keys[i];
//			}
//			auto h = hash<string>()((char *)ikeys);
//			delete ikeys;
//			return h;
//		}
//	};
//
//	template<>
//	class equal_to<vector<int>> 
//	{
//	public:
//		bool operator()(const vector<int> &keys1, const vector<int> &keys2) const
//		{
//			if (keys1.size() != keys2.size()) { return false; }
//			else
//			{
//				for (int i = 0; i < keys1.size(); ++i)
//				{
//					if (keys1[i] != keys2[i]) { return false; }
//				}
//			}
//			return true;
//		}
//
//	};
//};




int main()
{

	//unordered_map<vector<int>, int, hash<vector<int>>, equal_to<vector<int>>> aaa;
	//aaa[{1}] = 1;
	//aaa[1] = 1;

    class Solution 
    {
    private:
        void backtrack(string &s, int left, int right, int n,vector<string> &ans)
        {
            if (left == n)
            {
                string t = s;
                for (int i = right; i < n; ++i)
                {
                    t.push_back(')');
                }
                ans.push_back(t);
                return;
            }
            else if(left>right)
            {
                s.push_back('(');
                backtrack(s, left + 1, right, n, ans);
                s.pop_back();
                if (right < n)
                {
                    s.push_back(')');
                    backtrack(s, left, right + 1, n, ans);
                    s.pop_back();
                }
            }
            else //if(left==right)
            {
                s.push_back('(');
                backtrack(s, left + 1, right, n, ans);
                s.pop_back();
            }
            return;
        }
    public:
        vector<string> generateParenthesis(int n)
        {
            if (n == 0) { return vector<string>(); }
            vector<string> ans;
            string s("(");
            backtrack(s, 1, 0, n, ans);
            return ans;
        }
    };


	//vector<vector<char>> matrix(6);
	//matrix[0] = vector<char>({ 'O','O','O','O','X','X' });
	//matrix[1] = vector<char>({ 'O','O','O','O','O','O' });
	//matrix[2] = vector<char>({ 'O','X','O','X','O','O' });
	//matrix[3] = vector<char>({ 'O','X','O','O','X','O' });
	//matrix[4] = vector<char>({ 'O','X','O','X','O','O' });
	//matrix[5] = vector<char>({ 'O','X','O','O','O','O' });
	//matrix[6] = vector<char>({ 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O' });
	//matrix[7] = vector<char>({ 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O' });
	//matrix[8] = vector<char>({ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O' });


	//Solution().solve(matrix);


    vector<int> arr1 = { 1,2,4,3 };
	vector<int> arr2 = { 2,5,6 };
	////vector<string> ans;
	//Solution().maxArea(arr1);
    auto ans = Solution().generateParenthesis(3);
	//cout << ans << endl;
	print_vector(ans);


    //cout << Solution().poorPigs(1000,4,15) << endl;

	//vector<int> arr1 = {2, 7, 11, 15};
	//vector<int> arr2 = {9};

	//auto ans = Solution().twoSum(arr1, 9);
	//for (auto p = ans.begin(); p != ans.end(); ++p)
	//{
	//	cout << *p << "  ";
	//}
}

