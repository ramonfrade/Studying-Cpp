
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "PPP2/std_lib_facilities.h"

struct Token // defining token class
{
public:
    char kind;
    double value;
    string name;

    Token(char ch) : kind(ch) {}

    Token(char ch, double val) : kind(ch), value(val) {}

    Token(char ch, string s) : kind(ch), name(s) {}
};

class Token_stream // defining token stream
{
    bool full;
    Token buffer;

public:
    Token_stream() : full(false), buffer(0) {}

    Token get(); // get token from cin

    void unget(Token t) // store token in buffer
    {
        buffer = t;
        full = true;
    }

    void ignore(char);
};

// defining constant keywords
const char let = '#'; // define variable
const char quit = 'E';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 'S';
const char power = 'P';

Token Token_stream::get() // get token from cin
{
    if(full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch)
    {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
        case ',':
        case '#': return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            cin.unget();
            double val;
            cin >> val;
            return Token(number, val);
        }
        default:
            if(isalpha(ch)) // checking if it is a variable
            {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                cin.unget();
                if(s == "exit")
                    return Token(quit);
                if(s == "sqrt")
                {
                    return Token(square_root);
                }
                if(s == "pow")
                {
                    return Token(power);
                }

                return Token(name, s);
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char c) // function that 'throws away' token
{
    if(full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch;
    while(cin >> ch)
        if(ch == c)
            return;
}

struct Variable // defining variable class
{
    string name;
    double value;

    Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> names{Variable("k", 1000)};

double get_value(string s) // function that get a variable value
{
    for(int i = 0; i < names.size(); ++i)
        if(names[i].name == s)
            return names[i].value;
    error("get: undefined name ", s);
}

void set_value(string s, double d) // function that set a new value to a variable
{
    for(int i = 0; i <= names.size(); ++i)
        if(names[i].name == s)
        {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s) // checks if a variable is already declared
{
    for(int i = 0; i < names.size(); ++i)
        if(names[i].name == s)
            return true;
    return false;
}

Token_stream ts;

double expression();

double primary() // deal with numbers and parentheses
{
    Token t = ts.get(); // get from cin
    switch(t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')' && t.kind != ',')
                error("'(' expected");
            return d;
        }
        case '-': // case it is a negative number
            return -primary();
        case number: return t.value;
        case name: // case it is a variable
            return get_value(t.name);
        case square_root: // calculating sqrt()
        {
            double d = primary(); // getting the number inside the parentheses
            if(d < 0)
                error("can't calculate sqrt() of negative number");
            return sqrt(d);
        }
        case power: // calculating power
        {
            double d = primary();
            double f = primary();
            ts.ignore(')');
            return pow(d, f);
        }
        default: error("primary expected");
    }
}

double pow(double x, int y)
{
    if(y == 0)
    {
        return 1;
    }

    for(int i = 1; i < y; i++) { x *= x; }
    return x;
}

double term() // deal with '*' and '/'
{
    double left = primary();
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '*': left *= primary(); break;
            case '/':
            {
                double d = primary();
                if(d == 0)
                    error("divide by zero");
                left /= d;
                break;
            }
            case '%':
            {
                double d = primary();
                if(d == 0)
                    error("%: divide by zero");
                left = fmod(left, d);
                break;
            }
            default: ts.unget(t); return left;
        }
    }
}

double expression() // deal with '+' and '-'
{
    double left = term();
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '+': left += term(); break;
            case '-': left -= term(); break;
            default: ts.unget(t); return left;
        }
    }
}

double declaration() // declares a variable
{
    Token t = ts.get();
    if(t.kind != 'a')
        error("name expected in declaration");
    string name = t.name;
    if(is_declared(name))
        error(name, " declared twice");
    Token t2 = ts.get();
    if(t2.kind != '=')
        error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}

double statement() // declares or calculate a variable
{
    Token t = ts.get();
    switch(t.kind)
    {
        case let: // declares a variable
            return declaration();
        default: // calculate a variable
            ts.unget(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while(true) try
        {
            cout << prompt;
            Token t = ts.get();
            while(t.kind == print) t = ts.get();
            if(t.kind == quit)
                return;
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch(runtime_error& e)
        {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()

try
{
    calculate();
    return 0;
}
catch(exception& e)
{
    cerr << "exception: " << e.what() << endl;
    char c;
    while(cin >> c && c != ';');
    return 1;
}
catch(...)
{
    cerr << "exception\n";
    char c;
    while(cin >> c && c != ';');
    return 2;
}