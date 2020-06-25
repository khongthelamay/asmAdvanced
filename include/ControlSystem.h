#ifndef _CONTROL_SYSTEM_H_
#define _CONTROL_SYSTEM_H_

#include "MusicStore.h"
#include "Song.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ControlSystem
{
private:
    MusicStore* controlSys;
public:
    ControlSystem();
    void addSong(const string &name, const string &genre);
    void findSong(const string &name, const string &genre);
    void deleteSong(const string &name);
    void add_genre(const string &name);
    void show_song() const;
};
#endif