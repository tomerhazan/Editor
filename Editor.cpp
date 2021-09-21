#include "Editor.h"
#include "Document.h"
#include <iostream>
#include <string>


using namespace std;

Editor::Editor(){
    document = new Document();

}

Editor::~Editor(){

    delete document;

}

void Editor::loop(){

    string text;
    getline(cin,text);
    while (text != "Q")
    {
        if (text[0] == 'a'){
            document->a();
        }else if (text[0] == '%' && text[1] == 'p'){
            document->p();
        }else if (text[text.size() - 1] == 'n')
        {
            document->n(std::stoi(text.substr(0,text.length() - 1)));
        }else if (text[0] == 'i')
        {
            document->i();
        }else if (text[text.length() - 1] == 'j')
        {
            document->j(text);
        }else if (text[0] == '/')
        {
            document->slash(text);
        }else if (text[0] == 's')
        {
            document->slash3(text);
        }else if (text[text.length() - 1] == 'd')
        {
            document->d(std::stoi(text.substr(0,text.length() - 1)));
        }else if (text[0] == '?')
        {
            document->question(text);
        }
        else if (text[0] == 'c')
        {
            document->c();
        }else if (text[0] == 'Q')
        {
            break;
        }
        getline(cin,text);
    }
}