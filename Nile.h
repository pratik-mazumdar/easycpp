#include <string>
#include <iostream>
class String {
private: std::string $mainString;
		 const char* $charString;
public:
		String() {}
		String(const char* $charString) { 
			$mainString = $charString; 
			this->$charString = $charString;
		}
private:const char* toCharString() {
		return $charString;
		}
public:	int length() {
		int $count = 0;
			while( $charString[$count] != '\0') {
				$count++;
			}
			return $count;
		}
		void print() {std::cout << $mainString;}
		bool startsWith(String $prefix) {
		int $number_char = $prefix.length();
		const char* $mainchar = $mainString.c_str();
		const char* $prefixchar = $prefix.toCharString();
		for (int i = 0; i < $number_char; i++) {
			if ($mainchar[i] != $prefixchar[i])
				return false;
		}
		return true;
		}
		bool find(String $needle) {
			const char* $charNeedle = $needle.toCharString();
			const char* $charString = $mainString.c_str();
			for (int $i = 0; $i < $mainString.length(); $i++) {
				if ($charNeedle[0] == $charString[$i])
					return true;
			}
			return false;
		}
		void replace(String $needle) {
			
		}
};
class Int {
private: int $mainInteger;
	public:
		Int() {}
		Int(int $x) { $mainInteger = $x;}
		// Convert Int to String	
		String toString() {
		String output = std::to_string($mainInteger).c_str();
		return output;
	}					// Convert Int to String
		void print() {
		std::cout << $mainInteger;
		}
};
