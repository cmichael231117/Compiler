#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;
bool isDigitWithout0(char in)
{
    if (in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
        return true;
    return false;
}
bool isDigitWith0(char in)
{
    if (in == '0' || in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
        return true;
    return false;
}
bool isLetter(char in)
{
    if (in == 'a' || in == 'b' || in == 'c' || in == 'd' || in == 'e' || in == 'f' || in == 'g' || in == 'h' || in == 'i' || in == 'j' ||
        in == 'k' || in == 'l' || in == 'm' || in == 'n' || in == 'o' || in == 'p' || in == 'q' || in == 'r' || in == 's' || in == 't' ||
        in == 'u' || in == 'v' || in == 'w' || in == 'x' || in == 'y' || in == 'z' ||
        in == 'A' || in == 'B' || in == 'C' || in == 'D' || in == 'E' || in == 'F' || in == 'G' || in == 'H' || in == 'I' || in == 'J' ||
        in == 'K' || in == 'L' || in == 'M' || in == 'N' || in == 'O' || in == 'P' || in == 'Q' || in == 'R' || in == 'S' || in == 'T' ||
        in == 'U' || in == 'V' || in == 'W' || in == 'X' || in == 'Y' || in == 'Z')
        return true;
    return false;
}

bool isType(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "int")) || (!strcmp(buffer, "char")) || (!strcmp(buffer, "bool")) || (!strcmp(buffer, "float")))
    {
        out << "<TYPE, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isBoolean(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "true")) || (!strcmp(buffer, "false")))
    {
        out << "<BOOLEAN, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isKeyword(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "if")) || (!strcmp(buffer, "else")) || (!strcmp(buffer, "while")) || (!strcmp(buffer, "for")) || (!strcmp(buffer, "return")))
    {

        out << "<KEYWORD, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isArithmetic(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "+")) || (!strcmp(buffer, "-")) || (!strcmp(buffer, "*")) || (!strcmp(buffer, "/")))
    {
        out << "<ARITHMETIC, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isBitwise(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "<<")) || (!strcmp(buffer, ">>")) || (!strcmp(buffer, "&")) || (!strcmp(buffer, "|")))
    {
        out << "<BITWISE, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isComparison(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "<")) || (!strcmp(buffer, ">")) || (!strcmp(buffer, "==")) || (!strcmp(buffer, "!=")) || (!strcmp(buffer, "<=")) || (!strcmp(buffer, ">=")))
    {
        out << "<COMPARISON, " << buffer << ">" << endl;
        return true;
    }
    return false;
}
bool isSemicolon(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, ";")))
    {
        out << "<SEMICOLON>" << endl;
        return true;
    }
    return false;
}
bool isParen(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "(")))
    {
        out << "<LPAREN>" << endl;
        return true;
    }
    else if ((!strcmp(buffer, ")")))
    {
        out << "<RPAREN>" << endl;
        return true;
    }
    return false;
}
bool isBracket(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "{")))
    {
        out << "<LBRACKET>" << endl;
        return true;
    }
    else if ((!strcmp(buffer, "}")))
    {
        out << "<RBRACKET>" << endl;
        return true;
    }
    return false;
}
bool isComma(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, ",")))
    {
        out << "<COMMA>" << endl;
        return true;
    }
    return false;
}
bool isAssignment(char buffer[], ofstream &out)
{
    if ((!strcmp(buffer, "=")))
    {
        out << "<ASSIGNMENT>" << endl;
        return true;
    }
    return false;
}
bool isInteger(char buffer[], ofstream &out)
{
    //char symbol = buffer[0];
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((buffer[i] == '0') && (state == 0))
        {
            state = 1;
        }
        else if ((isDigitWithout0(buffer[i])) && (state == 0))
        {
            state = 3;
        }
        else if ((buffer[i] == '-') && (state == 0))
        {
            state = 2;
        }
        else if ((isDigitWithout0(buffer[i])) && (state == 2))
        {
            state = 3;
        }
        else if (((isDigitWithout0(buffer[i])) || (buffer[i] == '0')) && (state == 3))
        {
            state = 3;
        }
        else
        {
            return false;
            //out << "error at " << buffer[i] << endl;
        }
    }
    if ((state == 1) || (state == 3))
    {
        out << "<INT, " << buffer << ">" << endl;
        return true;
    }
    else
        return false;
    //
}
bool isFloat(char buffer[], ofstream &out)
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((state == 0) && isDigitWithout0(buffer[i]))
            state = 2;
    }
}
bool isString(char buffer[], ofstream &out)
{
}
bool isIdentifier(char buffer[], ofstream &out)
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isLetter(buffer[i]) && (state == 0))
        {
            state = 1;
        }
        else if ((buffer[i] == '_') && (state == 0))
        {
            state = 2;
        }
        else if (isLetter(buffer[i]) && (state == 1))
        {
            state = 3;
        }
        else if ((buffer[i] == '_') && (state == 1))
        {
            state = 5;
        }
        else if (isDigitWith0(buffer[i]) && (state == 1))
        {
            state = 4;
        }
        else if (isLetter(buffer[i]) && (state == 2))
        {
            state = 3;
        }
        else if ((buffer[i] == '_') && (state == 2))
        {
            state = 5;
        }
        else if (isDigitWith0(buffer[i]) && (state == 2))
        {
            state = 4;
        }
        else if (isLetter(buffer[i]) && (state == 3))
        {
            state = 3;
        }
        else if ((buffer[i] == '_') && (state == 3))
        {
            state = 5;
        }
        else if (isDigitWith0(buffer[i]) && (state == 3))
        {
            state = 4;
        }
        else if (isLetter(buffer[i]) && (state == 4))
        {
            state = 3;
        }
        else if ((buffer[i] == '_') && (state == 4))
        {
            state = 5;
        }
        else if (isDigitWith0(buffer[i]) && (state == 4))
        {
            state = 4;
        }
        else if (isLetter(buffer[i]) && (state == 5))
        {
            state = 3;
        }
        else if ((buffer[i] == '_') && (state == 5))
        {
            state = 5;
        }
        else if (isDigitWith0(buffer[i]) && (state == 5))
        {
            state = 4;
        }
        else
        {
            return false;
            //out << "error at " << buffer[i] << endl;
        }
    }
    if ((state == 1) || (state == 2) || (state == 3) || (state == 4) || (state == 5))
    {
        out << "<ID, " << buffer << ">" << endl;
        return true;
    }
    else
        return false;
    //
}

