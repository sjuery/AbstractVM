#include "ParseInput.hpp"

ParseInput::ParseInput() {};
ParseInput::~ParseInput() {};

int ParseInput::stringIsNumbers(std::string str)
{
	int cnt = 0;

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

char ParseInput::isvalidcomment(std::string string)
{
	for(size_t i = 0; i < string.length(); i++)
		if(!std::isspace(string[i]))
			return string[i];
	return ';';
}

void ParseInput::cleanfurther(std::string line, int cmdcnt)
{
	if(_cmds[cmdcnt] != "push" && _cmds[cmdcnt] != "assert")
	{
		if(isvalidcomment(line.substr(_cmds[cmdcnt].length())) == ';')
			_input.push_back(cmdcnt != 10 ? "0" + std::to_string(cmdcnt) : std::to_string(cmdcnt));
		else
			throw InvalidInstruction();
	}
	else if(stringIsNumbers(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1).c_str()) && isvalidcomment(line.substr(line.find(')')+1)) == ';')
	{
		for(int j = 0; j < 5; j++)
		{
			if(line.substr(_cmds[cmdcnt].length()+1, _types[j].length()) == _types[j])
			{
				_input.push_back((_cmds[cmdcnt] == "push" ? "00 " : "03 ") + std::to_string(j) + " " + line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
				return ;
			}
		}
		throw InvalidInstruction();
	}
	else
		throw InvalidInstruction();
}

void ParseInput::cleanInput(std::string line, int linecnt)
{
	try
	{
		if(line.empty() || isvalidcomment(line) == ';')
			return ;
		for(int i = 0; i < 11; i++)
		{
			if(line.substr(0, _cmds[i].length()) == _cmds[i])
			{
				cleanfurther(line, i);
				return ;
			}
		}
		throw InvalidInstruction();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << linecnt << std::endl;
	}
}

std::vector<std::string> ParseInput::getCleanInput()
{
	return _input;
}
