//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////<Lexical Analyzer>//////////////////////////////////////
//20154521 Seokjun CHoi
// - This is C++ code for lexical analyzer.
// - If you want to execute this program, then compile 
//   this with name 'lexical_analyzer', and command './lexical_analyzer <input_file_name>'
// - If you wrote input file correctly, this program will give you output file <input_file_name>.out
// - This program identify tokens (type, int, string, boolean, float, id, keyword, arithmetic, 
//   bitwise, assignment, comparison, semicolon, lbracket, rbracket, lparen, rparen, comma) 
// - If you understand how does this work, then read code and comments carefully.
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

void merged(char buffer[], ofstream &out);

bool isDigitWithout0(char in)//function of DigitWithoutZero regular expression
{
    if (in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
        return true;
    return false;
}

bool isType(char buffer[], ofstream &out)//simpe pattern matching
{
    if ((!strcmp(buffer, "int")) || (!strcmp(buffer, "char")) || (!strcmp(buffer, "bool")) || (!strcmp(buffer, "float")))
    {
        //out << "<TYPE, " << buffer << ">" << endl;//output
        out << "vtype"<< endl;
        return true;
    }
    return false;//move next function
}
bool isBoolean(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "true")) || (!strcmp(buffer, "false")))
    {
        out << "<BOOLEAN, " << buffer << ">" << endl;//output
        return true;
    }
    return false;//move next function
}
bool isKeyword(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "if")) || (!strcmp(buffer, "else")) || (!strcmp(buffer, "while")) || (!strcmp(buffer, "for")) || (!strcmp(buffer, "return")))
    {

        //out << "<KEYWORD, " << buffer << ">" << endl;//output
        out <<  buffer << endl;
        return true;
    }
    return false;//move next function
}
bool isArithmetic(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "+")) || (!strcmp(buffer, "-")) )
    {
        //out << "<ARITHMETIC, " << buffer << ">" << endl;
        out << "addsub" << endl;//output
        return true;
    }
    else if ((!strcmp(buffer, "*")) || (!strcmp(buffer, "/")))
    {
        //out << "<ARITHMETIC, " << buffer << ">" << endl;
        out << "multdiv" << endl;//output
        return true;
    }
    return false;
}
bool isBitwise(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "<<")) || (!strcmp(buffer, ">>")) || (!strcmp(buffer, "&")) || (!strcmp(buffer, "|")))
    {
        out << "<BITWISE, " << buffer << ">" << endl;//output
        return true;
    }
    return false;//move to next function
}
bool isComparison(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "<")) || (!strcmp(buffer, ">")) || (!strcmp(buffer, "==")) || (!strcmp(buffer, "!=")) || (!strcmp(buffer, "<=")) || (!strcmp(buffer, ">=")))
    {
        //out << "<COMPARISON, " << buffer << ">" << endl;//output
        out << "comp" << endl;
        return true;
    }
    return false;//move to next function
}
bool isSemicolon(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, ";")))
    {
        out << "semi" << endl;//output
        return true;
    }
    return false;//move to next function
}
bool isParen(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "(")))
    {
        out << "lparen" << endl;
        return true;
    }
    else if ((!strcmp(buffer, ")")))
    {
        out << "rparen" << endl;
        return true;
    }//outputs
    return false;//move to next function
}
bool isBracket(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "{")))
    {
        out << "lbrace" << endl;
        return true;
    }
    else if ((!strcmp(buffer, "}")))
    {
        out << "rbrace" << endl;
        return true;
    }//outputs
    return false;//move to next function
}
bool isComma(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, ",")))
    {
        out << "comma" << endl;//output
        return true;
    }
    return false;//move to next function
}
bool isAssignment(char buffer[], ofstream &out)//simple pattern matching
{
    if ((!strcmp(buffer, "=")))
    {
        out << "assign" << endl;//output
        return true;
    }
    return false;//move to next function
}
bool isInteger(char buffer[], ofstream &out)//complex dfa
{
    if ((buffer[0] == '-') && (buffer[1] == '0') && (strlen(buffer) > 2))//when - is confusing
    {
        char minusZero[3];
        minusZero[0] = '-';
        minusZero[1] = '0';
        minusZero[2] = '\0';
        merged(minusZero, out);//test -0
        char rest[strlen(buffer)];
        for (int i = 2; i < strlen(buffer) + 1; i++)
        {
            rest[i - 2] = buffer[i];
        }
        merged(rest, out);//test rest things
        return true;
    }

    int state = 0;//start state
    int acceptable = -1;//no acceptable
    for (int i = 0; i < strlen(buffer); i++)//read symbols
    {
        if ((buffer[i] == '0') && (state == 0))//these are transitions. move to next state for given situation
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
            if (acceptable != -1)//there is acceptable token!
            {
                char correct[acceptable + 2];
                for (int j = 0; j < acceptable + 1; j++)//partitioning
                {
                    correct[j] = buffer[j];
                }
                correct[acceptable + 1] = '\0';
                isInteger(correct, out);//accept INT

                char wrong[strlen(buffer) - acceptable];//rest things
                for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
                {
                    wrong[j - acceptable - 1] = buffer[j];//partitioning
                }
                wrong[strlen(buffer) - acceptable] = '\0';
                merged(wrong, out);//test
                state = -1;//not normal terminate
                break;//escape loop
            }
            else
            {
                return false;
            }
        }
    }
    if ((state == 1) || (state == 3))//we are in final state
    {
        //out << "<INT, " << buffer << ">" << endl;//output
        out << "num" << endl;
        return true;
    }
    else if (state == -1)
        return true;
    else
        return false;//move to next function
}
bool isFloat(char buffer[], ofstream &out)//complex dfa
{
    int state = 0;//start state
    int acceptable = -1;//no acceptable idx
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((state == 0) && (buffer[i] == '-'))//these are transitions. move to correct state for given situations
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
            acceptable = i;//when acceptable, remember idx
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
        else//not correct symbol
        {
            if (acceptable != -1)//there is acceptable token!
            {
                char correct[acceptable + 2];
                for (int j = 0; j < acceptable + 1; j++)//partitioning
                {
                    correct[j] = buffer[j];
                }
                correct[acceptable + 1] = '\0';
                isFloat(correct, out);//accept FLOAT

                char wrong[strlen(buffer) - acceptable];//remaing things
                for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
                {
                    wrong[j - acceptable - 1] = buffer[j];//partitioning
                }
                wrong[strlen(buffer) - acceptable] = '\0';
                merged(wrong, out);//test
                state = -1;//not normal terminate
                break;
            }
            else
            {
                return false;
            }
        }
    }
    if ((state == 7) || (state == 8))//we are in final state
    {
        //out << "<FLOAT, " << buffer << ">" << endl;//output
        out << "float" << endl;
        return true;
    }
    else if (state == 9)//read all, but cannot accept
    {
        if (acceptable != -1)//there is acceptable token!
        {
            char correct[acceptable + 2];
            for (int j = 0; j < acceptable + 1; j++)//partitioning
            {
                correct[j] = buffer[j];
            }
            correct[acceptable + 1] = '\0';
            isFloat(correct, out);//accept FLOAT

            char wrong[strlen(buffer) - acceptable];
            for (int j = acceptable + 1; j < (strlen(buffer) + 1); j++)
            {
                wrong[j - acceptable - 1] = buffer[j];//partitioning remaining things
            }
            wrong[strlen(buffer) - acceptable] = '\0';
            merged(wrong, out);//test
            return true;
        }
        else
            return false;//move to next function
    }
    else if (state == -1)
        return true;
    else
        return false;//move to next function
}
bool isString(char buffer[], ofstream &out)//complex dfa
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if ((state == 0) && (buffer[i] == '"'))//these are transitions for moving to correct state
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
    }
    if (state == 5)//this is final state
    {
        //out << "<STRING, " << buffer << ">" << endl;//output
        out << "literal" << endl;
        return true;
    }
    else
        return false;
}
bool isIdentifier(char buffer[], ofstream &out)//complex dfa
{
    int state = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isalpha(buffer[i]) && (state == 0))//these are transitions for moving to correct state
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
        }
    }
    if ((state == 1) || (state == 2) || (state == 3) || (state == 4) || (state == 5))//these are final states.
    {
        //out << "<ID, " << buffer << ">" << endl;
        out << "id" << endl;
        return true;
    }
    else
        return false;
}

