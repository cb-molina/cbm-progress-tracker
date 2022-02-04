#include "proglog.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
// using namespace std;

std::fstream sfile; 

Proglog::Proglog(void)
{
    std::cout << "Object created" << std::endl;
}

void Proglog::getweekday(void)
{
    sfile.open("log.txt",std::ios::in);
    std::string fileline;
    
    while(!sfile.eof()) // Grabs the last line
    {
        std::getline(sfile, fileline);
    }
    sfile.close();

    std::cout << "Date from file: " << fileline << std::endl; // This is grabbing the first line
    
    
    sfile.open("log.txt",std::ios_base::app); // append mode
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::string mon = std::to_string(1+ ltm->tm_mon);
    std::string mday = std::to_string(ltm->tm_mday);
    std::string year = std::to_string(1900 + ltm->tm_year);

    std::string date = mon + '/' + mday + '/' + year;

    std::cout << "Today is: ";
    std::cout << date <<std::endl;

    if (date == fileline)
    {
        std::cout << "Dates are the same" << std::endl;
        sfile.close();
    }
    else
    {
        std::cout << "Dates are not the same" << std::endl; 
        sfile << " " << date;
        sfile.close();
    }
}