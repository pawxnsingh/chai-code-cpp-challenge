#include <iostream>
#include <string>

using namespace std;

// complexity - O(n*m)

// you just need to implement this function
bool containsGlitchPattern(const string &videoStream, const string &glitchPattern)
{
    int n = videoStream.size();
    int m = glitchPattern.size();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (videoStream[i + j] != glitchPattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string videoStream, glitchPattern;
    cin >> videoStream;
    cin >> glitchPattern;

    // please do not change the below code
    if (containsGlitchPattern(videoStream, glitchPattern))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}