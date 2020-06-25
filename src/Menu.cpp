#include "../include/Menu.h"

#include <iostream>

using namespace std;
// Nếu như đã hiểu file ControlSystem thì qua bên này cũng như vậy thôi
Menu::Menu()
{
    ControlSys = new ControlSystem();
}
void Menu::Run()
{
    
    int choice = 0;
    while (choice != 6){

         printMenu();
         choice = getChoice();
         doTask(choice);
    }
}
void Menu::printMenu() const
{
   
    cout << "\n\n";
    cout <<                 "||========== SONG MANAGEMENT ============||" << endl;
    cout << ADD_GENRE <<   "||========== (1) Add Genre   ============||" << endl;
    cout << ADD_SONG <<    "||========== (2) Add Song    ============||" << endl;
    cout << FIND_SONG <<   "||========== (3) Find Song   ============||" << endl;
    cout << DELETE_SONG << "||========== (4) Delete Song ============||" << endl;
    cout << SHOW_SONG <<   "||========== (5) Show Song   ============||" << endl;
    cout << EXIT <<        "||========== (6) EXIT        ============||" << endl;
    
   
   
}
int Menu::getChoice() const
{
    int choice;
    cout << "Please Enter Your choice:",
        cin >> choice;
    return choice;
}
void Menu::doTask(const int &choice)
{
    switch (choice)
    {
    case ADD_SONG:
        addSong();
        break;
    case ADD_GENRE:
        addGenre();
        break;
    case FIND_SONG:
        findSong();
        break;
    case DELETE_SONG:
        deleteSong();
        break;
    case SHOW_SONG:
        showSong();
        break;
    case EXIT:
        printMessage("You have already EXIT!");
        break;
    default:
        printMessage("Invalid choice!");
        break;
    }
}
void Menu::addSong()
{
    string name,genre;
    cout << "Song's genre: ";
    cin >> genre;
    cout << "Song's name: ";
    cin >> name;
    ControlSys ->addSong(name,genre);
}

void Menu::findSong()
{
    cout << "|| ======= FIND THE SONG ======= ||" << endl;
    string name, genre;
    cout << "Name of song: ";
    cin >> name;
    cout << "Genre of song: ";
    cin >> genre;
    ControlSys->findSong(name, genre);
}

void Menu::showSong() const
{
    ControlSys->show_song();
}
void Menu::deleteSong() 
{
    ControlSys->show_song();
    string song_name;
    cout<<"Please enter your song's name:"<<endl;
    cin >> song_name;
    ControlSys->deleteSong(song_name);
}
void Menu::printMessage(const string &msg) const
{
    cout << msg << endl;
}
void Menu::addGenre()
{
    string genre;
    cout << "Enter genre: ";
    cin >> genre;
    ControlSys->add_genre(genre);
}