#include <iostream>
#include <string>
#include "Functions.h"
#include "utils.h"
using namespace std;

int main()
{
	int choice;// for the choices
	bool quit = false;// to end the while loop if it's true

	while (quit != true)
	{
		system("cls");
		cout << "MY MOVIES APPLICATION " << endl;
		cout << "-------------------------- " << endl;
		cout << "1.Display movies " << endl;
		cout << "2.Display a movie " << endl;
		cout << "3.Add a movie " << endl;
		cout << "4.Delete a movie " << endl;
		cout << "5.Find movies by title " << endl;
		cout << "6.Find movies by actor " << endl;
		cout << "7.Save movies to file " << endl;
		cout << "8.Load movies from file " << endl;
		cout << "9.Exit application " << endl;
		cout << "-------------------------- " << endl;
		cout << "Enter option number : ";

		choice = getOptionFromUser();//calls function and choice will have that value

		switch (choice)
		{

		case 1:
			//option to call functions
			displayMovies();
			pressAnyKey("");
			break;

		case 2:
			//option to call functions
			displayaMovie();
			pressAnyKey("");
			break;

		case 3:
			//option to call functions
			addMovie();
			pressAnyKey("");
			break;
         
		case 4:
			//option to call functions
			deleteMovie();
			pressAnyKey("");
			break;

		case 5:
			//option to call functions
			titleFind();
			pressAnyKey("");
			break;

		case 6:
			//option to call functions
			actorFind();
			pressAnyKey("");
			break;

		case 7:
			//option to call functions
			moviesToFile();
			pressAnyKey("");
			break;

		case 8:
			//option to call functions
			fileToMovies();
			pressAnyKey("");
			break;

		case 9:
			//option to end the program
			quit = true;
			break;

			//invalid inputs
		default: pressAnyKey("invalid");
			break;
		}

	}

	return 0;
}


