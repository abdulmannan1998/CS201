#include "Film.h"

#include <string>
using namespace std;
#include <iostream>

Film::Film(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
: title(fTitle), director(fDirector), year(fYear), duration(fDuration)
{
    noOfActors = 0;
    size = 0;
    actors = NULL;
}

Film::Film(const Film &fToCopy)
: title(fToCopy.getFilmTitle()), director(fToCopy.getFilmDirector()), year(fToCopy.getFilmYear()), duration(fToCopy.getFilmDuration())
,noOfActors(fToCopy.noOfActors), size(fToCopy.size)
{
    if( size > 0)
    {
        actors = new Actor[size];
        for( int i = 0; i < size; i++)
        {
            actors[i] = fToCopy.actors[i];
        }
    }
    else
        actors = NULL;
}

Film::~Film()
{
    if(actors)
        delete [] actors;
}

void Film::operator=(const Film &right)
{
    if( &right != this)
    {
        if( size != right.size)
        {
            if( size > 0)
                delete [] actors;
            size = right.size;
            if( size > 0)
                actors = new Actor[size];
            else
                actors = NULL;
        }
        for (int i = 0; i < size; i++)
            actors[i] = right.actors[i];
        title = right.getFilmTitle();
        director = right.getFilmDirector();
        year = right.getFilmYear();
        duration = right.getFilmDuration();
        noOfActors = right.noOfActors;
    }
}

string Film::getFilmTitle() const
{
    return title;
}

string Film::getFilmDirector() const
{
    return director;
}

unsigned int Film::getFilmYear() const
{
    return year;
}

unsigned int Film::getFilmDuration() const
{
    return duration;
}

bool Film::addActor(const string aName, const string aBirthPlace, const unsigned int aBirthYear)
{
    for(int i = 0; i < size; i++)
    {
        if(actors[i].getName() == aName && actors[i].getBirthPlace() == aBirthPlace && actors[i].getBirthYear() == aBirthYear)
            return false;
    }
    Actor *tempActors = new Actor[size + 1];
    for(int i = 0; i < size; i++)
    {
        tempActors[i] = actors[i];
    }
    delete [] actors;
    Actor newActor(aName, aBirthPlace, aBirthYear);
    tempActors[size] = newActor;
    actors = tempActors;
    tempActors = NULL;
    delete [] tempActors;
    size++;
    noOfActors++;
    return true;
}

void Film::removeActors()
{
    delete [] actors;
    actors = NULL;
    size = 0;
    noOfActors = 0;
}

unsigned int Film::calculateAverageActorAge() const
{
    if(noOfActors == 0)
        return 0;
    int totalAge = 0;
    for(int i = 0; i < size; i++)
    {
        totalAge += (year - actors[i].getBirthYear());
    }
    return (totalAge / noOfActors);
}

ostream& operator<<(ostream& out,const Film& f)
{
    out << f.title << ", " << f.director << ", " << f.year << ", " << f.duration << " min" << endl;
    for(int i = 0; i < f.size; i++)
    {
        out << "\t" << f.actors[i];
    }
    return out;
}
