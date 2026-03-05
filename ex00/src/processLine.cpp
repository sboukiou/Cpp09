#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

static void	parseDate(std::string &date,
		std::map<std::string, double>) {
	std::string year;
	std::string month;
	std::string day;

	split(year, month, date, '-');
	if (year.length() != 4)
		throw(std::runtime_error("Invalid year"));
	for (size_t i = 0; i < year.length(); i += 1)
		if (std::isdigit(year[i]) == false)
		throw(std::runtime_error("Invalid year"));
	year = month;
	split(month, day, year, '-');
	trim(month);
	trim(day);
	if (month.length() != 2 || day.length() != 2)
		throw(std::runtime_error("Invalid month | day"));
	for (size_t i = 0; i < month.length(); i += 1)
		if (std::isdigit(month[i]) == false || std::isdigit(day[i]) == false)
		throw(std::runtime_error("Invalid month | day"));
}

static void	parseValue(std::string &value, double &hold) {

	if (value.empty())
		throw(std::runtime_error("No value was found"));
	std::string::const_iterator iter = value.begin();
	while (iter != value.end() && (std::isdigit(*iter) || *iter == '.'))
		++iter;
	if (iter != value.end())
		throw(std::runtime_error("Value has a non numerical char"));
	const char *temp = value.c_str();
	char *end;
	hold = strtod(temp, &end);
}

void	processLine(std::map<std::string, double> &ref, std::string buffer, Type type) {
	char delim;
	std::string date;
	std::string value;
	double numValue;
	if (type == DB)
		delim = ',';
	else if (type == DATA)
		delim = '|';
	else
		throw(std::runtime_error("Invalid line delimiter\n"));
	split(date, value, buffer, delim);
	trim(date);
	trim(value);
	parseDate(date, ref);
	parseValue(value, numValue);
	ref[date] = numValue;
}
