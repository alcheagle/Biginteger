#include <iostream>
#include <bigint.hpp>

using namespace std;
using namespace bigint;

int main() {
    int correctness = 0;
    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0xC000000000000000");
	char expected = 0;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0xC000000000000000C000000000000000");
	UnsignedBigint b("0xC000000000000000");
	char expected = 1;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0xC000000000000000C000000000000000");
	char expected = -1;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0xC000000000000000C000000000000000");
	UnsignedBigint b("0xC000000000000000C000000000000000");
	char expected = 0;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0xC0000000000000000000000000000000");
	UnsignedBigint b("0xC000000000000000C000000000000000");
	char expected = -1;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	UnsignedBigint b("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	char expected = 0;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }
    {
	UnsignedBigint a("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	UnsignedBigint b("0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	char expected = 0;
	char res = a.compare(b);

	cout << "#################" << endl;
	cout << a.pretty_to_string() << " comparison " << endl << b.pretty_to_string() << " = " << (int) res << " expected " << (int) expected << (res == expected ? " OK" : " ERROR") << endl << endl;

	correctness = (res == expected ? 0 : -1);
    }

    return correctness;
}

