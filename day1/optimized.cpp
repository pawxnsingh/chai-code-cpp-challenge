#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

#define prime 7
// hash always going to be positive, so we gonna make it unsigned
// this is called universal hashing

// complexity is : O(n + m)

unsigned long calculateHash(const string &str)
{
    unsigned long hash = 0;

    for (int i = 0; i < str.size(); i++)
    {
        hash += str.at(i) * pow(prime, i);
    }

    return hash;
}

unsigned long updateHash(unsigned long prevHash, const char &oldChar, const char &newChar, int glitchSize)
{
    // remove the old char
    unsigned long newHash = (prevHash - oldChar) / prime;
    newHash += newChar * pow(prime, glitchSize - 1);
    return newHash;
}

// this will indetify the glich and return me the starting index of glitch in videoStream
void indentifyGlitch(const string &videoStream, const string &glitchPattern, vector<int> &glitchIndexes)
{
    int glitchSize = glitchPattern.size(); // 3
    unsigned long glitchPatternHash = calculateHash(glitchPattern);
    unsigned long textHash = calculateHash(videoStream.substr(0, glitchSize));

    for (int i = 0; i <= videoStream.size() - glitchSize; i++)
    {
        if (textHash == glitchPatternHash)
        {
            if (videoStream.substr(i, glitchSize) == glitchPattern)
            {
                glitchIndexes.push_back(i);
            }
        }

        if (i < videoStream.size() - glitchSize)
        {
            textHash = updateHash(textHash, videoStream.at(i), videoStream.at(i + glitchSize), glitchSize);
        }
    }
}

int main()
{
    // now lets upgrade this question let it store all the instance of the glitch
    string videoStream = "200200200";
    string glitchPattern = "200";

    vector<int> glitchIndexes;
    indentifyGlitch(videoStream, glitchPattern, glitchIndexes);
    if (glitchIndexes.size() > 0)
    {
        cout << "Success" << endl;
        for (int idx : glitchIndexes)
        {
            cout << idx << endl;
        }
    }
    else
    {
        cout << "Nothing found" << endl;
    }
}