#include "lsystem.h"
#include <iostream>


const std::vector<std::string>* Productions::getSuccessors(char target) const
{
	return &(successors[(int)target]);
}

void Productions::addSuccessor(char predecessor, std::string successor) 
{
	successors[(int)predecessor].push_back(successor);
}

void Productions::addSuccessor(std::string &s)
{
	std::cout << s.c_str() << std::endl;
	bool post(false);
	char pre('0');
	std::string toAdd;

	for (unsigned a = 0; a < s.size(); a++)
	{
		if (s[a] == '>')
		{
			post = true;
			continue;
		}

		if (s[a] == ',')
		{
			addSuccessor(pre, toAdd);
			post = false;
			toAdd.clear();
			continue;
		}	

		if (post)
			toAdd += s[a];
		else
			pre = s[a];
	}
}

LSystem::LSystem(char origin) : 
	currentString(),
	productions(),
	engine()
{
	currentString.push_back(origin);
}

std::string LSystem::toString() const
{
	std::cerr << currentString.size() << "\n";
	std::string toReturn;
	std::list<char>::const_iterator it(currentString.begin());
	while (it != currentString.end())
	{
		toReturn.push_back(*it);
		it++;
	}

	return toReturn;
}

void LSystem::update()
{

	std::list<char>::const_iterator it(currentString.begin());
	while (it != currentString.end())
	{
		const std::vector<std::string>* successors(productions.getSuccessors(*it));
		if (successors->size() > 0)	
		{
			it = currentString.erase(it);
			std::uniform_int_distribution<int> dist(0, successors->size()-1);
			const std::string* replacement(&(successors->at(dist(engine))));

			for (unsigned int a = 0; a < replacement->size(); a++)
				currentString.insert(it, replacement->at(a));
		}
		else
			it++;
	}
}
