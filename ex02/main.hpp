#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>


void	sort_vector(std::vector<int> &numbers);
std::vector<int>	parse_input(int ac, char **av);
std::vector<int>	merge_insert_sort(std::vector<int> &numbers);
void	insert_with_jacob_order(const int &value, std::vector<int> &list);
void	pair_up(std::vector<int> &numbers, std::vector<int> &winners,
	std::vector<int> &losers);

#endif
