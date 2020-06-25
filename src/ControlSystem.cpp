#include "../include/ControlSystem.h"

#include <iostream>
#include <string>

using namespace std;

ControlSystem::ControlSystem()
{
    controlSys = MusicStore::getStore();
}
void ControlSystem::addSong(const string &name, const string &genre)
{
    controlSys->addSong(name,genre);
}
void ControlSystem::findSong(const string &name, const string &genre)
{
    controlSys->findSong(name,genre);
}
void ControlSystem::deleteSong(const string &name)
{
    controlSys->deleteSong(name);
}
void ControlSystem::add_genre(const string &name)
{
    controlSys->add_gender(name);
}
void ControlSystem::show_song()const
{
    controlSys->show_song();
}
