#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <exception>

using namespace std;

int isdig(string input, int i);

class TimeFormatMistake: public exception
{
	public:
	  virtual const char* what() const throw()
  {
    return "Invalid Input";
  }
};

int main ()
{
	TimeFormatMistake ball;
	char confirm = 'Y';
	string input;
	int first2[2];
	int last2[2];
	char AMPM[3] = "AM";
	cout.precision(2);
	
	while (confirm == 'y' || confirm == 'Y')
	{
		
		try
		{
			
			cout << "Enter time in 24-hour notation: " << endl;
			cin >> input;
			
			if (input.length() > 5)
			{
				throw ball;
			}
			
			for (int i = 0; i < 4; i++)
			{
				if (!isdigit(input[i]) && input[i] != ':')
				{
					throw ball;
				}
			}
			
			if (input[1] == ':')
			{
				first2[0] = 0;
				first2[1] = isdig(input, 0);
				last2[0] = isdig(input, 2);
				last2[1] = isdig(input, 3);
				
				first2[0] = (first2[0] * 10) + first2[1];
				
				if (first2[0] >= 24 || first2[0] < 0)
				{
					throw ball;
				}
				
				last2[0] = (last2[0] * 10) + last2[1];
				
				if (last2[0] >= 60 || last2[0] < 0)
				{
					throw ball;
				}
				
				cout << "That is the same as ";
				if (first2[0] < 10)
					{
						cout << '0' << first2[0];
					}
				else
				{
						cout << first2[0];
				}
				
				cout << ':';
				
				if (last2[0] < 10)
					{
						cout << '0' << last2[0] << AMPM << endl;
					}
				else
				{
						cout << last2[0] << AMPM << endl;
				}
				
				cout << "Again?(y/n)" << endl;
				cin >> confirm;
			}
			else if (input[2] == ':')
			{
				first2[0] = isdig(input, 0);
				first2[1] = isdig(input, 1);
				last2[0] = isdig(input, 3);
				last2[1] = isdig(input, 4);
				
				first2[0] = (first2[0] * 10) + first2[1];
				if (first2[0] >= 12 && first2[0] < 24)
				{
					first2[0] = first2[0] % 12;
					AMPM[0] = 'P';
					AMPM[1] = 'M';
				}
				last2[0] = (last2[0] * 10) + last2[1]; // have to check for >60
				
							if (first2[0] < 10)
					{
						cout << '0' << first2[0];
					}
				else
				{
						cout << first2[0];
				}
				
				cout << ':';
				
				if (last2[0] < 10)
					{
						cout << '0' << last2[0] << AMPM << endl;
					}
				else
				{
						cout << last2[0] << AMPM << endl;
				}
				
				cout << "Again?(y/n)" << endl;
				cin >> confirm;
				
			}
			

		}
		
		catch(TimeFormatMistake& mistake)
		{
			cout << mistake.what() << endl;
			cout << "try again" << endl;
			
		}
	}
	
	return 0;
	
	
	
}


int isdig(string input, int i)
{
	stringstream temp;
	int tempint;
	if (isdigit(input[i]))
	{
		temp << input[i];
		temp >> tempint;
		return tempint;
		
	}
	else
	{
		cout << "invalid input" << endl;
	}
}