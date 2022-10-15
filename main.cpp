//Task 1 (a,b,c)

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

class BigDecimalInt
{
private:

    string num1;

    int nums;

public:


    BigDecimalInt(string n1) : num1(n1)
    {

    }

    //------------------------------------------------------------------------------------------

    BigDecimalInt(int n2) : nums(n2)
    {

    }

    //------------------------------------------------------------------------------------------

    BigDecimalInt operator + (BigDecimalInt anotherDec)
    {
        string ans = "";

        int i1 = num1.size() - 1, i2 = anotherDec.num1.size() - 1, carry = 0;

        while (i1 >= 0 || i2 >= 0 || carry > 0) {

            if (i1 >= 0) {

                carry += num1[i1] - '0';

                i1 -= 1;
            }
            if (i2 >= 0) {

                carry += anotherDec.num1[i2] - '0';

                i2 -= 1;
            }
            ans += char(carry % 10 + '0');

            carry /= 10;
        }
        reverse(ans.begin(), ans.end());

        return BigDecimalInt (ans);
    }

    //------------------------------------------------------------------------------------------

    void print()
    {
        cout << "The number = " << num1;
    }

    //------------------------------------------------------------------------------------------

    void print_int()
    {
        cout << "The number with intger value = " << nums;
    }

};






int main()
{
    string str1, str2;

    int flag = 1, count = 0;

    while (flag)
    {

        cout << "The first number = ";

        getline(cin, str1);

        count = 0;


        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == ' ')
            {
                count++;

                cout << "Invalid Input!!!, try again." << endl;

                cout << endl;

                break;
            }

        }

        if (count == 0) flag = 0;

    }

    flag = 1;

    cout << endl;

    while (flag)
    {

        cout << "The second number = ";

        getline(cin, str2);

        count = 0;

        cout << endl;

        for (int i = 0; i < str2.size(); i++)
        {
            if (str2[i] == ' ')
            {

                count++;

                cout << "Invalid Input!!!, try again." << endl;

                cout << endl;

                break;
            }

        }

        if (count == 0) flag = 0;
    }

    str1.erase(remove(str1.begin(), str1.end(), '+'), str1.end());

    str2.erase(remove(str2.begin(), str2.end(), '+'), str2.end());

    BigDecimalInt num3(123);

    BigDecimalInt num1(str1);

    BigDecimalInt num2(str2);

    BigDecimalInt num4 = num1 + num2;


    num4.print();

    cout << endl;

    num3.print_int();


    return 0;
}
