#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

class List {
	string familyname;
	string firstname;
	int age;
	int number;
public:
	void setfamilyname(const string& newfamilyname) { familyname = newfamilyname; }
	string getfamilyname() { return familyname; }

	void setfirstname(const string& newfirstname) { firstname = newfirstname; }
	string getfirstname() { return firstname; }

	void setage(int newage) { age = newage; }
	int getage() { return age; }

	void setnumber(int newnumber) { number = newnumber; }
	int getnumber() { return number; }
};

bool Name(List& lhs, List& rhs) {
	return lhs.getfamilyname() < rhs.getfamilyname();
}
bool Age(List& lhs, List& rhs) {
	return lhs.getage() < rhs.getage();
}
bool Number(List& lhs, List& rhs) {
	return lhs.getnumber() < rhs.getnumber();
}

int main() {
	ifstream detafile("Person List.txt");
	vector<List> v1;
	string a;
	string b;
	int c;
	int d;
	int i = 0;
	while (detafile >> a >> b >> c >> d) {
		v1.emplace_back();
		v1[i].setfamilyname(a);
		v1[i].setfirstname(b);
		v1[i].setage(c);
		v1[i].setnumber(d);
		++i;
	}
	cout << "n(Name),a(Age),c(Code)‚Ì‚¢‚Ã‚ê‚©“ü—Í‚µEnter\n";
	string str;
	cin >> str;
	if (str == "n") {
		sort(v1.begin(), v1.end(), Name);
		size_t u = v1.size();
		for (size_t j = 0; j < u; ++j) {
			cout << v1[j].getfamilyname() << " " << v1[j].getfirstname() << " " << v1[j].getage() << "Î ”Ô†" << v1[j].getnumber() << endl;
		}
	}
	if (str == "a") {
		sort(v1.begin(), v1.end(), Age);
		size_t u = v1.size();
		for (size_t j = 0; j < u; ++j) {
			cout << v1[j].getfamilyname() << " " << v1[j].getfirstname() << " " << v1[j].getage() << "Î ”Ô†" << v1[j].getnumber() << endl;
		}
	}
	if (str == "c") {
		sort(v1.begin(), v1.end(), Number);
		size_t u = v1.size();
		for (size_t j = 0; j < u; ++j) {
			cout << v1[j].getfamilyname() << " " << v1[j].getfirstname() << " " << v1[j].getage() << "Î ”Ô†" << v1[j].getnumber() << endl;
		}
	}
	else {
		cout << "‚à‚¤ˆê“x‚â‚è’¼‚µ‚Ä‚­‚¾‚³‚¢";
	}
}