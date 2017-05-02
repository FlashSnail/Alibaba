// AlibabaOnlineTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
/*输入:
第一行包含两个自然数N M。表明地图上有N个关隘城市（编号为1到N），城市间有M条道路。其中编号1为秦都咸阳，N为联军出发地。 随后有M行，每行以单个空格分隔的两个自然数X和Y，表明X和Y之间有一条道路。
输出:
秦军可以驻军阻挡五国联军的地点。从小到大输出，以单个空格分隔。
输入范例:
5 5
1 2
1 3
2 4
3 4
4 5
输出范例:
1 4 5*/
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
vector < int > Joint(int n, vector < vector < int > > edges) {
	for (int i = 1; i < edges.max_size; i++)
	{
		if (edges[1][i] != 1)
		{
			break;
		}		
	}
}

int main() {
	vector < int > res;

	int _n;	//表明地图上有N个关隘城市（编号为1到N）,其中编号1为秦都咸阳，N为联军出发地。
	cin >> _n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector< vector < int > > _edges;
	for (int i = 0; i < _n; ++i) {
		_edges.push_back(vector<int>());
		for (int j = 0; j < _n; ++j) {
			_edges.back().push_back(0);
		}
	}
	int _m = 0;		//城市间有M条道路
	cin >> _m;
	for (int i = 0; i < _m; ++i) {
		//随后有M行，每行以单个空格分隔的两个自然数X和Y，表明X和Y之间有一条道路。
		int a = 0;
		int b = 0;
		_edges[a][b] = 1;
		_edges[b][a] = 1;
	}

	res = Joint(_n, _edges);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << ' ';
	}
	cout << endl;

	return 0;

}