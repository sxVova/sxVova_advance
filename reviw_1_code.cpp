#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "insertion_element" between the "start_of_search" and 
// "end_of_search" of the given vector
std::vector<int>::iterator find_lower_bound(const std::vector<int>::iterator &start_of_search,
    const std::vector<int>::iterator &end_of_search, const int insertion_element)
{
    std::vector<int>::iterator temporary;
    std::vector<int>::iterator resault = start_of_search;
    std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
    count = distance(resault, end_of_search);
    while (count > 0) {
        temporary = resault;
        step = count / 2;
        advance(temporary, step);
        if (*temporary <= insertion_element)
        {
            resault = ++temporary;
            count -= step + 1;
        }
        else
        {
            count = step;
        }
    }
    return resault;
}

// Read the size of the input data
int read_integer()
{
    int variable;
    std::cin >> variable;
    return variable;
}

// Read an information about the workers 
std::vector<int> read_integer_vector(const int vector_size)
{
    std::vector<int> data_input(vector_size);
    for (int i(0); i < vector_size; ++i) {
        std::cin >> data_input[i];
    }
    return data_input;
}

// Find the numbers of all employees from 
// the largest non - increasing sequence
std::vector<int> find_optimal_subsequence(const std::vector<int> &employee_demand_ratios)
{
    std::vector<int> reversed_employee_ratios = employee_demand_ratios;
    std::reverse(reversed_employee_ratios.begin(), reversed_employee_ratios.end());
    const int vector_size = reversed_employee_ratios.size();
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
            dynamic_data.begin(), dynamic_data.end(), reversed_employee_ratios[current]);
        insertion_index += pointer_to_the_place_to_insert - dynamic_data.begin();
        if (dynamic_data[insertion_index - 1] <= 
            reversed_employee_ratios[current] && reversed_employee_ratios[current]
            <= dynamic_data[insertion_index]) {
            dynamic_data[insertion_index] = reversed_employee_ratios[current];
            position[insertion_index] = current;
            previous_element[current] = position[insertion_index - 1];
            if (insertion_index > length_of_the_maximum_subset) {
                length_of_the_maximum_subset = insertion_index;
            }
        }
    }
    std::vector<int> largest_non_increasing_sequence;
    int current_position = position[length_of_the_maximum_subset];
    while (current_position != -1) {    // answer recovery
        largest_non_increasing_sequence.push_back(vector_size - current_position);
        current_position = previous_element[current_position];
    }
    return largest_non_increasing_sequence;
}

// Write the size and content of the vector
void write_vector_information(const std::vector<int> &integer_vector)
{
    std::cout << integer_vector.size() << '\n';
    for (auto current_element : integer_vector) {
        std::cout << current_element << '\n';
    }
}

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
