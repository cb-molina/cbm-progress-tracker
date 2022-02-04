#include "proglog.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
// using namespace std;

std::fstream sfile;
std::vector<std::string> fileinput(2);
std::vector<std::string> date(2);

Proglog::Proglog(void)
{
    std::cout << "Object created" << std::endl;
}

void Proglog::getfileinput(void)
{
    sfile.open("log.txt",std::ios::in);
    while(!sfile.eof()) // Grabs the last line
    {
        std::getline(sfile, fileinput.at(0));
    }
    sfile.close();

    std::cout << "Date from file: " << fileinput.at(0) << std::endl; // This is grabbing the first line
}

void Proglog::getweekday(void)
{    
    sfile.open("log.txt",std::ios_base::app); // append mode
    time_t now = time(0);
    tm *ltm = localtime(&now);

    date.at(0) = std::to_string(1+ ltm->tm_mon) + '/' + std::to_string(ltm->tm_mday) + '/' + std::to_string(1900 + ltm->tm_year);

    std::cout << "Today is: ";
    std::cout << date.at(0) <<std::endl;
}

void Proglog::compare(void)
{
    if (date.at(0) == fileinput.at(0))
    {
        std::cout << "Dates are the same" << std::endl;
        sfile.close();
    }
    else
    {
        std::cout << "Dates are not the same" << std::endl; 
        sfile << " " << date.at(0);
        sfile.close();
    }
}