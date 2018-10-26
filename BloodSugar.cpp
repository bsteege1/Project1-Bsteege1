//BloodSugar.cpp
//Brandon Steege
//Project One
//10/26/18

/*
DESCRIPTION: This file houses main() and runs functions of the main program
*/

#include "LinkedList.h"

int main()
{
	//Initializing the lists for each day
	List dayOne;
	List dayTwo;
	List dayThree;
	List dayFour;
	List dayFive;
	List daySix;
	List daySeven;
	List dayEight;
	List dayNine;
	List dayTen;
	List dayEleven;
	List dayTwelve;
	List dayThirteen;
	List dayFourteen;

	//Initializing the input string
	string input;
	
	/*
	This section of code propts the user for the initial value for each day, the insertData() function is then called for each list for its conected day
	*/
	cout << "Please enter day one blood sugar readings:			Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayOne.insertData(input);
	
																
	cout << "Please enter day two blood sugar readings:			Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl;
	cin >> input;
	dayTwo.insertData(input);

	
	cout << "Please enter day three blood sugar readings:			Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayThree.insertData(input);

	cout << "Please enter day four blood sugar readings:			Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayFour.insertData(input);

	cout << "Please enter day five blood sugar readings:			Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl;
	cin >> input;
	dayFive.insertData(input);

	cout << "Please enter day six blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl;
	cin >> input;
	daySix.insertData(input);

	cout << "Please enter day seven blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	daySeven.insertData(input);

	cout << "Please enter day eight blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayEight.insertData(input);

	cout << "Please enter day nine blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayNine.insertData(input);

	cout << "Please enter day ten blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayTen.insertData(input);

	cout << "Please enter day eleven blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayEleven.insertData(input);

	cout << "Please enter day twelve blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl;
	cin >> input;
	dayTwelve.insertData(input);

	cout << "Please enter day thirteen blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl;
	cin >> input;
	dayThirteen.insertData(input);

	cout << "Please enter day fourteen blood sugar readings:				Type 'Next' or 'N' to move to next day" << endl <<
		"								Type 'D' or 'Day' for the summary of the current day" << endl <<
		"								Type 'W' or 'Week' for a summary of the current week " << endl; 
	cin >> input;
	dayFourteen.insertData(input);

	system("pause");
	return 0;
}

