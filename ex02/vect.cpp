#include "./main.hpp"
#include <climits>

std::vector<std::pair<int, int> >	create_pairs(std::vector<int> &main) {
	std::vector<std::pair<int, int> >	pairs;
	std::pair<int, int>						couple;

	for (size_t	i =0; i < main.size() - 1; i += 2) {
		if (main[i] < main[i + 1])
			couple = std::make_pair(main[i + 1], main[i]);
		else
			couple = std::make_pair(main[i], main[i + 1]);
		pairs.push_back(couple);
	}
	return (pairs);
}

std::vector<int>	extract_main_elements(std::vector<std::pair<int, int> > &pairs) {
	std::vector<int>	main;

	for (size_t i =0; i < pairs.size(); i += 1) {
		main.push_back(pairs[i].first);
	}
	return (main);
}

std::vector<int>	generate_jacob_seq(size_t size) {
	std::vector<int>	jacob_seq;

	jacob_seq.push_back(0);
	jacob_seq.push_back(1);
	size_t	i = 1;
	while (jacob_seq[i] <= (int)size) {
		int	next = jacob_seq[i] + (2 * jacob_seq[i - 1]);
		jacob_seq.push_back(next);
		i += 1;
	}
	return (jacob_seq);
}



int	fetch_pair(int value, std::vector<std::pair<int, int> > &ref) {
	for (size_t i = 0; i < ref.size();i += 1)
		if (ref[i].first == value)
			return (ref[i].second);
	return (value);
}

static void	binary_search_insert(std::vector<int> &main, int pair) {
	size_t left = 0;
	size_t right = main.size();

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (main[mid] < pair)
			left = mid + 1;
		else
			right = mid;
	}
	main.insert(main.begin() + left, pair);
}


void	jacob_seq_insert(std::vector<int> &main,
		std::vector<std::pair<int, int> > &ref) {
	std::vector<int>	jacob;
	std::vector<int>	insertion_addrs;
	size_t				main_size = main.size();
	std::vector<int>	losers;

	if (main.empty() || ref.empty())
		return ;
	if (main.size() == 1) {
		main.push_back(ref[0].second);
		int temp = main[0];
		main[0] = main[1];
		main[1] = temp;
		return ;
	}
	jacob = generate_jacob_seq(main_size);
	int group_id = 1;
	while (jacob[group_id] < (int)main_size) {
		int high = std::min(jacob[group_id + 1], (int)main_size) - 1;
		int low  = jacob[group_id - 1];

		for (int i = high; i >= low; i--)
			losers.push_back(fetch_pair(main[i], ref));
		group_id += 1;
	}
	// now insert all losers
	for (size_t i = 0; i < losers.size(); i++)
		binary_search_insert(main, losers[i]);
}

std::vector<int>	merge_insertion_sort(std::vector<int> &nums) {
	std::vector<int>	main;
	std::vector<std::pair<int, int> >	ref;
	int					hold;

	hold = INT_MIN;
	if (nums.empty() || nums.size() == 1)
		return (nums);
	if (nums.size() % 2) {
		hold = nums.back();
		nums.pop_back();
	}

	ref = create_pairs(nums);
	main = extract_main_elements(ref);
	main = merge_insertion_sort(main);
	jacob_seq_insert(main, ref);
	if (hold != INT_MIN)
		binary_search_insert(main, hold);
	return (main);
}
