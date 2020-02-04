// test_leecode.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;


int main()
{
	class Solution 
	{
	public:
		int findCircleNum(vector<vector<int>>& M) 
		{
			if (M.size() <= 1) { return M.size(); }
			unordered_set<int> students;
			for (int i = 0; i < M.size(); ++i)
			{
				students.insert(i);
			}
			int num = 0;
			unordered_set<int> circle;
			while (!students.empty())
			{
				int student = *students.begin();
				circle.insert(student);
				students.erase(student);
				while (1)
				{
					for (auto p = students.begin(); p != students.end(); ++p)
					{
						if (M[student][*p])
						{
							circle.insert(*p);
						}
					}
					circle.erase(student);
					for (auto p = circle.begin(); p != circle.end(); ++p)
					{
						students.erase(*p);
					}
					if (circle.empty()) { break; }
					student = *circle.begin();
				}
				num += 1;
			}
			return num;
		}
	};

	vector<vector<int>> M;
	M.push_back({ 1,1,0 });
	M.push_back({ 1,1,1 });
	M.push_back({ 0,1,1 });

    cout << Solution().findCircleNum(M) << endl;

	//vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	//vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };
	//auto ans = Solution().relativeSortArray(arr1, arr2);
	//for (auto p = ans.begin(); p != ans.end(); ++p)
	//{
	//	cout << *p << "  ";
	//}
}

