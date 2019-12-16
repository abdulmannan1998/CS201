#include "Actor.h"

#include <string>
using namespace std;
#include <iostream>

Actor::Actor(const string aName, const string aBirthPlace, const unsigned int aBirthYear)
: name(aName), birthPlace(aBirthPlace), birthYear(aBirthYear)
{
}

Actor::Actor(const Actor& actorToCopy)
: name(actorToCopy.getName()), birthPlace(actorToCopy.getBirthPlace()), birthYear(actorToCopy.getBirthYear())
{
}

Actor::~Actor()
{
}

void Actor::operator=(const Actor& right)
{
    if(&right != this)
    {
        name = right.getName();
        birthPlace = right.getBirthPlace();
        birthYear = right.getBirthYear();
    }
}

string Actor::getName() const
{
    return name;
}

string Actor::getBirthPlace() const
{
    return birthPlace;
}

unsigned int Actor::getBirthYear() const
{
    return birthYear;
}

ostream& operator<<(ostream& out, const Actor& a)
{
    out << a.name << ", " << a.birthPlace << ", " << a.birthYear << endl;
    return out;
}
