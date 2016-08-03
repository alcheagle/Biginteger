#include <iostream>
#include "bigint.hpp"
#include <utility>
#include <vector>
#include <sstream>

using namespace std;
using namespace bigint;

bool test_to_string(const UnsignedBigint& n, const std::string expected) {
	string s = (n.to_string());
	cout << "tostring " << s << ", expected: " << expected;
	if (s != expected) {
		cout << " " << false << endl;
		return false;
	} else {
		cout << " " << true << endl;
		return true;
	}
}

bool test_stream(const UnsignedBigint& n, const std::string expected) {
    cout << "stream " << n << ", expected: " << expected;
	
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

int main() {
	vector<pair<UnsignedBigint*, std::string> > n;
	
	pair<UnsignedBigint*, std::string> p0(new UnsignedBigint(0), "0x0");
	n.push_back(p0);

	pair<UnsignedBigint*, std::string> p1(new UnsignedBigint(0x1), "0x1");
	n.push_back(p1);

	pair<UnsignedBigint*, std::string> p2(new UnsignedBigint(0x10), "0x10");
	n.push_back(p2);

	pair<UnsignedBigint*, std::string> p3(new UnsignedBigint(0x100), "0x100");
	n.push_back(p3);

	pair<UnsignedBigint*, std::string> p4(new UnsignedBigint(0x3232412), "0x3232412");
	n.push_back(p4);

	pair<UnsignedBigint*, std::string> p5(new UnsignedBigint(0x1234567), "0x1234567");
	n.push_back(p5);

	pair<UnsignedBigint*, std::string> p6(new UnsignedBigint(0x2345612), "0x2345612");
	n.push_back(p6);

	bool success = true;
	for(unsigned int i = 0; i<n.size(); i++) {
		success = test_to_string(*n[i].first, n[i].second) && success;
		success = test_stream(*n[i].first, n[i].second) && success;
		
		delete n[i].first;
		n[i].first = NULL;
	}

	return success ? 0 : 1;
}
