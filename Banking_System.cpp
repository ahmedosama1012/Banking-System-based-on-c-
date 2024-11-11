#include<iostream>
#include<cstring>  //to use built-in function in array of characters
#include<limits> //to use numeric_limits
using namespace std;

class ATM {
private:
    char account_name[100];    //maximum length of account name=100
    char card_number[10];      //maximum length of card number=10
    double amount;             //double data type to accept long numbers with floating point
    long new_amount;           //to avoid any float number
public:

    void create_new_acc()      //function to create account
    {
        cout << "please enter the account name: ";
        cin.ignore();                                       //to ignore NULL before getting the name
    reinput:  cin.getline(account_name, 100);
        while (!cin) {                                      //to check that the name doesn't exceed 100 character
            cout << "name is too long\n" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "please enter the account name: ";
            cin.getline(account_name, 100);
        }
        for (int v = 0; v < strlen(account_name); v++) {          //loop to check that each character is a Letter or space
            int f = account_name[v];
            while ((f > 90 && f < 97) || f > 122 || (f < 65 && f != 32)) {
                cout << "\nINVALID NAME\n\n";
                cout << "\n ENTER LETTERS ONLY WITHOUT ANY NUMBERS \n\n";
                cout << "please enter the account name: ";

                cin.getline(account_name, 100);
                v = -1;
                break;
            }
        }
    int c = 0;
        for (int k = 1; k < strlen(account_name); k++) {           //loop to check that the name is not combined by one character only
            if (account_name[k] == account_name[0])
                c++;

        }
        if (c == strlen(account_name) - 1) {
            cout << " you can't enter the same charcter(s) only\n" << endl << endl;
            cout << "please enter the account name: ";
            c = 0;
            goto reinput;                          //reinput is in line 18
        }
        if (strlen(account_name) == 0) {                         //to check that the user entered a name
            cout << "no name detected please try again\n\n";
            cout << "please enter the account name: ";
            goto reinput;                          //reinput is in line 18
        }



    check2:
        cout << "Please enter the account number( 10 numbers ): ";
        cin >> card_number;
        cout << endl;

        amount = 0;
    check: for (int v = 0; v < strlen(card_number); v++) {      //to check that the user entered numbers only
        int f = card_number[v];
        while ((f < 48 || f > 57)) {
            cout << "\nINVALID ACCOUNT NUMBER\n\n";
            cout << "\n ENTER NUMBERS ONLY WITHOUT ANY CHARACTER \n\n";
            cout << "please enter the account number( 10 numbers ): ";
            cin >> card_number;
            goto check;                                   //check is in line 64
        }

    }
    while (strlen(card_number) != 10) {                              //to check that the user didn't enter more or less than 10 numbers
        cout << "you entered a wrong number\n";
        cout << "\n enter only 10 numbers \n\n";
        cout << "Please enter the account number( 10 numbers ): ";
        cin >> card_number;
        cout << endl;
        amount = 0;
        goto check;                                     //check is in line 64      to recheck the first condition(that the user entered numbers only)
    }
    int count = 0;
    for (int k = 1; k < 10; k++) {                           //to avoid easy guess card numbers that have the same entry
        if (card_number[k] == card_number[0])
            count++;

    }
    if (count == 9) {
        cout << " INVALID YOU CAN'T CHOOSE CARD NUMBER WITH ONE REAPETED NUMBERS ONLY" << endl << endl;
        count = 0;
        goto check2;                                     //check2 is in line 58
    }


    }
    int Deposit(ATM account[], ATM& test, int& check)
    {
        check = 1;                                             //to check that deposit done to an account to print its information
        cout << "Please enter the account number:";
        cin >> test.card_number;
        while (strlen(test.card_number) != 10) {               //to check that the user didn't enter more or less than 10 numbers
            cout << "you entered a wrong number\n";
            cout << "Please enter the account number:";
            cin >> test.card_number;
            cout << endl;

        }
        int i;
        for (i = 0; i < 100; i++) {                                          //loop to get the account with the card number entered and enter money in it
            if (strcmp(test.card_number, account[i].card_number) == 0)             //to search for the account with the entered card number
            {
            new_input:
                cout << "Please enter the amount to be deposited:";
                cin >> new_amount;
                while ((!cin) || (cin.peek() != '\n'))                        //to avoid entering any charcters other than numbers
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                    cout << "Please enter the amount to be deposited:";
                    cin >> new_amount;
                }

                while (new_amount < 0) {                                 //to check that he didn't enter negative numbers
                    cout << "\ndon't enter negative numbers\n\n";
                    goto new_input;
                }
                account[i].amount += new_amount + 0.01 * new_amount;
                return i;
                break;
            }
        }
        while (i == 100) {                                                  //if i=100 it means that the account doesn't exist so the user can either return to main menu or re-renter another card number
            cout << "\nNo matching account\n\n";
            int reset;
            cout << " If you want to write another account number press 1\n" << endl;
            cout << " If you want to continue with another process enter 2\n" << endl;
            cin >> reset;
            while ((!cin) || (cin.peek() != '\n'))                                    //to avoid entering any charcters other than numbers
            {
                cout << "\n\n INCORRECT INPUT! \n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
            }

            while (reset != 1 && reset != 2) {
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
                while ((!cin) || (cin.peek() != '\n'))                        //to avoid entering any charcters other than numbers
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                    cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                    cin >> reset;
                }

            }
            if (reset == 1) {
                goto number1;          //number1 is in line 175

            }
            else {
                check = 0;
                break;             //to return to the main menu
            }

