#include "FC.h"

#include <string>
using namespace std;
#include <iostream>

FC::FC()
{
    noOfFilms = 0;
    size = 0;
    films = NULL;
}

FC::FC(const FC &fcToCopy)
: size(fcToCopy.size), noOfFilms(fcToCopy.noOfFilms)
{
    if( size > 0)
    {
        films = new Film[size];
        for( int i = 0; i < size; i++)
        {
            films[i] = fcToCopy.films[i];
        }
    }
    else
        films = NULL;
}

FC::~FC()
{
    if(films)
        delete [] films;
}

void FC::operator=(const FC &right)
{
    if( &right != this)
    {
        if( size != right.size)
        {
            if( size > 0)
                delete [] films;
            size = right.size;
            if( size > 0)
                films = new Film[size];
            else
                films = NULL;
        }
        for (int i = 0; i < size; i++)
            films[i] = right.films[i];
        noOfFilms = right.noOfFilms;
    }
}

bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
    for( int i = 0; i < size; i++)
    {
        if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
            return false;
    }
    Film newFilm(fTitle, fDirector, fYear, fDuration);
    Film *tempFilms = new Film[size + 1];
    for(int i = 0; i < size; i++)
    {
        tempFilms[i] = films[i];
    }
    delete [] films;
    tempFilms[size] = newFilm;
    films = tempFilms;
    tempFilms = NULL;
    delete [] tempFilms;
    size++;
    noOfFilms++;
    return true;
}

bool FC::removeFilm(const string fTitle, const string fDirector)
{
    int index = -1;
    for( int i = 0; i < size; i++)
    {
        if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
            index = i;
    }
    if( index == -1)
        return false;
    else
    {
        Film *tempFilms = new Film[size - 1];
        int x = 0;
        for(int i = 0; i < size - 1; i++)
        {
            if( x == index)
            {
                films[x].removeActors();
                x++;
            }
            tempFilms[i] = films[x];
            x++;
        }
        delete [] films;
        films = tempFilms;
        tempFilms = NULL;
        delete [] tempFilms;
        size--;
        noOfFilms--;
        return true;
    }
}

bool FC::addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace, const unsigned int aBirthYear)
{
    for(int i = 0; i < size; i++)
    {
        if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
        {
            if(films[i].addActor(aName, aBirthPlace, aBirthYear))
                return true;
        }
    }
    return false;
}

bool FC::removeActors(const string fTitle, const string fDirector)
{
    for(int i = 0; i < size; i++)
    {
        if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
        {
            films[i].removeActors();
            return true;
        }
    }
    return false;
}

unsigned int FC::calculateAverageDuration() const
{
    if(noOfFilms == 0)
        return 0;
    int totalDuration = 0;
    for( int i = 0; i < size; i++)
    {
        totalDuration += films[i].getFilmDuration();
    }
    return (totalDuration / noOfFilms);
}

unsigned int FC::getFilms(Film *&allFilms) const
{
    allFilms = new Film[size];
    for( int i = 0; i < size; i++)
    {
        allFilms[i] = films[i];
    }
    return noOfFilms;
}
