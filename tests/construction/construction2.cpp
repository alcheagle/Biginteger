#include <iostream>
#include "bigint.hpp"
#include <utility>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace bigint;

bool test_to_string(const UnsignedBigint& n, const std::string expected) {
    string s = (n.to_string());
    cout << setfill(' ') << setw(10) << "tostring " << s << ", expected: " << expected;
    if (s != expected) {
	cout << " " << false << endl;
	return false;
    } else {
	cout << " " << true << endl;
	return true;
    }
}

bool test_stream(const UnsignedBigint& n, const std::string expected) {
    cout << setfill(' ') << setw(10) << "stream " << n << ", expected: " << expected;

    stringstream ss;
    ss << n;

    if (ss.str() != expected) {
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
	pair<UnsignedBigint*, std::string> p7(new UnsignedBigint("0"), "0x0");
	n.push_back(p7);

	pair<UnsignedBigint*, std::string> p8(new UnsignedBigint("0x1"), "0x1");
	n.push_back(p8);

	pair<UnsignedBigint*, std::string> p9(new UnsignedBigint("0x10"), "0x10");
	n.push_back(p9);

	pair<UnsignedBigint*, std::string> p10(new UnsignedBigint("0x100"), "0x100");
	n.push_back(p10);

	pair<UnsignedBigint*, std::string> p11(new UnsignedBigint("0xab3232412"), "0xab3232412");
	n.push_back(p11);

	pair<UnsignedBigint*, std::string> p12(new UnsignedBigint("0xcd1234567"), "0xcd1234567");
	n.push_back(p12);

	pair<UnsignedBigint*, std::string> p13(new UnsignedBigint("0x2345612"), "0x2345612");
	n.push_back(p13);
    }
    {
	pair<UnsignedBigint*, std::string> p7(new UnsignedBigint("0"), "0x0");
	n.push_back(p7);

	pair<UnsignedBigint*, std::string> p8(new UnsignedBigint("1"), "0x1");
	n.push_back(p8);

	pair<UnsignedBigint*, std::string> p9(new UnsignedBigint("16"), "0x10");
	n.push_back(p9);

	pair<UnsignedBigint*, std::string> p10(new UnsignedBigint("256"), "0x100");
	n.push_back(p10);

	pair<UnsignedBigint*, std::string> p11(new UnsignedBigint("3232412"), "0x31529C");
	n.push_back(p11);

	pair<UnsignedBigint*, std::string> p12(new UnsignedBigint("5431"), "0x1537");
	n.push_back(p12);

	pair<UnsignedBigint*, std::string> p13(new UnsignedBigint("2345612"), "0x23CA8C");
	n.push_back(p13);
    }
    {
	pair<UnsignedBigint*, std::string> p7(new UnsignedBigint("00"), "0x0");
	n.push_back(p7);

	pair<UnsignedBigint*, std::string> p8(new UnsignedBigint("01"), "0x1");
	n.push_back(p8);

	pair<UnsignedBigint*, std::string> p9(new UnsignedBigint("020"), "0x10");
	n.push_back(p9);

	pair<UnsignedBigint*, std::string> p10(new UnsignedBigint("040"), "0x20");
	n.push_back(p10);

	pair<UnsignedBigint*, std::string> p11(new UnsignedBigint("014251234"), "0x31529C");
	n.push_back(p11);

	pair<UnsignedBigint*, std::string> p12(new UnsignedBigint("012467"), "0x1537");
	n.push_back(p12);

	pair<UnsignedBigint*, std::string> p13(new UnsignedBigint("010745214"), "0x23CA8C");
	n.push_back(p13);
    }
    
    bool success = true;
    cout << "start testing: " << endl;
    for (unsigned int i = 0; i < n.size(); i++) {
	success = test_to_string(*n[i].first, n[i].second) && success;
	success = test_stream(*n[i].first, n[i].second) && success;

	delete n[i].first;
	n[i].first = NULL;
    }
    
    return success ? 0 : 1;
}

