#include "../include/BitcoinExchange.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cctype>

void split(std::string &left, std::string &right, std::string &src, char delim) {
	size_t	start = 0;
	size_t	end = src.find(delim);
	if (end == std::string::npos)
		throw(std::runtime_error("Found no delimiter\n"));
	left = src.substr(start, end - start);
	right = src.substr(end + 1, src.length() - 1);
}


void trim(std::string& s) {
	    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
}

size_t occurence(std::string &str, char c) {
	size_t	count = 0;
	for (size_t N = 0; N < str.length(); N += 1)
		if (str[N] == c)
			count += 1;
	return (count);
}
