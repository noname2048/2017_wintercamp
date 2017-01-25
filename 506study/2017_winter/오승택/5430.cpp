#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void getinteger(int &index, int &count);
int integers[100010];
string func, input;

int main()
{	
	int testcase;
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	
	while (testcase--)
	{
		int num;
		cin >> func >> num >> input;
		int head = 0, rear = num - 1;
		int lenfunc = func.length(), leninput = input.length();
		bool reverse = false, error_exist = false;
		int count = 0;

		for (int i = 0; i < leninput; i++)
		{
			if (input[i] >= '1'&&input[i] <= '9')
				getinteger(i, count);
		}

		for (int i = 0; i < lenfunc; i++)
		{
			if (func[i] == 'R')
			{
				reverse = !reverse;
			}
			else
			{
				if (num == 0)
				{
					cout << "error" << endl;
					error_exist = true;
					break;
				}
				else
				{
					if (reverse)
						rear--;
					else
						head++;
						num--;
				}
			}
		}

		if (!error_exist)
		{
			cout << '[';
			if (num == 0)
				cout << ']' << endl;
			if (reverse)
			{
				for (int i = 0; i < num; i++)
				{
					if (i == num - 1)
						cout << integers[rear - i] << ']' << endl;
					else
						cout << integers[rear - i] << ',';
				}
			}
			else
			{
				for (int i = 0; i < num; i++)
				{
					if (i == num - 1)
						cout << integers[head + i] << ']' << endl;
					else
						cout << integers[head + i] << ',';
				}
			}
		}
		
	}
	return 0;
}
 void getinteger(int &index,int &count)
 {
     int integer=input[index]-'0';
     index++;
     while(input[index]>='0'&&input[index]<='9')
	 {
         integer=integer*10 + input[index]-'0';
         index++;
     }
    integers[count]=integer;
     count++;
}