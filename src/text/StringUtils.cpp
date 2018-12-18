#include "StringUtils.h"

#define HOUR 3600
#define MIN 60

StringUtils::StringUtils()
{
}

StringUtils::~StringUtils()
{
}

string StringUtils::secondsToFormattedTime(int seconds) {
	int hour = seconds / HOUR;
	int second = seconds % HOUR;
	int minute = second / MIN;
	second = second % MIN;
	string hourStr = (hour < 10) ? "0" + to_string(int(hour)) : to_string(int(hour));
	string minuteStr = (minute < 10) ? "0" + to_string(int(minute)) : to_string(int(minute));
	string secondStr = (second < 10) ? "0" + to_string(int(second)) : to_string(int(second));
	return hourStr + ":" + minuteStr + ":" + secondStr;
}

string StringUtils::paddedNumber(int number, int length) {
	string numStr = to_string(number);
	while (numStr.length() < length) numStr = "0" + numStr;
	return numStr;
}

