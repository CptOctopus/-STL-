#include<vector>
#include<stdexcept>
#include<string>
#include<cstdlib> //abort()
#include<cstdio> //snprintf
#include<iostream>
#include<ctime>
#include<algorithm>
#include<iostream>
using namespace std;
using std::cout;
using std::string;
long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << ");";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];
	cout << "target" << RAND_MAX << ")" << endl;
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);

}
int comparelongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}
int comparestrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if(*(string*)a <*(string*)b)
		return -1;
	else
		return 0;
}

void test_vector(long& value)
{
	cout << "\ntest_vector()..............\n";
	vector<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p) {
			cout << "i=" << i << "" << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "vector_size:" << c.size() << endl;
	cout << "vector_front:" << c.front() << endl;
	cout << "vector_size:" << c.size() << endl;
	cout << "vector_data:" << c.data() << endl;
	cout << "vector_capacity:" << c.capacity() << endl;



	string	target=get_a_target_string();
	{
		clock_t timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);//find·µ»Øinterator
		cout << "find(),milli-seconds:" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "find() found" << *pItem << endl;
		else
			cout << "find() not found" << endl;
	}
	{
		clock_t tiemStart = clock();
		sort(c.begin(), c.end());
		string * pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), comparestrings);
		cout << "sort()+bserch():,milli-seconds:" << clock() - timeStart << endl;
		if (pItem != NULL)
			cout << "bsearch found" << endl;
		else
			cout << "bsearch not found" << endl;

	}
	while (1);
}

int main()
{
	long a = 1000000;
	test_vector(a);
	return 0;
}