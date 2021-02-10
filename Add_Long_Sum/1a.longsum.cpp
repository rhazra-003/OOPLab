#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void insert_zeros(string& s, int no_zeros)
{
    string zero;
    for(int i=0; i<no_zeros; i++)
        zero += "0";
    s.insert(0, zero);
}


string largeAdd(string& a,string& b)
{
    int carry{}, sum;
    string char_sum;
    int length_diff = abs(int(a.length()-b.length()));

    int max_length = (a.length()>b.length())?(insert_zeros(b, length_diff), a.length()):(insert_zeros(a, length_diff), b.length());

    for(int i=max_length-1; i>=0; i--)
    {
        sum = (a[i]-'0') + (b[i]-'0') + carry;      

        if(sum>=10)                                
        {
            carry = sum/10;
            char_sum += static_cast<char>(sum%10 + '0');
        }
        else                                        
        {
            carry = 0;
            char_sum += static_cast<char>(sum%10 + '0');
        }
    }

    reverse(char_sum.begin(), char_sum.end());      
    return char_sum;

}

int main()

{
    string a, b;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;    
    cout << endl;

    string sum = largeAdd(a, b);
    cout << "Actual Sum = a + b = "<< sum << endl;

    return 0;
}