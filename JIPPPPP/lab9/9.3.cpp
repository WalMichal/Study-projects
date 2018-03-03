#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <thread>

using namespace std;

class SimpleIntervalExecutor
{
public:

	SimpleIntervalExecutor() :functor_counter(1), functor_name_counter(class_counter)
	{
		class_counter++;
	}

	void Register(std::function<void(std::chrono::system_clock::time_point)> fun, std::chrono::milliseconds interval)
	{
		regvec.push_back(make_tuple(fun, interval));
	}

	void run()
	{
		if (regvec.empty())return;
		for (int i = 0; i<regvec.size(); i++)
		{
			(get<0>(regvec[i]))(std::chrono::system_clock::now());
			std::this_thread::sleep_for((get<1>(regvec[i])));
			if (i == regvec.size() - 1)i = -1;
		}
	}

	void operator()()
	{
		string help;
		help = "Functor" + to_string(functor_name_counter) + ". Number of calls:" + to_string(functor_counter) + ".";
		cout << help << endl;
		functor_counter++;
	}
private:

	vector <tuple <function<void(std::chrono::system_clock::time_point)>, std::chrono::milliseconds>> regvec;
	int functor_counter;
	int functor_name_counter;
	static int class_counter;
};

int SimpleIntervalExecutor::class_counter = 1;

void getdate(std::chrono::system_clock::time_point tpoint)
{
	time_t now1 = std::chrono::system_clock::to_time_t(tpoint);
	std::cout << put_time(std::localtime(&now1), "%T") << endl;;
}

int main()
{
	string strofcharacters;
	cout << "Enter string of characters." << endl;
	getline(std::cin,strofcharacters);
	cout << endl;
	SimpleIntervalExecutor a, b;
	//1
	a();
	a();
	b();
	a();
	//2
	std::chrono::system_clock::time_point tpoint = std::chrono::system_clock::now();
	getdate(tpoint);
	//3
	[](string str)->void {cout << str<<endl; }(strofcharacters);
	//4
	a.Register(getdate, std::chrono::milliseconds(3000));
	a.Register(getdate, std::chrono::milliseconds(1000));
	a.run();

	return 0;
}

