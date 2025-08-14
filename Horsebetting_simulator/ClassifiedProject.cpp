#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>


class Probability
{
    int numerator;
    int denominator;
public:

    Probability()
    {
        numerator = 1;
        denominator = 1;
    }
    Probability(int nmr, int dnm)
    {
        numerator = nmr;
        denominator = dnm;
    }
    friend ostream& operator<<(ostream& out, Probability& prob)
    {
        out << prob.numerator << '/' << prob.denominator;
        return out;
    }
    friend istream& operator>>(istream&in, Probability&prob)
    {
        char c1;
        in >> prob.numerator >> c1 >> prob.denominator;
        if (c1 != '/')
        {cout << "\nFraction is not correctly written, use '1/2' format only!";}
        else
        {return in;}
    }
    ~Probability()
    {}

    int GetNumerator()
    {return numerator;}
    int GetDenominator()
    {return denominator;}

    void GetValue()
    {cout << numerator << "/" << denominator;}

    void SetNumerator(int n)
    {numerator = n;}
    void SetDenominator(int d)
    {denominator = d;}

    void SetValue()
    {
        cin >> numerator;
        cout << "/";
        cin >> denominator;
    }
};
class Money 
{
    double balance;
    char currency;
public:
    Money()
    {
        balance = 0;
        currency = '$';
    }
    Money(double m,char c)
    {
        balance = m;
        currency = c;
    }
    friend ostream& operator<<(ostream& out, Money& cash)
    {
        out << cash.balance << cash.currency;
        return out;
    }
    friend istream& operator>>(istream& in, Money& cash)
    {
        int checkmoney = 0;
        char b1;
        while (checkmoney != 1)
        {
            in >> cash.balance >> b1;
            if ((b1 == '$') || (b1 == '₴') || (b1 == '£') || (b1 == '€'))
            {
                return in;
                checkmoney = 1;
            }
            else if(b1==' ')
            {
              cout << "\nCouldn't recognize the currency, use '30$' format only!\n"; 
            }
            else
            {
                cout << "\nCouldn't recognize the currency, use '30$' format only!\n";
            }
        }
    }
    Money& operator=(Money& cash)
    {
        if (this != &cash)
        {
            balance = cash.balance;
            currency = cash.currency;
        }
        return *this;
    }
    Money operator+(Money&cash)
    {
        Money temp;
        temp.balance = balance + cash.balance;
        return temp;
    }
    Money operator-(Money& cash)
    {
        Money temp;
        temp.balance = balance - cash.balance;
        return temp;
    }
    Money operator+=(Money&cash)
    {
        balance += cash.balance;
        return *this;
    }
    Money operator-=(Money& cash)
    {
        balance -= cash.balance;
        return *this;
    }
    ~Money()
    {}

    void SetBalance(double m)
    {balance = m;}
    double GetBalance()
    {return balance;}

    
    void DisplayBalance(Money Bal)
    {
        unsigned char c = 442;
        unsigned char l = 457;
        unsigned char r = 456;
        unsigned char s = 443;
        unsigned char k = 444;
               cout<<"\n\n         BALANCE"<<endl;
        cout << l << "~~~~~~~~~~~~~~~~~~~~~~" << s << endl;
        cout << c << "                      " << c << endl;
        cout << c << "        "<<Bal<<"         "  << endl;
        cout << c << "                      " << c << endl;
        cout << r << "~~~~~~~~~~~~~~~~~~~~~~" << k << endl;
    }
    
};

class Horse
{
    char* name;
    int number;
public:
    Horse()
    {
        name = new char[20];
        strcpy_s(name, 20, "somename");
        number = 0;
    }
    Horse(char* Name, int N)
    {
        name = new char[strlen(Name)+1];
        int v = (strlen(Name) + 1);
        strcpy_s(name, v, Name);
        number = N;
    }
     Horse& operator=(Horse& c)
     {
         if (this !=&c)
         {
             delete[]name;
             int n = strlen(c.name) + 1;
             name = new char[n];
             strcpy_s(name, n, c.name);
             number = c.number;
         }
         return *this;
     }
    ~Horse()
    {
        if (name)
            delete[]name;
    }

