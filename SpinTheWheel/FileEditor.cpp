#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class FileEditor {
private:
	string fname;

public:
	void static AddItem(vector<string>& vec, string item) {
		vec.emplace_back(item);
	}

	void static RemoveItem(vector<string>& vec, int pos) {
		vec.erase(vec.begin() + pos);
	}

	void static SaveList(vector<string>& vec, string fname) {
		ofstream ofile;
		ofile.open(fname);
		for (int i = 0; i < vec.size(); ++i) {
			ofile << vec.at(i) << endl;
		}
		ofile.close();
	}

	void static ShowList(vector<string> vec) {
		cout << "------The List------" << endl;
		for (int i = 0; i < vec.size(); ++i) {
			cout << (i+1) << ": " << vec.at(i) << endl;
		}
	}

	void static SortList(vector<string>& vec) {
		sort(vec.begin(), vec.end());
	}

	void static RemoveDuplicates(vector<string>& vec) {
		// Use built in function to simplify.
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

	vector<string> GetVector() {
		string str;
		vector<string> vec;
		vec.clear();
		ifstream infile(fname);
		while (getline(infile, str)) {
			vec.push_back(str);
		}
		infile.close();
		return vec;
	}

	void MakeFile(string fname) {
		cout << "You do not have the list " << fname << "." << endl;
		cout << "Creating " << fname << "." << endl << endl;
		ofstream outfile(fname);
		outfile.close();
		this->fname = fname;
	}

	void SetFileName(string fname) {
		this->fname = fname;
	}

	string GetFileName() {
		return fname;
	}

};