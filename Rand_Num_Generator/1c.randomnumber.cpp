#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void my_rand()

{
    unsigned long long int x, m, a;
    int n;

    time_t t;

    t = time(nullptr);
    cout << "The time as seed: " << t << endl;
    x = t;                             
    m = 242889467;
    a = 54354;

    srand(t);                           
    cout << "How many values:";
    cin >> n;

    double chi_test_my_rand{}, chi_test_comp_rand{};
    int my_rand_observe_val[5]={} , comp_rand_observe_val[5]={};

    double expected_value = (10/50.0) * n;      

    for(int i=0; i<n; i++)
    {
        x = (x * a) % m;                
        unsigned long long int my_rand_val = x % 50;
        unsigned long long int comp_rand_val = rand() % 50;

        if (my_rand_val >= 1 && my_rand_val <= 10)
            my_rand_observe_val[0]++;
        else if (my_rand_val >= 11 && my_rand_val <= 20)
            my_rand_observe_val[1]++;
        else if (my_rand_val >= 21 && my_rand_val <= 30)
            my_rand_observe_val[2]++;
        else if (my_rand_val >= 31 && my_rand_val <= 40)
            my_rand_observe_val[3]++;
        else if (my_rand_val >= 41 && my_rand_val <= 50)
            my_rand_observe_val[4]++;


        if (comp_rand_val >= 1 && comp_rand_val <= 10)
            comp_rand_observe_val[0]++;
        else if (comp_rand_val >= 11 && comp_rand_val <= 20)
            comp_rand_observe_val[1]++;
        else if (comp_rand_val >= 21 && comp_rand_val <= 30)
            comp_rand_observe_val[2]++;
        else if (comp_rand_val >= 31 && comp_rand_val <= 40)
            comp_rand_observe_val[3]++;
        else if (comp_rand_val >= 41 && comp_rand_val <= 50)
            comp_rand_observe_val[4]++;

    }

    for(int i=0; i<5; i++)
    {
        chi_test_my_rand += (pow(my_rand_observe_val[i]-expected_value,2))/expected_value;
        chi_test_comp_rand += (pow(comp_rand_observe_val[i]-expected_value,2))/expected_value;
    }

    cout << "Chi Square test of my_rand(): " << chi_test_my_rand << endl;
    cout << "Chi Square test of rand(): " << chi_test_comp_rand << endl;
}

int main()

{
    my_rand();

    return 0;
}

