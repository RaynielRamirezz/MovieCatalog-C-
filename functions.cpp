#include <iostream>
#include <string> 
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

const int SIZE_ARR = 100;// the size of the array 

struct movieStructure
{
	int id;//it'll hold all the movie id's
	string title;//it'll hold all the movie title's
	int year;//it'll hold all the movie year's
	string rating;//it'll hold all the movie rating's
	string mainActor;//it'll hold all the movie main actor's
	bool used;//used for each to determine which line is true or false
};


movieStructure movieList[SIZE_ARR] = { { 0, "", 0 , "" , ""} }; 
/*movieList with datatype  movieStructure which has a size array of 100 */


//this displays all movies that you currently have using a for loop
//but won't display the movies that are FALSE
void displayMovies() {
	system("cls");
	bool existe = false;//local variable that is used when it can't go in the if statement that's inside of the
	                    // for loop due to the all the movies being false.

	cout << "ID	    TITLE					        YEAR" << endl;
	cout << "-----       -------------------------------                     -----" << endl;

	//iterates 100 times
	for (int i = 0; i < SIZE_ARR; i++)
	{
		//if movie is not true then it can't be printed
		if (movieList[i].used != false)

		{
			cout << left;
			cout << "" << setw(12) << movieList[i].id << "" << setw(52) << movieList[i].title << "" << setw(4) << movieList[i].year
				<< endl;
			
			existe = true;//since it entered it doesn't have to go to the other if to print
			              //"There are no movies to display"
		}
			
	}

	if (existe == false) {

		cout << "There are no movies to display! " << endl;
	}

	cout << "---------------------------------------------------------------------" << endl;
}

void displayaMovie() {

	system("cls");

	int inputId;//used to compare the user's input with the movieList[i].id in order to print
	            //the specified id
    cout << left;// in order for them to be aligned to the left
	cout << "DISPLAYING A MOVIE " << endl;
	cout << "---------------------------------------------------- " << endl;
	cout << "Enter the movie id: ";
    cin >> inputId;//user input
	cout << "----------------------------------------------------" << endl;

	bool existe = false;// local variable that is used when it can't go in the if statement that's inside of the
	                    //for statement so it goes to the second if
	
	for (int i = 0; i < SIZE_ARR; i++) {

		
		     //if movie[i].id is equal to the input that the user put and if that line is not false
		     //then it'll go here 
			if (movieList[i].id == inputId && movieList[i].used != false) {

				cout << "ID	    :  " << movieList[i].id << endl;
				cout << "TITLE       :  " << movieList[i].title << endl;
				cout << "YEAR        :  " << movieList[i].year << endl;
				cout << "RATING      :  " << movieList[i].rating << endl;
				cout << "MAIN ACTOR: " << movieList[i].mainActor << endl;
				cout << "----------------------------------------------------" << endl;
				existe = true; //since it entered it doesn't have to go to the other if to print
			              // "Did not find any movie with that id!"
				break;//used break because once it finds that id, it doesn't have to keep iterating
			}
		
	}

	if (existe == false) {
		cout << "Did not find any movie with that id! " << endl;
		cout << "----------------------------------------------------";
	}


}

//deletes a movie 
void deleteMovie() {
	system("cls");

    int inputId;//used to compare the user's input with the movieList[i].id in order to delete
	            //the specified id
	cout << "DELETING A MOVIE " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Enter movie id:   ";
	cin >> inputId;//user input
	cout << "----------------------------------------------------" << endl;
	bool existe = false; // local variable that is used when it can't go in the if statement that's inside of the
	                    // for loop due to invalid comparison 

	for (int i = 0; i < SIZE_ARR; i++) {

		if (inputId == movieList[i].id) {
	
			cout << "Deleting " << movieList[i].title << " (" << movieList[i].year << ")" << "..." << endl;
            movieList[i].used = false;// that line of data becomes false so it doesn't get printed if the user
			                          //attempts to do so
			cout << "Done!" << endl;
			cout << "----------------------------------------------------" << endl;
			
			existe = true; //since it entered it doesn't have to go to the other if to print
			              //"Did not find any movie with that id!"
			break; //deleted one movie and then gets out of the for loop
		}
	}

	if (existe == false) {
		cout << "Did not find any movie with that id! " << endl;
		cout << "----------------------------------------------------" << endl;
	}


}

