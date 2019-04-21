#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <limits>
//#include "AuthService.h"
#include "Role.h"
//const int NotUsed = system("color F0");
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif

class Menu {
public:
	static int registration();
	static Role autorization();
	static int menuUser();
	static int menuAdmin();
};