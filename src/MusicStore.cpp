#include "../include/MusicStore.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

MusicStore* MusicStore::store = 0;

MusicStore::MusicStore()
{}
MusicStore* MusicStore:: getStore()
{
    if(store == 0)
    {
        store = new MusicStore();
    }
    return store;
}
void MusicStore::addSong(const string &name, const string &genre)
{
    for(int i =0; i < SongGenres.size();i++)
    {
        if(SongGenres[i].get_name() == genre)
        {
            SongGenres[i].addSong(name);
            cout << "Insert completed." << endl;
            cout << endl;
            return;
        }
    }
    SongGenres.push_back(genre);
    SongGenres[SongGenres.size()-1].addSong(name);
}
vector<SongGenre> MusicStore::get_song()
{
    return SongGenres;
}
void MusicStore::findSong(const string &name, const string &genre)
{
    cout << endl;
    cout << "------ RESULT SEARCHING -----" << endl;
    for(int i=0;i<SongGenres.size();i++)
    {
        if(SongGenres[i].get_name() == genre)
        {
            vector<Song> songs = SongGenres[i].get_song();
            for(int j = 0; j < songs.size(); j++)
            {
                if(songs[j].get_name() == name) {
                    cout << songs[j].get_name() << " || " << name;   
                }
            }

        }
    }
    cout << "Not found" << endl;
}
void MusicStore::deleteSong(const string &name)
{
    for(int i =0;i<SongGenres.size();i++)
    {
        if(SongGenres[i].findSong(name))
        {
            SongGenres[i].deleteSong(name);
        }
    }
    // cout << "Not found" << endl;
}
//
void MusicStore::show_song()const
{
    cout << "* --- LIST OF SONGS: --- *" << endl;
    for( int i = 0; i < SongGenres.size(); i++)
    {
        cout <<"- Genre: "<< SongGenres[i].get_name() << endl;
        vector<Song> songs = SongGenres[i].get_song();
        for(int j= 0; j < songs.size();j++)
        {
            cout << "     + " << songs[j].get_name() << endl;
        }
        //lam nao dung?
    }
}
void MusicStore::add_gender(const string &name)
{
    SongGenres.push_back(name);
}