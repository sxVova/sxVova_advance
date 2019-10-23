#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// The function returns an iterator that points 
// to the first(maximally left) at least value 
// comparable to "insertion_element" between the "start_of_search" and 
// "end_of_search" of the given vector
std::vector<int>::iterator find_lower_bound(const std::vector<int>::iterator& start_of_search,
    const std::vector<int>::iterator& end_of_search, const int insertion_element)
{
    std::vector<int>::iterator place_to_insert = start_of_search;
    std::iterator_traits<std::vector<int>::iterator>::difference_type cut_length, search_step;
    cut_length = distance(place_to_insert, end_of_search);

    while (cut_length > 0) {
        std::vector<int>::iterator middle_separator = place_to_insert;
        search_step = cut_length / 2;
        advance(middle_separator, search_step);
        if (*middle_separator <= insertion_element)
        {
            place_to_insert = ++middle_separator;
            cut_length -= search_step + 1;
        }
        else
        {
            cut_length = search_step;
        }
    }
    return place_to_insert;
}

// Read the size of the input data
int read_integer(std::istream& input = std::cin)
{
    int variable;
    input >> variable;
    return variable;
}

// Read an information about the workers 
std::vector<int> read_integer_vector(const int vector_size, std::istream& input = std::cin)
{
    std::vector<int> data_input(vector_size);
    for (int i = 0; i < vector_size; ++i) 
    {
        input >> data_input[i];
    }
    return data_input;
}

// Find the numbers of all employees from 
// the largest non - increasing sequence
std::vector<int> find_optimal_subsequence(const std::vector<int>& employee_demand_ratios)
{
    std::vector<int> reversed_ratios(employee_demand_ratios);
    std::reverse(reversed_ratios.begin(), reversed_ratios.end());

    const int vector_size = reversed_ratios.size();

    std::vector<int> largest_number_sequence_ends(vector_size + 1, INT_MAX);
    std::vector<int> position(vector_size + 1, 0);
    std::vector<int> previous_element(vector_size, 0);

    largest_number_sequence_ends[0] = INT_MIN;
    position[0] = -1;

    int length_maximum_subsequence = 0;

    std::vector<int>::iterator pointer_to_the_place_to_insert;

    for (int current = 0; current < vector_size; ++current) 
    {
        int insertion_index(0);
        pointer_to_the_place_to_insert = find_lower_bound(
            largest_number_sequence_ends.begin(), 
            largest_number_sequence_ends.end(), 
            reversed_ratios[current]
        );

        insertion_index += pointer_to_the_place_to_insert - largest_number_sequence_ends.begin();
        
        if (largest_number_sequence_ends[insertion_index - 1] <= reversed_ratios[current] && // bid
            reversed_ratios[current] <= largest_number_sequence_ends[insertion_index]) // validation
        {
            largest_number_sequence_ends[insertion_index] = reversed_ratios[current];
            position[insertion_index] = current;
            previous_element[current] = position[insertion_index - 1];
            
            if (insertion_index > length_maximum_subsequence) // checking for the maximum 
            {                                                 // length of a subsequence
                length_maximum_subsequence = insertion_index;
            }
        }
    }

    std::vector<int> largest_non_increasing_sequence;
    int current_position = position[length_maximum_subsequence];

    while (current_position != -1) // answer recovery
    {    
        largest_non_increasing_sequence.push_back(vector_size - current_position);
        current_position = previous_element[current_position];
    }

    return largest_non_increasing_sequence;
}

// Write the size and content of the vector
void write_vector_information(const std::vector<int>& integer_vector, 
    std::ostream& output = std::cout)
{
    output << integer_vector.size() << '\n';
    for (auto current_element : integer_vector) 
    {
        output << current_element << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    const int vector_size = read_integer();
    const std::vector<int> employee_demand_ratios = read_integer_vector(vector_size);
    const std::vector<int> optimal_subsequence = find_optimal_subsequence(employee_demand_ratios);
    write_vector_information(optimal_subsequence);
    return 0;
}
