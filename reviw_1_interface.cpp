#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "insertion_element" between the "start_of_search" and 
// "end_of_search" of the given vector
std::vector<int>::iterator find_lower_bound(const std::vector<int>::iterator &start_of_search,
    const std::vector<int>::iterator &end_of_search, const int insertion_element);

// Read the size of the input data
int read_integer();

// Read an information about the workers 
std::vector<int> read_integer_vector(const int vector_size);

// Find the numbers of all employees from 
// the largest non - increasing sequence
std::vector<int> find_optimal_subsequence(const std::vector<int> &employee_demand_ratios);

// Write the size and content of the vector
void write_vector_information(const std::vector<int> &integer_vector);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int vector_size = read_integer();
    const std::vector<int> employee_demand_ratios = read_integer_vector(vector_size);
    const std::vector<int> optimal_subsequence = find_optimal_subsequence(employee_demand_ratios);
    write_vector_information(optimal_subsequence);
    return 0;
}
