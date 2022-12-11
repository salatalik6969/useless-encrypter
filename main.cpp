#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{

	vector<pair<char, char>> key{{'a', '4'}, {'b', 'p'}, {'c', 'q'}, {'d', '@'}, {'e', 'z'}, {'f', '*'}, {'g', 'r'}, {'h', '/'}, {'i', 'x'}, {'j', 'y'}, {'k', '1'}, {'l', '<'}, {'m', 'v'}, {'n', 'w'}, {'o', '2'}, {'p', 'b'}, {'q', 'c'}, {'r', 'g'}, {'s', '3'}, {'t', '+'}, {'u', '#'}, {'v', 'm'}, {'w', 'n'}, {'x', 'i'}, {'y', 'j'}, {'z', 'e'}};
	const size_t keylen = key.size();
	char selection;
	string input;
	bool terminate{0};
	cout << "Welcome to simple encoding software.\n\n(E) - Encode a sentence\n(D) - Decode a sentence\n(X) - Quit\nType in your selection: ";
	while (!terminate)
	{
		cin >> selection;
		if (selection == 'X')
			terminate = true;
		else if (selection == 'E')
		{
			cout << "Type sentence you would like to encode :";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(),
					  [](unsigned char c)
					  { return std::tolower(c); });
			size_t def = size(input);
			for (size_t i{0}; i < def; ++i)
			{
				char c = input.at(i);
				for (size_t j{0}; j < keylen; ++j)
				{
					if (c == key[j].first)
						c = key[j].second;
					string cc{c};
					input.replace(i, 1, cc);
				}
			}
			cout << input;
		}
		else if (selection == 'D')
		{
			cout << "Type sentence you would like to decode :";
			bool loop{0};
			while (!loop)
			{
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(),
						  [](unsigned char c)
						  { return std::tolower(c); });
				size_t def = size(input);
				for (size_t i{0}; i < def; ++i)
				{
					char c = input.at(i);
					for (size_t j{0}; j < keylen; ++j)
					{
						if (c == key[j].second)
							c = key[j].first;
						string cc{c};
						input.replace(i, 1, cc);
					}
				}
				cout << input << "\nWould you like to do another? (Y/N) :";
				char sel;
				cin >> sel;
				sel = tolower(sel);
				if (sel == 'n')
			}
		}
		else
			cout << "\nInvalid selection\nPlease type in a valid choice :";
	};
	return 0;
}
