#include <iostream>
#include <vector>
#include <climits>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "insertion_element" between the "start_of_search" and 
// "end_of_search" of the given vector
std::vector<int>::iterator find_lower_bound(std::vector<int>::iterator start_of_search,
    const std::vector<int>::iterator &end_of_search, const int insertion_element);

// Read the size of the input data
int read_integer();

// Read an information about the workers 
// and reverse it for further calculations
std::vector<int> read_reverse_integer_vector(const int vector_size);

// Find the numbers of all employees from 
// the longest growing subset
std::vector<int> find_longest_growing_subset(
    const std::vector<int> &data_input, const int vector_size);

// Write the size and content of the vector
void write_vector_information(const std::vector<int> &informative_vector);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int vector_size = read_integer();
    const std::vector<int> data_input = read_reverse_integer_vector(vector_size);
    const std::vector<int> answer = find_longest_growing_subset(data_input, vector_size);
    write_vector_information(answer);
    return 0;
}
