#include <iostream>
#include <string>

using namespace std;


void pressAnyKey(string message) {
	cout << endl << message << endl << endl;
	cout << "<Press any key to continue>";
	cin.ignore();
	cin.get();

}

int getOptionFromUser() {
	int inputValue;//user's input

	cin >> inputValue;

	//if it's invalid
	if (cin.fail() == true) {
		cin.clear();//gets cleared
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//removed from the buffer
		return(-1);//returns -1 to where the function was called
	}
	//if it's not invalid then it'll return the user's input
	else {
		return(inputValue);
	}
}