#include "proglog.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <stdio.h>
// using namespace std;

// Global variables
std::fstream sfile;

Proglog::Proglog(void)
{
    std::cout << "Object created" << std::endl;
}

void Proglog::readlog(void)
{
    std::cout << "==== [readlog] ====" << std::endl;
    sfile.open("log.txt",std::ios::in);    
    std::string lastline;
    while (std::getline(sfile,lastline));
    sfile.close();
    char char_entry[lastline.length() + 1];
    strcpy(char_entry, lastline.c_str());
    // std::strcpy(lastentry, lastline.c_str());
    std::cout << "last Date from file: " << char_entry << std::endl;
}

void Proglog::logdate(void)
{
    std::cout << "==== [logdate] ====" << std::endl;
    sfile.open("log.txt",std::ios_base::app); // append mode
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int mon = 1+ ltm->tm_mon;
    int mday = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;

    // ERROR

    std::cout << "Today is: ";
    std::cout <<mon << mday << year <<std::endl;

    char char_mon = (char)mon;
    char char_mday = (char)mday;
    char char_year = (char)year;

    // date = char_mon + '/' + char_mday + '/' + char_year;

    std::cout << "Today is: ";
    std::cout <<char_mon << char_mday << char_year <<std::endl;
}


// bool Proglog::logcheck(void)
// {

// }

// void Proglog::logentry(void)
// {
//     std::cout << "==== [logentry] ====" << std::endl;
//     if (date == lastentry)
//     {
//         std::cout << "[entry already logged for today]" << std::endl;
//         sfile.close();
//     }
//     else
//     {
//         std::cout << "[entry logged]" << std::endl; 
//         sfile << std::endl << date;
//         sfile.close();
//     }
// }