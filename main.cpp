// Programmer: Sophia Bhoria
// Date: Nov 13, 2024
// Purpose: Demonstrates the `Time` class functionality by creating, adding, copying, and comparing `Time` objects with formatted output.

#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Default constructor
    // Description: Initializes the time to (0, 0, 0).
    // Precondition: None.
    // Postcondition: hours, minutes, and seconds are set to 0.
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    // Description: Initializes the time with given hours, minutes, and seconds.
    //              If minutes or seconds are out of range, they are set to 0.
    // Precondition: None.
    // Postcondition: Time object is initialized with validated hours, minutes, seconds.
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (minutes < 0 || minutes > 59) minutes = 0;
        if (seconds < 0 || seconds > 59) seconds = 0;
    }

    // Copy constructor
    // Description: Creates a copy of an existing Time object.
    // Precondition: None.
    // Postcondition: New Time object is initialized as a copy of another.
    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

    // Operator+ Overload
    // Description: Adds two Time objects and normalizes the result.
    // Precondition: None.
    // Postcondition: Returns a new Time object with the sum of two times, normalized.
    Time operator+ (const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes + result.seconds / 60;
        result.seconds %= 60;
        result.hours = hours + other.hours + result.minutes / 60;
        result.minutes %= 60;
        return result;
    }

    // isEqual function
    // Description: Checks if two Time objects have the same hours, minutes, and seconds.
    // Precondition: None.
    // Postcondition: Returns true if both Time objects are equal, otherwise false.
    bool isEqual(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    // Overloaded << Operator
    // Description: Prints the time in hours:minutes:seconds format.
    // Precondition: None.
    // Postcondition: Outputs the time to the stream in specified format.
    friend ostream &operator<<(ostream &output, const Time& t) {
        output << t.hours << ":" << (t.minutes < 10 ? "0" : "") << t.minutes << ":" 
               << (t.seconds < 10 ? "0" : "") << t.seconds;
        return output;
    }
};

int main() {
    // Create two Time objects
    Time t1(10, 45, 30), t2(2, 20, 50);

    // Print the values of the two objects
    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;

    // Add the two Time objects and print the sum
    Time sum = t1 + t2;
    cout << "Sum of Time 1 and Time 2: " << sum << endl;

    // Check if t1 is equal to t2
    cout << (t1.isEqual(t2) ? "Time 1 is equal to Time 2" : "Time 1 is not equal to Time 2") << endl;

    // Create a copy of t1 and print the copied object
    Time t1Copy = t1;
    cout << "Copy of Time 1: " << t1Copy << endl;

    return 0;
}
