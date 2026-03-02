#include "../include/BitcoinExchange.hpp"
#include <string>


bool isValidDate(std::string &param) {
	std::string chunk;
	std::string year;
	std::string month;
	std::string day;

	size_t delim = param.find('-');
	if (delim == std::string::npos)
		return (false);
	year = param.substr(0, delim);
	chunk = param.substr(delim + 1, param.size() - delim);
	if (year.length() != 4)
		return (false);
	for (size_t  i = 0; i < year.length(); i += 1)
		if (isdigit(year[i]) == false)
			return (false);
	delim = chunk.find('-');
	if (delim == std::string::npos)
		return (false);
	month = chunk.substr(0, delim);
	day = chunk.substr(delim + 1, chunk.size() - delim - 1);
	if (day[day.length() - 1] == ' ')
		day.erase(2, 1);
	if (month.length() != 2 || day.length() != 2)
		return (false);
	for (size_t  i = 0; i < month.length(); i += 1)
		if (isdigit(month[i]) == false)
			return (false);
	for (size_t  i = 0; i < day.length(); i += 1)
		if (isdigit(day[i]) == false)
			return (false);
	if (month[0] != '1' && month[0] != '0')
		return (false);
	if (month[1] > '9')
		return (false);
	if (day[0] > '3')
		return (false);
	if (day[1] > '9')
		return (false);
	if (day[0] == '3' && day[1] > '1')
		return (false);
	return (true);
}

bool isValidValue(std::string &value) {
	std::string N;
	std::string D;

	size_t delim = value.find('.');
	if (delim == std::string::npos) {
		for (size_t i = 0; i <  value.length(); i += 1)
			if (isdigit(value[i]) == false)
				return (false);
		if (value.length() > 4)
			return (false);
		if (value.length() == 4 && value != "1000")
			return (false);
		return (true);
	}

	for (size_t i = 0; i <  N.length(); i += 1)
		if (isdigit(N[i]) == false)
			return (false);
	if (N.length() > 4)
		return (false);
	if (N.length() == 4 && N != "1000")
		return (false);

	for (size_t i = 0; i <  D.length(); i += 1)
		if (isdigit(D[i]) == false)
			return (false);
	if (D.length() > 4)
		return (false);
	if (D.length() == 4 && D != "1000")
		return (false);
	return (true);
}
