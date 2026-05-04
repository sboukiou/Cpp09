#include "./main.hpp"


static std::vector<int>	parse_input(int ac, char **av) {
	std::vector<int>	numbers;
	double				temp;
	char				*garbage = NULL;

	if (ac == 1)
		throw(std::runtime_error("No agruments were provided!"));
	if (ac == 2)
		throw(std::runtime_error("Only one Argument!"));
	for (int idx = 1; idx < ac; idx += 1) {
		temp = std::strtod(av[idx], &garbage);
		if (garbage && *garbage)
			throw(std::runtime_error("NaN! NOT A NUMBER"));
		else
			numbers.push_back(temp);
	}
	return (numbers);

}


void	sort_with_vector(int ac, char **av) {
	std::vector<int>	numbers;
	std::vector<int> result;

	numbers = parse_input(ac, av);
	std::cout << "----------------- Sorting with Vector -----------------\n";
	result = merge_insertion_sort(numbers);
	for (size_t i = 0; i < result.size(); i += 1)
		std::cout << result[i] << " ";
	std::cout << std::endl;
}
