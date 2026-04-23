#include "./main.hpp"


static void	pair_up(std::vector<int> &numbers, std::vector<int> &winners,
		std::vector<int> &losers) {
	for (size_t idx = 0; idx < numbers.size() - 1; idx += 2) {
		if (numbers[idx] >= numbers[idx + 1]) {
			winners.push_back(numbers[idx]);
			losers.push_back(numbers[idx + 1]);
		}
		else  {
			winners.push_back(numbers[idx + 1]);
			losers.push_back(numbers[idx]);
		}
	}
}

static void	insert_with_jacob_order(const int &value, std::vector<int> &list) {
	size_t left = 0;
	size_t right = list.size();

	if (list.empty())
		return ;
	while (left < right) {
		size_t mid = (right + left) / 2;
		if (list[mid] < value)
			left = mid + 1;
		else 
			right = mid;
	}
	list.insert(list.begin() + left, value);
}

static std::vector<int>	merge_insert_sort(std::vector<int> &numbers)  {
	std::vector<int>	winners;
	std::vector<int>	losers;
	if (numbers.size() == 0 || numbers.size() == 1)
		return (numbers);
	pair_up(numbers, winners, losers);
	winners = merge_insert_sort(winners);
	for (size_t idx =0; idx < losers.size(); idx += 1) {
		insert_with_jacob_order(losers[idx], winners);
	}

	return (winners);
}

std::vector<int>	parse_input(int ac, char **av) {
	std::vector<int>	numbers;
	double				temp;
	char				*garbage = NULL;

	if (ac == 1)
		throw(std::runtime_error("No agruments were provided!"));
	if (ac == 2)
		throw(std::runtime_error("Only one argument!"));
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
	struct timeval	time_begin;
	struct timeval	time_end;
	long	long	time_begin_usec;
	long	long	time_end_usec;
	std::vector<int>		numbers;

	numbers = parse_input(ac, av);
	std::cout << "----------------- Sorting with vector -----------------\n";
	gettimeofday(&time_begin, NULL);
	time_begin_usec = time_begin.tv_sec * 1000000 + time_begin.tv_usec;
	if (numbers.size() % 2) {
		int temp = numbers[numbers.size() - 1];
		numbers.erase(numbers.end());
		numbers = merge_insert_sort(numbers);
		insert_with_jacob_order(temp, numbers);
	}
	else
		numbers = merge_insert_sort(numbers);
	for (size_t idx = 0; idx < numbers.size(); idx += 1)
		std::cout << numbers[idx] << " ";
	std::cout << std::endl;
	gettimeofday(&time_end, NULL);
	time_end_usec = time_end.tv_sec * 1000000 + time_end.tv_usec;
	std::cout << "\n--- it took " << time_end_usec - time_begin_usec << " u-seconds ---\n";
}
