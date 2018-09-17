#include <iostream>
using namespace std;

//Count number of ones in binary representation of decimal number
int BinOnes(int input){

    //Base Case - conversion is finished
    if(input == 1)
        return 1;

    //A remainder results in a 1 in the binary representation
    //If remainder make recursive call and add 1 to the result
    if (input % 2 == 1)
        return BinOnes(input / 2) + 1;

    //No remainder results in a 0 in the binary representation
    //Make recursive call if no remainder, without adding a 1
    return BinOnes(input / 2);
}

//Main method
int main()
{
    //Declare int input variable
    int num;

    //Recieve decimal number input
    cout << "Enter a number: ";
    cin >> num;

    //Call function and print result
    cout << BinOnes(num) << endl;

    return 0;
}

