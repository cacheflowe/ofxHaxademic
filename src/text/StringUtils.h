#pragma once
using namespace std;

#include <memory>
#include <iostream>
#include <string>
#include <cstdio>

class StringUtils
{
public:
	StringUtils();
	~StringUtils();
	static string StringUtils::secondsToFormattedTime(int seconds);
	static string StringUtils::paddedNumber(int number, int length);
};

