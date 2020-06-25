#ifndef _SONG_H_
#define _SONG_H_

#include <iostream>
#include <string>

using namespace std;

class Song
{
private:
    string name;
public:
    Song();
    Song(const string &name); 
    string get_name() const;
};
#endif