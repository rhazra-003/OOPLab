#include <iostream>
#include <fstream>
#include "Hash.h"
#include "Hash.cpp"

using namespace std;

const unsigned M = 1171;

int main() {

    Hash<string> H(M);

    ifstream fileInput("studentDB.csv");

    if (fileInput.is_open()) {
        int readLines{};

        while (!fileInput.eof()) {
            if(readLines > 3){
                string degree, regNo, rollNo, name, gender, phnNo, userEmail, clgEmail;

                getline(fileInput, degree, ',');
                getline(fileInput, regNo, ',');
                getline(fileInput, rollNo, ',');
                getline(fileInput, name, ',');
                getline(fileInput, gender, ',');
                getline(fileInput, phnNo, ',');
                getline(fileInput, userEmail, ',');
                getline(fileInput, clgEmail, '\n');

                //ignore spaces after registration number
                string noSpaceRegNo{};
                for(int i=0;regNo[i]!=' ';i++)
                {
                    noSpaceRegNo.push_back(regNo[i]);
                }


                H.insert(name, regNo);
            }else{
                string rejectLine;
                getline(fileInput, rejectLine, '\n');
                readLines++;
            }

        }

    }

    fileInput.close();

    H.tableLoadDistribution();
    H.display();


    return 0;
}
