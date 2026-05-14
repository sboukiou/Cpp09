#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <fstream>

void	 check_args(int ac, char **av);
void extract_line_data(std::string &line, std::map<std::string, float> &pairs);
std::map<std::string, float> load_database(int ac, char **av);
float parse_value(std::string &value);
void validate_days(int year, int month, int day, std::string &keyStr);
void parse_key_string(std::string &keyStr);
void	process_input_line(std::string &line, std::map<std::string, float> &db_data);

#endif /* MAIN_HPP */
