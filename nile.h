#pragma once
#include <string>
#include <iostream>
#include <map>
#define _NULL -1
class String;
class Double {
	long double $maindouble;
public:
	Double() {}
	Double(long double $stdDouble) { $maindouble = $stdDouble; }
	long double toDouble() { return $maindouble; }
	void debug() { std::cout << $maindouble; }
	String toString();
	Double operator + (Double const& obj) { return obj.$maindouble + $maindouble; }
	Double operator * (Double const& obj) { return obj.$maindouble * $maindouble; }
	Double operator - (Double const& obj) { return obj.$maindouble - $maindouble; }
	Double operator / (Double const& obj) { return obj.$maindouble / $maindouble; }
	bool operator == (Double const& obj) { return (obj.$maindouble == $maindouble) ? true : false; }
	bool operator != (Double const& obj) { return (obj.$maindouble != $maindouble) ? true : false; }
	bool operator <= (Double const& obj) { return (obj.$maindouble <= $maindouble) ? true : false; }
	bool operator >= (Double const& obj) { return (obj.$maindouble >= $maindouble) ? true : false; }
	bool operator > (Double const& obj) { return (obj.$maindouble > $maindouble) ? true : false; }
	bool operator < (Double const& obj) { return (obj.$maindouble < $maindouble) ? true : false; }
};
class Int {
private: long $mainInteger;
public:
	Int() {}
	Int(long $intInteger) { $mainInteger = $intInteger; }
	long toLong() { return $mainInteger; }
	void debug() { std::cout << $mainInteger; }
	String toString();
	Int reverse() {
		long $num = $mainInteger;
		long new_num = 0;
		while ($num > 0) {
			new_num = new_num * 10 + ($num % 10);
			$num = $num / 10;

		}
		return new_num;
	}
	Int operator + (Int const& obj) { return obj.$mainInteger + $mainInteger; }
	Int operator - (Int const& obj) { return obj.$mainInteger - $mainInteger; }
	Int operator / (Int const& obj) { return obj.$mainInteger / $mainInteger; }
	Int operator * (Int const& obj) { return obj.$mainInteger * $mainInteger; }
	bool operator == (Int const& obj) { return (obj.$mainInteger == $mainInteger) ? true : false; }
	bool operator != (Int const& obj) { return (obj.$mainInteger != $mainInteger) ? true : false; }
	bool operator <= (Int const& obj) { return (obj.$mainInteger <= $mainInteger) ? true : false; }
	bool operator >= (Int const& obj) { return (obj.$mainInteger >= $mainInteger) ? true : false; }
	bool operator > (Int const& obj) { return (obj.$mainInteger > $mainInteger) ? true : false; }
	bool operator < (Int const& obj) { return (obj.$mainInteger < $mainInteger) ? true : false; }
	bool operator % (Int const& obj) { return (obj.$mainInteger % $mainInteger) ? true : false; }
};
class String {
private: std::string $mainString;
public:
	String() {}
	template <class $dataType>
	String($dataType $charString) { $mainString = $charString; }
public:
	Int parseInt() {return std::stoi($mainString);	}
	bool isInt() { 
		try {
			std::stoi($mainString);
			return true;
		}
		catch (...) {return false;}
	}
	String operator + (String const& obj) { return  $mainString + obj.$mainString; }
	bool operator == (String const& obj) { return $mainString == obj.$mainString; }
	bool compareIgnoreCase(String $obj) {

	}
	size_t length() {
		int $count = 0;
		while ($mainString[$count] != '\0') { $count++; }
		return $count;
	}
	void debug() { std::cout << $mainString; }
	bool startsWith(String $prefix) {
		size_t $number_char = $prefix.length();
		std::string $prefixchar = $prefix.toString();
		for (rsize_t i = 0; i < $number_char; i++) {
			if ($mainString[i] != $prefixchar[i])
				return false;
		}
		return true;
	}
	bool find(String $needle) {
		std::string $charNeedle = $needle.toString();
		for (size_t $i = 0; $i < $mainString.length(); $i++) {
			if ($charNeedle[0] == $mainString[$i])
				return true;
		}
		return false;
	}
	size_t findPosition(String $needle) {
		std::string $charNeedle = $needle.toString();
		for (size_t $i = 0; $i < $mainString.length(); $i++) {
			if ($charNeedle[0] == $mainString[$i])
				return $i;
		}
		throw "Index Out of Bond";
	}
	std::string toString() { return $mainString; }
};

String Int::toString() { return  std::to_string(Int::$mainInteger); }
String Double::toString() { return  std::to_string(Double::$maindouble); }

