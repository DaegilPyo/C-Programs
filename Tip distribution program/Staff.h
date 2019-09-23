#ifndef RES_EMPINFO_H
#define RES_EMPINFO_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include <iomanip>
namespace res
{
	class Empinfo
	{
		char *m_name = nullptr;
		int m_StaffNum;
		int m_age;
		char m_sex;
		double m_TipRatings; 
		int m_StartTime;
		int m_EndTime;
		double m_TotalTips;
	public:
		Empinfo();
		Empinfo(const char*,int,int,char,double, int, int);
		~Empinfo();
		//----------------------------------------------
		bool isEmpty() const;
		std::ostream& display(std::ostream&) const;
		Empinfo(const Empinfo&);//copy constructor.
		Empinfo operator=(const Empinfo&);
		double getTiprating() const;
		int getStime() const;
		int getEtime() const;
		int getSnumber() const;
		char* getName() const;
		void addTotalTip(double);
		void setStimeEtime(int,int);
		double getTotalTip() const;
	};
	std::ostream& operator<<(std::ostream& os, const Empinfo& emp);
}
#endif // !RES_EMPINFO_H
