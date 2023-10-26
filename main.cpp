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

string encript(string& input, int password){
	for (int i =0; i< input.size();i++){
		input[i] += pow(password,2);
	}
	return input;
}

string decript(string& input, int password){
	for (int i =0; i< input.size();i++){
		input[i] -= pow(password,2);
	}
	return input;
}

int main(){

	while (1){

	string x;
	cout << "Decript or Encript(D/E): " << endl;
	cin >> x;

	bool isEncript = (x.compare("D") == 0)? true : false;
	bool isDecript = (x.compare("E") == 0)? true : false;



	if (isEncript){
		cout << "Your text: "<< endl;
		string something;
		cin >> something;
		cout << "password: "<< endl;
		int password;
		cin >> password;
		string outcome =encript(something, password);
		cout << outcome << endl;
	}else if (isDecript){
		cout << "Encripted text: "<< endl;
		string something1;
		cin >> something1;
		cout << "Password: "<< endl;
		int password1;
		cin >> password1;
		string outcome1 =decript(something1, password1);
		cout << outcome1 << endl;

	}

}
}