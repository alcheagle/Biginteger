#include <string>
#include <sstream>
#include "bigint.hpp"
#include <boost/regex.hpp>
#include <iomanip>

namespace bigint {
	static const boost::regex number_regex1("$(0x|0|)([0-9a-fA-F]{1,})");
	static const boost::regex number_regex2("");

	static int is_big_endian(void) {
		union {
			uint32_t i;
			char c[4];
		} bint = {0x01020304};

		return bint.c[0] == 1; 
	}

	//Constructor
	UnsignedBigint::UnsignedBigint()
	:number() { 
		number.push_back(0);
	}

	UnsignedBigint::UnsignedBigint(const UnsignedBigint &b)
	:number(b.number) { }

	UnsignedBigint::UnsignedBigint(const UBIGGEST_TYPE& value) {
		number.push_back(value);
	}

	UnsignedBigint::UnsignedBigint(std::string representation) {
		
	}

	UnsignedBigint::UnsignedBigint(std::string representation, unsigned int base) {
		
	}

	UnsignedBigint::UnsignedBigint(unsigned char* bytes, unsigned int length) {
		
	}
	
	std::string UnsignedBigint::to_string() const{
		std::stringstream ss;
		
		ss << "0x" << std::hex;
		ss << number[0];
		ss << std::setfill('0') << std::setw(sizeof(UBIGGEST_TYPE)*2);

		for(unsigned int i=1; i<number.size(); i++){
			ss << number[i];
		}
		
		return ss.str();
	}

	std::ostream &operator<<(std::ostream &out, const UnsignedBigint &a) {
		out << "0x" << std::hex;
        out << a.number[0];
        out << std::setfill('0') << std::setw(sizeof(UBIGGEST_TYPE)*2);

        for(unsigned int i=1; i<a.number.size(); i++){
            out << a.number[i];
        }

		return out;
	}

	std::istream &operator>>(std::istream &in, UnsignedBigint &a) {
		std::string s;
		in >> s;
		a = s;
		return in;
	}
}

