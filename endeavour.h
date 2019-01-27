#pragma once
#include <string>

class Endeavour {

		//  replace all substring from a string
	public: std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
		return str;
	}
	public:	bool startsWith(std::string mainstring, std::string prefix) {
				int n = prefix.length();
				const char *mainchar = mainstring.c_str();
				const char *prefixchar = prefix.c_str();

				for (int i = 0; i < n; i++) {
					if (mainchar[i] != prefixchar[i])
						return false;
				}
				return true;

			}
};