void merged(char buffer[], ofstream &out)//call functions for identifying tokens
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
    else if (!strcmp(buffer, "\0"))//buffer is null char
    {
        return;
    }
    else if (!strcmp(buffer, "-0"))
    {
        out << "<ARITHMETIC, " << buffer[0] << ">" << endl;
        out << "<INT, " << buffer[1] << ">" << endl;
        return;
    }
    else//no matching tokens. send error message
    {
        out << "error at "
            << (buffer) << endl;
        exit(0);
    }
}

int main(int argc, char **argv)//get input file name
{
    char ch, buffer[100];//buffer for primitive partitioning
    int i = 0;

    ifstream fin(argv[1]);//input file stream
    if (!fin.is_open())//check file open error
    {
        cout << "open file failure\n";
        exit(0);
    }
    ofstream out(strcat(argv[1], ".out"));//output file stream. the file name is <input_file_name>.out

    while (!fin.eof())//read all character of file
    {
        ch = fin.get();//get char
        if (isalnum(ch) || (ch == '_') || (ch == '.'))//usual input symbols 
        {
            buffer[i++] = ch;
        }
        else if (ch == '"')//if "(for string) is entered
        {
            if (i != 0)//there is preceding charaters before "
            {
                buffer[i] = '\0';//partitioning
                i = 0;
                merged(buffer, out);//test
            }

            buffer[i++] = ch;

            while (!fin.eof())//repeat reading until meet "
            {
                ch = fin.get();
                if (isalnum(ch) || (ch == ' '))//get alphabet, digit, blank
                {
                    buffer[i++] = ch;
                }
                else if (ch == '"')//if meet ", then partitioning and test, break
                {
                    buffer[i++] = ch;
                    buffer[i] = '\0';
                    i = 0;
                    merged(buffer, out);
                    break;
                }
                else if (ch == EOF)//when read everything, but cannot meet "
                {
                    out << "error at \"" << endl;//error and exit
                    exit(0);
                }
                else
                {
                    out << "error at " << ch << endl;//other case, like unvalid symbols
                    exit(0);
                }
            }
        }
        else if ((ch == ' ' || ch == '\n' || ch == '\t')) //ignore whitespace
        {
            if (i != 0)//partitioning
            {
                buffer[i] = '\0';
                i = 0;

                merged(buffer, out);//test
            }
        }
        else if ((ch == '>') || (ch == '<') || (ch == '!') || (ch == '='))//when meet special signs
        {
            if (i != 0)//when there is preceding inputs
            {
                buffer[i] = '\0';//partition
                i = 0;
                //test
                merged(buffer, out);
            }
            buffer[i++] = ch;

            ch = fin.get();//test next char
            if (((ch == '>') && (buffer[0] == '>')) || ((ch == '<') && (buffer[0] == '<')) || (ch == '='))
            {
                buffer[i++] = ch;
                buffer[i] = '\0';
                i = 0;
                //test
                merged(buffer, out);
            }
            else if (buffer[0] == '!')//when input is not !=, it is an error
            {
                out << "Error at !" << endl; 
                exit(0);
            }
            else//when only one character, partition
            {
                buffer[i] = '\0';
                i = 0;
                fin.seekg(-1, ios::cur);//move pointer forward
                //test
                merged(buffer, out);
            }
        }
        else if ((ch == '+') || (ch == '*') || (ch == '/') ||
                 (ch == '&') || (ch == '|') || (ch == ';') || (ch == '{') ||
                 (ch == '}') || (ch == '(') || (ch == ')') || (ch == ',')) //signs with only one case(these have only one char)
        {
            if (i != 0)//partirion preceding inputs
            {
                buffer[i] = '\0';
                i = 0;
                ///test
                merged(buffer, out);
            }
            buffer[i++] = ch;//partition for signs
            buffer[i] = '\0';
            i = 0;
            //test sign
            merged(buffer, out);
        }
        else if (ch == '-')//when input is '-', there is 2 ways to translate
        {
            if (i != 0)//partition preceding inputs
            {
                buffer[i] = '\0';
                i = 0;
                //test
                merged(buffer, out);
            }
            buffer[i++] = ch;
            ch = fin.get();//test next char
            fin.seekg(-1, ios::cur);
            if (!isdigit(ch)) //if next char is not number, this is operator
            {
                buffer[i] = '\0';//partition
                i = 0;
                merged(buffer, out);//test
            }
        }
        else if (ch == EOF)//read all
        {
            out<<"$"<<endl;
            buffer[i] = '\0';//partition
            i = 0;
            //test
            merged(buffer, out);
            exit(0);
        }
        else//input is unvallid symbol
        {
            cout << "unvaild symbol is entered\n"
                 << int(ch);
            exit(0);
        }
    }

    return 0;//end
}