void merged(char buffer[], ofstream &out)
{
    cout << "1";
    if (isType(buffer, out))
    {

        return;
    }
    else if (isBoolean(buffer, out))
    {
        return;
    }
    else if (isKeyword(buffer, out))
    {
        cout << "2\n";
        return;
    }
    else if (isArithmetic(buffer, out))
    {
        return;
    }
    else if (isBitwise(buffer, out))
    {
        return;
    }
    else if (isAssignment(buffer, out))
    {
        return;
    }
    else if (isComparison(buffer, out))
    {
        return;
    }
    else if (isSemicolon(buffer, out))
    {
        return;
    }
    else if (isParen(buffer, out))
    {
        return;
    }
    else if (isBracket(buffer, out))
    {
        return;
    }
    else if (isComma(buffer, out))
    {
        return;
    }
    else if (isInteger(buffer, out))
    {
        return;
    }
    else if (isFloat(buffer, out))
    {
        return;
    }
    else if (isString(buffer, out))
    {
        return;
    }
    else if (isIdentifier(buffer, out))
    {
        return;
    }
    else
    {
        cout << "there is no token for given lexeme\n"
             << buffer << endl;
        exit(0);
    }
}

int main(int argc, char **argv)
{
    char ch, buffer[20];
    int i = 0;

    ifstream fin(argv[1]);
    if (!fin.is_open())
    {
        cout << "open file failure\n";
        exit(0);
    }
    //ofstream out(strcat(argv[1], ".out"));
    ofstream out("result.txt");

    while (!fin.eof())
    {
        ch = fin.get();
        if (isalnum(ch) || (ch == '"') || (ch == '_') || (ch == '.')) //"랑(무조건 쌍이 맞아야함) . 따로(숫자랑만) 빼서 처리
        {
            buffer[i++] = ch;
        }
        else if ((ch == ' ' || ch == '\n' || ch == '\t') && (i != 0)) //ignore whitespace
        {
            buffer[i] = '\0';
            i = 0;

            merged(buffer, out);
        }
        else if ((ch == '>') || (ch == '<') || (ch == '!') || (ch == '='))
        {
            if (i != 0)
            {
                buffer[i] = '\0';
                i = 0;
                //test
                merged(buffer, out);
            }
            buffer[i++] = ch;

            ch = fin.get();
            if (((ch == '>') && (buffer[0] == '>')) || ((ch == '<') && (buffer[0] == '<')) || (ch == '='))
            {
                buffer[i++] = ch;
                buffer[i] = '\0';
                i = 0;
                //test
                merged(buffer, out);
            }
            else if (buffer[0] == '!')
            {
                cout << "Error at !" << endl; //파일에 출력하기
                exit(0);
            }
            else
            {
                buffer[i] = '\0';
                i = 0;
                fin.seekg(-1, ios::cur);
                //test
                merged(buffer, out);
            }
        }
        else if ((ch == '+') || (ch == '*') || (ch == '/') ||
                 (ch == '&') || (ch == '|') || (ch == ';') || (ch == '{') ||
                 (ch == '}') || (ch == '(') || (ch == ')') || (ch == ',')) //두개짜리 분리는 따로하자
        {
            if (i != 0)
            {
                buffer[i] = '\0';
                i = 0;
                ///test
                merged(buffer, out);
            }
            buffer[i++] = ch;
            buffer[i] = '\0';
            i = 0;
            //test sign
            merged(buffer, out);
        }
        else if (ch == '-')
        {
            if (i != 0)
            {
                buffer[i] = '\0';
                i = 0;
                //test
                merged(buffer, out);
            }
            buffer[i++] = ch;
        }
        else if ((i > 0) && (buffer[0] == '-') && (isalpha(ch) || ch == '"' || ch == '_'))
        {
            buffer[i] = '\0';
            i = 0;
            //test
            merged(buffer, out);
        }
        else if (ch == EOF)
        {
            buffer[i] = '\0';
            i = 0;
            //test
            merged(buffer, out);
            cout << "finish\n";
            exit(0);
        }
        else
        {
            cout << "unvaild symbol is entered\n";
            exit(0);
        }
    }

    return 0;
}