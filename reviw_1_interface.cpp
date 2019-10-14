#include <iostream>
#include <vector>
#include <climits>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "elem" between the "begin" and 
// "end" of the given vector
std::vector<int>::iterator l_bound(std::vector<int>::iterator begin,
    const std::vector<int>::iterator &end, const int elem);

// Input the size of the input data
int input_sizeof_data();

// Input an information about the workers 
// and reverse it for further calculations
std::vector<int> input_workers_data(const int vector_size);

// Find the numbers of all employees from 
// the longest growing subset
std::vector<int> work(const std::vector<int> &data_in, const int vector_size);

// Output the size and content of the vector
void output_vector_information(const std::vector<int> &answer);

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