class Array {
	std::map <size_t, Int> $integer;
	std::map <size_t, String> $string;
	std::map <size_t, Double> $double;
	size_t $key = 0;
	void intType(Int t) { $integer.insert(std::pair<size_t, Int>($key, t)); $key++; }
	void doubleType(Double t) { $double.insert(std::pair<size_t, Double>($key, t)); $key++; }
	void strType(String t) { $string.insert(std::pair<size_t, String>($key, t)); $key++; }
public:
	Array() {}
	template <typename $dataType>
	void push($dataType t) {}
	template <typename $dataType, typename... Args>
	void push($dataType t, Args... args) {
		push(t);
		push(args...);
	}
	template <typename $dataType>
	Array($dataType t) { push(t); }
	template <typename $dataType, typename... Args>
	Array($dataType t, Args... args) {
		push(t);
		push(args...);
	}
	size_t length() { return $string.size() + $double.size() + $integer.size(); }
	// Push Value
	template<>
	void push(Int t) { intType(t); }
	void push(int t) { intType(t); }
	void push(long t) { intType(t); }
	void push(String t) { strType(t); }
	void push(const char* t) { strType(t); }
	void push(std::string t) { strType(t); }
	void push(Double t) { doubleType(t); }
	void push(double t) { doubleType(t); }
	void push(float t) { doubleType(t); }
	void push(long double t) { doubleType(t); }
	// Pop Value
	void pop(size_t pos) {
		try { $integer.erase(pos); }
		catch (...) {
			try { $string.erase(pos); }
			catch (...) {
				$double.erase(pos);
			}
		}
	}
	//Get Value
	template<class $dataType>
	$dataType getValue(size_t pos) {}
	template<>	long getValue(size_t pos) { return ($integer.count(pos) != 0) ? $integer[pos].toLong() : _NULL; }
	template<>	std::string getValue(size_t pos) { return ($string.count(pos) != 0) ? $string[pos].toString() : "-1"; }
	template<>	long double getValue(size_t pos) { return ($double.count(pos) != 0) ? $double[pos].toDouble() : _NULL; }
	template<>	Int getValue(size_t pos) { return ($integer.count(pos) != 0) ? $integer[pos] : _NULL; }
	template<>	String getValue(size_t pos) { return ($string.count(pos) != 0) ? $string[pos] : "-1"; }
	template<>	Double getValue(size_t pos) { return ($double.count(pos) != 0) ? $double[pos] : _NULL; }
	// Set Value
	template<typename $type>
	void setValue(size_t pos, $type $value) { }
	template<> 	void setValue(size_t pos, long $value) { $integer.at(pos) = $value; }
	template<> 	void setValue(size_t pos, int $value) { $integer.at(pos) = $value; }
	template<>	void setValue(size_t pos, Int $value) { $integer.at(pos) = $value; }
	template<>	void setValue(size_t pos, Double $value) { $double.at(pos) = $value; }
	template<>	void setValue(size_t pos, double $value) { $double.at(pos) = $value; }
	template<>	void setValue(size_t pos, long double $value) { $double.at(pos) = $value; }
	template<>	void setValue(size_t pos, float $value) { $double.at(pos) = $value; }
	template<>	void setValue(size_t pos, std::string $value) { $string.at(pos) = $value; }
	template<>	void setValue(size_t pos, String $value) { $string.at(pos) = $value; }
	template<>	void setValue(size_t pos, const char* $value) { $string.at(pos) = $value; }

	Array operator + (Array obj) {	
		Array newArray = *this;
		for (size_t i = 0; i < obj.length(); i++) {
			try { newArray.push($key, obj.$integer.at(i)); }
			catch (...) {
				try { newArray.push($key, obj.$double.at(i)); }
				catch (...) {
					newArray.push($key, obj.$string.at(i));
				};
			};
		}
		return newArray;
	}
};

namespace input {
	Int integer_() {
		int $input;
		std::cin >> $input;
		return $input;
	}
	Int integer_(std::string $output) {
		std::cout << $output;
		int $input;
		std::cin >> $input;
		return $input;
	}
	Double double_() {
		double $input;
		std::cin >> $input;
		return $input;
	}
	Double double_(std::string $output) {
		std::cout << $output;
		double $input;
		std::cin >> $input;
		return $input;
	}
	String string_() {
		std::string $input;
		getline(std::cin, $input);
		return $input;
	}
	String string_(std::string $output) {
		std::cout << $output;
		std::string $input;
		getline(std::cin, $input);
		return $input;
	}
}
