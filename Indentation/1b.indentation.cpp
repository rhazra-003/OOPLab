#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("test.txt", ios::in);        //opening file in read mode
    ofstream f_indent("test_indent.txt", ios::out);     //opening file in write mode

    string line;

    cout<<"Non-indented code:"<<endl<<endl;

    while(!f.eof())             //while loop flows till end of file
    {
        getline(f, line);       //getting a single line in "line" from the file
        cout<<line<<endl;
    }

    f.clear();                  //clearing the eof() flag
    f.seekg(ios::beg);          //moving the file pointer to the beginning of file

    int tabs{0};                //initializing tabs to zero

    cout<<endl<<endl<<endl<<"Indented code:"<<endl<<endl;

    while(!f.eof())             //while loop flows till end of file
    {
        getline(f, line);       //getting a single line in "line" from the file
        if(line == "}")                //if "}" is caught then tab count is decremented
            tabs--;

        for(int i=0; i<tabs; i++)       //loop to apply the tabs in file
        {
            f_indent<<"\t";
            cout<<"\t";                 //displaying the tabs on console
        }

        if(line.find('{')!=string::npos)        //finding "{" to increment the tab count
            tabs++;
        f_indent<<line<<endl;                       //writing in the file
        cout<<line<<endl;                           //displaying the line on console

    }

    f.close();                          //closing both files
    f_indent.close();
    return 0;
}