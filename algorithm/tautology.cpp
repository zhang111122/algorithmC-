#include<iostream>
#include<stack>
using namespace std;
//* 输入由p、q、r、s、t、K、A、N、C、E共10个字母组成的逻辑表达式，
//* 其中p、q、r、s、t的值为1（true）或0（false），即逻辑变量；
//* K、A、N、C、E为逻辑运算符，
//* K-- > and :  x && y
//* A-- > or :  x || y
//* N-- > not :  !x
//* C-- > implies :  (!x) || y
//* E-- > equals :  x == y
//* 问这个逻辑表达式是否为永真式。
//* PS : 输入格式保证是合法的
int p, q, r, s, t;

char arr[100];

int flag = 1;

int len ;


int  check()//检查特定取值下arr数组中的表达式是否为真 只要出现假的情况立马返回0 为真则返回1
{
	stack<int> st;//每一次调用搞一个新栈
	for (int i = len - 1; i >= 0; i--)
	{
		if (arr[i] == 'p')
			st.push(p);
		else if (arr[i] == 'q')
			st.push(q);
		else if (arr[i] == 'r')
			st.push(r);
		else if (arr[i] == 's')
			st.push(s);
		else if (arr[i] == 't')
			st.push(t);
		else if (arr[i] == 'K')
		{
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (x == 1 && y == 1)
				st.push(1);
			else
				st.push(0);
		}
			
		else if (arr[i] == 'A')
		{
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (x == 0 && y == 0)
				st.push(0);
			else
				st.push(1);
		}
		else if (arr[i] == 'N')
		{
			int x = st.top();
			st.pop();
			if (x == 1)
				st.push(0);
			else
				st.push(1);
		}
		else if (arr[i] == 'C')
		{
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (x == 1 && y == 0)
				st.push(0);
			else
				st.push(1);
		}
		else if (arr[i] == 'E')
		{
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (x==y)
				st.push(1);
			else
				st.push(0);
		}

	}
	return st.top();
}
int  fun()
{
	for (p = 0; p <= 1; p++)
	{
		for (q = 0; q <= 1; q++)
		{
			for (r = 0; r <= 1; r++)
			{
				for (s = 0; s <= 1; s++)
				{
					for (t = 0; t <= 1; t++)
					{
						flag = check();
						if (flag == 0)
							return 0;
					}
				}
			}
		}
	}
	return 1;
}
int main()
{
	memset(arr, 0, sizeof arr);
	while (cin >> arr)
	{
		if (arr[0] == '0')
			return 0;
		len = strlen(arr);
		int tem = fun();
		if(tem == 1)
			cout << "tautology\n" << endl;
		else
			cout << "not\n" << endl;
	}
	return 0;
}
