#ifndef _MUSIC_STORE_H_
#define _MUSIC_STORE_H_

#include <iostream>
#include <string>
#include <vector>

#include "./SongGenre.h"

using namespace std;


class MusicStore
{
private:
    static MusicStore* store;
    vector<SongGenre> SongGenres;
public:
    MusicStore();
    static MusicStore* getStore();
    void addSong(const string &name, const string &genre);
    void findSong(const string &name, const string &genre);
    void deleteSong(const string &name); 
    void add_gender(const string &name);
    vector<SongGenre> get_song();
    void show_song() const;
};
#endif