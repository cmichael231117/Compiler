#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void printfile(ofstream &out)
{
    string out_line;
    cin >> out_line;
    //ostringstream ss;
    //ss << out_line;
    //return ss.str();
    out << "<INT>" << out_line << endl;
}

bool prien(ofstream &out){
    printfile(out);
    return true;
}

int main()
{
    ofstream out("tesdsad.txt");
    /*for (int i = 0; i <= 5; i++)
    {
        prien(out);
        //out << printfile() << endl;
    }*/

    //int i = (!strcmp("if", "if"));

    char buffer[20];
    for(int i=0;i<10;i++){
        buffer[i]='a';
    }
    buffer[10]='\0';
    cout<<strlen(buffer);

    cout<<buffer;

//    char ch= EOF;
 //   cout<<int(ch);

    out.close();
    return 0;
}
