//#include<iostream>
//#include<string>
//#include<vector>
////#include<unordered_map>
////#include<math.h>
////#include<unordered_map>
//#include<algorithm>
//
//using namespace std;
////
//////class record_node
//////{
//////public:
//////	string filename;
//////	int line;
//////	int count;
//////	record_node * pre;
//////	record_node * next;
//////	record_node(const string &_filename, int _line, int _count=1, record_node*_pre = NULL,record_node*_next=NULL)
//////	{
//////		filename = _filename;
//////		line = _line;
//////		count =  _count;
//////		pre = _pre;
//////		next = _next;
//////	}
//////};
//////
//////bool is_same_node(record_node * r,const string &filename,int line)
//////{
//////	if (r->filename == filename && r->line == line) { return true; }
//////	return false;
//////};
//////
//////string get_filename(const string &fullname)
//////{
//////	int i = fullname.rfind('\\');
//////	string filename;
//////	if (i == string::npos) { filename = fullname; }
//////	else { filename = fullname.substr(i + 1); }
//////	if (filename.size() > 16)
//////	{
//////		return filename.substr(filename.size() - 16);
//////	}
//////	else
//////	{
//////		return filename;
//////	}
//////};
////
////
////bool is_prime(int num)
////{
////	if (num == 2 || num == 3 || num == 5)
////		return true;
////	unsigned long c = 7;
////	if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num == 1)
////		return false;
////	int maxc = int(sqrt(num));
////	while (c <= maxc)
////	{
////		if (num%c == 0)
////			return false;
////		c += 4;
////		if (num%c == 0)
////			return false;
////		c += 2;
////		if (num%c == 0)
////			return false;
////		c += 4;
////		if (num%c == 0)
////			return false;
////		c += 2;
////		if (num%c == 0)
////			return false;
////		c += 4;
////		if (num%c == 0)
////			return false;
////		c += 6;
////		if (num%c == 0)
////			return false;
////		c += 2;
////		if (num%c == 0)
////			return false;
////		c += 6;
////	}
////	return true;
////}
////
////void Encrypt(const string & strIn)
////{
////	const int b = 1;
////	for (const auto &c : strIn)
////	{
////		if (c == 'Z') { cout << 'a'; }
////		else if (c == 'z') { cout << 'A'; }
////		else if ('A' <= c&&c <= 'Y') { cout << char(c + 32 + b); }
////		else if ('a' <= c&&c <= 'y') { cout << char(c - 32 + b); }
////		else if (c == '9') { cout << '0'; }
////		else if ('0' <= c&&c <= '8') { cout << char(c + b); }
////		else { cout << c; }
////	}
////	cout << endl;
////	return;
////}
////
////
////void unEncrypt(const string & strIn)
////{
////	const int b = -1;
////	for (const auto &c : strIn)
////	{
////		if (c == 'a') { cout << 'Z'; }
////		else if (c == 'A') { cout << 'z'; }
////		else if ('B' <= c&&c <= 'Z') { cout << char(c + 32 + b); }
////		else if ('b' <= c&&c <= 'z') { cout << char(c - 32 + b); }
////		else if (c == '0') { cout << '9'; }
////		else if ('1' <= c&&c <= '9') { cout << char(c + b); }
////		else { cout << c; }
////	}
////	cout << endl;
////	return;
////}
////
////void print_sentence_r(const string &s, int b, int e)
////{
////	if (e == b)
////	{
////		return;
////	}
////	if ('a' <= s[b] && s[b] <= 'z' || 'A' <= s[b] && s[b] <= 'Z')
////	{
////		for (int i = b + 1; i < e; ++i)
////		{
////			if (!('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z'))
////			{
////				print_sentence_r(s, i, e);
////				cout << s.substr(b, i - b);
////				return;
////			}
////		}
////		cout << s.substr(b, e);
////	}
////	else
////	{
////		for (int i = b + 1; i < e; ++i)
////		{
////			if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
////			{
////				print_sentence_r(s, i, e);
////				cout << ' ';
////				return;
////			}
////		}
////	}
////
////}
//
//
//bool str_lower(const string &n1, const string &n2)
//{
//    if (n1[0] == '-' && n2[0] == '-')
//    {
//        if (n1.size() < n2.size()) { return false; }
//        else if (n1.size() > n2.size()) { return true; }
//        else
//        {
//            for (int i = 1; i<n1.size(); ++i)
//            {
//                if (n1[i] > n2[i])
//                {
//                    return true;
//                }
//                else if (n1[i] < n2[i])
//                {
//                    return false;
//                }
//            }
//            return true;
//        }
//    }
//    else if (n1[0] == '-')
//    {
//        return true;
//    }
//    else if (n2[0] == '-')
//    {
//        return false;
//    }
//    else
//    {
//        int s1 = n1.size();
//        if (n1[0] == '+') { s1--; }
//        int s2 = n2.size();
//        if (n2[0] == '+') { s2--; }
//
//
//        if (s1 < s2) { return true; }
//        else if (s1 > s2) { return false; }
//        else
//        {
//            int i = 0, j = 0;
//            if (n1[0] == '+') { i = 1; }
//            if (n2[0] == '+') { j = 1; }
//            for (; i<n1.size()&&j<n2.size(); ++i,++j)
//            {
//                if (n1[i] > n2[j])
//                {
//                    return false;
//                }
//                else if (n1[i] < n2[j])
//                {
//                    return true;
//                }
//            }
//            return true;
//        }
//    }
//    return true;
//}
//
//
//bool str_greater(const string &n1, const string &n2)
//{
//    return !str_lower(n1, n2);
//}
//
//int main()
//{
//
//    string strIn;
//    while (getline(cin, strIn))
//    {
//        bool is_ASCE = true;
//        for(auto &c:strIn)
//        {
//            if (c == 'D' || c == 'd') { is_ASCE = false; break; }
//            else if (c == 'A' || c == 'a') { is_ASCE = true; break; }
//        }
//
//        //split nums
//        vector<string> nums;
//        string t;
//        strIn.push_back(',');
//        for (int i = 0; i < strIn.size(); ++i)
//        {
//            char c = strIn[i];
//            if ('0' <= c && c <= '9' || c == '-'|| c=='+')
//            {
//                t.push_back(c);
//            }
//            else
//            {
//                if (t.size() != 0)
//                {
//                    nums.push_back(t);
//                    t.clear();
//                }
//            }
//        }
//
//        //sort each number
//        for (auto &n : nums)
//        {
//            sort(n.begin(), n.end());
//            if (n[0] == '-')
//            {
//                reverse(n.begin() + 1, n.end());
//            }
//            else if(n[0] == '+' && n[1] == '0')
//            {
//                int i = 2;
//                for (; i < n.size(); ++i)
//                {
//                    if (n[i] != '0')
//                    {
//                        break;
//                    }
//                }
//                char t = n[1];
//                n[1] = n[i];
//                n[i] = t;
//            }
//            else if (n[0] == '0')
//            {
//                int i = 1;
//                for (;i < n.size(); ++i)
//                {
//                    if (n[i] != '0')
//                    {
//                        break;
//                    }
//                }
//                char t = n[0];
//                n[0] = n[i];
//                n[i] = t;
//            }
//        }
//
//        //sort list and print
//        if (nums.size() != 0)
//        {
//            //if (is_ASCE)
//            //{
//            //    for (int i = 0; i < nums.size() - 1; ++i)
//            //    {
//            //        for (int j = 0; j < nums.size() - i - 1; ++j)
//            //        {
//            //            if (!str_lower(nums[j], nums[j + 1]))
//            //            {
//            //                swap(nums[j], nums[j + 1]);
//            //            }
//            //        }
//            //    }
//            //}
//            //else
//            //{
//            //    for (int i = 0; i < nums.size() - 1; ++i)
//            //    {
//            //        for (int j = 0; j < nums.size() - i - 1; ++j)
//            //        {
//            //            if (str_lower(nums[j], nums[j + 1]))
//            //            {
//            //                swap(nums[j], nums[j + 1]);
//            //            }
//            //        }
//            //    }
//            //}
//            if (is_ASCE)
//            {
//                sort(nums.begin(), nums.end(), str_lower);
//            }
//            else
//            {
//                sort(nums.begin(), nums.end(), str_greater);
//            }
//            cout << nums[0];
//            for (int i = 1; i < nums.size(); ++i)
//            {
//                cout << ',' << nums[i];
//            }
//            cout << endl;
//        }
//        
//    }
//
//    return 0;
//}
//
//
//
//
//