//finds a title from a movie
void titleFind() {
	system("cls");

	string inputTitle; //used to compare the user's input with the movieList[i].id in order to print
	            //the specified title
	bool existe = false;// local variable that is used when it can't go in the if statement that's inside of the
	                    // for loop due to invalid comparison and used being false

	cout << left; //alligned to the left
	cout << "FINDING MOVIES BY TITLE " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Enter title name: ";
	cin.ignore();//erases unnecesary buffer
	getline(cin,inputTitle);
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	
	 cout << "ID	    TITLE					        YEAR" << endl;
	 cout << "-----       -------------------------------                     -----" << endl;

	for (int i = 0; i < SIZE_ARR; i++) {

			if (inputTitle == movieList[i].title && movieList[i].used != false) {

				cout << left;
				cout << "" << setw(12) << movieList[i].id << "" << setw(52) << movieList[i].title << "" << setw(4) << movieList[i].year
					<< endl;
				existe = true;//since it entered it doesn't have to go to the other if statement

			}
		
		
	}

	if (existe == false) {
		system("cls");
		cout << "FINDING MOVIES BY TITLE " << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "Enter title name: " << inputTitle;
		cout << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "Did not find any movie with that title! " << endl;
	}
	cout << "---------------------------------------------------------------------" << endl;

}

//finds an actor from a movie
void actorFind() {
	system("cls");

	string inputActor;//used to compare the user's input with the movieList[i].id in order to print
	            //the specified actor
	bool existe = false;// local variable that is used when it can't go in the if statement that's inside of the
	                    // for loop due to invalid comparison and used being false

	cout << left;//alligned to the left
	cout << "FINDING MOVIES BY ACTOR " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Enter the actor's name: ";
	cin.ignore();//erases unnecesary buffer
	getline(cin, inputActor);
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
    cout << "ID	    TITLE					        YEAR" << endl;
    cout << "-----       -------------------------------                     -----" << endl;

	for (int i = 0; i < SIZE_ARR; i++) {
		
			if (inputActor == movieList[i].mainActor && movieList[i].used != false) {

				cout << left;
				cout << "" << setw(12) << movieList[i].id << "" << setw(52) << movieList[i].title << "" << setw(4) << movieList[i].year
					<< endl;
				existe = true;//since it entered it doesn't have to go to the other if statement

			}
	}
	
	
	if (existe == false) {
		system("cls");
		cout << "FINDING MOVIES BY ACTOR " << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "Enter the actor's name: " << inputActor;
		cout << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "Did not find any movie associated with that actor! " << endl;
		cout << endl;
	}
	cout << "---------------------------------------------------------------------" << endl;

}

//saves all movies to the file named "movies.txt"
void moviesToFile() {

	system("cls");

	ofstream myOMovieFile;//output file in order to give data to a specified file
	myOMovieFile.open("movies.txt");//opening movie.txt 

	cout << "SAVING TO FILE	" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	//if the file exists, enter
	if (myOMovieFile) {

		for (int i = 0; i < SIZE_ARR; i++)
		{       
			//only save movies that are not false since those movies are turned false
			//by the deleteMovie function
			if (movieList[i].used != false) {
				//send all data of the variables in the structure and print "|" after
				//each sent
				myOMovieFile << movieList[i].id << "|"
					<< movieList[i].title << "|"
					<< movieList[i].year << "|"
					<< movieList[i].rating << "|"
					<< movieList[i].mainActor << endl;
				
			}

                


		}

		cout << "Your movies were successfully saved! " << endl;
		cout << "---------------------------------------------------------------------" << endl;

		myOMovieFile.close();//close the file or it can cause problems


	} else {

	 cout << "Could not save to file! " << endl;
	 cout << "---------------------------------------------------------------------" << endl;
}

}
 

