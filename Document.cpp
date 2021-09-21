#include "Document.h"
#include <iostream>
#include <string>


#include <vector>
using namespace std;

Document::Document(){

    currLine = 0;

}
void Document::a(){
    string line;
    getline(cin,line);
    while (line[0] != '.'){
        mytext.push_back(line);
        getline(cin,line);
    }
}
void Document::n(int numline){
    string line;
    currLine = numline - 1;
    cout<<numline<< '\t' << mytext[currLine]<<endl;
}
void Document::p(){
    
    for (int i = 0; i < mytext.size(); i++)
    {
        cout << mytext[i]<<endl;
    }
    currLine = mytext.size() - 1;
}
void Document::i(){
    string line;
    int c = currLine;
    getline(cin,line);
    while (line[0] != '.')
    {
        mytext.insert(mytext.begin() + currLine , line);
        currLine = currLine + 1;
        getline(cin,line);
    }
    currLine = c;
}

void Document::j(string line){
    string str = line.substr(0,line.size() - 1);
    int i = str.find(",");
    int a = std::stoi(str.substr(0, i)) - 1;
    int b = std::stoi(str.substr(i+1, line.size())) - 1;
    string s = mytext[a];
    string s2 = mytext[b];
    s.insert(s.length(),s2);
    mytext[a] = s;
    mytext.erase(mytext.begin()+b);
    currLine = a;
}

void Document::slash(string text){

    currLine = currLine +1;
    text.erase(0,1);
    
    while (currLine != mytext.size())
    {
        string s = mytext[currLine];
        int found = s.find(text);
        if (found != -1){
            cout<<s<<endl;
            break;
        }else
        {
            currLine = currLine + 1;
        }
    }
}
void Document::slash3(string text){

    string str = text.substr(2,text.size());
    int i = str.find("/");
    string a = str.substr(0, i);
    string b = str.substr(i+1, str.size());
    i = b.find("/");
    b = b.substr(0, i);
    int l = mytext[currLine].find(a);
    str = mytext[currLine];
    str.replace(l,a.length(), b);
    mytext[currLine] = str;
}
void Document::d(int numline){
    currLine = numline -1;
    mytext.erase(mytext.begin()+currLine+1);
}
void Document::question(string text){
    
    currLine = currLine -1;
    text.erase(0,1);
    
    while (currLine != -1)
    {
        string s = mytext[currLine];
        int found = s.find(text);
        if (found != -1){
            cout<<s<<endl;
            break;
        }else
        {
            currLine = currLine - 1;
        }
    }
    if (currLine == -1)
    {
        currLine = currLine +1;
    }
    
}
void Document::c(){

    string line;
    getline(cin,line);
    mytext.erase(mytext.begin() + currLine);
    while (line[0] != '.'){
        mytext.insert(mytext.begin() + currLine , line);
        currLine = currLine + 1;
        getline(cin,line);
    }
}
