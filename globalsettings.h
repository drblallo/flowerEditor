#pragma once
#include <string>

namespace parser
{
	class FileParser;
}
class GlobalSettings
{
	public:
		static GlobalSettings* getSettings();
		int iterations;
		float angle;
		float persistance;
		float fade;
		std::string productions;

	private:
		GlobalSettings();
		GlobalSettings(parser::FileParser* parser);
		static GlobalSettings* settings;

};
