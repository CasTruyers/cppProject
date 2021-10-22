#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum teachers
{
    Bart,
    Valerie,
    Sarah,
    Joost,
    Frederik
}

enum degrees
{
    Math,
    Science,
    Biology,
    Electronics
}

class classroom
{
public:
    char year;
    teachers teacher;
    degrees degree;

    classroom(char Year, teachers Teacher, degrees Degree)
    {
        year = Year;
        teacher = Teacher;
        degree = Degree;
    }
    //addstudent
}

int
main()
{

    return 0;
}