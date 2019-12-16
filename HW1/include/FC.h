#ifndef FC_H
#define FC_H

#include "Film.h"
#include <string>
using namespace std;
#include <iostream>

class FC{
    public:
        FC();
        FC(const FC &fcToCopy);
        ~FC();
        void operator=(const FC &right);
        bool addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration);
        bool removeFilm(const string fTitle, const string fDirector);
        unsigned int getFilms(Film *&allFilms) const;
        bool addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace, const unsigned int aBirthYear);
        bool removeActors(const string fTitle, const string fDirector);
        unsigned int calculateAverageDuration() const;
    private:
        Film *films;
        unsigned int noOfFilms;
        unsigned int size;
};

#endif // FC_H
