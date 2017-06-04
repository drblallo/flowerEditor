#include "globalsettings.h"
#include "globaldefines.h"
#include "parser/parser.h"
#include <iostream>

GlobalSettings* GlobalSettings::settings(NULL);

GlobalSettings* GlobalSettings::getSettings()
{
	if (!settings)
	{
		string s(SETTING_FILE_NAME);
		string d(DEFAULT_FILE);
		parser::FileParser parser(&s, &d);
		settings = new GlobalSettings(&parser);
		
	}
	return settings;
}

GlobalSettings::GlobalSettings() : 
	iterations(5),
	angle(30.0f),
	persistance(0.7),
	fade(0.7),
	productions("")
{

}

GlobalSettings::GlobalSettings(parser::FileParser* pars) :
	iterations(5),
	angle(30.0f),
	persistance(0.7),
	fade(0.7),
	productions("")
{
	try
	{
		std::string s(SETTING_ITERATIONS);
		iterations = std::stoi(pars->getValue(&s));	

		s = SETTING_ANGLE;
		angle = std::stof(pars->getValue(&s));

		s = SETTING_PERSISTANCE;
		persistance = std::stof(pars->getValue(&s));

		s = SETTING_FADE;
		fade = std::stof(pars->getValue(&s));

		s = SETTING_PRODUCTION;
		productions = pars->getValue(&s);
	}
	catch(std::exception)
	{
		std::cerr << "setting file malformated, using default setting" << std::endl;
	}
}
