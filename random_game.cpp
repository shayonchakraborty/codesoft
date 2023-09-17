#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int result(int y, int z)
{
    int flag = 0;
    if (y == z)
    {
        flag = 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
void hint_1(int y, int u)
{
    if (y % 2 == 0)
    {
        cout << "number is even" << endl;
        if (u % 2 == 0)
            cout << "but not"
                 << " " << u << endl;
    }
    else
    {
        cout << "number is odd" << endl;
        if (u % 2 != 0)
            cout << "but not"
                 << " " << u << endl;
    }
}
void hint_2(int y, int u, int k)
{
    int i;
    int x = k / 2;
    if (y <= x)
    {
        cout << "predict between 1-" << x << " ";
        for (i = 1; i <= x; i++)
        {
            if (u == i)
                cout << "except"
                     << " " << u << endl;
        }
    }
    else
    {
        cout << "predict between " << (x + 1) << "-" << k << " ";
        for (i = (x + 1); i <= k; i++)
        {
            if (u == i)
            {
                cout << "except"
                     << " " << u << endl;
            }
        }
    }
}
void hint_3(int y, int u, int z)
{

    if (y == 1)
    {
        cout << "predict between 1-3" << endl;
        cout << "except:" << u << endl;
    }
    else if (y == 2)
    {
        cout << "predict between 2-4" << endl;
        cout << "except:" << u << endl;
    }
    else
    {
        cout << "predict between " << (y - 2) << "-";
        if ((y + 1) <= z)
        {
            if ((y + 2) >= z)
                cout << (y + 1);
            else
                cout << (y + 2);
        }
        else
            cout << y;
        if (u == (y - 2) || u == (y - 1) || u == (y) || u == (y + 1) || u == (y + 2))
        {
            cout << endl
                 << "except:" << u << endl;
        }
    }
}
void scoreboard(int A[], int n)
{
    cout << endl
         << "Results:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        if (A[i] != 0)
        {
            cout << "Round" << (i + 1) << endl;
            cout << "Score out of 100 is:" << A[i] << endl;
        }
    }
}
void bonus_hint(int k, int range)
{
    int i = 1;
    cout << "The acutal number is divisible by:" << endl;
    for (i = 1; i <= range; i++)
    {
        if (k % i == 0)
            cout << i << " ";
    }
}
int isprime(int k)
{
    int i, count = 0;
    for (i = 2; i < 1000; i++)
    {
        if (k % i == 0)
            count++;
    }
    if (count > 1)
        return 1;
    else
        return 0;
}
int main()
{
    int a, b, c, d, e, i, round;
    srand(time(0));
    cout << "enter the range in which you want to guess starting from-1" << endl;
    cin >> e;
    cout << "how many rounds you want to play" << endl;
    cin >> round;
    int array[round];
    for (i = 0; i < round; i++)
    {
        array[i] = 0;
    }
    for (i = 0; i < round; i++)
    {
        int efficiency = 100;
        cout << "predict a number between 1-" << e << endl;
        int x = ((rand() % e) + 1);
        cin >> a;
        if (result(x, a) == 1)
        {
            cout << "you are right" << endl;
            array[i] = efficiency;
        }

        else
        {
            cout << "wrong!" << endl;
            cout << "Attempts left:03" << endl;
            cout << "Hint:";
            hint_1(x, a);
            cout << "predict again" << endl;
            cin >> b;
            int k = result(x, b);
            if (k == 1)
            {
                cout << "you got it" << endl;
                array[i] = (efficiency - 30);
            }

            else
            {
                cout << "wrong!" << endl;
                cout << "Attempts left:02" << endl;
                cout << "Hint:";
                hint_2(x, b, e);
                int m = isprime(x);
                if (m == 1)
                    bonus_hint(x, e);
                cout << endl;
                cin >> c;
                int q = result(x, c);
                if (q == 1)
                {
                    cout << "you got it!!" << endl;
                    array[i] = (efficiency - 50);
                }

                else
                {
                    cout << "wrong!" << endl;
                    cout << "Last Attempt" << endl;
                    cout << "Hint:";
                    hint_3(x, c, e);
                    cout << endl;
                    cin >> d;
                    int h = result(x, d);
                    if (h == 1)
                    {
                        cout << "you got it finally!!" << endl;
                        array[i] = (efficiency - 70);
                    }

                    else
                    {
                        cout << "your prediction ended"
                             << " "
                             << "better luck next time" << endl
                             << "the number was:" << x;
                        array[i] = (efficiency - 100);
                    }
                }
            }
            cout << "**************************";
            scoreboard(array, round);
            cout << "**************************" << endl;
        }
    }
}