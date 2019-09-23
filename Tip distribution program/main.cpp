/*-----------------------------------------------
	Name : Daegil Pyo
	Email Address : dpyo@myseneca.ca

*** Description of this program ***

 - Tips Distribution program for restaurant.

   I simply made this program for using our restaurant.

   This program is the simply tip distribution program.
There are already some staff`s information who are working 
in restaurant. Each staff has their own tip rating , which 
will influence to the amount of tips.

  There are two sections of shift, those are morning and night shift.
 At first, we will add the staffs that will work for that day and 
 will allocate start time and end time for each staff. Secondly, 
 we will add the tips for each hours( which is option 2 ) .
 Basically morning shift is from 11 to 17, will devided into 6 sections.
 night shift is from 17 to 23.

-----------------------------------------------*/


#include"Staff.h"
#include"functions.h"

using namespace std;

int main()
{
	///------------------------- Needed Variables ------------------------------//
	int option = 0; // the option for program.
	int NumOfStaff = 0; // will store the Number of staff on the shift.
	double morningTips[6] = { 0 }; //  will store morning shift tips.
	double nightTips[6] = { 0 };   //  will store night shift tips.
	///------------------------- Staff Info ------------------------------//
	res::Empinfo staff[MAX_STAFF] = { {"Daegil",1,28,'m',5.0,0,0},{"Donghwan",2,28,'m',6.0,0,0},{"Gahyeon",3,27,'w',6.0,0,0},{"Jinho",4,30,'m',10.0,0,0},
									  {"Hyeonsuk",5,60,'w',10.0,0,0}, {"Mai",6,50,'w',10.0,0,0}, {"Seonhwa",7,30,'w',6.0,0,0}															
	}; // store the information of staffs.
	res::Empinfo* staff_on_shift = nullptr; // will store staffs on the shift.
	///------------------------- Program start ------------------------------//
	do
	{
		function::intro();
		option = function::getNumber(0, 5);
		switch (option)
		{
		case 1:// This section is for the adding the staff on shift.
			system("CLS");

			cout << "--------------------\n"
				<< "     Restaurant      \n"
				<< "        Staff        \n"
				<< "     Add System      \n"
				<< "--------------------" << endl;
			cout << "How many staff want to add ?  : ";
			NumOfStaff = function::getNumber(1, MAX_STAFF);
			staff_on_shift = new res::Empinfo[NumOfStaff]; // dynamically allocate the memory of staffs on shift.
			system("CLS");
			function::AddStaff(staff, staff_on_shift,NumOfStaff);// Place the chosen staff on shift.
			system("CLS");
			break;
		case 2:
			system("CLS");
			function::InsertMorningTips(morningTips);
			function::InsertNightTips(nightTips);
			function::addTips(staff_on_shift, morningTips, nightTips);
			function::pause_();
			system("CLS");
			break;
		case 3:
			system("CLS");
			function::displayTips(morningTips,nightTips, staff_on_shift, NumOfStaff);
			function::pause_();
			system("CLS");
			break;
		case 4:
			system("CLS");
			for (int i = 0; i < MAX_STAFF; i++)
			{
				cout << staff[i];
			}
			function::pause_();
			system("CLS");
			break;
		case 5:
			system("CLS");
			function::TimeSchedule(staff_on_shift, NumOfStaff);
			system("CLS");
			break;
		case 0:
			system("CLS");
			if (function::Yes_Or_No()) {
				system("CLS");
				option = 99; 
			}
			else { 
				system("CLS"); 
				cout << "\n****** Thank you ******\n"; 
			}
			break;
		}
	} while (option != 0);
	delete[] staff_on_shift;
	return 0;
}