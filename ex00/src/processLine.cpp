#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

static bool getClosestRate(const std::map<std::string, double>& db,
                           const std::string& date,
                           double& rate)
{
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);

    if (it != db.end() && it->first == date) {
        rate = it->second;
        return true;
    }

    if (it == db.begin()) {
        return false;
    }

    if (it == db.end() || it->first != date) {
        --it;
    }

    rate = it->second;
    return true;
}

static void	parseDate(std::string &date,
		std::map<std::string, double>) {
	std::string year;
	std::string month;
	std::string day;

	split(year, month, date, '-');
	if (year.length() != 4)
		throw(std::runtime_error("bad input"));
	for (size_t i = 0; i < year.length(); i += 1)
		if (std::isdigit(year[i]) == false)
		throw(std::runtime_error("bad input"));
	if (year > "2026" || year < "2000")
		throw(std::runtime_error("bad input"));
	year = month;
	split(month, day, year, '-');
	trim(month);
	trim(day);
	if (month.length() != 2 || day.length() != 2)
		throw(std::runtime_error("bad input"));
	if (month > "12")
		throw(std::runtime_error("bad input"));
	if (day > "30")
		throw(std::runtime_error("bad input"));

	for (size_t i = 0; i < month.length(); i += 1)
		if (std::isdigit(month[i]) == false || std::isdigit(day[i]) == false)
		throw(std::runtime_error("bad input"));
}

static void	parseValue(std::string &value, double &hold) {

	// Check if string is empty
	if (value.empty())
		throw(std::runtime_error("bad input"));
	if (value[0] == '.' || value[value.length() -1] == '.')
		throw(std::runtime_error("bad input"));
	std::string::const_iterator iter = value.begin();
	++iter;
	if (occurence(value, '.') > 1)
		throw(std::runtime_error("bad input"));
	while (iter != value.end() && (std::isdigit(*iter) || *iter == '.'))
		++iter;
	if (iter != value.end())
		throw(std::runtime_error("bad input"));
	if (value[0] == '-')
		throw(std::runtime_error("bad input"));
	const char *temp = value.c_str();
	char *end;
	hold = strtod(temp, &end);
	if (hold > 1000)
		throw(std::runtime_error("bad input"));
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
		throw(std::runtime_error("bad input"));
	split(date, value, buffer, delim);
	trim(date);
	trim(value);
	parseDate(date, ref);
	parseValue(value, numValue);
	if (type == DATA) {
		double rate;
		if (!getClosestRate(ref, date, rate)) {
			throw std::runtime_error("bad input");
		}
		std::cout << date << " => " << numValue << " = " << (numValue * rate) << std::endl;
	}
	else {
		ref[date] = numValue;
	}
}
