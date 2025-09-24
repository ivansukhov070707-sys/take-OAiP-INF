#include <iostream>
#include <string>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "RU");
    string s;
    int i = 0;
    getline(cin, s);
    string vowels = "aeiouAEIOU";
    for (char c : s) 
    {
        for (char v : vowels) 
        {
            if (c == v) 
            {
                i++;
                break;
            }
        }
    }
    cout << "Кол-во: " << i << endl;
    return 0;
}