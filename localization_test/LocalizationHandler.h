#ifndef LOCALIZATION_HANDLER_H
#define LOCALIZATION_HANDLER_H

#include <map>
#include <string>

class LocalizationHandler
{
public:
	std::map<std::string, std::string> localization_map;
	enum languages {
		English = 0, 
		German = 1, 
		French = 2
	};
	void SetLanguage(languages);
	std::string Localize(std::string);
	std::string Localize(std::string, std::string*);
private:
	languages language;
	void LoadLanguage();
};

#endif