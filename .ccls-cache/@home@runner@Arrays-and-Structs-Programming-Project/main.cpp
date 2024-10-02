/*
this program reads in the names and number of miles ran each day by each runner
and outputs the formatted data with the totals and average
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#define NUM_RUNNERS 5
#define DAYS_RUN 7
using namespace std;

// struct to store data for each runner
struct Runner {
  char name[10];
  int miles[DAYS_RUN];
  int total;
  double average;
};
// read and store names/miles func
bool read_names(Runner runners[NUM_RUNNERS]) {
  ifstream file;
  file.open("runners.txt");
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return false;
  }
  for (int i = 0; i < NUM_RUNNERS; i++) {
    file >> names[i];
    for (int j = 0; j < DAYS_RUN; j++) {
      file >> miles[i][j];
    }
  }
  file.close();
  return true;
}
// calc each total/average
void calc_totals(Runner runners[NUM_RUNNERS]) {
  int count;
  for (int i = 0; i < NUM_RUNNERS; i++) {
    count = 0;
    for (int j = 0; j < DAYS_RUN; j++) {
      count += miles[i][j];
    }
    totals[i] = count;
    averages[i] = double(count) / DAYS_RUN;
  }
}
// output results
void displayResults(Runner runner[NUM_RUNNERS]) {
  // print title
  cout << setw(15) << "Name" << setw(10) << "Day 1" << setw(10) << "Day 2"
       << setw(10) << "Day 3" << setw(10) << "Day 4" << setw(10) << "Day 5"
       << setw(10) << "Day 6" << setw(10) << "Day 7" << setw(10) << "Total"
       << setw(10) << "Average" << endl;
  cout << fixed << setprecision(1);
  // print data
  for (int i = 0; i < NUM_RUNNERS; i++) {
    cout << setw(15) << names[i] << setw(10) << miles[i][0] << setw(10)
         << miles[i][1] << setw(10) << miles[i][2] << setw(10) << miles[i][3]
         << setw(10) << miles[i][4] << setw(10) << miles[i][5] << setw(10)
         << miles[i][6] << setw(10) << totals[i] << setw(10) << averages[i]
         << "\n";
  }
}

int main() {
  // stores all structs
  Runner runners[NUM_RUNNERS];
  // read file for data
  if (!read_names(runners))
    return 1;
  // calculate totals and averages
  calc_totals(runners);
  // output results
  displayResults(runners);

  return 0;
}