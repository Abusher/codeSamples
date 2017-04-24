// Parse_XML.cpp: определяет точку входа для консольного приложения.
//

// XMLParse.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <thread>



using namespace std;

string remove(string& s);
bool xml_parse(string s, int start, int finish, vector<pair<int, int>>& inter);
void sieve(int max, vector<int>& primes);
string getTag(string& s);
pair<int, int> interval_analys(string s);
int getNumber(string s);
int PastePosition(string s);

int main()
{
	ifstream red("test.xml");

	string s
	(
		(istreambuf_iterator<char>(red))
		, istreambuf_iterator<char>()
	);
	vector<pair<int, int>> intervals;

	vector<int> primes;


	xml_parse(remove(s), 0, s.length(), intervals);
	//sieve(120);

	sort(intervals.begin(), intervals.end());

	int max = 0;
	for (int i = 0; i < intervals.size(); i++)
	{
		if (intervals[i].second > max)
			max = intervals[i].second;
	}

	thread t((sieve), max, ref(primes));


	if (t.joinable())
		t.join();

	int i = 0;
	int j = 0;
	while (j < primes.size()) {

		if (primes[j] < intervals[i].first) {
			j++;
		}
		else if (primes[j] < intervals[i].second) {
			cout << primes[j] << endl;
			j++;
		}
		else i++;
	}

	

	return 0;
}

string remove(string &s)
{
	string ans = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\n') ans += s[i];
	}
	return ans;
}


pair<int, int> interval_analys(string s)
{
	int startLow = 0, finishLow = 0, startHigh = 0, finishHigh = 0;

	try
	{
		startLow = s.find("<low>");
		finishLow = s.find("</low>");
		startHigh = s.find("<high>");
		finishHigh = s.find("/high");


		if (startLow > s.length()
			|| finishLow < startLow
			|| finishLow > s.length()
			|| startHigh < finishLow
			|| finishHigh < startLow
			|| finishHigh > s.length()
			|| startHigh > s.length())
		{
			throw "Wrong data format";
		}
		int min = getNumber(s.substr(startLow + 5, finishLow - startLow - 5));
		int max = getNumber(s.substr(startHigh + 6, finishHigh - (startHigh + 7)));
		return{ min,max };
	}
	catch (string ex)
	{
		cout << ex;
	}

	return{ 1,1 };
}

int getNumber(string s)
{
	int number = 0;
	try
	{
		for (char element : s)
		{
			int c = element - '0';
			if (c <= 9 && c >= 0) number = number * 10 + c;
			else throw "Wrong data input";
		}
	}
	catch (string ex)
	{
		cout << ex << endl;
	}
	return number;
}

bool xml_parse(string s, int start, int finish, vector<pair<int, int>>& inter)
{
	//cout << finish<<endl;

	string root = "";
	if (start >= finish)
	{
		return 0;
	}


	do
	{
		root += s[start];
		start++;
	} while (s[start] != '>');

	root += s[start];
	start++;


	string root_end = root.substr(0, 1) + '/' + root.substr(1, root.length() - 1);
	if(s.find("/interval",start) > finish) return true;

	if (root == "<interval>")
	{
		//cout << root_end << endl;
		string interval = s.substr(start, s.find(root_end, start) - start);
		//cout <<  interval << " "<<endl;
		inter.push_back(interval_analys(interval));
		start = s.find(root_end, start) + root_end.length();
		//cout << start << " " << finish << endl;
	}
	else if (s.find(root_end) != finish - root_end.length() && finish - start < root_end.length())
	{
		return true;
	}

	else
	{
		//cout << root << " " << root_end << endl;
		finish -= root_end.length();
		root = "";
		root_end = "";
	}

	if (!xml_parse(s, start, finish, inter)) return false;

	return true;
}


void sieve(int max, vector<int>& primes)
{
	//cout << "from thread " << max << endl;

	bool* numbers = new bool[max + 1];
	for (int i = 0; i <= max; i++)
	{
		numbers[i] = true;
	}

	primes.push_back(2);
	for (int i = 4; i <= max; i *= 2)
	{
		numbers[i] = false;
	}

	for (int i = 3; i <= max; i += 2)
	{
		if (numbers[i])
		{
			primes.push_back(i);
			for (int j = 2 * i; j <= max; j += i)
				numbers[j] = false;
		}
	}
}
int PastePosition(string s)
{
	int end = s.length() - 1;
	while (s[end] != '<')
		end--;
	return end;
}

