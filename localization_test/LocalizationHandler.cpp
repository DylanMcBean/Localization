#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include  <random>
#include  <iterator>


#include "LocalizationHandler.h"

void LocalizationHandler::SetLanguage(languages selected_language)
{
	language = selected_language;
	LoadLanguage();
}

void LocalizationHandler::LoadLanguage()
{
	const std::string _languages[3]{ "english","german","french" };
	std::ifstream localized_file("Data/Localization/" + _languages[language] + ".lff");

	std::string line;
	std::string localized_id = "";
	std::string localized_text = "";
	while (std::getline(localized_file, line))
	{
		if (line.find("}") != std::string::npos && line.find("=") == std::string::npos)
			localized_id = localized_id.substr(0, localized_id.find_last_of('.'));
		else if (line.find("=") != std::string::npos)
		{
			if (localized_id == "")
				localized_id += line.substr(0, line.find(" "));
			else
				localized_id += "." + line.substr(line.find_last_of('\t') + 1, line.find_first_of(" ") - line.find_last_of('\t') - 1);
		}

		if (line.find("=") != std::string::npos && line.find("\"") != std::string::npos)
		{
			localized_text = line.substr(line.find_first_of('\"') + 1, line.find_last_of('\"') - (line.find_first_of('\"') + 1));
			localization_map[localized_id] = localized_text;
		}

		if (line.find("=") != std::string::npos && line.find("\"") != std::string::npos)
			localized_id = localized_id.substr(0, localized_id.find_last_of('.'));

	}
}

std::vector<std::string> split(std::string str)
{
	std::smatch matches;
	std::vector<std::string> values;
	while (std::regex_search(str, matches, std::regex("(\\s?\\w+\\s?)+")))
	{
		values.push_back(matches.str(0));
		str = matches.suffix().str();
	}
	return values;
}

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
	std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

std::string LocalizationHandler::Localize(std::string text)
{
	return Localize(text,NULL);
}

std::string LocalizationHandler::Localize(std::string text, std::string* substitutions = NULL)
{
	std::string return_string = std::string(localization_map[text]);
	std::smatch matches;
	int index = 0;
	if (substitutions != NULL) {
		while (std::regex_search(return_string, matches, std::regex("\\{(.*?)\\}")))
		{
			return_string.replace(matches.position(), matches.str(0).length(), substitutions[index]);
			index++;
		}
	}

	while (std::regex_search(return_string, matches, std::regex("\\((.*?)\\)")))
	{
		std::vector<std::string> items = split(matches.str(0));
		return_string.replace(matches.position(), matches.str(0).length(), *select_randomly(items.begin(), items.end()));
		index++;
	}
	return return_string;
}