        number1:                                     //to check all conditions again
            cout << "Please enter the account number:";
            cin >> test.card_number;
            while (strlen(test.card_number) != 10) {                      //to check that the user didn't enter more or less than 10 numbers
                cout << "you entered a wrong number\n";
                cout << "Please enter the account number:";
                cin >> test.card_number;
                cout << endl;


            }
            for (i = 0; i < 100; i++) {
                if (strcmp(test.card_number, account[i].card_number) == 0)         //to search for the account with the entered card number
                {
                anothor_input:
                    cout << "Please enter the amount to be deposited:";
                    cin >> new_amount;
                    while ((!cin) || (cin.peek() != '\n'))                          //to avoid entering any charcters other than numbers
                    {
                        cout << "\n\n INCORRECT INPUT! \n\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                        cout << "Please enter the amount to be deposited:";
                        cin >> new_amount;
                    }
                    cin.ignore();
                    while (new_amount < 0) {                            //to avoid entering negative numbers
                        cout << "\ndon't enter negative numbers\n\n";
                        goto anothor_input;              //ananothor_input is in line 189
                    }
                    account[i].amount += new_amount + 0.01 * new_amount;
                    return i;
                    break;
                }
            }
        }
    }

    int Withdrawal(ATM account[], ATM& test, int& check) {
        check = 1;                                                 //to check that an account has been withdrawaled to print its information
        cout << "Please enter the account number:";
        cin >> test.card_number;
        while (strlen(test.card_number) != 10) {                                 //to check that the user didn't enter more or less than 10 numbers
            cout << "you entered a wrong number\n";
            cout << "Please enter the account number:";
            cin >> test.card_number;
            cout << endl;


        }
        int i;
        for (i = 0; i < 100; i++) {
            int reset;                                                                //to let the user choose between continue with this operation or another
            if (strcmp(test.card_number, account[i].card_number) == 0)                //to search for the account with the entered card number
            {
            anthor_input:
                cout << "Please enter the amount to be withdrawn: ";
                cin >> new_amount;
                while ((!cin) || (cin.peek() != '\n'))
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                    cout << "Please enter the amount to be withdrawn: ";
                    cin >> new_amount;
                }
                while (account[i].amount < (new_amount + 0.03 * new_amount)) {                     //to check that the user has enough money
                    cout << " No enough amount to withdrawal your current amount is " << account[i].amount << endl;
                    cout << " If you want to withdrawal another amount enter 1" << endl;
                    cout << " If you want to continue with another process enter 2" << endl;
                    cin >> reset;
                    while ((!cin) || (cin.peek() != '\n'))
                    {
                        cout << "\n\n INCORRECT INPUT! \n\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                        cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                        cin >> reset;
                    }

                    while (reset != 1 && reset != 2) {                         //to let the user choose between continue with this operation or another
                        cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                        cin >> reset;
                        while ((!cin) || (cin.peek() != '\n'))
                        {
                            cout << "\n\n INCORRECT INPUT! \n\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                            cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                            cin >> reset;
                        }

                    }
                    if (reset == 1) {                                          //to retry the process with new input
                        cout << "Please enter the amount to be withdrawn: ";
                        cin >> new_amount;
                        while ((!cin) || (cin.peek() != '\n'))
                        {
                            cout << "\n\n INCORRECT INPUT! \n\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                            cout << "Please enter the amount to be withdrawn: ";
                            cin >> new_amount;
                        }
                    }
                    else {
                        cout << " Your account information is " << endl;
                        return i;                                       //to print user informations if his account exists
                    }

                }
                while (new_amount < 0) {                                 //to ignore negative numbers
                    cout << "\ndon't enter negative numbers\n\n";
                    goto anthor_input;
                }
                account[i].amount -= (new_amount + 0.03 * new_amount);
                return i;
                break;
            }
        }
        while (i == 100) {                                         //if account doesn't exist i will be 100 from the above loop
            cout << "\nNo matching account\n\n";
            int reset;
            cout << " If you want to write another account number press 1\n" << endl;
            cout << " If you want to continue with another process enter 2\n" << endl;
            cin >> reset;                                                   //to re-enter another card number or continue with another process
            while ((!cin) || (cin.peek() != '\n'))
            {
                cout << "\n\n INCORRECT INPUT! \n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
            }

            while (reset != 1 && reset != 2) {
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
                while ((!cin) || (cin.peek() != '\n'))
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                    cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                    cin >> reset;
                }

            }
            if (reset == 1) {
                goto number1;                   //go to line 338

            }
            else {
                check = 0;                                           //make check equal zero to not print information
                break;
            }
        number1:
            cout << "Please enter the account number:";
            cin >> test.card_number;
            while (strlen(test.card_number) != 10) {                                //to check that the user didn't enter more or less than 10 numbers
                cout << "you entered a wrong number\n";
                cout << "Please enter the account number:";
                cin >> test.card_number;
                cout << endl;
                //  amount=0;

            }
            for (i = 0; i < 100; i++) {
                if (strcmp(test.card_number, account[i].card_number) == 0)                 //to search for the account with the entered card number
                {
                    int reset;
                new_input:
                    cout << "Please enter the amount to be withdrawn: ";
                    cin >> new_amount;
                    while ((!cin) || (cin.peek() != '\n'))
                    {
                        cout << "\n\n INCORRECT INPUT! \n\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                        cout << "Please enter the amount to be withdrawn: ";
                        cin >> new_amount;
                    }
                    while (account[i].amount < (new_amount + 0.03 * new_amount)) {
                        cout << " No enough amount to withdrawal your current amount is " << account[i].amount << endl;
                        cout << " If you want to withdrawal another amount enter 1" << endl;
                        cout << " If you want to continue with another process enter 2" << endl;
                        cin >> reset;
                        while ((!cin) || (cin.peek() != '\n'))
                        {
                            cout << "\n\n INCORRECT INPUT! \n\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                            cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                            cin >> reset;
                        }

                        while (reset != 1 && reset != 2) {
                            cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                            cin >> reset;
                            while ((!cin) || (cin.peek() != '\n'))
                            {
                                cout << "\n\n INCORRECT INPUT! \n\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                                cin >> reset;
                            }

                        }
                        if (reset == 1) {
                            cout << "Please enter the amount to be withdrawn: ";
                            cin >> new_amount;
                        }
                        else {
                            cout << " Your account information is " << endl;
                            return i;
                        }

                    }
                    while (new_amount < 0) {
                        cout << "\ndon't enter negative numbers\n\n";
                        goto new_input;
                    }
                    account[i].amount -= (new_amount + 0.03 * new_amount);
                    return i;
                    break;
                }
            }
        }


    }
    void Transfer(ATM account[], ATM& sending, ATM& receiving, int& a, int& b, int& check) {
        check = 1;
        cout << "please enter the number of the sending account: ";
        cin >> sending.card_number;
        while (strlen(sending.card_number) != 10) {                             //to check that the user didn't enter more or less than 10 numbers
            cout << "you entered a wrong number\n";
            cout << "please enter the number of the sending account: ";
            cin >> sending.card_number;
            cout << endl;
            //  amount=0;

        }
        int i;
        for (i = 0; i < 100; i++) {
            if (strcmp(sending.card_number, account[i].card_number) == 0)                //to search for the account with the entered card number
            {
                a = i;                      //to get the location of the account in the array
                break;
            }
        }
        while (i == 100) {
            cout << "\nNo matching account\n\n";
            int reset;
            cout << " If you want to write another account number press 1\n" << endl;
            cout << " If you want to continue with another process enter 2\n" << endl;
            cin >> reset;
            while ((!cin) || (cin.peek() != '\n'))
            {
                cout << "\n\n INCORRECT INPUT! \n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
            }

            while (reset != 1 && reset != 2) {
                cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                cin >> reset;
                while ((!cin) || (cin.peek() != '\n'))
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                    cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                    cin >> reset;
                }

            }
            if (reset == 1) {
                goto number1;                 //go to line 475

            }
            else {
                check = 0;
                break;
            }
        number1:
            cout << "please enter the number of the sending account: ";
            cin >> sending.card_number;
            while (strlen(sending.card_number) != 10) {                                 //to check that the user didn't enter more or less than 10 numbers
                cout << "you entered a wrong number\n";
                cout << "please enter the number of the sending account: ";
                cin >> sending.card_number;
                cout << endl;
                //  amount=0;

            }
            for (i = 0; i < 100; i++) {
                if (strcmp(sending.card_number, account[i].card_number) == 0)                            //to search for the account with the entered card number
                {
                    a = i;                                       //to get the location of the account in the array
                    break;
                }
            }
        }
        if (check == 1) {                   //to check that a sending account has been detected
        re_enter: cout << "please enter the number of the receiving account: ";
            cin >> receiving.card_number;
            while (strlen(receiving.card_number) != 10) {                             //to check that the user didn't enter more or less than 10 numbers
                cout << "you entered a wrong number\n";
                cout << "please enter the number of the receiving account: ";
                cin >> receiving.card_number;
                cout << endl;
                //  amount=0;

            }
            int q = 0;
            for (int same = 0; same < 10; same++) {

                if (receiving.card_number[same] == sending.card_number[same])
                {
                    q++;
                }

            }
            if (q == 10) {
                cout << "\n you can't enter the same number for the sender and the receiver\n\n";
                goto re_enter;                    //go to line 495
            }
            for (i = 0; i < 100; i++) {
                if (strcmp(receiving.card_number, account[i].card_number) == 0)                    //to search for the account with the entered card number
                {
                    b = i;                        //to get the location of the account in the array
                    break;
                }
            }
            while (i == 100) {
                cout << "\nNo matching account\n\n";
                int reset;
                cout << " If you want to write another account number press 1\n" << endl;
                cout << " If you want to continue with another process enter 2\n" << endl;
                cin >> reset;
                while ((!cin) || (cin.peek() != '\n'))
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                    cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                    cin >> reset;
                }

                while (reset != 1 && reset != 2) {
                    cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                    cin >> reset;
                    while ((!cin) || (cin.peek() != '\n'))
                    {
                        cout << "\n\n INCORRECT INPUT! \n\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                        cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                        cin >> reset;
                    }

                }
                if (reset == 1) {
                    goto num1ber;

                }
                else {
                    check = 0;
                    break;
                }
            num1ber:
                cout << "please enter the number of the receiving account: ";
                cin >> receiving.card_number;
                while (strlen(sending.card_number) != 10) {                             //to check that the user didn't enter more or less than 10 numbers
                    cout << "you entered a wrong number\n";
                    cout << "please enter the number of the receiving account: ";
                    cin >> receiving.card_number;
                    cout << endl;


                }
                q = 0;
                for (int same = 0; same < 10; same++) {          //to avoid entering the same card number in sending and receiving accounts

                    if (receiving.card_number[same] == sending.card_number[same])
                    {
                        q++;
                    }

                }
                if (q == 10) {
                    cout << "\n you can't enter the same number for the sender and the receiver\n\n";
                    goto re_enter;                               //go to line 495
                }
                for (i = 0; i < 100; i++) {
                    if (strcmp(receiving.card_number, account[i].card_number) == 0)                              //to search for the account with the entered card number
                    {
                        b = i;
                        break;
                    }
                }
            }
            if (check == 1) {
            new_input:
                cout << "please enter the amount to be transferred:  ";
                cin >> new_amount;
                while ((!cin) || (cin.peek() != '\n'))
                {
                    cout << "\n\n INCORRECT INPUT! \n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                    cout << "please enter the amount to be transferred:  ";
                    cin >> new_amount;
                }
                while (account[a].amount < (new_amount + 0.015 * new_amount)) {
                    cout << " No enough amount FOR TRASFER your current AMOUNT IS " << account[a].amount << endl;
                    cout << " If you want to TRANSFER another amount enter 1" << endl;
                    cout << " If you want to CONTINUE with another process enter 2" << endl;
                    int reset;
                    cin >> reset;
                    while ((!cin) || (cin.peek() != '\n'))
                    {
                        cout << "\n\n INCORRECT INPUT! \n\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                        cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                        cin >> reset;
                    }

                    while (reset != 1 && reset != 2) {
                        cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                        cin >> reset;
                        while ((!cin) || (cin.peek() != '\n'))
                        {
                            cout << "\n\n INCORRECT INPUT! \n\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\n ENTER ONLY NUMBER WITHOUT ANY LETTERS \n\n";
                            cout << " PLEASE CHOOSE JUST 1 OR 2 ";
                            cin >> reset;
                        }

                    }
                    if (reset == 1) {
                        cout << "Please enter the amount to be TRANSFERED: ";
                        cin >> new_amount;
                        while ((!cin) || (cin.peek() != '\n'))
                        {
                            cout << "\n\n INCORRECT INPUT! \n\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n\n ENTER ONLY NUMBERS (0:9) WITHOUT ANY LETTERS \n\n";
                            cout << "please enter the amount to be transferred:  ";
                            cin >> new_amount;
                        }
                    }
                    else {
                        cout << " The accounts information (without any change in amount) is " << endl;
                        return;
                    }
                }
                while (new_amount < 0) {
                    cout << "\ndon't enter negative numbers\n\n";
                    goto new_input;               //go to line 596
                }
                account[a].amount -= (new_amount + 0.015 * new_amount);
                account[b].amount += (new_amount - 0.015 * new_amount);
            }
        }
    }
    void Print_acc_data() {
        cout << "name: " << account_name << endl;
        cout << "Card number: " << card_number << endl;
        cout << "amount: " << amount << endl;


    }
    void search(ATM account[], ATM& test, int searcht) {               //to search for another accounts with the same card number (to be a unique card number in every account)
        int i = 0;
        while (i < 100) {                               //to search in the 100 account for the same card number
            if (i == searcht) {                         //to avoid checking with the same account index
                i++;
                continue;
            }


            while (strcmp(test.card_number, account[i].card_number) == 0) {         //to search for the account with the entered card number
                cout << "\nyou entered a reserved number\n\n`" << endl;
            check2:  cout << "Please enter the account number:";
                cin >> test.card_number;
            check: for (int v = 0; v < strlen(test.card_number); v++) {
                int f = test.card_number[v];
                while ((f < 48 || f > 57)) {
                    cout << "\nINVALID ACCOUNT NUMBER\n\n";
                    cout << "please enter the account number:";
                    cin >> test.card_number;
                    goto check;                  //go to line 685
                }

            }
            while (strlen(test.card_number) != 10) {                       //to check that the user didn't enter more or less than 10 numbers
                cout << "you entered a wrong number\n";
                cout << "Please enter the account number:";
                cin >> test.card_number;
                cout << endl;
                amount = 0;
                goto check;                     //go to line 685
            }
            int count = 0;
            for (int k = 1; k < 10; k++) {
                if (card_number[k] == card_number[0])
                    count++;

            }
            if (count == 9) {
                cout << " INVALID YOU CAN'T CHOOSE CARD NUMBER WITH ONE REAPETED NUMBERS ONLY" << endl << endl;
                count = 0;
                goto check2;                 //go to line 683
            }
            }
            i++;

        }

    }
};
int main() {
    ATM account[100];                      //100 accounts of the atm
    int number_of_accounts = 0;            //to count number of accounts
    char operation[2] = "0";               //equals zero to enter the loop
    while (strcmp(operation, "5")) {       //to exit if the operation number equals 5
        cout << "1----Create new account\n" << "2----Deposit\n" << "3----transfer to another account\n" << "4----withdrawal\n" << "5----exit\n" << endl;
        cout << "Please enter the number of operation: ";
        cin >> operation;
        while (strlen(operation) != 1) {                                    //to check that the user didn't enter more than one charcter
            cout << "\n Wrong input!\n";
            cout << "Please enter the number of operation: ";
            cin >> operation;
        }
        if (strcmp(operation, "1") == 0) {
            if (number_of_accounts >= 100) {
                cout << endl;
                cout << endl;
                cout << "-------  you can't create a new account  -------\n";
                cout << "-------  choose another operation  -------\n";
                cout << endl;
                cout << endl;
                continue;
            }
            account[number_of_accounts].create_new_acc();
            account[number_of_accounts].search(account, account[number_of_accounts], number_of_accounts);//to check that the card number is unique

            account[number_of_accounts].Print_acc_data();
            number_of_accounts++;

        }
        else if (strcmp(operation, "2") == 0) {
            if (number_of_accounts >= 1) {             //if there is no accounts make the user create an account before use
                int j;
                int check;
                ATM deposit;
                j = deposit.Deposit(account, deposit, check);
                if (check == 1) {                      //to print data if it has been deposited or entered a correct card number
                    account[j].Print_acc_data();
                }
            }
            else cout << " \n NO DATA FOR ACCOUNTS TO BE DEPOSITED CREATE NEW ACCOUNT AND DO THAT  " << endl << endl;
        }
        else if (strcmp(operation, "3") == 0) {
            if (number_of_accounts >= 2) {              //if there is no enough accounts make the user create an account before use
                int send, rec;
                int check;
                ATM transfer;
                ATM sender;
                ATM receiver;
                transfer.Transfer(account, sender, receiver, send, rec, check);
                if (check == 1) {                                 //to print data if it has been transfered or entered a correct card numbers
                    cout << "sending account: \n";
                    account[send].Print_acc_data();
                    cout << "receiving account: \n";
                    account[rec].Print_acc_data();
                }

            }
            else cout << " \n NO DATA FOR ACCOUNTS FOR TRANSFERING CREATE NEW ACCOUNTS AND DO THAT " << endl << endl;
        }
        else if (strcmp(operation, "4") == 0) {
            if (number_of_accounts >= 1) {           //if there is no accounts make the user create an account before use
                int j;
                int check;
                ATM withdrawal;
                j = withdrawal.Withdrawal(account, withdrawal, check);
                if (check == 1) {                              //to print data if it has been withdrawaled or entered a correct card number
                    account[j].Print_acc_data();
                }
            }
            else cout << " \n NO DATA FOR ACCOUNTS TO BE WITHDRAWALED CREATE NEW ACCOUNT AND DO THAT  " << endl << endl;
        }
        else if (strcmp(operation, "5") == 0) {           //to exit the program if operation = 5
            cout << endl;
            cout << "            Thank you!             ";
            cout << endl;
            cout << endl;
            continue;
        }
        else if (operation > "5" || operation < "1") {      //to enter only numbers between 1 and 5
            cout << endl;
            cout << "NOT VALID";
            cout << endl;
            cout << endl;
            continue;
        }
    }
    return 0;
}
