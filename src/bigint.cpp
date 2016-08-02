#include <string>
#include <sstream>
#include "bigint.hpp"
#include <boost/regex.hpp>

namespace bigint {
	static int is_big_endian(void) {
		union {
			uint32_t i;
			char c[4];
		} bint = {0x01020304};

		return bint.c[0] == 1; 
	}

	//Constructor
	UnsignedBigint::UnsignedBigint()
	:number() { }

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
}

