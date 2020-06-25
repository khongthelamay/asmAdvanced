#include "../include/ControlSystem.h"

#include <iostream>
#include <string>

using namespace std;

//lấy ra đối tượng duy nhất đã được hoặc chưa được tạo của class MusicStore
//Đối tượng duy nhất này chính là store trong MusicStore
ControlSystem::ControlSystem()
{
    controlSys = MusicStore::getStore();
}
//gọi tới hàm addSong của class MusicStore
//Ở đây à biến controlSys gọi hàm n thực chất là biến store trong MusicStore
//gọi ra các method của nó mà thôi
void ControlSystem::addSong(const string &name, const string &genre)
{
    controlSys->addSong(name,genre);
}
//gọi tới hàm findSong của class MusicStore
void ControlSystem::findSong(const string &name, const string &genre)
{
    controlSys->findSong(name,genre);
}
//gọi tới hàm deleteSong của class MusicStore
void ControlSystem::deleteSong(const string &name)
{
    controlSys->deleteSong(name);
}
//gọi tới hàm add_genre của class MusicStore
void ControlSystem::add_genre(const string &name)
{
    controlSys->add_gender(name);
}
//gọi tới hàm show_song của class MusicStore
void ControlSystem::show_song()const
{
    controlSys->show_song();
}
