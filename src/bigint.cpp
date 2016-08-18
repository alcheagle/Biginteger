#include <string>
#include <sstream>
#include "bigint.hpp"
#include <boost/regex.hpp>
#include <iomanip>
#include <boost/assert.hpp>
#include <cmath>

namespace bigint {
    //static const boost::regex number_regex1("(0x)([0-9a-fA-F]{1,})|(0)([0-7]{1,})|([0-9]{1,})");
    static const boost::regex hex_number_regex("0x([0-9a-fA-F]{1,})");
    static const boost::regex oct_number_regex("0([0-7]{1,})");
    static const boost::regex dec_number_regex("([0-9]{1,})");
    //static const boost::regex number_regex2("([0-9]{1,})"); //FIXME for safer use a regex which checks also the interval of the value

    static int is_big_endian(void) {

	union {
	    uint32_t i;
	    char c[4];
	} bint = {0x01020304};

	return bint.c[0] == 1;
    }

    static UBIGGEST_TYPE ipow(UBIGGEST_TYPE base, UBIGGEST_TYPE exp) {
	UBIGGEST_TYPE result = 1;
	while (exp) {
	    if (exp & 1)
		result *= base;
	    exp >>= 1;
	    base *= base;
	}

	return result;
    }

    //Constructor

    UnsignedBigint::UnsignedBigint()
    : number() {
	number.push_back(0);
    }

    UnsignedBigint::UnsignedBigint(const UnsignedBigint &b)
    : number(b.number) {
    }

    UnsignedBigint::UnsignedBigint(const UBIGGEST_TYPE& value) {
	number.push_back(value);
    }

    UnsignedBigint::UnsignedBigint(const std::string &representation) {
	boost::smatch matches;
	std::string *number = NULL;
	unsigned int base = 0;

	if (boost::regex_match(representation, matches, hex_number_regex)) {
	    number = new std::string(matches[1].first, matches[1].second);
	    base = 16;
	} else if (boost::regex_match(representation, matches, oct_number_regex)) {
	    number = new std::string(matches[1].first, matches[1].second);
	    base = 8;
	} else if (boost::regex_match(representation, matches, dec_number_regex)) {
	    number = new std::string(matches[1].first, matches[1].second);
	    base = 10;
	} else {
	    BOOST_ASSERT_MSG(true, "not recognized number represetation"); ///TODO throw exception instead
	}

	std::cout << "match: " << *number << "base:" << base << std::endl;
	init_with_base(*number, base);
	delete number;
    }

    UnsignedBigint::UnsignedBigint(const std::string &representation, unsigned int base) {
	init_with_base(representation, base);
    }

    UnsignedBigint::UnsignedBigint(unsigned char* bytes, unsigned int length) {
	UBIGGEST_TYPE value = 0;
	for (unsigned int i = 0; i < length; i++) {
	    UBIGGEST_TYPE next = ((UBIGGEST_TYPE) bytes[i]) << (((length - 1 - i) % sizeof (UBIGGEST_TYPE))*8);
	    value = value | next;
//	    std::cout << "module: " << (i % sizeof(UBIGGEST_TYPE)) << std::endl;
//	    std::cout << std::setfill(' ') << std::setw(10) << "char: 0x" << std::hex << (unsigned int)bytes[i] << std::endl;
//	    std::cout << std::setfill(' ') << std::setw(10) << "next: 0x" << std::hex << next << std::endl;
//	    std::cout << std::setfill(' ') << std::setw(10) << "value: 0x" << std::hex << value << std::endl;

	    if (((i + 1) % sizeof (UBIGGEST_TYPE)) == 0 || (i + 1) == length) {
		//		std::cout << "storing: 0x" << std::hex << value << std::endl;
		number.push_back(value);
		value = 0;
	    }
	}
    }

    void UnsignedBigint::init_with_base(const std::string& representation, unsigned int base) {
	//TODO decide how representation should be
	//static unsigned long long upper_boound = std::pow(2, sizeof(UBIGGEST_TYPE));

	number.push_back(0);
    }

    std::string UnsignedBigint::to_string() const {
	std::stringstream ss;
	ss << *this;
	return ss.str();
    }

    std::string UnsignedBigint::pretty_to_string() const {
	std::stringstream ss;
	ss << "0x" << std::hex;
	ss << std::setfill('0') << std::setw(sizeof (UBIGGEST_TYPE)*2);
	ss << number[0];

	for (unsigned int i = 1; i < number.size(); i++) {
	    ss << " " << std::setfill('0') << std::setw(sizeof (UBIGGEST_TYPE)*2) << number[i];
	}
	return ss.str();
    }
    
    std::ostream &operator<<(std::ostream &out, const UnsignedBigint &a) {
	out << "0x" << std::hex;
	out << a.number[0];

	out << std::setfill('0') << std::setw(sizeof (UBIGGEST_TYPE)*2);
	for (unsigned int i = 1; i < a.number.size(); i++) {
	    out << std::setfill('0') << std::setw(sizeof (UBIGGEST_TYPE)*2) << a.number[i];
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

