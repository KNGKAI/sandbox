#include "system.h"

void message(string text) { cout << text << endl; }

void errorMessage(string text) { message("error: " + text); }