#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>

#include "ControlSystem.h"

using namespace std;
#define ADD_GENRE 1
#define ADD_SONG 2
#define FIND_SONG 3
#define DELETE_SONG 4
#define SHOW_SONG 5
#define EXIT 6

class Menu
{
private:
    ControlSystem* ControlSys;
public:
    Menu();
public:
    void Run(); 
public:
    void printMenu() const;
    int getChoice() const;
    void doTask(const int &choice);
    void addSong();
    void addGenre();
    void findSong();
    void deleteSong();
    void showSong() const;
    void printMessage(const string &msg) const;   
};
#endif