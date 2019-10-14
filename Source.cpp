#include <iostream>
#include <vector>
#include <climits>

std::vector<int>::iterator l_bound(std::vector<int>::iterator begin, std::vector<int>::iterator end, int elem)
{
	std::vector<int>::iterator tempp;
	std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
	count = distance(begin, end);
	while (count > 0) {
		tempp = begin;
		step = count / 2;
		advance(tempp, step);
		if (*tempp <= elem)
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
// Функция возвращает итератор, который указывает на 
// первое(максимально левое) не меньшее значение, сравнимое 
// с "elem", между "begin" и "end" заданного вектора.
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int amount;
	std::cin >> amount;
	std::vector<int>data_in(amount);
	for (int i(amount - 1); i >= 0; --i) {
		std::cin >> data_in[i];				//сразу реверсирую заданный вектор
	}
	std::vector<int>data(amount + 1, INT_MAX);
	data[0] = INT_MIN;
	std::vector<int>pos(amount + 1, 0);
	pos[0] = -1;
	std::vector<int>prev(amount, 0);
	int length = 0;
	std::vector<int>::iterator l_b;
	for (int cur(0); cur < amount; ++cur) {
		int temp(0);
		l_b = l_bound(data.begin(), data.end(), data_in[cur]);
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
	std::vector<int>answer;
	int position = pos[length];
	while (position != -1) {	//восстановление ответа
		answer.push_back(amount - position);
		position = prev[position];
	}
	std::cout << length << '\n';
	for (auto now : answer) {
		std::cout << now << '\n';
	}
	return 0;
}
