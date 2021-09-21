#pragma once
#include <iostream>
#include "Document.h"

class Editor{

    Document* document;

public:

    Editor();
    ~Editor();
    void loop();
};