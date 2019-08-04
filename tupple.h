#pragma once
#include<map>
#include"datatype.h"
#define _NULL -1
namespace easycpp {
	class Tupple {
		std::map <size_t, Int> integer;
		std::map <size_t, String> string;
		std::map <size_t, Double> _double;
		size_t key = 0;
		void intType(Int t) { integer.insert(std::pair<size_t, Int>(key, t)); key++; }
		void doubleType(Double t) { _double.insert(std::pair<size_t, Double>(key, t)); key++; }
		void strType(String t) { string.insert(std::pair<size_t, String>(key, t)); key++; }
	public:
		Tupple() {}
		template <typename dataType>
		void push(dataType t) {}
		template <typename dataType, typename... Args>
		void push(dataType t, Args... args) {
			push(t);
			push(args...);
		}
		template <typename dataType>
		Tupple(dataType t) { push(t); }
		template <typename dataType, typename... Args>
		Tupple(dataType t, Args... args) {
			push(t);
			push(args...);
		}
		size_t length() { return string.size() + _double.size() + integer.size(); }
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
			try { integer.erase(pos); }
			catch (...) {
				try { string.erase(pos); }
				catch (...) {
					_double.erase(pos);
				}
			}
		}
		//Get Value
		template<class dataType>
		dataType get_value(size_t pos) {}
		template<>	long get_value(size_t pos) { return (integer.count(pos) != 0) ? integer[pos].to_long() : _NULL; }
		template<>	std::string get_value(size_t pos) { return (string.count(pos) != 0) ? string[pos].to_string() : "-1"; }
		template<>	long double get_value(size_t pos) { return (_double.count(pos) != 0) ? _double[pos].to_double() : _NULL; }
		template<>	Int get_value(size_t pos) { return (integer.count(pos) != 0) ? integer[pos] : _NULL; }
		template<>	String get_value(size_t pos) { return (string.count(pos) != 0) ? string[pos] : "-1"; }
		template<>	Double get_value(size_t pos) { return (_double.count(pos) != 0) ? _double[pos] : _NULL; }
		// Set Value
		template<typename type>
		void set_value(size_t pos, type value) { }
		template<> 	void set_value(size_t pos, long value) { integer.at(pos) = value; }
		template<> 	void set_value(size_t pos, int value) { integer.at(pos) = value; }
		template<>	void set_value(size_t pos, Int value) { integer.at(pos) = value; }
		template<>	void set_value(size_t pos, Double value) { _double.at(pos) = value; }
		template<>	void set_value(size_t pos, double value) { _double.at(pos) = value; }
		template<>	void set_value(size_t pos, long double value) { _double.at(pos) = value; }
		template<>	void set_value(size_t pos, float value) { _double.at(pos) = value; }
		template<>	void set_value(size_t pos, std::string value) { string.at(pos) = value; }
		template<>	void set_value(size_t pos, String value) { string.at(pos) = value; }
		template<>	void set_value(size_t pos, const char* value) { string.at(pos) = value; }

		Tupple operator + (Tupple obj) {
			Tupple newTupple = *this;
			for (size_t i = 0; i < obj.length(); i++) {
				try { newTupple.push(key, obj.integer.at(i)); }
				catch (...) {
					try { newTupple.push(key, obj._double.at(i)); }
					catch (...) {
						newTupple.push(key, obj.string.at(i));
					};
				};
			}
			return newTupple;
		}
	};
}