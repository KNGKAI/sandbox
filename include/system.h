#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include "list.h"
#include "filesystem.h"

using namespace std;

void message(string text) { cout << text << endl; }

void errorMessage(string text) { message("error: " + text); }

#endif