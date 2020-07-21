#include <iostream>
#include <string.h>
#include <istream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void loginuser();//login for user
void registr();//registering a user **admin**
void forgotuser();//for the user
void mainuser();//main for the user
void mainadmin();//main for the admin
void loginadmin();//login for administation
void step1admin();//first steps for admin
void step1user();//first steps for user
void deposit();//admin deposit money for the user

void withdrawal();//user withdraw cash


void checktable();//check table of transactions for the user
void editchecktable();//only admin can edit the table of transactions



int main()
{
    char opt0;
    cout << "||||||||||||||||||||||||\t\t\||||||||||||||||||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\t\t\t\t\t||\n          ||\n||||||||||||||||||||||||\n"<<endl;
    cout << "-----------------------------------------------------------------------------------------------------\n";
    cout << "\t \t Page 1"<< endl;
    cout << "\t WELCOME TO BMI BANK \n  CUSTOMER SERVICES AVAILABLE HERE"<< endl;
    cout << "Are you : \n";
    cout << "1. Administrator \n";
    cout << "2. Normal user \n";
    cout << "Choose an Option to Proceed: "<<endl;
    cin >> opt0;
    switch (opt0)
    {
        case '1':
            cout << "**********You are an Administrator**********" <<endl;
            step1admin();
            break;
        case '2':
            cout << "**********You are a Normal user**********" <<endl;
            step1user();
            break;
        default:
            system("cls");
            cout << "Error! The option is not invalid.\n\n";
            main();
            break;

    }
    return 0;
}

void step1admin()
{
    system("cls");
    char opt1;
    cout << "Pick one : "<<endl;
    cout << "\t a. login to the admin system"<<endl;
    cout << "\t b. Forgot credentials"<<endl;
    cout << "\t c. main menu"<<endl;
    cout << "\n choose either of the options : ";
     cin >> opt1;

    switch (opt1)
     {

        case 'a':
            cout << "You have selected the login to the admin system option.\n\n";
            loginadmin();
            break;
        case 'b':
            cout << "You have selected the Forgot credentials option.\n\n";

            system("cls");
            cout << "You have selected the Forgot credentials option.\n\n";
            cout << "\t \t !!!!!REPORT YOUR ISSUE TO THE MANAGER WE ARE NOT ALLOWED TO DISPLAY THE BANK'S INFORMATION!!!!!" <<endl;
            cin.get();
            cin.get();
            step1admin();
            break;
         case 'c':
             system("cls");
            cout << "You have selected the main menu." <<endl;
            main();
            break;
        default:
            system("cls");
            cout << "Error! The option is not invalid.\n\n";
            step1admin();
            break;
     }
}

void loginadmin()
{
    system("cls");
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 6)
    {
        cout << "Please enter your admin user name: ";
        cin >> userName;
        cout << "Please enter your admin user password: ";
        cin >> userPassword;

        if (userName == "admin" && userPassword == "admin123")
        {
            system("cls");
            cout << "Welcome admin to the system!\n";
            mainadmin();
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << endl;
            loginAttempt++;
        }
    }
    if (loginAttempt == 6)
    {
            cout << "Too many login attempts! The program will now terminate.";
    }

    cout << "Thank you for logging in.\n";
}

