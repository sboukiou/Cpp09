#include <iostream>
#include <vector>


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

static void	insert_with_jacob_order(int &value, std::vector<int> &list) {
	size_t left = 0;
	size_t right = list.size() - 1;

	while (left < right) {
		size_t mid = (right + left) / 2;
		if (list[mid] < value)
			left = mid + 1;
		else right = mid;
	}
	list.insert(list.begin() + left, value);
}

std::vector<int>	merge_insert_sort(std::vector<int> &numbers)  {
	std::vector<int>	winners;
	std::vector<int>	losers;
	if (numbers.size() == 0 || numbers.size() == 1)
		return (numbers);
	// TODO: Implement pair up and split to winners + losers
	pair_up(numbers, winners, losers);
	// TODO: get the new winners from the next winners;
	winners = merge_insert_sort(winners);
	for (size_t idx =0; idx < losers.size(); idx += 1) {
		insert_with_jacob_order(losers[idx], winners);
	}

	return (winners);
}

int main(void) {
	int arr[] = {12, 44, 1, 23, 2, 99, 13, 22, 87, 44, -77, 34};

	std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (size_t idx = 0; idx < numbers.size(); idx += 1)
		std::cout << numbers[idx] << " ";
	std::cout << std::endl;
	numbers = merge_insert_sort(numbers);
	for (size_t idx = 0; idx < numbers.size(); idx += 1)
		std::cout << numbers[idx] << " ";
	std::cout << std::endl;

	return (0);
}
