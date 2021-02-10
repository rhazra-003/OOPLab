#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

const double pi = 3.1415926;

//for cosine function

void cos_func()
{
    cout << "Enter the domain of the function in degrees: " << endl;
    double lower{}, upper{};
    int step{};
    char c{};

    cout << "Lower Boundary: ";       
    cin >> lower;
    cout << "Upper Boundary: ";       
    cin >> upper;
    cout << "Enter the step length: ";     
    cin >> step;
    cout << "Enter the fill character: ";  
    cin >> c;

    cout << endl << endl;

    double i = lower, interval = (upper - lower)/step;

    while(i <= upper)
    {
        int val = floor(cos((i*pi)/180) * 50);

        if(val>=0)
        {
            cout << setw(60) << setfill(' ') << "||" << setw(val) << setfill(c) << '*' << endl;
        }
        else
        {
            val = abs(val);
            cout << setw(60-val) << setfill(' ') << '*' << setw(val) << setfill(c) << "||" << endl ;
        }

        i = i + interval;
    }
}

//for exponential function

void exp_func()
{
    cout << "Enter the domain of the function: " << endl;
    double lower{}, upper{};
    int step{};
    char c{};

    cout << "Lower bound: ";   
    cin >> lower;
    cout << "Upper bound: ";   
    cin >> upper;
    cout<<"Enter the step length: ";     
    cin >> step;
    cout << "Enter the fill character: ";  
    cin >> c;

    cout << endl << endl;

    double i = lower, interval = (upper - lower)/step;

    while(i <= upper)
    {
        double val = exp(i);

        if(val<1)
        {
            cout << setw(5) << setfill(' ') << "||" << setw(int (val*10)) << setfill(c) << "*" << endl;
        }
        else
        {
            cout << setw(5) << setfill(' ') << "||" << setw(int(val*12)) << setfill(c) << "*" << endl;
        }

        i = i + interval;
    }

}

int main()

{
    char choice{};
    
    while(true) {
        cout << "\nWhich function do you want to use?\n\n1. Cosine Function\n2. Exponential Function" << endl;
        cout << "\nEnter your choice (1/2): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cos_func();
                break;
            case '2':
                exp_func();
                break;
            default: cout << "Something is wrong. Try again!" << endl;
        }

        cout << "Do you want to try again?(Y/N): ";
        cin >> choice;

        if(choice=='N' || choice=='n')
            break;
    }

    cout << endl << "Function generator is closing... " << endl;
    
    return 0;

}