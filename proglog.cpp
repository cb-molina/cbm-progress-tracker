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

// Testing variables
std::string filestr;

Proglog::Proglog(void)
{
    std::cout << "Object created" << std::endl;
}
Proglog::~Proglog()
{
    std::cout << "Object destroyed" << std::endl;
}

void Proglog::getfileinput(void)
{
    std::string filestr;
    sfile.open("log.txt",std::ios::in);
    while(!sfile.eof()) std::getline(sfile, fileinput.at(0)); // Grabs the last line
    sfile.close();

    std::cout << "Stream from file: " << fileinput.at(0) << std::endl; // This is grabbing the last line from file

    for (int i = 0; i < fileinput[0].size(); i++)
    {
        if (fileinput[0][i] == ' ') break;
        else filestr = filestr + fileinput[0][i];
    }
    date.at(1) = filestr;
}

void Proglog::getweekday(void)
{    
    time_t now = time(0);
    tm *ltm = localtime(&now);

    date.at(0) = std::to_string(1+ ltm->tm_mon) + '/' + std::to_string(ltm->tm_mday) + '/' + std::to_string(1900 + ltm->tm_year);

    std::cout << "Today is: ";
    std::cout << date.at(0) <<std::endl;
}

void Proglog::compare(void)
{
    sfile.open("log.txt",std::ios_base::app); // append mode
    std::cout << "Date for today: " << date.at(0) << std::endl;
    std::cout << "Date from file: " << date.at(1) << std::endl;

    if (date.at(0) == date.at(1)) std::cout << "Dates are the same" << std::endl;
    else
    {
        std::cout << "Dates are not the same" << std::endl; 
        sfile << std::endl << date.at(0);
        Proglog::logdata();
    }
    sfile.close();
}

void Proglog::logdata(void)
{
    // sfile.open("log.txt",std::ios_base::app); // append mode
    std::string test;
    int rate1, rate2, rate3, rate4, rate5;
    std::cout << "Input test, enter input: " ; // Change this to a proper prompt
    
    std::cin >> rate1 >> rate2 >> rate3 >> rate4 >> rate5;
    sfile << " " << rate1 << " " << rate2 << " "  << rate3 << " "  << rate4 << " "  << rate5;
    
    // sfile.close();
}