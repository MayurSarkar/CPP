#include <iostream>
using namespace std;

// Direct XOR of all numbers from 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    int n;
    cout << "Enter a positive integer (n): ";
    cin >> n;

    if (n < 0)
    {
        cout << "Please enter a positive integer." << endl;
    }
    else
    {
        int result = computeXOR(n);
        cout << "XOR of all numbers from 1 to " << n << " is: " << result << endl;
    }

    return 0;
}
