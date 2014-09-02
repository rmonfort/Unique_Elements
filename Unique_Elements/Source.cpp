#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::stoi;
using std::set;
using std::to_string;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Load the values of each line into a set
		istringstream iss(line);
		set<int> uniques;
		string temp;
		while (getline (iss, temp, ','))
		{
			int number = stoi(temp);
			uniques.insert(number);
		}

		// Print unique elements
		string result;
		for (auto i = uniques.begin(); i != uniques.end(); i++)
		{
			result += (to_string(*i) + ",");
		}
		result.pop_back(); // Remove unnecessary comma
		cout << result << endl;
	}

	return 0;
}