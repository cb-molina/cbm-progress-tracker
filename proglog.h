// proglog.h
#ifndef PROGLOG_H
#define PROGLOG_H

class Proglog
{
    public:
        Proglog(void);
        void logentry(void);
        void readlog(void);
        void logdate(void);
        bool logcheck(void);
    private:
        int wkday;
        char date;
        char * lastentry;
};

#endif