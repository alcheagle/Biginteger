#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <iostream>
#include <map>

#define UBIGGEST_TYPE unsigned long long 

namespace bigint {

    class UnsignedBigint {
    private:
	std::vector<UBIGGEST_TYPE> number; //number[0] is the most sigificative word and number[size-1] is the less significative
    public:
	//Constructors
	UnsignedBigint();
	UnsignedBigint(const UBIGGEST_TYPE&);
	UnsignedBigint(const std::string &representation);
	//UnsignedBigint(const std::string &representation, unsigned int base);
	UnsignedBigint(const UnsignedBigint& b);
	UnsignedBigint(unsigned char* bytes, unsigned int length); //FIXME endianness problems

	//Adding
	UnsignedBigint sum(const UnsignedBigint&) const;
	UnsignedBigint &selfSum(const UnsignedBigint&);
	UnsignedBigint sum(const UBIGGEST_TYPE&) const;
	UnsignedBigint &selfSum(const UBIGGEST_TYPE&);
	UnsignedBigint operator+(const UnsignedBigint&) const;
	UnsignedBigint &operator+=(const UnsignedBigint&);
	UnsignedBigint operator+(const UBIGGEST_TYPE&) const;
	UnsignedBigint &operator+=(const UBIGGEST_TYPE&);

	//Subtraction
	UnsignedBigint sub(const UnsignedBigint&) const;
	UnsignedBigint &selfSub(const UnsignedBigint&);
	UnsignedBigint sub(const UBIGGEST_TYPE&) const;
	UnsignedBigint &selfSub(const UBIGGEST_TYPE&);
	UnsignedBigint operator-(UnsignedBigint const &) const;
	UnsignedBigint &operator-=(UnsignedBigint const &);
	UnsignedBigint operator-(const UBIGGEST_TYPE&) const;
	UnsignedBigint &operator-=(const UBIGGEST_TYPE&);

	//Multiplication
	UnsignedBigint mul(const UnsignedBigint &);
	UnsignedBigint &selfMul(const UnsignedBigint &);
	UnsignedBigint mul(const UBIGGEST_TYPE&);
	UnsignedBigint &selfMul(const UBIGGEST_TYPE&);
	UnsignedBigint operator*(UnsignedBigint const &);
	UnsignedBigint &operator*=(UnsignedBigint const &);
	UnsignedBigint operator*(long long const &);
	UnsignedBigint &operator*=(int const &);

	//division
	UnsignedBigint div(const UnsignedBigint &);
	UnsignedBigint &selfDiv(const UnsignedBigint &);
	UnsignedBigint div(const UBIGGEST_TYPE&);
	UnsignedBigint &selfDiv(const UBIGGEST_TYPE&);
	UnsignedBigint operator/(UnsignedBigint const &);
	UnsignedBigint &operator/=(UnsignedBigint const &);
	UnsignedBigint operator/(long long const &);
	UnsignedBigint &operator/=(int const &);

	//module
	UnsignedBigint mod(const UnsignedBigint &);
	UnsignedBigint &selfMod(const UnsignedBigint &);
	UnsignedBigint mod(const UBIGGEST_TYPE&);
	UnsignedBigint &selfMod(const UBIGGEST_TYPE&);
	UnsignedBigint operator%(UnsignedBigint const &);
	UnsignedBigint &operator%=(UnsignedBigint const &);
	UnsignedBigint operator%(long long const &);
	UnsignedBigint &operator%=(int const &);

	//division and module: the first is the quotient and the second is the remainder
	std::pair<UnsignedBigint, UnsignedBigint> divisionAndModule(const UnsignedBigint&);
	std::pair<UnsignedBigint, UnsignedBigint> divisionAndModule(const UBIGGEST_TYPE&);
	
	//Compare
	char compare(UnsignedBigint const &) const; //0 a == b, -1 a < b, 1 a > b
	bool operator<(const UnsignedBigint &) const;
	bool operator>(const UnsignedBigint &) const;
	bool operator<=(const UnsignedBigint &) const;
	bool operator>=(const UnsignedBigint &) const;
	bool operator==(const UnsignedBigint &) const;

	//Allocation
	UnsignedBigint operator=(const UBIGGEST_TYPE&);

	//Access
	int operator[](const unsigned int &);

	//Input&Output
	friend std::istream &operator>>(std::istream &, UnsignedBigint &);
	friend std::ostream &operator<<(std::ostream &, const UnsignedBigint&);

	//Helpers
	void clear();

	//Power
	UnsignedBigint &pow(int const &);

	//Trivia
	int digits() const;
	int trailing_zeros() const;

	//bitwise operators
	UnsignedBigint andb(const UnsignedBigint &) const;
	UnsignedBigint orb(const UnsignedBigint &) const;
	UnsignedBigint notb() const;
	UnsignedBigint xorb(const UnsignedBigint &) const;
	UnsignedBigint shiftLeft(const UnsignedBigint &) const;
	UnsignedBigint shiftRight(const UnsignedBigint &) const;
	UnsignedBigint shiftLeft(const UBIGGEST_TYPE&) const;
	UnsignedBigint shiftRight(const UBIGGEST_TYPE&) const;
	UnsignedBigint operator&(const UnsignedBigint &) const;
	UnsignedBigint operator|(const UnsignedBigint &) const;
	UnsignedBigint operator~() const;
	UnsignedBigint operator^(const UnsignedBigint &) const;
	UnsignedBigint operator<<(const UnsignedBigint &) const;
	UnsignedBigint operator>>(const UnsignedBigint &) const;
	UnsignedBigint operator<<(const UBIGGEST_TYPE&) const;
	UnsignedBigint operator>>(const UBIGGEST_TYPE&) const;

	//size
	unsigned int size() const;

	std::string to_string() const;
	std::string pretty_to_string() const;
    private:
//	void init_with_base(const std::string& representation, unsigned int base);
    };
}

#endif
