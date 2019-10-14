#include <iostream>
#include <vector>
#include <climits>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "insertion_element" between the "start_of_search" and 
// "end_of_search" of the given vector
std::vector<int>::iterator find_lower_bound(std::vector<int>::iterator start_of_search,
    const std::vector<int>::iterator &end_of_search, const int insertion_element)
{
    std::vector<int>::iterator temporary;
    std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
    count = distance(start_of_search, end_of_search);
    while (count > 0) {
        temporary = start_of_search;
        step = count / 2;
        advance(temporary, step);
        if (*temporary <= insertion_element)
        {
            start_of_search = ++temporary;
            count -= step + 1;
        }
        else
        {
            count = step;
        }
    }
    return start_of_search;
}

// Read the size of the input data
int read_integer()
{
    int variable;
    std::cin >> variable;
    return variable;
}

// Read an information about the workers 
// and reverse it for further calculations
std::vector<int> read_reverse_integer_vector(const int vector_size)
{
    std::vector<int> data_input(vector_size);
    for (int i(vector_size - 1); i >= 0; --i) {
        std::cin >> data_input[i];
    }
    return data_input;
}

// Find the numbers of all employees from 
// the longest growing subset
std::vector<int> find_longest_growing_subset(
    const std::vector<int> &data_input, const int vector_size)
{
    std::vector<int> dynamic_data(vector_size + 1, INT_MAX);
    dynamic_data[0] = INT_MIN;
    std::vector<int> position(vector_size + 1, 0);
    position[0] = -1;
    std::vector<int> previous_element(vector_size, 0);
    int length_of_the_maximum_subset = 0;
    std::vector<int>::iterator pointer_to_the_place_to_insert;
    for (int current(0); current < vector_size; ++current) {
        int insertion_index(0);
        pointer_to_the_place_to_insert = find_lower_bound(
            dynamic_data.begin(), dynamic_data.end(), data_input[current]);
        insertion_index += pointer_to_the_place_to_insert - dynamic_data.begin();
        if (dynamic_data[insertion_index - 1] <= 
            data_input[current] && data_input[current] <= dynamic_data[insertion_index]) {
            dynamic_data[insertion_index] = data_input[current];
            position[insertion_index] = current;
            previous_element[current] = position[insertion_index - 1];
            if (insertion_index > length_of_the_maximum_subset) {
                length_of_the_maximum_subset = insertion_index;
            }
        }
    }
    std::vector<int> answer;
    int current_position = position[length_of_the_maximum_subset];
    while (current_position != -1) {    // answer recovery
        answer.push_back(vector_size - current_position);
        current_position = previous_element[current_position];
    }
    return answer;
}

// Write the size and content of the vector
void write_vector_information(const std::vector<int> &informative_vector)
{
    std::cout << informative_vector.size() << '\n';
    for (auto current_element : informative_vector) {
        std::cout << current_element << '\n';
    }
}

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