    char* GetName()
    {
    return name;
    cout << name;
    }
    int GetNumber()
    {return number;}

void DisplayHorseInfo()
    {
        unsigned char c=442;
        unsigned char l = 457;
        unsigned char r = 456;
        GetName();
        int n = GetNumber();
        cout << l<<"============================"<<endl;
        cout << c<<" NAME:" << GetName()<<"   Number:["<<n<<"]   "<<endl;
        cout <<r<< "============================";      
    }

int nextposition(int pos) //this function will generate a random number between 1 and 3 and move the horse accordingly 
    {
        cout << GetName()<< ": ";
        pos = pos + rand() % 3 + 1; 
        for (int b = 0;b <= pos;b++)
        cout << " ";
        cout << "~ww^";
        cout << endl << endl;
        return pos;
    }
};

int CheckBet(Money GenBal, Money Bet)
    {
        int checkbet = 0;
        double generalbal = GenBal.GetBalance();
        double bet1 = Bet.GetBalance();
        if (bet1 > generalbal)
        {
            cout << "\nNot enough money to place the bet! Your balance is: "<<generalbal<<"$\n";
            return checkbet = 0;
        }
        else 
        {
            return checkbet = 1;
        }
    }


void DrawHorse()
{
    unsigned char c = 442; // side |
    unsigned char l = 457; // top left corner  
    unsigned char r = 456; // lower left corner
    unsigned char s = 443; // top right corner
    unsigned char k = 444; // lower right corner
    cout <<l<<"========================="<<s<<endl;
    cout <<c<<"             A_A         "<<c<<endl;
    cout <<c<<"            /$ $)        "<<c<<endl;
    cout <<c<<"     ______/ (___)       "<<c<< endl;
    cout <<c<<" o~~(            )       "<<c<< endl;
    cout <<c<<"    (  ____ _  _/        "<<c<< endl;
    cout <<c<<"    | / |  | | |         "<<c<<endl;
    cout <<c<<"    (_]_)  (_|_)         "<<c<< endl;
    cout <<r<<"========================="<<k<< endl;
}
void PrintInfoAuthor()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;

    cout << "\n\n\n";
    cout << "                                 " << "         " << "ABOUT AUTHOR\n";
    cout << "                                 " << l << "================================" << s << endl;
    cout << "                                 " << c << "     This game was developed,   " << c << endl;
    cout << "                                 " << c << "  designed, tested and released " << c << endl;
    cout << "                                 " << c << "  by the students of KPI, IASA  " << c << endl;
    cout << "                                 " << c << "           team 33              " << c << endl;
    cout << "                                 " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                                 " << c << "   Any unauthorized use or      " << c << endl;
    cout << "                                 " << c << "   non-licensed reproduction    " << c << endl;
    cout << "                                 " << c << "   of this work is strictly     " << c << endl;
    cout << "                                 " << c << "   prohibited, and will be a    " << c << endl;
    cout << "                                 " << c << "   copyright violation          " << c << endl;
    cout << "                                 " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                                 " << c << "         Kyiv, year 2023        " << c << endl;
    cout << "                                 " << r << "================================" << k << endl;
    cout << "\n\n\n";
}
void PrintMenu()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;
    
    cout << "\n\n\n";
    cout << "                                 " << "             " << "MENU\n";
    cout << "                                 " << l << "================================" << s << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       1)Start new game         " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       2)Continue game          " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       3)About author           " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       4)Instructions           " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       5)Exit                   " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << r << "================================" << k << endl;
    cout << "\n\n\n";
    
}
void PrintInstructons()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;

    cout << "\n\n\n";
    cout << "                    " << "                     " << "INSTRUCTIONS\n";
    cout << "                    " << l << "======================================================" << s << endl;
    cout << "                    " << c << " 1)How to use MENU: Press 1-for starting a new game;  " << c << endl;
    cout << "                    " << c << "           Press 2-for continuing the previous game;  " << c << endl;
    cout << "                    " << c << "           Press 3-for printing info about authors;    " << c << endl;
    cout << "                    " << c << "           Press 4-for printing instructions          " << c << endl;
    cout << "                    " << c << "           Press 5-for exiting the program            " << c << endl;
    cout << "                    " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                    " << c << " 2)If you want the program to run successfuly without " << c << endl;
    cout << "                    " << c << " warnings, always follow the directions when entering " << c << endl;
    cout << "                    " << c << " numbers or letters; program always tells you in what " << c << endl;
    cout << "                    " << c << " format it expects you to enter symbol, do exactly as " << c << endl;
    cout << "                    " << c << " it says.If you have entered a wrong number/letter,or " << c << endl;
    cout << "                    " << c << " used inappropriate format, you will have to reenter  " << c << endl;
    cout << "                    " << c << " it after getting a warning.                          " << c << endl;
    cout << "                    " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                    " << c << "                   HAVE A NICE GAME!                  " << c << endl;
    cout << "                    " << r << "======================================================" << k << endl;
    cout << "\n\n\n";

}
void PrintGoodbye()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;
    cout << "\n\n";
    cout << l << "=============================================" << s << endl;
    cout << c << "          Thanks for using my program!       " << c << endl;
    cout << c << "               Have a nice day :)            " << c << endl;
    cout << r << "=============================================" << k << endl;
    cout << "\n\n";
}
Money StartNewGame(Money NewBal1)
{
    char name0[20] = "Gush";     char name5[20] = "Rezzo";
    char name1[20] = "Polisher"; char name6[20] = "Mesa";
    char name2[20] = "Bronxie";  char name7[20] = "Pix";
    char name3[20] = "Chip";     char name8[20] = "Bunker";
    char name4[20] = "Mussel";   char name9[20] = "Hornet";
    char name10[20] = "Swaff";
    char bethorsename[20] = "bethorsename";
    char winhorsename[20] = "winhorsename";

    Horse arr[20];Horse arrX[20];Horse arrM[20]; int pos[200];
    Horse M0(name0, 0);     arr[0] = M0;   arrX[0] = M0;
    Horse M1(name1, 1);     arr[1] = M1;   arrX[1] = M1;
    Horse M2(name2, 2);     arr[2] = M2;   arrX[2] = M2;
    Horse M3(name3, 3);     arr[3] = M3;   arrX[3] = M3;
    Horse M4(name4, 4);     arr[4] = M4;   arrX[4] = M4;
    Horse M5(name5, 5);     arr[5] = M5;   arrX[5] = M5;
    Horse M6(name6, 6);     arr[6] = M6;   arrX[6] = M6;
    Horse M7(name7, 7);     arr[7] = M7;   arrX[7] = M7;
    Horse M8(name8, 8);     arr[8] = M8;   arrX[8] = M8;
    Horse M9(name9, 9);     arr[9] = M9;   arrX[9] = M9;
    Horse M10(name10, 10);  arr[10] = M10; arrX[10] = M10;

    Money Bal(0, '$');  Money BetMoney(0, '$'); Horse BetHorse(bethorsename, 20); Horse WinHorse(winhorsename, 21);


    cout << "WELCOME TO THE HORSEBETTING PROGRAM!" << endl;
    DrawHorse();
    cout << "\n\nSet your starting balance of cash in currency (expected formats [320$]):";
    cin >> Bal;
    Bal.DisplayBalance(Bal);

    cout << "\n\nThere are your horses:" << endl;

    for (int i = 0;i < 11;i++)
    {
        arr[i].DisplayHorseInfo();
        cout << endl;
    }
    cout << "\n\n";

    int F, G, check1 = 0;

    cout << "How many racers will be competing? This determines the difficulty of your game and bet multiplier!" << endl;
    cout << "Number of racers(in range from 2 to 11):";

    while (check1 != 1)
    {
        cin >> G;
        if ((G == 2) || (G == 3) || (G == 4) || (G == 5) || (G == 6) || (G == 7) || (G == 8) || (G == 9) || (G == 10) || (G == 11))
        {
            check1 = 1;
        }
        else
        {
            cout << "Incorrect number, use range (2-11)!" << endl;
        }
    }
    cout << "Select " << G << " horses for the race(use their numbers):" << endl;
    int i = 1;
    while (i <= G)
    {
        cout << "Horse " << i << ": ";
        cin >> F;
        if ((F == 0) || (F == 1) || (F == 2) || (F == 3) || (F == 4) || (F == 5) || (F == 6) || (F == 7) || (F == 8) || (F == 9) || (F == 10))
        {
            cout << endl;
            arrX[F].DisplayHorseInfo();
            arrM[i] = arrX[F];
            cout << endl << endl;
            i++;
        }
        else
        {
            cout << "\nIncorrect number, use horse numbers (0-10)!" << endl;
        }
    }
    Probability P1(1, G);
    cout << "Probability to bet on winner is:" << P1 << "; your $ bet will be multiplied by " << G << "x if successful!\n";
    cout << "Place your bet (expected format [100$]):";
    int check2 = 9;
    while (check2 != 1)
    {
        cin >> BetMoney;
        check2 = CheckBet(Bal, BetMoney);
    }
    Bal -= BetMoney;
    cout << "\n Which horse is fast and lucky enough to win? Pick! (use number):";
    int f;
    int check3 = 0;
    while (check3 != 1)
    {
        cin >> f;
        for (int u = 1;u <= G;u++)
        {
            if (f == arrM[u].GetNumber())
            {
                cout << "\nYour bet: " << BetMoney << " on horse:\n";
                arrM[u].DisplayHorseInfo();
                BetHorse = arrM[u];
                check3 = 1;
            }
        }
        if (check3 != 1)
        {
            cout << "There is no horse with this number!\n";
        }
    }

    Bal.DisplayBalance(Bal);
    char hm;
    int checkstart = 0;
    cout << "\nEnter A to start the race:";
    while (checkstart != 1)
    {
        cin >> hm;
        if ((hm == 'A') || (hm == 'a'))
        {

            cout << "\n\n\n==========================================||  Starting race  ";
            cout << "||=====================================\n\n";

            srand(time(NULL));
            for (int i = 1;i <= G;i++)
            {
                pos[i] = 0;
            }

            for (int a = 0;a <= 85;a++)
            {
                system("cls");
                for (int i = 1;i <= G;i++)
                {
                    pos[i] = arrM[i].nextposition(pos[i]);
                }
                for (int timer = 0;timer <= 1000000;timer++);
            }

            int HighestScoreInd = 0;
            int Win[100];

            for (int y = 1;y <= G;y++)
            {
                Win[y] = pos[y];
            }
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ RESULTS ]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
            for (int P = 1;P <= G;P++)
            {
                arrM[P].DisplayHorseInfo();
                cout << "----->Distance:" << Win[P] << endl;
                if (Win[P] > Win[HighestScoreInd])
                    HighestScoreInd = P;
            }
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            for (int P = 1;P <= G;P++)
            {
                if (Win[P] == Win[HighestScoreInd])
                {
                    cout << "\n\nOUR WINNER IS:  \n";
                    arrM[P].DisplayHorseInfo();
                    WinHorse = arrM[P];
                    cout << "----->Distance:" << Win[P] << endl;
                }
            }
            cout << "\nYour bet: " << BetMoney << " on horse:\n";
            BetHorse.DisplayHorseInfo();

            if (BetHorse.GetNumber() == WinHorse.GetNumber())
            {
                cout << "\n\nGOOD JOB!!!You picked the right horse, your bet " << BetMoney << " is multiplied by " << G;
                double oldbet = BetMoney.GetBalance();
                double newbet = (oldbet * G);
                BetMoney.SetBalance(newbet);
                cout << " and " << BetMoney << " added to your balance, which is now:\n";
                Bal += BetMoney;
                Bal.DisplayBalance(Bal);
                NewBal1 = Bal;
            }
            else
            {
                cout << "\n\nSorry, your bet was unlucky, maybe next time you'll do better :)\n";
                cout << "Your remaining balance:\n ";
                Bal.DisplayBalance(Bal);
                NewBal1 = Bal;
            }
            checkstart = 1;
        }
        else
        {
            cout << "\nUnknown symbol, cant start the race!\n";
        }
    }
    return NewBal1;
}
Money ContinueGame(Money NewBal1)
{
    char name0[20] = "Gush";     char name5[20] = "Rezzo";
    char name1[20] = "Polisher"; char name6[20] = "Mesa";
    char name2[20] = "Bronxie";  char name7[20] = "Pix";
    char name3[20] = "Chip";     char name8[20] = "Bunker";
    char name4[20] = "Mussel";   char name9[20] = "Hornet";
    char name10[20] = "Swaff";
    char bethorsename[20] = "bethorsename";
    char winhorsename[20] = "winhorsename";

    Horse arr[20];Horse arrX[20];Horse arrM[20]; int pos[200];
    Horse M0(name0, 0);     arr[0] = M0;   arrX[0] = M0;
    Horse M1(name1, 1);     arr[1] = M1;   arrX[1] = M1;
    Horse M2(name2, 2);     arr[2] = M2;   arrX[2] = M2;
    Horse M3(name3, 3);     arr[3] = M3;   arrX[3] = M3;
    Horse M4(name4, 4);     arr[4] = M4;   arrX[4] = M4;
    Horse M5(name5, 5);     arr[5] = M5;   arrX[5] = M5;
    Horse M6(name6, 6);     arr[6] = M6;   arrX[6] = M6;
    Horse M7(name7, 7);     arr[7] = M7;   arrX[7] = M7;
    Horse M8(name8, 8);     arr[8] = M8;   arrX[8] = M8;
    Horse M9(name9, 9);     arr[9] = M9;   arrX[9] = M9;
    Horse M10(name10, 10);  arr[10] = M10; arrX[10] = M10;

    Money Bal(0, '$');  Money BetMoney(0, '$'); Horse BetHorse(bethorsename, 20); Horse WinHorse(winhorsename, 21);

    cout << "\n\n Your starting balance of cash is:";
    Bal = NewBal1;
    Bal.DisplayBalance(Bal);

    cout << "\n\nThere are your horses:" << endl;

    for (int i = 0;i < 11;i++)
    {
        arr[i].DisplayHorseInfo();
        cout << endl;
    }
    cout << "\n\n";

    int F, G, check1 = 0, check2 = 0;

    cout << "How many racers will be competing? This determines the difficulty of your game and bet multiplier!" << endl;
    cout << "Number of racers(in range from 2 to 11):";

    while (check1 != 1)
    {
        cin >> G;
        if ((G == 2) || (G == 3) || (G == 4) || (G == 5) || (G == 6) || (G == 7) || (G == 8) || (G == 9) || (G == 10) || (G == 11))
        {
            check1 = 1;
        }
        else
        {
            cout << "Incorrect number, use range (2-11)!" << endl;
        }
    }
    cout << "Select " << G << " horses for the race(use their numbers):" << endl;
    int i = 1;
    while (i <= G)
    {
        cout << "Horse " << i << ": ";
        cin >> F;
        if ((F == 0) || (F == 1) || (F == 2) || (F == 3) || (F == 4) || (F == 5) || (F == 6) || (F == 7) || (F == 8) || (F == 9) || (F == 10))
        {
            cout << endl;
            arrX[F].DisplayHorseInfo();
            arrM[i] = arrX[F];
            cout << endl << endl;
            i++;
        }
        else
        {
            cout << "\nIncorrect number, use horse numbers (0-10)!" << endl;
        }
    }
    Probability P1(1, G);
    cout << "Probability to bet on winner is:" << P1 << "; your $ bet will be multiplied by " << G << "x if successful!\n";
    cout << "Place your bet(expected format [100$]):";
    int check4 = 9;
    while (check4 != 1)
    {
        cin >> BetMoney;
        check4 = CheckBet(Bal, BetMoney);
    }
    Bal -= BetMoney;
    cout << "\n Which horse is fast and lucky enough to win? Pick! (use number):";
    int f;
    int check3 = 0;
    while (check3 != 1)
    {
        cin >> f;
        for (int u = 1;u <= G;u++)
        {
            if (f == arrM[u].GetNumber())
            {
                cout << "\nYour bet: " << BetMoney << " on horse:\n";
                arrM[u].DisplayHorseInfo();
                BetHorse = arrM[u];
                check3 = 1;
            }
        }
        if (check3 != 1)
        {
            cout << "There is no horse with this number!\n";
        }
    }

    Bal.DisplayBalance(Bal);
    char hm;
    int checkstart = 0;
    cout << "\nEnter A to start the race:";
    while (checkstart != 1)
    {
        cin >> hm;
        if ((hm == 'A') || (hm == 'a'))
        {
            cout << "\n\n\n==========================================||  Starting race  ";
            cout << "||=====================================\n\n";

            srand(time(NULL));
            for (int i = 1;i <= G;i++)
            {
                pos[i] = 0;
            }

            for (int a = 0;a <= 85;a++)
            {
                system("cls");
                for (int i = 1;i <= G;i++)
                {
                    pos[i] = arrM[i].nextposition(pos[i]);
                }
                for (int timer = 0;timer <= 1000000;timer++);
            }

            int HighestScoreInd = 0;
            int Win[100];

            for (int y = 1;y <= G;y++)
            {
                Win[y] = pos[y];
            }
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ RESULTS ]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
            for (int P = 1;P <= G;P++)
            {
                arrM[P].DisplayHorseInfo();
                cout << "----->Distance:" << Win[P] << endl;
                if (Win[P] > Win[HighestScoreInd])
                    HighestScoreInd = P;
            }
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            for (int P = 1;P <= G;P++)
            {
                if (Win[P] == Win[HighestScoreInd])
                {
                    cout << "\n\nOUR WINNER IS:  \n";
                    arrM[P].DisplayHorseInfo();
                    WinHorse = arrM[P];
                    cout << "----->Distance:" << Win[P] << endl;
                }
            }
            cout << "\nYour bet: " << BetMoney << " on horse:\n";
            BetHorse.DisplayHorseInfo();

            if (BetHorse.GetNumber() == WinHorse.GetNumber())
            {
                cout << "\n\nGOOD JOB!!!You picked the right horse, your bet " << BetMoney << " is multiplied by " << G;
                double oldbet = BetMoney.GetBalance();
                double newbet = (oldbet * G);
                BetMoney.SetBalance(newbet);
                cout << " and " << BetMoney << " added to your balance, which is now:\n";
                Bal += BetMoney;
                Bal.DisplayBalance(Bal);
                NewBal1 = Bal;
            }
            else
            {
                cout << "\n\nSorry, your bet was unlucky, maybe next time you'll do better :)\n";
                cout << "Your remaining balance:\n ";
                Bal.DisplayBalance(Bal);
                NewBal1 = Bal;
            }
            checkstart = 1;
        }
        else
        {
            cout << "\nUnknown symbol, cant start the race!\n";
        }
    }
    return NewBal1;
}


int main()
{
    int Option=19;
    int XM = 0; int Iteration=0;
    Money NewBal1(0, '$');
  cout << "\n------------------------------ Nice to see you in my program! Lets get started ------------------------------\n\n";
  while (XM!=1)
  {
      PrintMenu();
      
      cin >> Option;

    switch (Option)
    {
      case 1:
      {   
          Iteration = 1;
          system("cls");
          Money m = StartNewGame(NewBal1);
          NewBal1 = m;
          
      }break;
      case 2:
      {
          if (Iteration == 1)
          {
              Money m = ContinueGame(NewBal1);
              NewBal1 = m;
          }
          else
          {
              system("cls");
          cout << "\nYou have no previous games! Create a new one to start\n";
          }
      }break;
      case 3:
      {
          system("cls");
          PrintInfoAuthor();
      }break;
      case 4:
      {
          system("cls");
          PrintInstructons();
      }break;
      case 5:
      {
        system("cls");
        PrintGoodbye();
        XM = 1;
        system("pause");
      }break;
      default:
      {
          system("cls");
          cout << "\nCommand not found! Use numbers 1-5 for selecting commands\n";
      }
    }
  }
    
    
     
     
}

