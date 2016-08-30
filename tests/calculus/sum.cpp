#include <iostream>
#include "bigint.hpp"

using namespace std;
using namespace bigint;

/*
 * TODOS: add further values for tests 
 */

int main() {
    int correctness = 0;
    {
	unsigned char val0[] = {1};
	UnsignedBigint a(val0, sizeof (val0));

	unsigned char val1[] = {1};
	UnsignedBigint b(val1, sizeof (val1));

	UnsignedBigint d("0x2");
	
	UnsignedBigint c = a.sum(b);
	bool correct = c==d;
	
	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0xffffffffffffffff");

	unsigned char val1[] = {1};
	UnsignedBigint b(val1, sizeof (val1));
	
	UnsignedBigint d("0x10000000000000000");

	UnsignedBigint c = a.sum(b);
	bool correct = c==d;

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0x8000000000000000");
	UnsignedBigint b("0x8000000000000000");
	UnsignedBigint d("0x10000000000000000");

	UnsignedBigint c = a.sum(b);
	bool correct = c==d;
	
	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << d.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0xC000000000000000");
	UnsignedBigint d("0x0000000000000001 8000000000000000");

	UnsignedBigint c = a.sum(b);
	bool correct = c==d;

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << d.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0xC000000000000000");
	UnsignedBigint b("0x8000000000000000");
	UnsignedBigint d("0x0000000000000001 4000000000000000");

	UnsignedBigint c = a.sum(b);
	bool correct = c==d;

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << d.pretty_to_string() <<  (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0x8000000000000000");
	UnsignedBigint b("0x0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10");
	UnsignedBigint d("0x0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 890A0B0C0D0E0F10");
	
	UnsignedBigint c = a.sum(b);
	bool correct = c==d;

	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << d.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }

    {
	UnsignedBigint a("0x0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10");
	UnsignedBigint b("0x8000000000000000");
	UnsignedBigint d("0x0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 090A0B0C0D0E0F10 0102030405060708 890A0B0C0D0E0F10");
	
	UnsignedBigint c = a.sum(b);
	bool correct = c==d;
	
	cout << a.pretty_to_string() << " + " << endl << b.pretty_to_string() << " = " << endl << c.pretty_to_string() << endl << d.pretty_to_string() << (correct ? " OK" : " ERROR") << endl << endl;
	correctness = (correct ? 0 : -1);
    }
    
    return correctness;
}

