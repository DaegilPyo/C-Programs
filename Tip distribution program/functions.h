#ifndef FUNCTION_H
#define FUNCTION_H
#include"Staff.h"
#define MAX_STAFF 20
namespace function
{
	//---------------------------------------------------------------
	void intro();
	void AddStaff(const res::Empinfo*, res::Empinfo*, int Staff);
	bool Yes_Or_No();
	void clearKeyboard(void);
	void pause_();
	void InsertMorningTips(double*);
	void InsertNightTips(double*);
	void TimeSchedule(const res::Empinfo*, int);
	void displayTips(const double*, const double*, const res::Empinfo*, int);
	int getNumber(int, int);
	void addTips(res::Empinfo*, double*, double*);
}
#endif // !FUNCTION_H


