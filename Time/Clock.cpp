#include "Clock.h"

Clock::Clock()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
	hour = now->tm_hour;
	minute = now->tm_min;
	second = now->tm_sec;
}

void Clock::LocalNow()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
}

void Clock::UTCNow()
{
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
	char* dt = asctime(gmtm);
	cout << "The UTC date and time is:" << dt << endl;
}

void Clock::CurrentSystem()
{
	time_t now = time(0);
	cout << "Number of sec since January 1,1970: " << now << endl;
}

void Clock::Adjust(int y, int m, int d, int h, int mi, int s)
{
	year += y;
	month += m;
	day += d;
	minute += mi;
	hour += h;
	second += s;
	Correct();
}

void Clock::Correct()
{
	int lc = 0;
	while (second > 59)
	{
		second -= 60;
		minute++;
	}
	while (minute > 59)
	{
		minute -= 60;
		hour++;
	}
	while (hour > 23)
	{
		hour -= 24;
		day++;
	}

	if (month == 0)
	{
		if (day > 31 && year == 0)
		{
			day -= 31;
			month++;
		}
		else
		{
			return;
		}
	}

	while (lc == 0)
	{
		switch (month)
		{
		case 1:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}

		case 2:
			if (year % 4 == 0)
			{
				if (day > 29)
				{
					day -= 29;
					month++;
				}
				else
				{
					lc++;
					break;
				}
			}
			else
			{
				if (day > 28)
				{
					day -= 28;
					month++;
				}
				else
				{
					lc++;
					break;
				}
			}
		case 3:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 4:
			if (day > 30)
			{
				day -= 30;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 5:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 6:
			if (day > 30)
			{
				day -= 30;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 7:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 8:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 9:
			if (day > 30)
			{
				day -= 30;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 10:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 11:
			if (day > 30)
			{
				day -= 30;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		case 12:
			if (day > 31)
			{
				day -= 31;
				month++;
			}
			else
			{
				lc++;
				break;
			}
		default:
			if (month > 12)
			{
				month -= 12;
				year++;
			}
			break;
		}
	}

}

void Clock::Output()
{
	cout << year << "/" << month << "/" << day << " : " << hour << "h " << minute << "m " << second << "s " << endl;
}
