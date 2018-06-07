/** 
 * @file Date3.h
 * A third version of Date.h
*/
#ifndef DATE3_H
#define DATE3_H
#include <string>
#include <stdexcept>
#include <iosfwd>

/**
 * @brief A struct for storing the elapsed time.
 */
struct Duration {
	/**
	 * @brief Integer containing amount of years, one of the fields of the Duration struct.
	 */
	int years;
	/**
	 * @brief Integer containing amount of months, one of the fields of the Duration struct.
	 */
	int months;
	/**
	 * @brief Integer containing amount of days, one of the fields of the Duration struct.
	 */
	int days;
    /**
     * @brief Constructor for initializing a duration variable
     *
     * Initializes a new duration variable with the values passed 
     * as parameters for year, months and days.
     *
     * @param y The amount of years as integer.
     * @param m The amount of months as integer.
     * @param d The amount of days as integer.
     */
	Duration(int y, int m, int d) : years(y), months(m), days(d) {}
};

/**
 * @brief A class for managing dates as composed of year, month and day.
 */
class Date {
	private:
		/**
		 * @brief Integer containing amount of years, one of the properties of the Date class.
	     */
	    int year;
	    /**
		 * @brief Integer containing amount of months, one of the properties of the Date class.
	     */
		int month;
		/**
		 * @brief Integer containing amount of days, one of the properties of the Date class.
	     */
		int day;
		/**
         * @brief Private method for comparing the caller date object with the 
         * one passed as parameter.
         * 
         * @param date A second date object sent to the method to compare it to the caller object.
         * 
         * @return Integer value which is 0, negative or positive if the caller 
         * date object and the one passed as parameter are equal, less or larger.
         */
		int compare(const Date &) const;
        /**
         * @brief Static private method which returns how many days the previous month has.
         * 
         * @param year Integer value corresponding to a year.
         * @param month Integer value corresponding to a month in a year.
         * 
         * @return Integer value representing the amount of days in the month previous to 
         * the one encoded by the two parameters.
         */
		static int daysInPrevMonth(int, int);
	public:
	    /**
		 * @brief An inner class of Date for generating errors regarding dates.
         */
		class DateError : public std::logic_error {
			public:
			    /**
				 * @brief Constructor of the DateError class which is derived from 
				 * logic_error.
				 * 
				 * This constructor calls the constructor of the parent class by 
				 * passing a string object to it.
				 * 
				 * @param msg A string object containing an error message. By default 
				 * this message is the empty string. 
				 */
				DateError(const std::string &msg = "") : std::logic_error(msg) {}
		};
		/**
         * @brief Constructor with no parameters.
         * 
         * Initializes the date object with the current local time of the system.
         */
		Date();
		/**
         * @brief Parametric constructor for creating a date object.
         * 
         * Initializes the date object according to the data passed as parameters.
         * 
         * @param year The amount of years as integer.
         * @param month The amount of months as integer.
         * @param day The amount of days as integer.
         * 
         * @throw DateError DateError is thrown if the parametric data is not a valid Date.
         */
		Date(int year, int month, int day) throw(DateError);
		/**
         * @brief Parametric constructor for creating a date object.
         * 
         * Initializes the date object according to the data passed as parameter.
         * 
         * @param string The string encoding a date. 
         * 
         * @throw DateError DateError is thrown if the parametric data is not a valid Date.
         */
		Date(const std::string&) throw(DateError);
		/**
         * @brief Getter for the attribute year.
         * 
         * @return An integer corresponding to the year.
         */
		int getYear() const;
		/**
         * @brief Getter for the attribute month.
         * 
         * @return An integer corresponding to the month.
         */
		int getMonth() const;
		/**
         * @brief Getter for the attribute day.
         * 
         * @return An integer corresponding to the day.
         */
		int getDay() const;
		/**
         * @brief Method returning the date as a string.
         * 
         * @return A string containing the date data.
         */
		std::string toString() const;
		/**
         * @brief Less operator for comparing two date objects.
         * 
         * Friend function for overloading the less operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is less than d2.
         */
		friend bool operator<(const Date&, const Date&);
		/**
         * @brief Greater operator for comparing two date objects.
         * 
         * Friend function for overloading the greater operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is greater than d2.
         */
		friend bool operator>(const Date&, const Date&);
		/**
         * @brief Less or equal operator for comparing two date objects.
         * 
         * Friend function for overloading the less or equal operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is less or equal than d2.
         */
		friend bool operator<=(const Date&, const Date&);
		/**
         * @brief Greater or equal operator for comparing two date objects.
         * 
         * Friend function for overloading the greater or equal operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is greater or equal than d2.
         */
		friend bool operator>=(const Date&, const Date&);
		/**
         * @brief Equal operator for comparing two date objects.
         * 
         * Friend function for overloading the equal operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is equal to d2.
         */
		friend bool operator==(const Date&, const Date&);
		/**
         * @brief Not equal operator for comparing two date objects.
         * 
         * Friend function for overloading the not equal operator for the Date class.
         * 
         * @param date1 Date object to be compared with the other date object.
         * @param date2 Date object to be compared with the other date object.
         * 
         * @return Boolean value depending if d1 is not equal to d2.
         */
		friend bool operator!=(const Date&, const Date&);
		/**
         * @brief Method for computing the duration between two date objects.
         * 
         * Friend function for computing and returning the duration between two 
         * date objects passed as parameters
         * 
         * @param date1 First date object.
         * @param date2 Second date object.
         * 
         * @return Another date object containing the difference in time between 
         * date1 and date2.
         */
		friend Duration duration(const Date&, const Date&);
};
#endif