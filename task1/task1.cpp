#include <iostream>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;

string itoBase(unsigned int nb, string base);

int main(int argc, char* argv[])
{
    stringstream convert(argv[1]);
    int param1 = 0;
    convert >> param1;
    cout << "Got integer: " << param1 << '\n';

    string temp = itoBase(param1, argv[2]);
    char res[1024];
    strncpy(res, temp.c_str(), sizeof(res));
    res[sizeof(res) - 1] = 0;

    for (int i = 0; i < strlen(res); i++)
    {
        int digit = (int)res[i];
        if (digit >= 0 && digit <= 9)
        {
            cout << digit;
        }
        else cout << res[i];
    }

    cout << endl;
}

string itoBase(unsigned int nb, string base)
{
    int num = nb;
    int sz = 0, a[1000];
    char result[10000];

    int base1 = base.length();

    while (num > 0)
    {
        a[sz++] = num % base1;
        num /= base1;
    }


    for (int i = sz - 1, j = 0; i >= 0; i--, j++)
    {
        if (a[i] >= 0 && a[i] <= 9)
        {
            result[j] = a[i];
        }
        else
        {
            result[j] = char(a[i] - 10 + 'A');
        }
    }

    result[sz] = '\0';

    return result;
}