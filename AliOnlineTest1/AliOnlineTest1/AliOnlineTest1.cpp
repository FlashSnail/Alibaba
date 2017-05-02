// AliOnlineTest1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

/*真实世界的股票交易规则太复杂，我们这里做一些简化。首先我们假设有N个股票和M个交易期。
可以认为在单个交易期内所有股票的价格都是恒定的。股票卖出需要缴纳交易额的P倍的印花税。
股票可以零碎地买卖，即，你买个0.01股也是可以的。
我们这个市场里没有停牌，没有休市，没有涨停跌停，没有买空卖空，没有分红，而且股票价格也不会跌到零。
 
举个例子，假设你用手里的一元钱买了个股票。
这个股票第一期价格1元/股，你买入之后手上有1股股票和0元现金。
这个股票在第二期涨到2元/股，那么你这时卖出1股就获得了2元（税前），扣除10%的印花税，你手上没有股票却有1.8元现金。
 
如果你在一开始有1元现金，在M个交易期之后，你最多能持有多少现金？

输入:
第一行是两个正整数N和M以及一个浮点数P。随后是M行，每行N个浮点数，代码某期（行）内某股票（列）的价格。
输出:
M期后你持有的现金，一个精确到小数点后一位的浮点数。
输入范例:
1 2 0.1
1
2
输出范例:
1.8*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	int M;
	double P;
	double temp;
	vector<double> price;
	double ans = 0;
	while (cin>>N)
	{
		cin >> M;
		cin >> P;
		price.resize(N);
		ans = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				price[j] = temp;
			}			
		}
		for (auto i : price)
		{
			ans += i;
		}
		ans = ans - (ans*P);
		cout << ans << endl;
	}

	system("pause");
	return 0;
}*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
	//找出每一列的波谷买入
	vector<double> min;
	//找出每一列的波峰卖出
	vector<double> max;
	double ans = 0;
	bool findMax = false;
	bool findMin = true;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (prices[j][i] < prices[j][i - 1] && prices[j][i] < prices[j][i + 1] && findMin)
			{
				min.push_back(prices[j][i]);
				findMax = true;
				findMin = false;
			}
			if (prices[j][i] > prices[j][i - 1] && prices[j][i] > prices[j][i + 1] && findMax)
			{
				max.push_back(prices[j][i]);
				findMin = true;
				findMax = false;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		ans += (max[i] - min[i]);
	}
	ans = ans - (ans * p);
	return ans;
}
/******************************结束写代码******************************/
int main()
{
	int n = 0;
	int m = 0;
	double p = 0;
	cin >> n >> m >> p;

	vector<vector<double>> prices;
	for (int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for (int j = 0; j < n; ++j) {
			double x = 0;
			cin >> x;
			prices.back().push_back(x);
		}
	}

	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);

	return 0;
}*/
//找出每一列的最小值买入
vector<double> min(n);
//找出每一列的最大值卖出
vector<double> max(n);
double ans = 0;
for (int i = 0; i < n; i++)
{
	max[i] = prices[0][i];
	min[i] = prices[0][i];
	for (int j = 0; j < m; j++)
	{
		if (prices[j][i] > max[i])
		{
			max[i] = prices[j][i];
		}
		if (prices[j][i] < min[i])
		{
			min[i] = prices[j][i];
		}
	}
}
for (int i = 0; i < n; i++)
{
	ans += (max[i] - min[i]);
}
ans = ans - (ans * p);
return ans;