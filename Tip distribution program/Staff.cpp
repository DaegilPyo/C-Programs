#ifndef STAFF_RES_H
#define STAFF_RES_H

#include"Staff.h"
namespace res
{
	//----------------------------------------------
	Empinfo::Empinfo()
	{
		delete[] m_name;
		m_name = nullptr;
		m_StaffNum = 0;
		m_age = 0;
		m_sex = '\0';
		m_TipRatings = 0.0;
		m_StartTime = 0;
		m_EndTime = 0;
		m_TotalTips = 0.0;
	}
	Empinfo::Empinfo(const char* name, int sNum, int age, char sex, double tiprating, int Stime, int Etime)
	{
		if (name != nullptr && name[0] != '\0' && age != 0 && sex != '\0' && tiprating != 0.0)
		{
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_StaffNum = sNum;
			m_sex = sex;
			m_age = age;
			m_TipRatings = tiprating;
			m_StartTime = Stime;
			m_EndTime = Etime;
			m_TotalTips = 0.0;
		}
		else
		{
			delete[] m_name;
			m_name = nullptr;
			m_StaffNum = 0;
			m_age = 0;
			m_sex = '\0';
			m_TipRatings = 0.0;
			m_StartTime = 0;
			m_EndTime = 0;
			m_TotalTips = 0.0;
		}
	}
	Empinfo::~Empinfo()
	{
		delete[] m_name;
	}
	//----------------------------------------------//Display operator.
	std::ostream& Empinfo::display(std::ostream& os) const
	{
		if (m_name != nullptr)
		{
			os << "-- Name : " << m_name << " | Staff Number : " << m_StaffNum << " --" << std::endl
				<< "     Age : " << m_age << " | Sex : " << m_sex << std::endl
				<< "       Tip Rationg : " << m_TipRatings << std::endl
				<< "---------------------------\n";
		}
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Empinfo& emp)
	{
		emp.display(os);
		return os;
	}
	//----------------------------------------------
	Empinfo::Empinfo(const Empinfo& copy)
	{
		if (copy.m_name != nullptr && copy.m_name[0] != '\0' && copy.m_age != 0 && copy.m_sex != '\0' && copy.m_TipRatings != 0.0)
		{
			m_name = new char[strlen(copy.m_name) + 1];
			strcpy(m_name, copy.m_name);
			m_StaffNum = copy.m_StaffNum;
			m_age = copy.m_age;
			m_sex = copy.m_sex;
			m_TipRatings = copy.m_TipRatings;
			m_StartTime = copy.m_StartTime;
			m_EndTime = copy.m_EndTime;
			m_TotalTips = copy.m_TotalTips;
		}
		else
		{
			delete[] m_name;
			m_name = nullptr;
			m_StaffNum = 0;
			m_age = 0;
			m_sex = '\0';
			m_TipRatings = 0.0;
			m_StartTime = 0;
			m_EndTime = 0;
			m_TotalTips = 0.0;
		}
	}
	Empinfo Empinfo::operator=(const Empinfo& copy)
	{
		if (copy.m_name != nullptr && copy.m_name[0] != '\0' && copy.m_age != 0 && copy.m_sex != '\0' && copy.m_TipRatings != 0.0)
		{
			m_name = new char[strlen(copy.m_name) + 1];
			strcpy(m_name, copy.m_name);
			m_StaffNum = copy.m_StaffNum;
			m_age = copy.m_age;
			m_sex = copy.m_sex;
			m_TipRatings = copy.m_TipRatings;
			m_StartTime = copy.m_StartTime;
			m_EndTime = copy.m_EndTime;
			m_TotalTips = copy.m_TotalTips;
		}
		else
		{
			delete[] m_name;
			m_name = nullptr;
			m_StaffNum = 0;
			m_age = 0;
			m_sex = '\0';
			m_TipRatings = 0.0;
			m_StartTime = 0;
			m_EndTime = 0;
			m_TotalTips = 0.0;
		}
		return *this;
	}
	//----------------------------------------------
	bool Empinfo::isEmpty() const
	{
		bool result = true;
		if (m_name != nullptr) { result = false; }
		return result;
	}
	char* Empinfo::getName() const
	{
		return m_name;
	}
	double Empinfo::getTiprating() const
	{
		return m_TipRatings;
	}
	int Empinfo::getStime() const
	{
		return m_StartTime;
	}
	int Empinfo::getEtime() const
	{
		return m_EndTime;
	}
	int Empinfo::getSnumber() const
	{
		return m_StaffNum;
	}
	void Empinfo::addTotalTip(double tips)
	{
		m_TotalTips += tips;
	}
	void Empinfo::setStimeEtime(int Stime, int Etime)
	{
		m_StartTime = Stime;
		m_EndTime = Etime;
	}
	double Empinfo::getTotalTip() const
	{
		return m_TotalTips;
	}
	//----------------------------------------------
}
#endif // !STAFF_RES_H
