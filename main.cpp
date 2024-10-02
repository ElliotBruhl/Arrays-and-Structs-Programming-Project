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

// read and store names/miles func
bool read_names(char names[NUM_RUNNERS][10], int miles[NUM_RUNNERS][DAYS_RUN]) {
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
void calc_totals(int miles[NUM_RUNNERS][DAYS_RUN], int totals[NUM_RUNNERS], double averages[NUM_RUNNERS]) {
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
void displayResults(char names[NUM_RUNNERS][10], int miles[NUM_RUNNERS][DAYS_RUN], int totals[NUM_RUNNERS], double averages[NUM_RUNNERS]) {
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
  // read file for data
  char names[NUM_RUNNERS][10];
  int milesRan[NUM_RUNNERS][DAYS_RUN];
  if (!read_names(names, milesRan))
    return 1;

  // calculate totals and averages
  int totals[NUM_RUNNERS];
  double averages[NUM_RUNNERS];
  calc_totals(milesRan, totals, averages);

  // output results
  displayResults(names, milesRan, totals, averages);

  return 0;
}