#pragma once
#include <string>
#include <list>
#include <vector>
#include <random>

class Productions
{
	public:
		const std::vector<std::string>* getSuccessors(char target) const;
		void addSuccessor(char predecessor, std::string successor);
		void addSuccessor(std::string &string);

	private:
		std::vector<std::string> successors[256];
};

class LSystem
{
	public:
		LSystem(char origin);
		Productions& getProductions() {return productions;}
		const std::list<char>& getList() const {return currentString;}
		std::string toString() const;
		void update();

	private:
		std::list<char> currentString;
		Productions productions;
		std::default_random_engine engine;
};
