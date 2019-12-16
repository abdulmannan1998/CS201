#ifndef FILM_H
#define FILM_H

#include "Actor.h"
#include <string>
using namespace std;
#include <iostream>

class Film{
    public:
        Film(const string fTitle = "", const string fDirector = "", const unsigned int fYear = 0, const unsigned int fDuration = 0);
        Film(const Film &fToCopy);
        ~Film();
        void operator=(const Film &right);
        string getFilmTitle() const;
        string getFilmDirector() const;
        unsigned int getFilmYear() const;
        unsigned int getFilmDuration() const;
        bool addActor(const string aName = "", const string aBirthPlace = "", const unsigned int aBirthYear = 0);
        void removeActors();
        unsigned int calculateAverageActorAge() const;
        friend ostream& operator<<(ostream& out, const Film& f);
    private:
        string title;
        string director;
        unsigned int year;
        unsigned int duration;
        Actor *actors;
        unsigned int noOfActors;
        unsigned int size;
};

#endif // FILM_H
