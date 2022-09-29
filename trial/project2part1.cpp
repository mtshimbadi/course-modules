/* This program asks the user to input a digit and the program display
 the digit as a whole*/
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

// Class declaration 
class Numbers 
{
    public:
    static int numbers;
    static void print ();
};

void Numbers::print ()
{
    int x; // initialization of x as an integer

    // string literal that holds the numbers
    string lessthan[20] = { "zero "," one ", " two ", " three ", " four ", " five ", " six ", " seven ", " eight ", " nine ", " ten ", " eleven ",
           " twelve ", " thirteen ", " fourteen ", " fifteen "," sixteen ", " seventeen ", " eighteen ", " nineteen " };

    string tens[] = { " zero"," ten", " twenty", " thirty", " fourty", " fifthy", " sixty", " seventy", " eighty", " ninety"};

    string  hundreds = "hundred";
    string  thousand = "thousand";

    // input validation for the user input numbers
    if (numbers < 0)
    cout << "This is a negeative number - please add positive number!";
    numbers = abs(numbers);
    x = numbers / 1000;

    if (x > 0) 
    cout << " " << lessthan[x] << thousand; 
    numbers %= 1000;

    x = numbers / 100;
    if (x > 0)
       cout << lessthan[x] << hundreds;
    numbers%= 100;

    if (numbers >= 20)
    {
        x = numbers / 10;
         
        if (x > 0)
           cout << tens[x] << " ";
    }
    else if (numbers >=10)
    {
        cout << lessthan[numbers] << " ";
        return;
    }
    numbers %= 10;
    if (numbers > 0)
       cout << lessthan[numbers];
    cout << " ";

}

int Numbers::numbers; // reference from the class objects
int main ()
{
    int x; 

    // prompt user input 
    cout << "Enter a number from 0 - 9999, or press [N] to end \n ";
    cin >> x;

    // input validation 
    while (x != 0)
    {
        cout << "The number " << x << " is translated into " << "";
        Numbers::numbers = x;

        Numbers::print();
        cout << "\n Enter a number from 0 - 9999, or press [N] to end \n";
        cin >> x;
    }
    cin.ignore(); 
    cin.get();

    system("pause"); // pauses the program after displaying the output

    return 0;

}