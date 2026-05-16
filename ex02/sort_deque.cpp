#include "./main.hpp"
#include <deque>
#include <algorithm>



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
		if (std::find(numbers.begin(), numbers.end(), temp) != numbers.end())
			throw(std::runtime_error("Found duplicates!"));
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
	gettimeofday(&time_begin, NULL);
	time_begin_usec = time_begin.tv_sec * 1000000 + time_begin.tv_usec;
	result = merge_insertion_sort_deque(numbers);
	gettimeofday(&time_end, NULL);
	time_end_usec = time_end.tv_sec * 1000000 + time_end.tv_usec;
	std::cout << "Time to process a range of " << result.size() << " elements with std::vector is " << time_end_usec - time_begin_usec << " us\n";
}
