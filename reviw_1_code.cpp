#include <iostream>
#include <vector>
#include <climits>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "elem" between the "begin" and 
// "end" of the given vector
std::vector<int>::iterator l_bound(std::vector<int>::iterator begin,
    const std::vector<int>::iterator &end, const int &elem)
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

// Input the size of the input data
int input_sizeof_data()
{
    int vector_size;
    std::cin >> vector_size;
    return vector_size;
}

// Input an information about the workers 
// and reverse it for further calculations
std::vector<int> input_workers_data(const int vector_size)
{
    std::vector<int> data_in(vector_size);
    for (int i(vector_size - 1); i >= 0; --i) {
        std::cin >> data_in[i];
    }
    return data_in;
}

// Find the numbers of all employees from 
// the longest growing subset
std::vector<int> work(const std::vector<int> &data_in, const int vector_size)
{
    std::vector<int> data(vector_size + 1, INT_MAX);
    data[0] = INT_MIN;
    std::vector<int> pos(vector_size + 1, 0);
    pos[0] = -1;
    std::vector<int> prev(vector_size, 0);
    int length = 0;
    std::vector<int>::iterator l_b;
    for (int cur(0); cur < vector_size; ++cur) {
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
    std::vector<int> answer;
    int position = pos[length];
    while (position != -1) {    // answer recovery
        answer.push_back(vector_size - position);
        position = prev[position];
    }
    return answer;
}

// Output the size and content of the vector
void output_vector_information(const std::vector<int> &answer)
{
    std::cout << answer.size() << '\n';
    for (auto now : answer) {
        std::cout << now << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int vector_size = input_sizeof_data();
    const std::vector<int>data_in = input_workers_data(vector_size);
    const std::vector<int>answer = work(data_in, vector_size);
    output_vector_information(answer);
    return 0;
}
