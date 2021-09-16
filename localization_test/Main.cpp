#include "LocalizationHandler.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#pragma execution_character_set( "utf-8" )

int main() {
	SetConsoleOutputCP(65001);
	LocalizationHandler local;
	local.SetLanguage(LocalizationHandler::languages::English);

	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HAPPY") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.SAD") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HELLO", new std::string[]{ "John" }) << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.HURT") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.ATTACK") << "\n\n";

	local.SetLanguage(LocalizationHandler::languages::French);

	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HAPPY") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.SAD") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HELLO", new std::string[]{ "John" }) << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.HURT") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.ATTACK") << "\n\n";

	local.SetLanguage(LocalizationHandler::languages::German);

	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HAPPY") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.SAD") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HELLO", new std::string[]{ "John" }) << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.HURT") << "\n";
	std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.ATTACK") << "\n";
}