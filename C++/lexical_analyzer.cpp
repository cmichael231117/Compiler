#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

void merged(char buffer[], ofstream &out);

bool isDigitWithout0(char in)
{
    if (in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
        return true;
    return false;
}
/*bool isDigitWith0(char in)
{
    if (in == '0' || in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
        return true;
    return false;
}*/
/*bool isLetter(char in)
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
*/
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
    if ((buffer[0] == '-') && (buffer[1] == '0') && (strlen(buffer) > 2))
    {
        char minusZero[3];
        minusZero[0] = '-';
        minusZero[1] = '0';
        minusZero[2] = '\0';
        merged(minusZero, out);
        char rest[strlen(buffer)];
        for (int i = 2; i < strlen(buffer) + 1; i++)
        {
            rest[i - 2] = buffer[i];
        }
        merged(rest, out);
        return true;
    }

    //char symbol = buffer[0];
    int state = 0;
    int acceptable = -1;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((buffer[i] == '0') && (state == 0))
        {
            state = 1;
            acceptable = i;
        }
        else if ((isDigitWithout0(buffer[i])) && (state == 0))
        {
            state = 3;
            acceptable = i;
        }
        else if ((buffer[i] == '-') && (state == 0))
            state = 2;
        else if ((isDigitWithout0(buffer[i])) && (state == 2))
        {
            state = 3;
            acceptable = i;
        }
        else if (((isDigitWithout0(buffer[i])) || (buffer[i] == '0')) && (state == 3))
        {
            state = 3;
            acceptable = i;
        }
        else //not correct symbol
        {
            if (acceptable != -1)
            {
                char correct[acceptable + 2];
                for (int j = 0; j < acceptable + 1; j++)
                {
                    correct[j] = buffer[j];
                }
                correct[acceptable + 1] = '\0';
                isInteger(correct, out);

                char wrong[strlen(buffer) - acceptable];
                for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
                {
                    wrong[j - acceptable - 1] = buffer[j];
                }
                wrong[strlen(buffer) - acceptable] = '\0';
                merged(wrong, out);
                state = -1;
                break;
            }
            else
            {
                return false;
            }
            //out << "error at " << buffer[i] << endl;
        }
    }
    if ((state == 1) || (state == 3))
    {
        out << "<INT, " << buffer << ">" << endl;
        return true;
    }
    else if (state == -1)
        return true;
    else
        return false;
    //
}
bool isFloat(char buffer[], ofstream &out)
{
    int state = 0;
    int acceptable = -1;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((state == 0) && (buffer[i] == '-'))
            state = 1;
        else if ((state == 0) && isDigitWithout0(buffer[i]))
            state = 2;
        else if ((state == 0) && (buffer[i] == '0'))
            state = 3;
        else if ((state == 1) && isDigitWithout0(buffer[i]))
            state = 2;
        else if ((state == 1) && (buffer[i] == '0'))
            state = 3;
        else if ((state == 2) && isDigitWithout0(buffer[i]))
            state = 4;
        else if ((state == 2) && (buffer[i] == '0'))
            state = 5;
        else if ((state == 2) && (buffer[i] == '.'))
            state = 6;
        else if ((state == 3) && (buffer[i] == '.'))
            state = 6;
        else if ((state == 4) && isDigitWithout0(buffer[i]))
            state = 4;
        else if ((state == 4) && (buffer[i] == '0'))
            state = 5;
        else if ((state == 4) && (buffer[i] == '.'))
            state = 6;
        else if ((state == 5) && isDigitWithout0(buffer[i]))
            state = 4;
        else if ((state == 5) && (buffer[i] == '0'))
            state = 5;
        else if ((state == 5) && (buffer[i] == '.'))
            state = 6;
        else if ((state == 6) && isDigitWithout0(buffer[i]))
        {
            state = 7;
            acceptable = i;
        }
        else if ((state == 6) && (buffer[i] == '0'))
        {
            state = 8;
            acceptable = i;
        }
        else if ((state == 7) && isDigitWithout0(buffer[i]))
        {
            state = 7;
            acceptable = i;
        }
        else if ((state == 7) && (buffer[i] == '0'))
            state = 9;
        else if ((state == 8) && isDigitWithout0(buffer[i]))
        {
            state = 7;
            acceptable = i;
        }
        else if ((state == 8) && (buffer[i] == '0'))
            state = 9;
        else if ((state == 9) && isDigitWithout0(buffer[i]))
        {
            state = 7;
            acceptable = i;
        }
        else if ((state == 9) && (buffer[i] == '0'))
            state = 9;
        else
        {
            if (acceptable != -1)
            {
                char correct[acceptable + 2];
                for (int j = 0; j < acceptable + 1; j++)
                {
                    correct[j] = buffer[j];
                }
                correct[acceptable + 1] = '\0';
                isFloat(correct, out);

                char wrong[strlen(buffer) - acceptable];
                for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
                {
                    wrong[j - acceptable - 1] = buffer[j];
                }
                wrong[strlen(buffer) - acceptable] = '\0';
                merged(wrong, out);
                state = -1;
                break;
            }
            else
            {
                return false;
            }
        }
    }
    if ((state == 7) || (state == 8))
    {
        out << "<FLOAT, " << buffer << ">" << endl;
        return true;
    }
    else if (state == 9)
    {
        if (acceptable != -1)
        {
            char correct[acceptable + 2];
            for (int j = 0; j < acceptable + 1; j++)
            {
                correct[j] = buffer[j];
            }
            correct[acceptable + 1] = '\0';
            isFloat(correct, out);

            char wrong[strlen(buffer) - acceptable];
            for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
            {
                wrong[j - acceptable - 1] = buffer[j];
            }
            wrong[strlen(buffer) - acceptable] = '\0';
            merged(wrong, out);
            return true;
        }
        else
            return false;
    }
    else if (state == -1)
        return true;
    else
        return false;
}
bool isString(char buffer[], ofstream &out)
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((state == 0) && (buffer[i] == '"'))
            state = 1;
        else if ((state == 1) && isdigit(buffer[i]))
            state = 2;
        else if ((state == 1) && isalpha(buffer[i]))
            state = 3;
        else if ((state == 1) && (buffer[i] == ' '))
            state = 4;
        else if ((state == 2) && isdigit(buffer[i]))
            state = 2;
        else if ((state == 2) && isalpha(buffer[i]))
            state = 3;
        else if ((state == 2) && (buffer[i] == ' '))
            state = 4;
        else if ((state == 2) && (buffer[i] == '"'))
            state = 5;
        else if ((state == 3) && isdigit(buffer[i]))
            state = 2;
        else if ((state == 3) && isalpha(buffer[i]))
            state = 3;
        else if ((state == 3) && (buffer[i] == ' '))
            state = 4;
        else if ((state == 3) && (buffer[i] == '"'))
            state = 5;
        else if ((state == 4) && isdigit(buffer[i]))
            state = 2;
        else if ((state == 4) && isalpha(buffer[i]))
            state = 3;
        else if ((state == 4) && (buffer[i] == ' '))
            state = 4;
        else if ((state == 4) && (buffer[i] == '"'))
            state = 5;
        else
            return false;
        //
    }
    if (state == 5)
    {
        out << "<STRING, " << buffer << ">" << endl;
        return true;
    }
    else
        return false;
    //
}
bool isIdentifier(char buffer[], ofstream &out)
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isalpha(buffer[i]) && (state == 0))
            state = 1;
        else if ((buffer[i] == '_') && (state == 0))
            state = 2;
        else if (isalpha(buffer[i]) && (state == 1))
            state = 3;
        else if ((buffer[i] == '_') && (state == 1))
            state = 5;
        else if (isdigit(buffer[i]) && (state == 1))
            state = 4;
        else if (isalpha(buffer[i]) && (state == 2))
            state = 3;
        else if ((buffer[i] == '_') && (state == 2))
            state = 5;
        else if (isdigit(buffer[i]) && (state == 2))
            state = 4;
        else if (isalpha(buffer[i]) && (state == 3))
            state = 3;
        else if ((buffer[i] == '_') && (state == 3))
            state = 5;
        else if (isdigit(buffer[i]) && (state == 3))
            state = 4;
        else if (isalpha(buffer[i]) && (state == 4))
            state = 3;
        else if ((buffer[i] == '_') && (state == 4))
            state = 5;
        else if (isdigit(buffer[i]) && (state == 4))
            state = 4;
        else if (isalpha(buffer[i]) && (state == 5))
            state = 3;
        else if ((buffer[i] == '_') && (state == 5))
            state = 5;
        else if (isdigit(buffer[i]) && (state == 5))
            state = 4;
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
    else if (isFloat(buffer, out))
    {
        return;
    }
    else if (isInteger(buffer, out))
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
    else if (!strcmp(buffer, "\0"))
    {
        return;
    }
    else if (!strcmp(buffer, "-0"))
    //else if((buffer[0]=='-')&&(buffer[1]=='0')&&(buffer[2]=='\0'))
    {
        out << "<ARITHMETIC, " << buffer[0] << ">" << endl;
        out << "<INT, " << buffer[1] << ">" << endl;
        return;
    }
    else
    {
        out << "error at "
            << (buffer) << endl;
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
        if (isalnum(ch) || (ch == '_') || (ch == '.')) //"랑(무조건 쌍이 맞아야함) . 따로(숫자랑만) 빼서 처리
        {
            buffer[i++] = ch;
        }
        else if (ch == '"')
        {
            if (i != 0)
            {
                buffer[i] = '\0';
                i = 0;
                merged(buffer, out);
            }

            buffer[i++] = ch;
            while (!fin.eof())
            {
                ch = fin.get();
                if (isalnum(ch) || (ch == ' '))
                {
                    buffer[i++] = ch;
                }
                else if (ch == '"')
                {
                    buffer[i++] = ch;
                    buffer[i] = '\0';
                    i = 0;
                    merged(buffer, out);
                    break;
                }
                else if (ch == EOF)
                {
                    out << "error at \"" << endl;
                    exit(0);
                }
                else
                {
                    out << "error at " << ch << endl;
                    exit(0);
                }
            }
        }
        else if ((ch == ' ' || ch == '\n' || ch == '\t')) //ignore whitespace
        {
            if (i != 0)
            {
                buffer[i] = '\0';
                i = 0;

                merged(buffer, out);
            }
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
            ch = fin.get();
            fin.seekg(-1, ios::cur);
            if (!isdigit(ch)) ////////////////////////////////
            {
                buffer[i] = '\0';
                i = 0;
                merged(buffer, out);
            }
        } /*
        else if ((i > 0) && (buffer[0] == '-') && (isalpha(ch) || ch == '"' || ch == '_'))
        {
            buffer[i] = '\0';
            i = 0;
            //test
            merged(buffer, out);
        }*/
        else if (ch == EOF)
        {
            buffer[i] = '\0';
            i = 0;
            //test
            merged(buffer, out);
            //cout << "finish\n";
            exit(0);
        }
        else
        {
            cout << "unvaild symbol is entered\n"
                 << int(ch);
            exit(0);
        }
    }

    return 0;
}