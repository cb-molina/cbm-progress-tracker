// proglog.h
#ifndef PROGLOG_H
#define PROGLOG_H

class Proglog
{
    public:
        Proglog(void);
        void getweekday(void);
        void getfileinput(void);
        void compare(void);
        void logdata(void);
        ~Proglog();
    private:
        int wkday;
};

#endif