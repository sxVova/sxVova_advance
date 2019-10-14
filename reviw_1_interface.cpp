#include <iostream>
#include <vector>
#include <climits>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "elem" between the "begin" and 
// "end" of the given vector
std::vector<int>::iterator l_bound(std::vector<int>::iterator begin,
    const std::vector<int>::iterator &end, const int &elem);

// Write the size of the input data
int input_size();

// Write an information about the workers 
// and reverse it for further calculations
std::vector<int> input_vector(const int &amount);

// Find the numbers of all employees from 
// the longest growing subset
std::vector<int> work(const std::vector<int> &data_in, const int &amount);

// Show the answer
void output(const std::vector<int> &answer);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int amount = input_size();
    const std::vector<int>data_in = input_vector(amount);
    const std::vector<int>answer = work(data_in, amount);
    output(answer);
    return 0;
}
