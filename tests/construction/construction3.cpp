#include <iostream>
#include "bigint.hpp"
#include <utility>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace bigint;

bool test_pretty_to_string(const UnsignedBigint& n, const std::string expected) {
    string s = (n.pretty_to_string());
    cout << setfill(' ') << setw(10) << "tostring " << s << ", expected: " << expected;
    if (s != expected) {
	cout << " " << false << endl;
	return false;
    } else {
	cout << " " << true << endl;
	return true;
    }
}

int main(int argc, char** argv) {
    vector<pair<UnsignedBigint*, std::string> > n;
    
    {
	unsigned char val0[] = {0};
	pair<UnsignedBigint*, std::string> p0(new UnsignedBigint(val0, sizeof (val0)), "0x0000000000000000");
	n.push_back(p0);

	unsigned char val1[] = {1};
	pair<UnsignedBigint*, std::string> p1(new UnsignedBigint(val1, sizeof (val1)), "0x0000000000000001");
	n.push_back(p1);

	unsigned char val2[] = {0x10};
	pair<UnsignedBigint*, std::string> p2(new UnsignedBigint(val2, sizeof (val2)), "0x0000000000000010");
	n.push_back(p2);

	unsigned char val3[] = {0x1, 0x0};
	pair<UnsignedBigint*, std::string> p3(new UnsignedBigint(val3, sizeof (val3)), "0x0000000000000100");
	n.push_back(p3);
	
	unsigned char val9[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8};
	pair<UnsignedBigint*, std::string> p9(new UnsignedBigint(val9, sizeof (val9)), "0x0102030405060708");
	n.push_back(p9);

	unsigned char val4[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	pair<UnsignedBigint*, std::string> p4(new UnsignedBigint(val4, sizeof (val4)), "0xffffffffffffffff");
	n.push_back(p4);

	unsigned char val5[] = {0x1, 0, 0, 0, 0, 0, 0, 0, 0};
	pair<UnsignedBigint*, std::string> p5(new UnsignedBigint(val5, sizeof (val5)), "0x0000000000000001 0000000000000000");
	n.push_back(p5);

	unsigned char val6[] = {0x1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	pair<UnsignedBigint*, std::string> p6(new UnsignedBigint(val6, sizeof (val6)), "0x0000000000010000 0000000000000000");
	n.push_back(p6);
	
	unsigned char val7[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	pair<UnsignedBigint*, std::string> p7(new UnsignedBigint(val7, sizeof (val7)), "0xffffffffffffffff ffffffffffffffff");
	n.push_back(p7);
	
	unsigned char val8[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10};
	pair<UnsignedBigint*, std::string> p8(new UnsignedBigint(val8, sizeof (val8)), "0x0102030405060708 090a0b0c0d0e0f10");
	n.push_back(p8);
	
	unsigned char val10[] = {
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10,
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 
	    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10
	};
	pair<UnsignedBigint*, std::string> p10(new UnsignedBigint(val10, sizeof (val10)), 
		"0x0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10 0102030405060708 090a0b0c0d0e0f10");
	n.push_back(p10);
    }
    
    bool success = true;
    cout << "start testing: " << endl;
    for (unsigned int i = 0; i < n.size(); i++) {
	success = test_pretty_to_string(*n[i].first, n[i].second) && success;

	delete n[i].first;
	n[i].first = NULL;
    }
    
    return success ? 0 : 1;
}

