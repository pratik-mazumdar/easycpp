#pragma once
#include <string>
#include <iostream>
#include <map>
#include <any>
class String;
class Double;
class Int {
private: long $mainInteger;
		 long $intInteger;
public:
	Int() {}
	Int(long $intInteger) {
		$mainInteger = $intInteger;
		this->$intInteger = $intInteger;
	}
	long toLong() {
		return $mainInteger;
	}
	void debug() {
		std::cout << $mainInteger;
	}
	bool isEqual(long $x) {
		if ($intInteger == $x)
			return true;
		return false;
	}
	String toString();
};
class String {
private: std::string $mainString;
public:
		String() {}
		template <class $dataType>
		String($dataType $charString) {
			$mainString = $charString; 
		}
public:	int length() {
		int $count = 0;
			while( $mainString[$count] != '\0') {
				$count++;
			}
			return $count;
		}
		std::string toString() {
			return $mainString;
		}
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

		std::string toStdString() {
			return $mainString;
		}
		/*bool replace(String $needle) {
			std::string $charNeedle = $needle.toString();
			for (long $i = 0; $i < $mainString.length(); $i++) {
				if ($charNeedle[0] == $mainString[$i])
					$mainString[$i] = $needle.toStdString().c_str();
			}
		}*/
};

String Int::toString() {
	return  std::to_string(Int::$mainInteger);
}

class Double {};

class Array {
	std::map <int, Int> $integer;
	std::map <int, String> $string;
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
		void strType(String t) { $string.insert(std::pair<int, String>($key, t)); $key++; }
public:
		template<>
		void array(Int t) { intType(t); }
		void array(int t) { intType(t); }
		void array(long t) { intType(t); }
		void array(String t) { strType(t); }
		void array(const char* t) { strType(t); }
		void array(std::string t) { strType(t);}
		/*void array(float t) { $string.push_back(t);}
		void array(double t) { $string.push_back(t);}
		void array(long double t) { $string.push_back(t);}*/
		template<class $dataType>
		$dataType getValue(size_t pos) {}
		template<>
		Int getValue(size_t pos) { return ($integer.count(pos) != 0) ? $integer[pos] : - 1; }
		template<>
		String getValue(size_t pos) { return ($string.count(pos) != 0) ? $string[pos] : "Array out of Bond"; }
};
