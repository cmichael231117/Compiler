#20154521 Seokjun CHoi
#syntax analyzer
# - This is python3 code for syntax analyzer.
# - If you want to execute this program, then execute. 
#   command 'python3 syntax_analyzer <input_file_name>' ex) test input file name is 'testcode.txt.out'
# - If you wrote input file correctly, this program will give you message that given code is accepted or rejected
# - This program determine that given code is valid in syntax. 
# - If you understand how does this work, then read code and comments carefully.
import sys
#check argument #
if len(sys.argv) != 2:
    print("Insufficient arguments")
    sys.exit()
#file name
file_path = sys.argv[1]
#read file
with open(file_path, mode='rt', encoding='utf-8') as f:
    terminal_list = f.readlines()
## if lines
terminal_num = len(terminal_list)
#print(terminal_num)
#initial
splitter = 0
state = 0
#for slr parsing
stack = [0]
#goto() with current_state and non-terminal
def goto(cur_state, nonterminal):
    global state, stack
    if(cur_state==0): #current_state
        if(nonterminal=='A'): #non-terminal
            state = 1 #goto 1
            stack.append(state) #push current state into stack
        elif(nonterminal=='B'):
            state = 3
            stack.append(state)
        elif(nonterminal=='C'):
            state = 2
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==2):
        if(nonterminal=='A'):
            state = 5
            stack.append(state)
        elif(nonterminal=='B'):
            state = 3
            stack.append(state)
        elif(nonterminal=='C'):
            state = 2
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==3):
        if(nonterminal=='A'):
            state = 6
            stack.append(state)
        elif(nonterminal=='B'):
            state = 3
            stack.append(state)
        elif(nonterminal=='C'):
            state = 2
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==4):
        if(nonterminal=='H'):
            state = 8
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==10):
        if(nonterminal=='I'):
            state = 13
            stack.append(state)
        elif(nonterminal=='J'):
            state = 15
            stack.append(state)
        elif(nonterminal=='K'):
            state = 16
            stack.append(state)
        elif(nonterminal=='L'):
            state = 17
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==11):
        if(nonterminal=='D'):
            state = 22
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==18):
        if(nonterminal=='J'):
            state = 26
            stack.append(state)
        elif(nonterminal=='K'):
            state = 16
            stack.append(state)
        elif(nonterminal=='L'):
            state = 17
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==24):
        if(nonterminal=='J'):
            state = 29
            stack.append(state)
        elif(nonterminal=='K'):
            state = 16
            stack.append(state)
        elif(nonterminal=='L'):
            state = 17
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==25):
        if(nonterminal=='K'):
            state = 30
            stack.append(state)
        elif(nonterminal=='L'):
            state = 17
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==28):
        if(nonterminal=='E'):
            state = 33
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==32):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 35
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==35):
        if(nonterminal=='N'):
            state = 45
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==36):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 47
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==43):
        if(nonterminal=='H'):
            state = 8
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==46):
        if(nonterminal=='L'):
            state = 55
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==48):
        if(nonterminal=='H'):
            state = 56
            stack.append(state)
        else:
            print('error')
            sys.exit()
    
    elif(cur_state==49):
        if(nonterminal=='L'):
            state = 58
            stack.append(state)
        elif(nonterminal=='M'):
            state = 57
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==50):
        if(nonterminal=='L'):
            state = 58
            stack.append(state)
        elif(nonterminal=='M'):
            state = 59
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==53):
        if(nonterminal=='E'):
            state = 60
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==62):
        if(nonterminal=='L'):
            state = 58
            stack.append(state)
        elif(nonterminal=='M'):
            state = 66
            stack.append(state)
        else:
            print('error')
            sys.exit()    

    elif(cur_state==64):
        if(nonterminal=='L'):
            state = 68
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==67):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 71
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==69):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 72
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==70):
        if(nonterminal=='H'):
            state = 73
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==75):
        if(nonterminal=='Q'):
            state = 77
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==79):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 81
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

    elif(cur_state==80):
        if(nonterminal=='B'):
            state = 41
            stack.append(state)
        elif(nonterminal=='F'):
            state = 82
            stack.append(state)
        elif(nonterminal=='G'):
            state = 36
            stack.append(state)
        elif(nonterminal=='H'):
            state = 40
            stack.append(state)
        else:
            print('error')
            sys.exit()

#get current_state(top) from stack
def current_state(stack):
    return stack[len(stack)-1]    

