#include <iostream>
#include "bigint.hpp"

using namespace std;
using namespace bigint;

int main() {
    {
	unsigned char val0[] = {1};
	UnsignedBigint a(val0, sizeof (val0));

	unsigned char val1[] = {1};
	UnsignedBigint b(val1, sizeof (val1));

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0xffffffffffffffff");

	unsigned char val1[] = {1};
	UnsignedBigint b(val1, sizeof (val1));

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0x8000000000000000");
	UnsignedBigint b("0x8000000000000000");

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0xC000000000000000");

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0x8000000000000000");

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0x8000000000000000");
	UnsignedBigint b("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }

    {
	UnsignedBigint a("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	UnsignedBigint b("0x8000000000000000");

	UnsignedBigint c = a.sum(b);

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << endl;
    }
    
    return 0;
}

