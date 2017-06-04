#pragma once
#include "render/linesobject.h"
#include <string>

using namespace renderer;
class TreeLineObject
{
	public:
		TreeLineObject(std::string source, float ang, float pers, float fade);	

	private:
		float angle;
		std::vector<Dot> lines;
		LinesObject ogg;
		static std::vector<Dot> makeLines(std::string &source, float ang, float pers, float fd);
		float persistance;
		float fade;	

};
