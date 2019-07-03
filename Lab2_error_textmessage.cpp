#include <iostream>

#include <string>

#include <fstream>

#include <ctime>

using namespace std;



class Message

{
	
string mbody;
	
string mtype;
	
int year;
	
int month;
	
int day;
	
int hour;
	
int minutes;
	
int seconds;



public:
	
Message(string body, string type)

	{
		
if (type != "error"&&type != "notification"&&type != "warning")
		
{
			
type = "empty";
		
}
	
	mtype = type;
    
        mbody = body;

	
	time_t present = time(0);
	tm *pt = localtime(&present);
	
	year = 1900 + pt->tm_year;
	month = 1 + pt->tm_mon;
	day = pt->tm_mday;
	hour = 1 + pt->tm_hour;
	minutes = 1 + pt->tm_min;
	seconds = 1 + pt->tm_sec;

	
}
	
string get()
	
{
		
string all;
	
all = "[" + mtype + "]" + "[" + to_string(year) + "-" + to_string(month) + "-" + to_string(day) + " "+to_string(hour) + ":" + to_string(minutes) + ":" + to_string(seconds) +"]"+mbody;
	
return all;
	
}

};


class Logger

{
	
fstream file;


public:
	
Logger(string file_name)
	
{
		
file_name += ".txt";
		
file.open(file_name, ios::out | ios::app);

	}
	
void append(Message message)
	
{
		
file << message.get() << endl;
	
	cout << "Dodano komunikat" << endl;
	
}
	
~Logger()
	
{
	
file.close();
	
}

};



int main()

{
	
Message New("Message","error");

	Logger W("File");
	
W.append(New);

	


system("pause");	
return 0;

}