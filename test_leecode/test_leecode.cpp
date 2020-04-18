// test_leecode.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include<numeric>
#include<exception>
#include<bitset>
#include<math.h>
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

class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int main()
{
    class Solution
    {
    private:
        void infect(const vector<vector<char>>& grid,int i, int j, int m, int n, vector<vector<bool>> &flag)
        {
            flag[i][j] = true;
            if (i > 0)
            {
                if (flag[i - 1][j] == false && grid[i - 1][j] == '1') { infect(grid, i - 1, j, m, n, flag); }
                else { flag[i - 1][j] = true; }
            }
            if (i < m - 1)
            { 
                if (flag[i + 1][j] == false && grid[i + 1][j] == '1') { infect(grid, i + 1, j, m, n, flag); }
                else { flag[i + 1][j] = true; }
            }
            if (j > 0)
            {
                if (flag[i][j - 1] == false && grid[i][j - 1] == '1') { infect(grid, i, j - 1, m, n, flag); }
                else { flag[i][j - 1] = true; }
            }
            if (j < n - 1)
            {
                if (flag[i][j + 1] == false && grid[i][j + 1] == '1') { infect(grid, i, j + 1, m, n, flag); }
                else { flag[i][j + 1] = true; }
            }
            return;
        }

    public:
        int numIslands(vector<vector<char>>& grid) 
        {
            if (grid.size() == 0) { return 0; }
            int m = grid.size();
            int n = grid[0].size();
            int count = 0;
            vector<vector<bool>> flag(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j <n; ++j)
                {
                    if (flag[i][j] == false)
                    {
                        if (grid[i][j] == '1')
                        {
                            ++count;
                            infect(grid, i, j, m, n, flag);
                        }
                        else { flag[i][j] = true; }
                    }
                }
            }
            return count;
        }
    };

	vector<vector<char>> matrix(3);
    matrix[0] = vector<char>({ '1','1','1' });
    matrix[1] = vector<char>({ '0','1','0' });
    matrix[2] = vector<char>({ '1','1','1' });
    //matrix[3] = vector<char>({ '0','0','0','1','1' });
	//matrix[4] = vector<char>({ 1,1,1,1,0 });
	//matrix[5] = vector<char>({ 'O','X','O','O','O','O' });
	//matrix[6] = vector<char>({ 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O' });
	//matrix[7] = vector<char>({ 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O' });
	//matrix[8] = vector<char>({ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O' });

	//Solution().solve(matrix);

    vector<int> arr1 = {0,0,1,0,0,0,1,1};
	//vector<int> arr2 = { 3,2,1,0,4 };
	////vector<string> ans;
	//Solution().numDecodings("12");
    auto ans = Solution().numIslands(matrix);
	cout << ans << endl;
	//print_vector(ans);


    //cout << Solution().poorPigs(1000,4,15) << endl;

	//vector<int> arr1 = {2, 7, 11, 15};
	//vector<int> arr2 = {9};

	//auto ans = Solution().twoSum(arr1, 9);
	//for (auto p = ans.begin(); p != ans.end(); ++p)
	//{
	//	cout << *p << "  ";
	//}
}

