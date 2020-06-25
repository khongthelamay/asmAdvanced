#ifndef _SONG_GENRE_H_
#define _SONG_GENRE_H_

#include "Song.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SongGenre
{
private:
    string name;
    //đây chính là cái vector chứa tất cả bài hát của loại nhạc nào đấy mà t đã nhắc tới trước đó
    vector<Song> Songs;
public:
    SongGenre(const string &name);
    void addSong(const string &name);
    bool findSong(const string &name);
    void deleteSong(const string &name);
    string get_name() const;
    vector<Song> get_song() const;
};
#endif