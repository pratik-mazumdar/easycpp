#pragma once
#include <string>
#include <iostream>
#include <map>
class String;
class Double {
	long double $maindouble;
public:
	Double() {}
	Double(long double $stdDouble) { $maindouble = $stdDouble; }
	long double toLong() { return $maindouble; }
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
	Int(long $intInteger) {$mainInteger = $intInteger;	}
	long toLong() {return $mainInteger;	}
	void debug() { std::cout << $mainInteger;}
	String toString();
	Int operator + (Int const& obj) { return obj.$mainInteger + $mainInteger;}
	Int operator - (Int const& obj) { return obj.$mainInteger - $mainInteger; }
	Int operator / (Int const& obj) { return obj.$mainInteger/ $mainInteger; }
	Int operator * (Int const& obj) { return obj.$mainInteger * $mainInteger; }
	bool operator == (Int const& obj) { return (obj.$mainInteger == $mainInteger) ? true : false; }
	bool operator != (Int const& obj) { return (obj.$mainInteger != $mainInteger) ? true : false; }
	bool operator <= (Int const& obj) { return (obj.$mainInteger <= $mainInteger) ? true : false; }
	bool operator >= (Int const& obj) { return (obj.$mainInteger >= $mainInteger) ? true : false; }
	bool operator > (Int const& obj) { return (obj.$mainInteger > $mainInteger) ? true : false; }
	bool operator < (Int const& obj) { return (obj.$mainInteger < $mainInteger) ? true : false; }

};
class String {
private: std::string $mainString;
public:
		String() {}
		template <class $dataType>
		String($dataType $charString) {$mainString = $charString; }
public:	int length() {
			int $count = 0;
				while( $mainString[$count] != '\0') { $count++; }
				return $count;
		}
		std::string toString() {return $mainString;}
		void debug() {std::cout << $mainString;}
		bool startsWith(String $prefix) {
		int $number_char = $prefix.length();
		std::string $prefixchar = $prefix.toString();
		for (int i = 0; i < $number_char; i++) {
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
		Int findPosition(String $needle) {
			std::string $charNeedle = $needle.toString();
			for (long $i = 0; $i < $mainString.length(); $i++) {
				if ($charNeedle[0] == $mainString[$i])
					return $i;
			}
			return -1;
		}

		std::string toStdString() { return $mainString;}
};

String Int::toString() { return  std::to_string(Int::$mainInteger);}
String Double::toString() { return  std::to_string(Double::$maindouble); }

class Array {
	std::map <int, Int> $integer;
	std::map <int, String> $string;
	std::map <int, Double> $double;
	size_t $key = 0;
public:	
		Array() {}
		template <typename $dataType>
		Array($dataType t) { array(t); }
		template <typename $dataType>
		void array($dataType t) {}
		template <typename $dataType, typename... Args>
		void array($dataType t,Args... args) {
			array(t);
			array(args...);
		}
		template <typename $dataType, typename... Args>
		Array($dataType t, Args... args) {	
			array(t);
			array(args...);
		}
		void intType(Int t) {$integer.insert(std::pair<int, Int>($key, t)); $key++;}
		void doubleType(Double t) { $double.insert(std::pair<int, Double>($key, t)); $key++; }
		void strType(String t) { $string.insert(std::pair<int, String>($key, t)); $key++; }
		template<>
		void array(Int t) { intType(t); }
		void array(int t) { intType(t); }
		void array(long t) { intType(t); }
		void array(String t) { strType(t); }
		void array(const char* t) { strType(t); }
		void array(std::string t) { strType(t);}
		void array(Double t) { doubleType(t); }
		void array(float t) { doubleType(t); }
		void array(long double t) { doubleType(t); }
		template<class $dataType>
		$dataType getValue(size_t pos) {}
		template<>
		Int getValue(size_t pos) { return ($integer.count(pos) != 0) ? $integer[pos] : - 1; }
		template<>
		String getValue(size_t pos) { return ($string.count(pos) != 0) ? $string[pos] : "Array out of Bond"; }
		template<>
		Double getValue(size_t pos) { return ($double.count(pos) != 0) ? $double[pos] : -1; }
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
