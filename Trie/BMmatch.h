#ifndef _BMMATCH_H_
#define _BMMATCH_H_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> buildLastFunction(const string& pattern);
int BMmatch(const string& text, const string& pattern);

#endif