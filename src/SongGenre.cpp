#include "../include/SongGenre.h"

#include <iostream>
#include <string>

using namespace std;

//Lấy tên của thể loại nhạc
SongGenre::SongGenre(const string &name)
{
    this->name = name;
}
//thêm bài hát vào trong vector Songs
void SongGenre::addSong(const string &name)
{
    Songs.push_back(Song(name));
}
// Những phần code dưới này tương tự như việc thêm loại
// nhạc trong File MusicStore


bool SongGenre::findSong(const string &name)
{
    for(int i = 0; i < Songs.size(); i++)
    {
        if(Songs[i].get_name() == name) {
            return true;
        }
    }
    return false;
}
void SongGenre::deleteSong(const string &name)
{
    for(int i = 0; i < Songs.size(); i++)
    {
        if(Songs[i].get_name() == name) {
            Songs.erase(Songs.begin() + i);
            cout << "Deleted" <<endl;
            return;
        }
    }
    cout << "Not founded song";
}

string SongGenre::get_name() const
{
    return name;
}
vector<Song> SongGenre::get_song() const
{
    return Songs;
}