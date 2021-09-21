#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Document{

    vector<string> mytext;
    int currLine;

    public:
        Document();
        void a();
        void p();
        void n(int);
        void i();
        void j(string);
        void slash(string);
        void slash3(string);
        void d(int);
        void question(string);
        void c();

};
