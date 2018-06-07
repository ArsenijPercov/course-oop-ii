/** 
 * @file Date3.cpp
 * Implementation of the Date methods.
*/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include "Date3.h"
using namespace std;

namespace {
	const int daysInMonth[][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	inline bool isleap(int y) {
		return (((y%4 == 0) && (y%100 != 0)) || (y%400 == 0));
	}
}

Date::Date() {
	// Get current date
	time_t tval= time(NULL);
	struct tm *now = localtime(&tval);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
}

Date::Date(int year, int month, int day) throw(Date::DateError) {
	if (!((1 <= month) && (month <= 12)))
		throw DateError("Bad month n Date");
	if (!((1 <= day) && (day <= daysInMonth[isleap(year)][month])))
		throw DateError("Bad day in Date");
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const string& s) throw(Date::DateError) {
	// Assume YYYYMMDD format
	if (!(s.size()==8))
		throw DateError("Bad string in Date");
	for(int n = 8; --n >= 0;)
		if (!isdigit(s[n]))
			throw DateError("Bad string in Date");
	string buf = s.substr(0, 4);
	year = atoi(buf.c_str());
	buf = s.substr(4, 2);
	month = atoi(buf.c_str());
	buf = s.substr(6, 2);
	day = atoi(buf.c_str());
	if (!((1 <= month) && (month <= 12)))
		throw DateError("Bad month in Date");
	if (!((1 <= day) && (day <= daysInMonth[isleap(year)][month])))
		throw DateError("Bad day in Date");
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const{
	return day;
}

string Date::toString() const {
	ostringstream os;
	os.fill('0');
	os << setw(4) << year << setw(2) << month << setw(2) << day;
	return os.str();
}

int Date::compare(const Date & date) const {
	int result = year -date.year;
	if (result==0) {
		result = month - date.month;
		if (result==0) {
			result = day - date.day;
		}
	}
	return result;
}

bool operator<(const Date& date1, const Date& date2) {
	return date1.compare(date2) < 0;
}

bool operator<=(const Date& date1, const Date& date2) {
	return date1 < date2 || date1 == date2;
}

bool operator>(const Date& date1, const Date& date2) {
	return !(date1<date2) && !(date1==date2);
}

bool operator>=(const Date& date1, const Date& date2) {
	return !(date1<date2);
}

bool operator==(const Date& date1, const Date& date2) {
	return date1.compare(date2) == 0;
}

bool operator!=(const Date& date1, const Date& date2) {
	return !(date1==date2);
}

int Date::daysInPrevMonth(int year, int month) {
	if (month == 1) {
		--year;
		month=12;
	}
	else
		--month;
	return daysInMonth[isleap(year)][month];
}

Duration duration(const Date& date1, const Date& date2) {
	int y1 = date1.year;
	int y2 = date2.year;
	int m1 = date1.month;
	int m2 = date2.month;
	int d1 = date1.day;
	int d2 = date2.day;
	
	// Compute and compare
	int order = date1.compare(date2);
	if (order == 0)
		return Duration(0, 0, 0);
	else if (order > 0) {
		// Make date1 precede date2 locally
		swap(y1, y2);
		swap(m1, m2);
		swap(d1, d2);
	}
	int years = y2 - y1;
	int months = m2 - m1;
	int days = d2 - d1;
	assert(((years > 0) || ((years == 0) && (months > 0)) || ((years == 0) && (months == 0) && (days > 0))));
	// adjust days before months
	int lastMonth = m2;
	int lastYear = y2;
	while (days < 0) {
		// Borrow from month
		assert(days < 0);
		days += Date::daysInPrevMonth(lastYear, lastMonth--);
		--months;
	}
	if (months < 0) {
		// Borrow from year
		assert(years > 0);
		months += 12;
		--years;
	}
	return Duration(years, months, days);
}
