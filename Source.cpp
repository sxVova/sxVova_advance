#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::cin;
using std::vector;

vector<int>::iterator l_bound(vector<int>::iterator begin, vector<int>::iterator end, int xy)
{
	vector<int>::iterator tempp;
	std::iterator_traits<vector<int>::iterator>::difference_type count, step;
	count = distance(begin, end);
	while (count > 0) {
		tempp = begin;
		step = count / 2;
		advance(tempp, step);
		if (*tempp <= xy)
		{
			begin = ++tempp;
			count -= step + 1;
		}
		else
		{
			count = step;
		}
	}
	return begin;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount;
	cin >> amount;
	vector<int>data_in(amount);
	for (int i(amount - 1); i >= 0; --i) {
		cin >> data_in[i];
	}
	vector<int>data(amount + 1, INT_MAX);
	data[0] = INT_MIN;
	vector<int>pos(amount + 1, 0);
	pos[0] = -1;
	vector<int>prev(amount, 0);
	int length = 0;
	vector<int>::iterator l_b;
	for (int cur(0); cur < amount; ++cur) {
		int temp(0);
		l_b = l_bound(data.begin(), data.end(), data_in[cur]);
		/*while (data[l_b - data.begin()] == data_in[cur]) {
			++l_b;
		}*/
		temp += l_b - data.begin();
		if (data[temp - 1] <= data_in[cur] && data_in[cur] <= data[temp]) {
			data[temp] = data_in[cur];
			pos[temp] = cur;
			prev[cur] = pos[temp - 1];
			if (temp > length) {
				length = temp;
			}
		}
	}
	vector<int>answer;
	int position = pos[length];
	while (position != -1) {
		answer.push_back(amount - position);
		position = prev[position];
	}
	cout << length << '\n';
	for (auto now : answer) {
		cout << now << '\n';
	}
	return 0;
}
