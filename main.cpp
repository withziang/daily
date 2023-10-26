#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>
#include <limits>
#include <map>
#include <cmath>
#include <deque>
#include <utility>
#include <functional>
#include <fstream>
#include <cstring>
        
using namespace std;

string encript(string& input, int password) {
    for (int i = 0; i < input.size(); i++) {
        input[i] = char(input[i] + pow(password,2)); // Use char() to avoid integer overflow
    }
    return input;
}

string decript(string& input, int password) {
    for (int i = 0; i < input.size(); i++) {
        input[i] = char(input[i] - pow(password,2)); // Use char() to avoid integer overflow
    }
    return input;
}
int main(){

	while (1){

	string x;
	printf("%s\n", "Decript or Encript(D/E): ");
	cin >> x;

	bool isEncript = (x.compare("E") == 0)? true : false;
	bool isDecript = (x.compare("D") == 0)? true : false;



	if (isEncript){
		printf("%s\n", "Your text: ");
		string something;
		getline(cin >> ws,something);
		printf("%s\n", "Password: ");
		int password;
		cin >> password;
		string outcome = encript(something, password);
		cout << outcome << endl;
	}else if (isDecript){
		printf("%s\n", "Encripted text: ");
		string something1;
		getline(cin >> ws,something1);
		printf("%s\n", "Password: ");
		int password1;
		cin >> password1;
		string outcome1 = decript(something1, password1);
		cout << outcome1 << endl;

	}

}
}