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
    //đây là vector lưu trữ các thể loại nhạc đáng nhẽ nó phải lưu phần tử
    //dưới dạng SongGenre thì thằng bỏ mẹ nào đáy lại ép kiểu string nạp vào
    //trong vector này đoạn add_gender()
    vector<SongGenre> SongGenres;
    //Với mỗi phần tử kiểu SongGrenres này thì lại chứa một vector khác có phần tử 
    //là tất cả bài hát có trong loại nhạc đó (mở File SongGenre.h sẽ thấy)
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