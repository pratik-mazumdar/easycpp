#pragma once
#include <string>
#include <iostream>
namespace easycpp {
	class String;
	class Double {
		long double maindouble = 0;
	public:
		Double() {}
		Double(long double stdDouble) { maindouble = stdDouble; }
		long double to_double() { return maindouble; }
		void debug() { std::cout << maindouble; }
		String to_string();
		Double operator + (Double const& obj) { return obj.maindouble + maindouble; }
		String operator + (String  obj);
		Double operator * (Double const& obj) { return obj.maindouble * maindouble; }
		Double operator - (Double const& obj) { return obj.maindouble - maindouble; }
		Double operator / (Double const& obj) { return obj.maindouble / maindouble; }
		bool operator == (Double const& obj) { return (obj.maindouble == maindouble) ? true : false; }
		bool operator != (Double const& obj) { return (obj.maindouble != maindouble) ? true : false; }
		bool operator <= (Double const& obj) { return (obj.maindouble <= maindouble) ? true : false; }
		bool operator >= (Double const& obj) { return (obj.maindouble >= maindouble) ? true : false; }
		bool operator > (Double const& obj) { return (obj.maindouble > maindouble) ? true : false; }
		bool operator < (Double const& obj) { return (obj.maindouble < maindouble) ? true : false; }
	};
	class Int {
	private: long mainInteger = 0;
	public:
		Int() {}
		Int(long intInteger) { mainInteger = intInteger; }
		long to_long() { return mainInteger; }
		void debug() { std::cout << mainInteger; }
		String to_string();
		Int reverse() {
			long num = mainInteger;
			long new_num = 0;
			while (num > 0) {
				new_num = new_num * 10 + (num % 10);
				num = num / 10;
			}
			return new_num;
		}
		Int operator + (Int const& obj) { return obj.mainInteger + mainInteger; }
		String operator + (String  obj);
		Int operator - (Int const& obj) { return obj.mainInteger - mainInteger; }
		Int operator / (Int const& obj) { return obj.mainInteger / mainInteger; }
		Int operator * (Int const& obj) { return obj.mainInteger * mainInteger; }
		bool operator == (Int const& obj) { return (obj.mainInteger == mainInteger) ? true : false; }
		bool operator != (Int const& obj) { return (obj.mainInteger != mainInteger) ? true : false; }
		bool operator <= (Int const& obj) { return (obj.mainInteger <= mainInteger) ? true : false; }
		bool operator >= (Int const& obj) { return (obj.mainInteger >= mainInteger) ? true : false; }
		bool operator > (Int const& obj) { return (obj.mainInteger > mainInteger) ? true : false; }
		bool operator < (Int const& obj) { return (obj.mainInteger < mainInteger) ? true : false; }
		bool operator % (Int const& obj) { return (obj.mainInteger % mainInteger) ? true : false; }
	};
	class String {
	private: std::string mainString;
	public:
		String() {}
		template <class dataType>
		String(dataType charString) { mainString = charString; }
	public:
		Int parse_int() { return std::stoi(mainString); }
		bool isInt() {
			try {
				std::stoi(mainString);
				return true;
			}
			catch (...) { return false; }
		}
		String operator + (String const& obj) { return  mainString + obj.mainString; }
		bool operator == (String const& obj) { return mainString == obj.mainString; }
		String operator + (Int obj) { return obj.to_string() + this->mainString; }
		String operator + (Double obj) { return obj.to_string() + this->mainString; }
		bool compare_ignore_case(String obj) {

		}
		size_t length() {
			int count = 0;
			while (mainString[count] != '\0') { count++; }
			return count;
		}
		/*void toLower() {
			icu::UnicodeString someUString(mainString.c_str(), "ISO-8859-1");
			std::cout << someUString.toLower();
		}*/
		void debug() { std::cout << mainString; }
		bool starts_with(String prefix) {
			size_t number_char = prefix.length();
			std::string prefixchar = prefix.to_string();
			for (rsize_t i = 0; i < number_char; i++) {
				if (mainString[i] != prefixchar[i])
					return false;
			}
			return true;
		}
		bool find(String needle) {
			std::string charNeedle = needle.to_string();
			for (size_t i = 0; i < mainString.length(); i++) {
				if (charNeedle[0] == mainString[i])
					return true;
			}
			return false;
		}
		size_t find_position(String needle) {
			std::string charNeedle = needle.to_string();
			for (size_t i = 0; i < mainString.length(); i++) {
				if (charNeedle[0] == mainString[i])
					return i;
			}
			throw "Index Out of Bond";
		}
		std::string to_string() { return mainString; }
		/*bool replace(String needle) {
			std::string charNeedle = needle.to_string();
			for (long i = 0; i < mainString.length(); i++) {
				if (charNeedle[0] == mainString[i])
					mainString[i] = needle.toStdString().c_str();
			}
		}*/
	};

	String Int::to_string() { return  std::to_string(Int::mainInteger); }
	String Int::operator + (String  obj) { return this->to_string() + obj; }
	String Double::to_string() { return  std::to_string(Double::maindouble); }
	String Double::operator + (String  obj) { return this->to_string() + obj; }
	template <class type>
	void println(type x) { std::cout << x << "\n"; }
	template<>
	void println(Int x) { x.debug(); std::cout << "\n"; }
	void println(Double x) { x.debug(); std::cout << "\n"; }
	void println(String x) { x.debug(); std::cout << "\n"; }
	template <class type>
	void print(type x) { std::cout << x; }
	template<>
	void print(Int x) { x.debug(); }
	void print(Double x) { x.debug(); }
	void print(String x) { x.debug(); }
	Int integer_() {
		int input;
		std::cin >> input;
		return input;
	}
	Int integer_(std::string output) {
		std::cout << output;
		int input;
		std::cin >> input;
		return input;
	}
	Double double_() {
		double input;
		std::cin >> input;
		return input;
	}
	Double double_(std::string output) {
		std::cout << output;
		double input;
		std::cin >> input;
		return input;
	}
	String string_() {
		std::string input;
		getline(std::cin, input);
		return input;
	}
	String string_(std::string output) {
		std::cout << output;
		std::string input;
		getline(std::cin, input);
		return input;
	}
}