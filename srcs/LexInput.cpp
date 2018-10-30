#include "LexInput.hpp"

LexInput::LexInput() {};
LexInput::~LexInput() {};

int LexInput::stringIsNumbers(std::string str)
{
	int cnt = 0;

	if(str.empty())
		return 0;
	if(str[cnt] == '-')
		cnt++;
	for(size_t i = cnt; i < str.length(); i++)
	{
		if((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			continue;
		else
			return 0;
	}
	return 1;
}

char LexInput::isvalidcomment(std::string string)
{
	for(size_t i = 0; i < string.length(); i++)
		if(!std::isspace(string[i]))
			return string[i];
	return ';';
}

void LexInput::cleanfurther(std::string line, int cmdcnt)
{
	if(_cmds[cmdcnt] != "push" && _cmds[cmdcnt] != "assert" && _cmds[cmdcnt] != "dupe")
	{
		if(isvalidcomment(line.substr(_cmds[cmdcnt].length())) == ';')
			_input.push_back(cmdcnt != 10 ? "0" + std::to_string(cmdcnt) : std::to_string(cmdcnt));
		else
			throw ExtraInstructions(line.substr(_cmds[cmdcnt].length()));
	}
	else if(isvalidcomment(line.substr(line.find(')')+1)) == ';')
	{
		if(stringIsNumbers(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1).c_str()))
		{
			for(int j = 0; j < 5; j++)
			{
				if(line.substr(_cmds[cmdcnt].length()+1, _types[j].length()) == _types[j])
				{
					if(_cmds[cmdcnt] == "push")
						_input.push_back("00 " + std::to_string(j) + " " + line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
					else if(_cmds[cmdcnt] == "assert")
						_input.push_back("03 " + std::to_string(j) + " " + line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
					else if(_cmds[cmdcnt] == "dupe")
						_input.push_back("09 " + std::to_string(j) + " " + line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
					return ;
				}
			}
			throw InvalidType(line.substr(_cmds[cmdcnt].length()+1, line.find('(') - _cmds[cmdcnt].length() - 1));
		}
		throw InvalidNumber(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
	}
	else
		throw ExtraInstructions(line.substr(line.find(')')+1));
}

int LexInput::cleanInput(std::string line, int linecnt)
{
	try
	{
		if(line.empty() || isvalidcomment(line) == ';')
			return 0;
		for(int i = 0; i < 11; i++)
		{
			if(line.substr(0, _cmds[i].length()) == "exit")
			{
				return 1;
			}
			if(line.substr(0, _cmds[i].length()) == _cmds[i])
			{
				cleanfurther(line, i);
				return 0;
			}
		}
		throw InvalidCommand(line.substr(0, line.find(" ")));
	}
	catch(std::exception& e)
	{
		std::cout << "\033[1;33m[Line: " << linecnt << "] Lexical Error: " << e.what() << "\033[1;32m" << std::endl;
	}
	return 0;
}

std::vector<std::string> LexInput::getCleanInput()
{
	return _input;
}
