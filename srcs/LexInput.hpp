#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class LexInput {
private:
	std::string _cmds[11] = { "push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "dupe", "print" };
	std::string _types[5] = { "int8(", "int16(", "int32(", "float(", "double(" };
	std::vector<std::string> _input;
public:
	LexInput();
	~LexInput();
	char isvalidcomment(std::string);
	int stringIsNumbers(std::string);
	int cleanInput(std::string, int);
	void cleanfurther(std::string, int);
	std::vector<std::string> getCleanInput();

	class InvalidCommand : public std::exception {
			std::string _message;
		public:
			InvalidCommand(std::string cmd) : _message("\"" + cmd + "\"" + " isn't valid command.") {}
			const char * what () const throw () {
				system("say Read the PDF!");
				return _message.c_str();
			}
	};

	class InvalidType : public std::exception {
			std::string _message;
		public:
			InvalidType(std::string type) : _message("\"" + type + "\"" + " isn't valid type.") {}
			const char * what () const throw () {
				system("say what type is that?");
				return _message.c_str();
			}
	};

	class ExtraInstructions : public std::exception {
			std::string _message;
		public:
			ExtraInstructions(std::string cmd) : _message("\"" + cmd + "\"" + " is an extrenious command. Use \";\" to make it a comment.") {}
			const char * what () const throw () {
				system("say Are you trying to break me?");
				return _message.c_str();
			}
	};

	class InvalidNumber : public std::exception {
			std::string _message;
		public:
			InvalidNumber(std::string nbr) : _message("\"" + nbr + "\"" + " isn't a valid number.") {}
			const char * what () const throw () {
				system("say Do you even know simple maths?");
				return _message.c_str();
			}
	};

	struct InvalidInstruction : public std::exception {
		const char * what () const throw () {
			system("say Invalid instruction on line dafuck");
			return "Invalid instruction on line dafuck";
		}
	};
};
