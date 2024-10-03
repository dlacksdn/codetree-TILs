#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	int count = 0;
	for (int i = 0; i < str.size() - 3; i++) {
		if (str[i] != '(' || str[i+1] != '(')
			continue;
		
		for (int j = i + 2; j < str.size() - 1; j++) {
			if (str[j] != ')' || str[j + 1] != ')')
				continue;

			count++;
		}
	}

	cout << count;
}