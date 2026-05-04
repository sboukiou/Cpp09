#include "./main.hpp"
#include <deque>



static std::deque<int>	parse_input(int ac, char **av) {
	std::deque<int>	numbers;
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

void	sort_with_deque(int ac, char **av) {
	std::deque<int>	numbers;
	std::deque<int> result;

	struct timeval	time_begin;
	struct timeval	time_end;
	long	long	time_begin_usec;
	long	long	time_end_usec;

	numbers = parse_input(ac, av);
	std::cout << "----------------- Sorting with Vector -----------------\n";
	gettimeofday(&time_begin, NULL);
	time_begin_usec = time_begin.tv_sec * 1000000 + time_begin.tv_usec;
	result = merge_insertion_sort_deque(numbers);
	for (size_t i = 0; i < result.size(); i += 1)
		std::cout << result[i] << " ";
	std::cout << std::endl;
	gettimeofday(&time_end, NULL);
	time_end_usec = time_end.tv_sec * 1000000 + time_end.tv_usec;
	std::cout << "\n--- it took " << time_end_usec - time_begin_usec << " u-seconds ---\n";
}
