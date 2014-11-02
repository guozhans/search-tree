
#include "WordSearch.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
  vector<IWordSearch*> searchTasks;
  
  searchTasks.push_back(new CWordLinearSearch());
  searchTasks.push_back(new CWordBinarySearch());
  
  string iteration;
  string keyword;
  
  cout << ">>>>> SEARCH TASKS BEGIN <<<<<\n";
  cout << "> Enter iteration: ";
  cin >> iteration;
  cout << "> Enter keyword: ";
  cin >> keyword;
  
  fstream file;
  file.open("wordlist_sorted.txt");
  
  vector<string> strings;
  string line = "";
  cout << ">>>>> READ FLIE TO STRINGS <<<<<\n";
  const clock_t begin_time = clock();
  while (getline(file, line))
  {
    strings.push_back(line);
    line.clear();
  }
  const clock_t end_time = clock();
  cout << ">>>>> ELAPSED: " << (float(end_time - begin_time) / CLOCKS_PER_SEC) << " <<<<<\n";
  for (vector<IWordSearch*>::iterator it = searchTasks.begin(); it != searchTasks.end(); it++)
  {
    cout << ">>>>> SEARCH  <<<<<\n";
    const clock_t begin_time = clock();
	int iteration_num = atoi(iteration.c_str());
	for (int i = 0; i < iteration_num; i++)
	{
      (*it)->Search(strings, keyword);
	}
    const clock_t end_time = clock();
    cout << ">>>>> ELAPSED: " << (float(end_time - begin_time) / CLOCKS_PER_SEC) << " <<<<<\n";
  }
  file.close();
  cout << ">>>>> SEARCH TASKS END <<<<<\n";
  cout << "> Any key and press Enter to end... ";
  cin >> keyword;
}