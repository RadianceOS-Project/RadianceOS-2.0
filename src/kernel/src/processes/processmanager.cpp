#include "process.h"
#include "processmanager.h"
#include <list>
#include <iostream>

using namespace std;
using std::list;

list<process> processes = {};

void AddProcess(process p)
{
	p.processID = processes.size();
	processes.push_back(p);

}
void KillProcess(int processid)
{
	auto it = processes.begin();
	advance(it, processid);
	processes.erase(it);
}