void mainadmin()
{

    char opt1;

    cout << "********************login Successfully********************\n";
    cout << "\t WELCOME \n  ADMINISTRATION SERVICES AVAILABLE HERE"<< endl;
    cout << "You are able to Access to the following options "<<endl;


    cout << "\t a. Deposit money for client \n";
    cout << "\t b. Register a new Client \n";
    cout << "\t c. Change their own admin password from the default" <<endl;
    cout << "\t d. Forgot credentials"<<endl;
    cout << "\t e. Switch user and log out"<<endl;
    cout << "\t f. Build a transaction table and view"<<endl;

    cout << "\n Choose either of the options : ";
    cin >> opt1;

    switch (opt1)
     {

        case 'a':
            cout << "You have selected the Deposit money for client option.\n\n";
            cin.get();
            cin.get();
            deposit();
            break;
        case 'b':
            cout << "You have selected the Register a new Client option.\n\n";
            cin.get();
            cin.get();
            registr();
            break;
        case 'c':
            cout << "You have selected the Reset admin Password option.\n\n";
            cout << "\t \t !!NOTICE!! \n \t !!Unfortunately you will have to report your issue to the manager since this option is terminated !!"<<endl;
            cin.get();
            cin.get();
            break;
        case 'd':
            system("cls");
            cout << "You have selected the Forgot credentials option.\n\n";
              cout << "\t \t !!!!!REPORT YOUR ISSUE TO THE MANAGER WE ARE NOT ALLOWED TO DISPLAY THE BANK'S INFORMATION!!!!!" <<endl;
              cin.get();
              cin.get();
              mainadmin();
            break;
        case 'e':
            system("cls");
            cout << "You have selected switch user and logged out successfully. \n"<<endl;
            main();
        case 'f':
            system("cls");
            cout << "You have selected Build a transaction table and view it option. \n"<<endl;
            editchecktable();
        default:
            system("cls");
            cout << "Error! The option is not invalid.\n\n";
            mainadmin();
            break;
      }

}

void registr()
{
    int age;
    string gender;

    double nationID;
    string reguser, regpass, realname1, realname2;
    system("cls");
    cout << "\t YOU ARE REGISTERING A NEW CLIENT." << endl;
    cout << "1. Type your first name : "<<endl;
    cin >> realname1;
    cout << "2. Type your second name : "<<endl;
    cin >> realname2;
    cout << "3. Your gender please : "<<endl;
    cin >> gender;
    cout << "4. Type your AGE: "<<endl;
    cin >> age;
    cout << "5. Type your National ID number : "<<endl;
    cin >> nationID;
    cout << "Enter the username : \n";
    cin >> reguser;
    cout << "Enter the password : \n";
    cin >> regpass;

    ofstream reg("usersDB.txt", ios::app);
    ofstream host("detailsDB.txt", ios::app);
    host << realname1<< ' '<<realname2 << ' '<<gender << ' '<<age << ' '<<nationID<<endl;
    reg<< reguser <<' '<< regpass<<endl;

    system("cls");
    cout << "Registration is successfull\n";
    mainadmin();
}
void deposit()
{
    char p;
    int memo, logattempt=0;
   double amount;
   string nameuser, a, r;

   system("cls");
   cout << "TOTAL AMOUNT YOU WISH TO DEPOSIT but first"<<endl;
    cout << "Please enter the user's name registered : "<<endl;
    cin >> nameuser;

   ifstream inpi("usersDB.txt");
   while(inpi >>a>>r)
    {
        if(a == nameuser )
        {
            memo = 1;
        }

    }
    inpi.close();

        if (memo == 1)
        {
        cout <<"Hello admin this user is valid in the system : "<<nameuser<< "\nWe're glad that you're still with us\n";
        cin.get();
        cin.get();
        cout << "NOW indicate the TOTAL AMOUNT YOU WISH TO DEPOSIT : "<<endl;
        cin >> amount;

        ofstream amo("depositDB.txt", ios::app);
        amo << amount << '&'<<a<< endl;
         system("cls");
         cout << "YOU HAVE SUCCESSFULLY DEPOSITED :" << amount << " in :" << nameuser << "'s Account\n"<<endl;
         mainadmin();

        }

        else
    {
            system("cls");
            cout << "Invalid username attempt. This person is not in the system yet. \nPlease try again till u get the person you want to deposit for \n" << endl;
            cout << "So do you want to continue" <<endl;
            cout << "1. Return to the admin menu" <<endl;
            cout << "2. Continue" <<endl;
            cin >> p;
               switch (p)
               {
              case '1':
                  system("cls");
                mainadmin();

              case '2':
                 deposit();
               }
    }

}