//loads all movies to string variables from a file named "movies.txt"
void fileToMovies() {

	system("cls");

	ifstream myIMovieFile;//input file to send data to the variables in the structure from that specified file
	string storage;//will hold all the value from the specified file
	stringstream stream;// a stream string that will hold the values of storage
	int j = 0;//variable to increment each time it finishes what's inside of the WHILE loop
	string sId;//string variable for the id since id is an integer data type
	string sYear;//string variable for the year since year is an integer data type

	myIMovieFile.open("movies.txt");//opening file movies.txt

	cout << "LOADING FROM FILE " << endl;
	cout << "---------------------------------------------------------------------" << endl;

	//if the file exists, enter
	if (myIMovieFile) {

		//gives all the data from movies.txt to the string variable storage
		while(getline(myIMovieFile,storage))
		{
	        
			stream = stringstream(storage);//stream now has all the values of storage which is now a stringstream
			getline(stream, sId, '|');//stream gives the value of the first line of the file till it reaches a "|"
			movieList[j].id = stoi(sId);//now the id is equal to sId (it has to be like this due to id being an integer)
			getline(stream, movieList[j].title, '|');
			getline(stream, sYear, '|');
			movieList[j].year = stoi(sYear);
			getline(stream, movieList[j].rating, '|');
			getline(stream, movieList[j].mainActor, '|');

			movieList[j].used = true; //that line of data becomes true
			j++;//increments
		}

		cout << "Your movies were successfully loaded! " << endl;
		cout << "---------------------------------------------------------------------" << endl;

		myIMovieFile.close();//close the file or it can cause problems

	} else {

		cout << "Could not load file! " << endl;
		cout << "---------------------------------------------------------------------" << endl;
	}
}


//adds a movie if it's not full and if the id does not exists
void addMovie() {

	bool existe = false;//local variable that is used inside of the 'if (userId == movieList[i].id)' when an id exists  
	int userId; //used to compare the user's input with the movieList[i].id in order to check if 
	            //the specified id exists

	system("cls");
	cout << "ADDING A MOVIE " << endl;
	cout << "---------------------------------------------------- " << endl;
	cout << "Enter movie id	         : ";
	cin >> userId; //user's input

	for (int i = 0; i < SIZE_ARR; i++) {

		if (userId == movieList[i].id) {

			cout << "Enter title              : " << movieList[i].title << endl;
			cout << "Enter year of release:  " << movieList[i].year << endl;
			cout << "Enter rating             : " << movieList[i].rating << endl;
			cout << "Enter main actor         : " << movieList[i].mainActor << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "The movie id " << movieList[i].id << " already exists!" << endl;
			cout << "----------------------------------------------------" << endl;
			existe = true;//becomes true and it won't go to the other if
			break;
		}
	}

	if (existe == false) {
 
		for (int i = 0; i < SIZE_ARR; i++) {

           
			//enter if used is equal to false
			//that means that it has space to add since it's false
			if (movieList[i].used == false) {
           

				movieList[i].id = userId;//what the user entered will be used for 'movieList[i].id'
				cin.ignore();//helpful to erase what's on the buffer or it'll skip title
				cout << "Enter title              : ";
				getline(cin, movieList[i].title);
				cout << "Enter year of release:  ";
				cin >> movieList[i].year;
				cout << "Enter rating             : ";
				cin.ignore();
				getline(cin, movieList[i].rating);
				cout << "Enter main actor         : ";
				getline(cin, movieList[i].mainActor);
				cout << "----------------------------------------------------" << endl;
				cout << "Contact was added successfully! " << endl;
				cout << "----------------------------------------------------" << endl;
				movieList[i].used = true;// that line of data becomes true 

                
				break;//adds only one movie and it'll get out of the for loop or it'll just keep adding more

			} 
			//'i' starts from 0 to 99 which is technically like starting from 1 to 100 
			//so if it reaches that then all the lines are gonna be true 
			//and it wont be able to add movies thus so it'll go here
			else if (i == 99) {

		        system("cls");
		        cout << "ADDING A MOVIE " << endl;
		        cout << "----------------------------------------------------" << endl;
		        cout << "Your movie catalog is full! " << endl;
		        cout << "----------------------------------------------------" << endl;
		        
				break;//prints the catalog is full and it'll get out of the for loop
	        }




			
			}
		}


	}



