#ifndef MAIN_HPP
# define MAIN_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>



void	sort_with_deque(int ac, char **av);
void	sort_with_vector(int ac, char **av);
std::vector<int>	merge_insertion_sort_vector(std::vector<int> &nums);
std::deque<int>	merge_insertion_sort_deque(std::deque<int> &nums);
#endif
