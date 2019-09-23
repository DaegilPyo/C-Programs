#include"functions.h"
using namespace std;
namespace function
{
	bool Yes_Or_No()
	{
		char YON = '\0';
		bool result = false;
		cout << " Would you like to exit Tip Rating program?(Y(y)/N(n)) : ";
		do
		{
			cin >> YON;
			clearKeyboard();
			if (YON != 'N' && YON != 'n' && YON != 'Y' && YON != 'y') { cout << "Invalid value, please enter Y(y)/N(n) : "; }
			if (YON != 'Y' && YON != 'y') { result = true; }
			else if (YON != 'N' && YON != 'n') { result = false; }
		} while (YON != 'N' && YON != 'n' && YON != 'Y' && YON != 'y');
		return result;
	}
	void clearKeyboard(void)
	{
		while (getchar() != '\n'); // empty execution code block on purpose
	}
	void pause_()
	{
		cout << "Press enter to continue ... ";
		cin.ignore(1000, '\n');
		cout << endl;
	}
	//---------------------------------------------------------------------
	void AddStaff(const res::Empinfo* emp, res::Empinfo* emp_on_shift, int NumOfStaff)
	{ 
		int Staff_Count = 0;
		int StaffNumber = 0;
		int StaffNumber_on_Shift[MAX_STAFF] = { 0 };
		int StaffAdd = 0;
		int Stime = 0;
		int Etime = 0;
		for (int k = 0; k < NumOfStaff; k++)
		{
			bool This_Staff_On_Shift = false;
			cout << "\n                  ** Staff list **\n\n";
				for (int i = 0; i < MAX_STAFF; i++)
				{
					if (!emp[i].isEmpty())
					{
						This_Staff_On_Shift = false;
						for (int j = 0; j < MAX_STAFF; j++)
						{
							if (emp[i].getSnumber() == StaffNumber_on_Shift[i])
							{
								This_Staff_On_Shift = true;
							}
						}
						if (!This_Staff_On_Shift)
						{
							cout << " - Staff Num : " << emp[i].getSnumber() << " | Name : "
								<< setw(10) << left << emp[i].getName() << " | TipRating : "
								<< emp[i].getTiprating() << "\n";
						}
						Staff_Count++;
					}
					else { i = MAX_STAFF; }
				}
//----------------------------------------------------------------------------------------------------
				cout << "\n-------------------------------------------- \n";
				cout << "  Which staff do you want to add? \n  Please enter the Staff Number : ";
				StaffNumber = function::getNumber(1, Staff_Count);
				for (int i = 0; i < MAX_STAFF; i++)
				{
					if (StaffNumber_on_Shift[i] == 0)
					{
						
						StaffNumber_on_Shift[i] = StaffNumber;
						i = MAX_STAFF;
					}
				}
//----------------------------------------------------------------------------------------------------
				for (int i = 0; i < MAX_STAFF; i++)
				{
					if (!emp[i].isEmpty())
					{
						if (emp[i].getSnumber() == StaffNumber)
						{
							system("CLS");
							cout << "      *** Shift ***" << endl;
							cout <<"  " << emp[i].getName() << "`s Start time : ";
							Stime = function::getNumber(11, 22);
							cout << "  " << emp[i].getName() << "`s End time : ";
							Etime = function::getNumber(12, 23);
							cout << "\n\n  ******* SECCESS!! *******" << endl;
							cout << "  " << emp[i].getName() << " is added on shift.\n" << endl;
							pause_();
							system("CLS");
							res::Empinfo copy = emp[i];
							emp_on_shift[StaffAdd] = copy;
							emp_on_shift[i].setStimeEtime(Stime, Etime);
							StaffAdd++;
						}
					}
					else
					{
						i = MAX_STAFF;
					}
				}
		}
	}
	//---------------------------------------------------------------------
	//---------------------------------------------------------------------
	void InsertMorningTips(double* Morningtips)
	{
		int M_startTime = 11;
		for (int i = 0; i < 6; i++)
		{
			do
			{
				cout << "--------------------\n"
					<< "     Restaurant     \n"
					<< "       Mornig       \n"
					<< "   Tip Inserting    \n"
					<< "--------------------" << endl;
				cout << " " << M_startTime << " - " << M_startTime + 1 << " Tips($) : ";
				cin >> Morningtips[i];
				clearKeyboard();
				if (Morningtips[i] < 0)
				{
					system("CLS");
					cout << "**** Entered Tip amount is wrong, please enter again ****\n";
				}
				else { system("CLS"); }
				
			} while (Morningtips[i] < 0);
			M_startTime++;
		}
		pause_();
		system("CLS");
	}
	void InsertNightTips(double* Nighttips)
	{
		int N_startTime = 17;

		for (int i = 0; i < 6; i++)
		{
			do
			{
				cout << "--------------------\n"
					<< "     Restaurant     \n"
					<< "       Night        \n"
					<< "   Tip Inserting    \n"
					<< "--------------------" << endl;
				cout << " " << N_startTime << " - " << N_startTime + 1 << " Tips($) : ";
				cin >> Nighttips[i];
				clearKeyboard();
				if (Nighttips[i] < 0)
				{

					system("CLS");
					cout << "**** Entered Tip amount is wrong, please enter again ****\n";
				}
				else { system("CLS"); }
			} while (Nighttips[i] < 0);
			N_startTime++;
			system("CLS");
		}
	}
	void intro()
	{
		cout << "--------------------\n"
			<< "     Restaurant     \n"
			<< "         Tip        \n"
			<< "    Rating System   \n"
			<< "--------------------" << endl;
		cout<< " 1. Add staff on the shift\n"
			<< " 2. Tip Inserting\n"
			<< " 3. Display Tips\n"
			<< " 4. Display all the staffs\n"
			<< " 5. Display Time schedule\n"
			<< " 0. exit\n"
			<< " Enter the option : ";
	}
	void displayTips(const double* morning, const double* night, const res::Empinfo* emp, int NumOfStaff)
	{
		int option;
		double Mtotal = 0.0;
		double Ntotal = 0.0;
		cout << "--------------------\n"
			<< "     Restaurant      \n"
			<< "        Tips         \n"
			<< "       Display       \n"
			<< "--------------------" << endl;
		cout << "1.Display Morning Shift tips\n"
			<< "2.Display Night Shift Tips\n"
			<< "Enter the Option : ";
		option = getNumber(1, 2);
		if (morning[0] < 0 || night[0] < 0)
		{
			cout << "\n                 *****Error*****                \n" 
			     << "   Tips have not added yet. Please add tips first.\n" 
				 << endl;
		}
		else
		{
			if (option == 1)
			{
				int mornigStart = 11;
				for (int i = 0; i < 6; i++)
				{
					cout << mornigStart << " - " << mornigStart+1 << " : " << morning[i] << "$" << endl;
					mornigStart++;
					Mtotal += morning[i];
				}
				cout << "\nTotal Morning Tips Amount : " << Mtotal << "$\n" << endl;
				for (int i = 0; i < NumOfStaff; i++)
				{
					if (!emp[i].isEmpty())
					{
						if (emp[i].getEtime() <= 17)
						{
							cout << emp[i].getName() << " : " << emp[i].getTotalTip() << "$\n" << endl;
						}
					}
					else
					{
						i = NumOfStaff;
					}
				}
			}
			else if (option == 2)
			{
				int nightStart = 17;
				for (int i = 0; i < 6; i++)
				{
					cout << nightStart << " - " << nightStart + 1 << " : " << night[i] << "$" << endl;
					nightStart++;
					Ntotal += night[i];
				}
				cout << "\nTotal Night Tips Amount : " << Ntotal << "$\n" << endl;
				for (int i = 0; i < NumOfStaff; i++)
				{
					if (!emp[i].isEmpty())
					{
						if (emp[i].getStime() >= 17)
						{
							cout << emp[i].getName() << " : " << emp[i].getTotalTip() << "$\n" << endl;
						}
					}
					else
					{
						i = NumOfStaff;
					}
				}
			}
		}		
	}
	int getNumber(int min, int max)
	{
		int Number;
		do
		{
			std::cin >> Number;
			clearKeyboard();
			if (Number < min || Number > max)
			{
				cout << "*****Warning******\n"
					<< "Please enter the number within in range ( " << min  << " and " << max << " ) : ";
			}
		} while (Number < min || Number > max);
		return Number;
	}
	void TimeSchedule(const res::Empinfo* emp, int NumOfStaff)
	{
		cout<<"----------------------\n"
			<< "     Time Schedule   \n"
			<< "                     \n"
			<< "        Diplay       \n"
			<< "----------------------" << endl;
		int option = 0 ;
		cout << "1.Morning Schedule\n"
			<< "2.Night Schedule\n"
			<< " Enter the option : ";
		option = getNumber(1, 2);
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "----------------------\n"
				 << "    Morning Schedule   \n"
				 << "                       \n"
				 << "        Diplay         \n"
				 << "-----------------------\n" << endl;
			cout << "    Name    | Time shift\n";
			for (int i = 0; i < NumOfStaff; i++)
			{
				if (!emp[i].isEmpty())
				{
					if (emp[i].getStime() >= 11 && emp[i].getEtime() <= 17)
					{
						cout << "-----------------------------------------------\n"
							<< " " << setw(11) << left << emp[i].getName() << "|"
							<< " " << emp[i].getStime() << " - " << emp[i].getEtime() << endl;
						cout << endl;
					}
				}else{	i = NumOfStaff; }
			}
			cout << "-----------------------------------------------" << endl;
			function::pause_();
			system("CLS");
			break;
		case 2:
			system("CLS");
			cout << "----------------------\n"
				<< "     Night Schedule    \n"
				<< "                       \n"
				<< "        Diplay         \n"
				<< "-----------------------\n" << endl;
			cout << "    Name    | Time shift\n";
			for (int i = 0; i < NumOfStaff; i++)
			{
				if (!emp[i].isEmpty() )
				{
					if (emp[i].getStime() >= 17)
					{
						cout << "-----------------------------------------------\n"
							<< " " << setw(11) << left << emp[i].getName() << "|"
							<< " " << emp[i].getStime() << " - " << emp[i].getEtime() << endl;
						cout << endl;
					}
				} else { i = NumOfStaff; }
			}
			cout << "-----------------------------------------------" << endl;
			function::pause_();
			system("CLS");
			break;
		default:
			break;
		}

	}
	//---------------------------------------------------------------------
	void addTips( res::Empinfo* emp, double* morning, double* night)
	{
		int Mshift[6][MAX_STAFF] = { 0 };
		int Nshift[6][MAX_STAFF] = { 0 };
		double MTiprateSum[6] = { 0 };
		double NTiprateSum[6] = { 0 };
		//-----------------------------------------------------------------
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < MAX_STAFF; j++)
			{
				if (!emp[j].isEmpty())
				{
					if (emp[j].getEtime() <= 17)
					{
						if (emp[j].getStime() <= i + 12 && emp[j].getEtime() >= i + 12)
						{
							Mshift[i][j] = emp[j].getSnumber();
							MTiprateSum[i] += emp[j].getTiprating();
						}
					}
					else if (emp[j].getStime() >= 17)
					{
						if (emp[j].getStime() <= i + 17 && emp[j].getEtime() >= i + 17)
						{
							Nshift[i][j] = emp[j].getSnumber();
							NTiprateSum[i] += emp[j].getTiprating();
						}
					}
				}
				else { j = MAX_STAFF; }
			}
		}
		//-----------------------------------------------------------------
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < MAX_STAFF; j++)
			{
				for (int k = 0; k < MAX_STAFF; k++)
				{
					if (Mshift[i][j] == emp[k].getSnumber() )
					{
						emp[k].addTotalTip((morning[i]/MTiprateSum[i])*emp[k].getTiprating());
						k = MAX_STAFF;
					}
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < MAX_STAFF; j++)
			{
				for (int k = 0; k < MAX_STAFF; k++)
				{
					if (Nshift[i][j] == emp[k].getSnumber())
					{
						emp[k].addTotalTip((night[i] / NTiprateSum[i]) * emp[k].getTiprating());
						k = MAX_STAFF;
					}
				}
			}
		}
		//-----------------------------------------------------------------
	}
}