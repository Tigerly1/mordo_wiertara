﻿#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "antlr4-runtime.h"
#include "sharkbitLexer.h"
#include "sharkbitParser.h"
#include "sharkbitBaseListener.h"
#include "MyVisitor.h"
#include "MyListner.h"

using namespace antlr4;
class TreeShapeListener : public sharkbit::sharkbitBaseListener {
public:
	void enterProgram(sharkbit::sharkbitParser::ProgramContext* ctx) override  {
		// Do something when entering the key rule.
		std::cout << ctx->declList() << std::endl;
		//std::cout << "DZIAŁA KURWA AAA AA AAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	}
};


int main(int argc, const char* argv[]) {
    std::ifstream myfile;
    myfile.open("C:/Users/JF/mordo_wiertara/test_sript.txt");
    std::string line;
    std::string stringinput;

    if (!myfile.is_open()){
        std::cout << "ERROR WHILE LOADING FILE";
        exit(1);
    }

    // converting file into string
    while (std::getline(myfile, line)) {
        stringinput += line + "\n";
    }

    ANTLRInputStream input(stringinput);
    sharkbit::sharkbitLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    sharkbit::sharkbitParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.program();

    MyListner listener;
    listener.enterProgram(parser.program());
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    myfile.close();

    return 0;
}