#check entire table. shift&goto or reduce&goto.
def check_table():
    #global variables
    global state, splitter, terminal_list, stack
    #accept
    if(state == 1 and terminal_list[splitter]=='$\n'):
        print('accept')
        sys.exit()

    elif(state==0) :
        #shift&goto
        if(terminal_list[splitter]=='vtype\n'):
            state = 4 #goto
            splitter = splitter + 1#shift
            stack.append(state) #push current state into stack
            print(stack) #give information
        elif(terminal_list[splitter]=='$\n'):
            #no pop
            #call goto
            goto(current_state(stack), 'A')
        else:#reject
            #give error message&info.
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or '$'")
            sys.exit() #terminate

    elif(state==2):
        if(terminal_list[splitter]=='vtype\n'):
            state = 4
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='$\n'):
            goto(current_state(stack), 'A')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or '$'")
            sys.exit()

    elif(state==3):
        if(terminal_list[splitter]=='vtype\n'):
            state = 4
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='$\n'):
            goto(current_state(stack), 'A')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or '$'")
            sys.exit()

    elif(state==4):
        if(terminal_list[splitter]=='id\n'):
            state = 7
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==5):
        if(terminal_list[splitter]=='$\n'):
            #pop twice
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'A')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected '$'")
            sys.exit()
    
    elif(state==6):
        if(terminal_list[splitter]=='$\n'):
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'A')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected '$'")
            sys.exit()

    elif(state==7):
        if(terminal_list[splitter]=='assign\n'):
            state = 10
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='semi\n'):
            state = 9
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 11
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'assign' or 'semi' or 'lparen'")
            sys.exit()

    elif(state==8):
        if(terminal_list[splitter]=='semi\n'):
            state = 12
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi'")
            sys.exit()

    elif(state==9):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n' or terminal_list[splitter]=='$\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'B')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace' or '$'")
            sys.exit()
            
    elif(state==10):
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='literal\n'):
            state = 14
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'literal' or 'id' or 'lparen'")
            sys.exit()

    elif(state==11):
        if(terminal_list[splitter]=='vtype\n'):
            state = 23
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='rparen\n'):
            goto(current_state(stack), 'D')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'rparen'")
            sys.exit()

    elif(state==12):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n' or terminal_list[splitter]=='$\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'B')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace' or '$'")
            sys.exit()

    elif(state==13):
        if(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'H')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi' or 'rparen'")
            sys.exit()

    elif(state==14):
        if(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'I')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi' or 'rparen'")
            sys.exit()

    elif(state==15):
        if(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'I')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi' or 'rparen'")
            sys.exit()

    elif(state==16):
        if(terminal_list[splitter]=='addsub\n'):
            state = 24
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'J')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'addsub' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==17):
        if(terminal_list[splitter]=='multdiv\n'):
            state = 25
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'K')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'multdiv' or 'addsub' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==18):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==19):#k l o r n
        if(terminal_list[splitter]=='comp\n' or terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='multdiv\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'L')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comp' or 'addsub' or 'multdiv' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==20):#k l o r n
        if(terminal_list[splitter]=='comp\n' or terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='multdiv\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'L')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comp' or 'addsub' or 'multdiv' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==21):#k l o r n
        if(terminal_list[splitter]=='comp\n' or terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='multdiv\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            goto(current_state(stack), 'L')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comp' or 'addsub' or 'multdiv' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==22):
        if(terminal_list[splitter]=='rparen\n'):
            state = 27
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==23):
        if(terminal_list[splitter]=='id\n'):
            state = 28
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==24):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==25):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==26):
        if(terminal_list[splitter]=='rparen\n'):
            state = 31
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==27):
        if(terminal_list[splitter]=='lbrace\n'):
            state = 32
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lbrace'")
            sys.exit()

    elif(state==28):
        if(terminal_list[splitter]=='comma\n'):
            state = 34
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='rparen\n'):
            goto(current_state(stack), 'E')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comma' or 'rparen'")
            sys.exit()

    elif(state==29):# o r
        if(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'J')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi' or 'rparen'")
            sys.exit()

    elif(state==30):#k o r
        if(terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'K')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'addsub' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==31):#k l o r n
        if(terminal_list[splitter]=='comp\n' or terminal_list[splitter]=='addsub\n' or terminal_list[splitter]=='multdiv\n' or terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'L')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comp' 'addsub' or 'semi' or 'rparen'")
            sys.exit()

    elif(state==32):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==33):#r
        if(terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'D')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==34):
        if(terminal_list[splitter]=='vtype\n'):
            state = 44
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype'")
            sys.exit()

    elif(state==35):
        if(terminal_list[splitter]=='return\n'):
            state = 46
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'return'")
            sys.exit()

    elif(state==36):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==37):
        if(terminal_list[splitter]=='lparen\n'):
            state = 48
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lparen'")
            sys.exit()

    elif(state==38):
        if(terminal_list[splitter]=='lparen\n'):
            state = 49
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lparen'")
            sys.exit()

    elif(state==39):
        if(terminal_list[splitter]=='lparen\n'):
            state = 50
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lparen'")
            sys.exit()

    elif(state==40):
        if(terminal_list[splitter]=='semi\n'):
            state = 51
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi'")
            sys.exit()
    
    elif(state==41):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            goto(current_state(stack), 'G')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==42):
        if(terminal_list[splitter]=='assign\n'):
            state = 10
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'assign'")
            sys.exit()

    elif(state==43):
        if(terminal_list[splitter]=='id\n'):
            state = 52
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==44):
        if(terminal_list[splitter]=='id\n'):
            state = 53
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==45):
        if(terminal_list[splitter]=='rbrace\n'):
            state = 54
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==46):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==47):#j t
        if(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'return' or 'rbrace'")
            sys.exit()

    elif(state==48):
        if(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==49):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==50):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==51):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'G')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==52):#m o
        if(terminal_list[splitter]=='assign\n'):
            state = 10
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='semi\n'):
            state = 9
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'assign' or 'semi'")
            sys.exit()

    elif(state==53):#p #r
        if(terminal_list[splitter]=='comma\n'):
            state = 34
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='rparen\n'):
            goto(current_state(stack), 'E')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comma' or 'rparen'")
            sys.exit()

    elif(state==54):#p #r
        if(terminal_list[splitter]=='$\n' or terminal_list[splitter]=='vtype\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'C')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected '$'")
            sys.exit()

    elif(state==55):
        if(terminal_list[splitter]=='semi\n'):
            state = 61
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi'")
            sys.exit()

    elif(state==56):
        if(terminal_list[splitter]=='semi\n'):
            state = 62
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi'")
            sys.exit()

    elif(state==57):
        if(terminal_list[splitter]=='rparen\n'):
            state = 63
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==58):
        if(terminal_list[splitter]=='comp\n'):
            state = 64
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'comp'")
            sys.exit()

    elif(state==59):
        if(terminal_list[splitter]=='rparen\n'):
            state = 65
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==60):#p #r
        if(terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'E')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==61):#p #r
        if(terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'N')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==62):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==63):
        if(terminal_list[splitter]=='lbrace\n'):
            state = 67
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lbrace'")
            sys.exit()

    elif(state==64):#bceq
        if(terminal_list[splitter]=='num\n'):
            state = 20
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='float\n'):
            state = 21
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 19
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='lparen\n'):
            state = 18
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'num' or 'float' or 'id' or 'lparen'")
            sys.exit()

    elif(state==65):
        if(terminal_list[splitter]=='lbrace\n'):
            state = 69
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lbrace'")
            sys.exit()

    elif(state==66):
        if(terminal_list[splitter]=='semi\n'):
            state = 70
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi'")
            sys.exit()

    elif(state==67):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==68):#p #r
        if(terminal_list[splitter]=='semi\n' or terminal_list[splitter]=='rparen\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'M')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'semi' or 'rparen'")
            sys.exit()

    elif(state==69):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==70):
        if(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'id'")
            sys.exit()

    elif(state==71):
        if(terminal_list[splitter]=='rbrace\n'):
            state = 74
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==72):
        if(terminal_list[splitter]=='rbrace\n'):
            state = 75
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==73):
        if(terminal_list[splitter]=='rparen\n'):
            state = 76
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rparen'")
            sys.exit()

    elif(state==74):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'G')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==75):
        if(terminal_list[splitter]=='else\n'):
            state = 78
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'Q')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'else' or 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==76):
        if(terminal_list[splitter]=='lbrace\n'):
            state = 79
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lbrace'")
            sys.exit()

    elif(state==77):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'G')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==78):
        if(terminal_list[splitter]=='lbrace\n'):
            state = 80
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'lbrace'")
            sys.exit()

    elif(state==79):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==80):#a e f h i # j t
        if(terminal_list[splitter]=='vtype\n'):
            state = 43
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='id\n'):
            state = 42
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='if\n'):
            state = 39
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='while\n'):
            state = 38
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='for\n'):
            state = 37
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        elif(terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            goto(current_state(stack), 'F')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==81):
        if(terminal_list[splitter]=='rbrace\n'):
            state = 83
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==82):
        if(terminal_list[splitter]=='rbrace\n'):
            state = 84
            splitter = splitter + 1
            stack.append(state)
            print(stack)
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'rbrace'")
            sys.exit()

    elif(state==83):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'G')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

    elif(state==84):
        if(terminal_list[splitter]=='vtype\n' or terminal_list[splitter]=='id\n' or terminal_list[splitter]=='if\n' or terminal_list[splitter]=='while\n' or terminal_list[splitter]=='for\n' or terminal_list[splitter]=='return\n' or terminal_list[splitter]=='rbrace\n'):
            stack.pop()
            stack.pop()
            stack.pop()
            stack.pop()
            goto(current_state(stack), 'Q')
        else:
            print("reject!")
            print("line " + str(splitter+1) + " : we expected 'vtype' or 'id' or 'if' or 'while' or 'for' or 'return' or 'rbrace'")
            sys.exit()

#loop until the end
while(True):
    check_table()
