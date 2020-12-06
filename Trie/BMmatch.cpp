#include <iostream>
#include "BMmatch.h"

using namespace std;

// construct function last
std::vector<int> buildLastFunction(const string& pattern)
{
    const int N_ASCII = 128;			// number of ASCII characters
    std::vector<int> last(N_ASCII);		// assume ASCII character set
    for (int i = 0; i < N_ASCII; i++)		// initialize array
        last[i] = -1;
    for (size_t i = 0; i < pattern.size(); i++)
    {
        last[pattern[i]] = i;			// (implicit cast to ASCII code)
    }
    return last;
}

// Simplified version of the Boyer-Moore algorithm. Returns the index of
// the leftmost substring of the text matching the pattern, or -1 if none.
int BMmatch(const string& text, const string& pattern)
{
    std::vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;
    if (i > n - 1)				// pattern longer than text?
        return -1;				// ...then no match
    int j = m - 1;
    do {
        if (pattern[j] == text[i])
            if (j == 0) return i;			// found a match
            else {					// looking-glass heuristic
                i--; j--;				// proceed right-to-left
            }
        else {					// character-jump heuristic
            i = i + m - min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    } while (i <= n - 1);
    return -1;					// no match
}