void step1user()
{
    system("cls");
    char opt1;
    cout << "\t a. Login to the user system"<<endl;
    cout << "\t b. Forgot credentials"<<endl;
    cout << "\t c. main menu"<<endl;
    cout << "\n choose either of the options : "<<endl;
     cin >> opt1;

    switch (opt1)
     {

        case 'a':
            system("cls");
            cout << "You have selected the Login to the user system option.\n\n";
            cin.get();
            cin.get();
            loginuser();
            break;
        case 'b':
            system("cls");
            cout << "You have selected the Forgot credentials option.\n\n";
            cin.get();
            cin.get();
            forgotuser();
            break;
         case 'c':
             system("cls");
            cout << "You have selected the main menu." <<endl;
            main();
            break;

        default:
            system("cls");
            cout << "Error! The option is not invalid.\n\n";
            step1user();
            break;
     }
}

void loginuser()
{
    int exist, loginattempt=0;
    string username, password, u, p;
    system ("cls");
        cout << "YOU NEED TO LOGIN FIRST TO YOUR ACCOUNT." << endl;
        cout << "Please enter your username: "<<endl;
        cin >> username;
        cout << "Please enter your user password: "<<endl;
        cin >>password;

        ifstream input("usersDB.txt");

    while(input >>u>>p)
    {
        if(u == username && p == password)
        {
            exist = 1;
        }

    }
    input.close();
        if (exist == 1)
        {
        cout <<"Hello "<<username<< "\nWe're glad that you're here\n";
        cin.get();
        cin.get();
        mainuser();
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << endl;
            cin.get();
            cin.get();
            step1user();
        }
}

void checktable()
{
    string hori[3]= {"Min(KSHs.)\t", "Max(KSHs.)\t", "Laser charges\t"};
    int verti[5][3]= {{200,2500,34}, {2501, 5000, 67}, {5001, 10000, 112},{10001,20000,197},{20001,50000,244}};

    cout << hori[0] << hori[1] <<hori[2] <<endl;

    for(int row = 0; row <5; row++)
    {
        for(int col = 0; col <3; col++)
        {
            cout << verti[row][col] << "\t \t";
        }
        cout << endl;
    }
    cout << "Returning to users menu : "<<endl;
    cin.get();
    cin.get();
    cin.get();
    mainuser();
}


