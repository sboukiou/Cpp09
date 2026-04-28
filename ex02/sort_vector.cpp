#include "./main.hpp"

std::vector<int> jacob_generator(size_t size) {
    std::vector<int> jacob;

    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < static_cast<long>(size)) {
        size_t n = jacob.size();
        jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
    }
    return jacob;
}

void	bs_insertion(std::vector<int> &main, int value) {
    size_t left = 0;
    size_t right = main.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (main[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, value);
}

static void	insert_with_jacob(std::vector<int> &main, std::vector<int> &pend) {
	std::vector<int>	jacob = jacob_generator(pend.size());

	if (pend.empty())
		return ;
	bs_insertion(main, pend[0]);
	size_t prev = 1;

    for (size_t i = 2; i < jacob.size(); i++) {
        size_t curr = jacob[i];

        if (curr > pend.size())
            curr = pend.size();

        for (size_t j = curr; j > prev; j--) {
            bs_insertion(main, pend[j - 1]);
        }

        prev = curr;
    }

    // Insert remaining elements
    for (size_t i = pend.size(); i > prev; i--) {
        bs_insertion(main, pend[i - 1]);
    }

}

std::vector<int>	fj_merge_insertion_sort(std::vector<int> &numbers) {
	std::vector<int>	main_chunk;
	std::vector<int>	pend_chunk;

	if (numbers.empty() || numbers.size() == 1)
		return (numbers);
	if (numbers.size() == 2){
		if (numbers[0] > numbers[1]) {
			int temp = numbers[0];
			numbers[0] = numbers[1];
			numbers[1] = temp;
			return (numbers);
		}
	}
	for (size_t	idx = 0; idx < numbers.size() - 1; idx += 2)
		if (numbers[idx] > numbers[idx + 1]) {
			main_chunk.push_back(numbers[idx]);
			pend_chunk.push_back(numbers[idx + 1]);
		}
		else {
			main_chunk.push_back(numbers[idx + 1]);
			pend_chunk.push_back(numbers[idx]);
		}
	if (numbers.size() % 2)
		pend_chunk.push_back(numbers.back());
	main_chunk = fj_merge_insertion_sort(main_chunk);
	insert_with_jacob(main_chunk, pend_chunk);
	return (main_chunk);
}

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
	struct timeval	time_begin;
	struct timeval	time_end;
	long	long	time_begin_usec;
	long	long	time_end_usec;
	std::vector<int>	numbers;

	numbers = parse_input(ac, av);
	std::cout << "----------------- Sorting with Deque -----------------\n";
	gettimeofday(&time_begin, NULL);
	time_begin_usec = time_begin.tv_sec * 1000000 + time_begin.tv_usec;
	fj_merge_insertion_sort(numbers);
	for (size_t idx = 0; idx < numbers.size(); idx += 1)
		std::cout << numbers[idx] << " ";
	std::cout << std::endl;
	gettimeofday(&time_end, NULL);
	time_end_usec = time_end.tv_sec * 1000000 + time_end.tv_usec;
	std::cout << "\n--- it took " << time_end_usec - time_begin_usec << " u-seconds ---\n";
}
