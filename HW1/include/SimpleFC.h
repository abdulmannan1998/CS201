#ifndef SIMPLE_FC_H
#define SIMPLE_FC_H

#include <string>
using namespace std;
#include <iostream>
#include "SimpleFilm.h"

class FC
{
    public:
        FC();
        FC(const FC &fcToCopy);
        ~FC();
        void operator=(const FC &right);
        bool addFilm(const string fTitle, const string fDirector,
                     const unsigned int fYear,
                     const unsigned int fDuration);
        bool removeFilm(const string fTitle, const string fDirector);
        unsigned int getFilms(Film *&allFilms) const;

    private:
        Film *films;
        unsigned int noOfFilms;
        unsigned int size;
};

#endif // SIMPLE_FC_H
