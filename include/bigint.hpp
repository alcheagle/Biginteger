#ifndef DODECAHEDRON_BIGINT_H_
#define DODECAHEDRON_BIGINT_H_

#include <vector>
#include <iostream>
#include <map>

#define UBIGGEST_TYPE unsigned long long 

namespace bigint{
	class UnsignedBigint{
	private:
		std::vector<UBIGGEST_TYPE> number;
	public:
		//Constructors
		UnsignedBigint();
		UnsignedBigint(const UBIGGEST_TYPE&);
		UnsignedBigint(std::string representation);
		UnsignedBigint(std::string representation, unsigned int  base);
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

		//Compare
		int compare(UnsignedBigint const &) const; //0 a == b, -1 a < b, 1 a > b
		bool operator<(const UnsignedBigint &) const;
		bool operator>(const UnsignedBigint &) const;
		bool operator<=(const UnsignedBigint &) const;
		bool operator>=(const UnsignedBigint &) const;
		bool operator==(const UnsignedBigint &) const;

		//Allocation
		UnsignedBigint operator=(const UBIGGEST_TYPE&);

		//Access
		int operator[](const int &);

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
	};
}

#endif
