#include "../include/Song.h"

#include <iostream>
#include <string>

using namespace std;

Song::Song()
{
    name = "";
}

Song::Song(const string &name)
{
    this->name = name;
}

string Song::get_name() const{
    return name;
}