void mainuser()
{
    char opt1;
    system("cls");
    cout << "********************login Successfully********************\n";
    cout << "\t WELCOME \n  USER'S SERVICES AVAILABLE HERE"<< endl;
    cout << "You are able to Access to the following options "<<endl;

    cout << "\t a. Withdraw cash \n";
    cout << "\t b. Check your account balance \n";
    cout << "\t c. Change your own user's password from the default" <<endl;
    cout << "\t d. Forgot credentials"<<endl;
    cout << "\t e. Switch user"<<endl;
    cout << "\t f. Look at the bank's Transaction Table."<<endl;
    cout << "\n choose either of the options : ";
    cin >> opt1;

    switch (opt1)
     {
        case 'a':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected the Withdraw cash option.\n\n";
             withdrawal();
            break;
        case 'b':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected the Check your account balance option.\n\n";

            break;
        case 'c':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected the Reset user's Password option.\n\n";

            break;
        case 'd':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected the Forgot credentials option.\n\n";
            forgotuser();
            break;
        case 'e':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected switch user. \n"<<endl;
            main();
            break;
        case 'f':
            system("cls");
            cin.get();
            cin.get();
            cout << "You have selected Look at the bank's Transaction Table. \n"<<endl;
            checktable();
            break;
        default:
            system("cls");
            cout << "Error! The option is not invalid.\n\n";
            mainuser();
            break;
      }

}
void editchecktable()
{

   int a,b,c,d,e;
     cout << "THE CHARGES MADE IN TRANSACTIONS\n";
     cout << "For charges running between 200 - 2,500 : "<<endl;
     cin >> a;
      cout << "For charges running between 2,501 - 5,000 : "<<endl;
     cin >>b;
      cout << "For charges running between 5,001 - 10,000 : "<<endl;
     cin >>c;
      cout << "For charges running between 10,001 - 20,000 : "<<endl;
     cin >>d;
      cout << "For charges running between 20,001 - 50,000 : "<<endl;
     cin>>e;
    string hori[3]= {"Min(KSHs.)\t", "Max(KSHs.)\t", "Laser charges\t"};
    int verti[5][3]= {{200,2500,a}, {2501, 5000, b}, {5001, 10000, c},{10001,20000,d},{20001,50000,e}};

    cout << hori[0] << hori[1] <<hori[2] <<endl;

    for(int row = 0; row <5; row++)
    {
        for(int col = 0; col <3; col++)
        {
            cout << verti[row][col] << "\t \t";
        }

        cout << endl;
    }
   cout << "you will Return to the admin's Menu page\n";
cin.get();
cin.get();
system("cls");
cout << "You are from the transaction page\n";
mainadmin();

}
void withdrawal()
{
    char w;
    int memo1=0, memo2=0;
    double num1, num2, balance, z, store;
    string myname, mypassword, t, u, h;
    cout << "**********HOW MUCH DO YOU WANT TO WITHDRAW?**********" <<endl;

    cout << "We need to confirm if it is really you" <<endl;
    cout << "Your username first : " <<endl;
    cin >> myname;
    cout << "Your password : "<<endl;
    cin >> mypassword;

    ifstream papa("usersDB.txt");
    while(papa>>t>>u)
    {
        if(t == myname && u ==mypassword)
        {
            memo1 = 1;
            break;
        }
    }
    papa.close();

    if (memo1 == 1)
        {
        cout <<"Successfully verified\n for sure you are valid in the system as : "<<myname<< "\nWe're glad that you're still with us\n";
        cin.get();
        cin.get();
        cout << "HOW MUCH DO YOU WANT TO WITHDRAW?" <<endl;
        cout << "NOW indicate the TOTAL AMOUNT YOU WISH TO WITHDRAW : "<<endl;
        cin >>num1;
        system("cls");
        cout << "Successfully withdrawn : "<<endl;
        mainuser();


    }

     else
    {
            system("cls");
            cout << "Invalid username attempt. This person is not YOU. \nPlease try again till you get your username correct"<< endl;
            cout << "So do you want to continue" <<endl;
            cout << "1. Return to the user menu" <<endl;
            cout << "Continue - use any number " <<endl;
            cin >> w;
               switch (w)
               {
              case '1':
                  system("cls");
                mainuser();
                break;

            default:
            withdrawal();
            break;
               }

}
}

void forgotuser()
{
    int ch;//choice
    system("cls");
    cout << "1. Search your account by username ";
    cout << "\n2. Search your account password ";
    cout << "\n3. Mainmenu where you switch to users ";
    cout << "\nEnter your choice : ";
    cin >> ch;

    switch(ch)
    {
    case 1:{
        int ex = 0;
        string searchuser,su,sp;
        cout << "Enter your remembered username : ";
        cin >> searchuser;

        ifstream searchu("usersDB.txt");
        while (searchu >>su>>sp)
        {
            if(su == searchuser )
            {
               ex =1;
               break;
            }
        }
        searchu.close();
        if (ex == 1)
        {
            cout << "Hurray! Account found !\n";
            cout << "Your password is : "<<sp;
            cin.get();
            cin.get();
            step1user();
        }
        else
        {
            cout << "Sorry, your account is not found \n";
            cin.get();
            cin.get();

            step1user();
        }
        break;}

    case 2:{
        int exi =0;
        string searchpass, su2,sp2;
        cout << "enter the remembered password : ";
        cin >> searchpass;

        ifstream searchp("usersDB.txt");
        while(searchp>>su2>>sp2)
        {
            if(sp2 == searchpass)
            {
                exi = 1;
                break;
            }
        }
        searchp.close();
        if(exi == 1)
        {
            cout << "hurray! the account found \n";
            cout << "YOUR USERNAME IS : " <<su2 <<endl;
            cout << "YOUR PASSWORD IS : " <<sp2 <<endl;
            cin.get();
            cin.get();
            step1user();
        }
        else
        {
            cout << "Sorry, your password does not march with any account. \n";
            cin.get();
            cin.get();

            step1user();
        }
        break;}
    case 3:{
        main();
        }
        break;
    default:{
        cout << "You have given a wrong choice. Press a key to try again.";
        cin.get();
        cin.get();
        forgotuser();
    }}
}



