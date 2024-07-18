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

    Token_stream(istream& ts);
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
const char constant = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 'S';
const char power = 'P';
const char help = 'H';

Token Token_stream::get() // get token from cin
{
    if(full)
    {
        full = false;
        return buffer;
    }
    while(true)
    {

        char ch;
        cin.get(ch);

        switch(ch)
        {
            case quit:
            case help:
            case print:
            case let:
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '=':
            case ',': return Token(ch);
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
                    while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
                    cin.unget();
                    if(s == "quit")
                        return Token(quit);
                    if(s == "sqrt")
                    {
                        return Token(square_root);
                    }
                    if(s == "pow")
                    {
                        return Token(power);
                    }
                    if(s == "const")
                    {
                        return Token(constant);
                    }
                    if(s == "help")
                    {
                        return Token(help);
                    }
                    return Token(name, s);
                }
                if(isspace(ch))
                {
                    if(ch == '\n')
                        return Token{print};
                    break;
                }

                error("Bad token");
        }
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
    bool is_constant;

    Variable(string n, double v, bool b) : name(n), value(v), is_constant(b) {}
};

class Symbol_table // defining function class
{
public:
    vector<Variable> var_table{
        Variable("k", 1000, true), Variable("pi", 3.14, true), Variable("e", 2.7182818284, true)};
    double get_value(string s);
    double set_value(string s, double d);
    bool is_declared(string s);
    double declaration();
    double const_declaration();
};

Symbol_table st;

double Symbol_table::get_value(string s) // function that get a variable value
{
    for(Variable v : var_table)
    {
        if(v.name == s)
        {
            return v.value;
        }
    }
    error("get: undefined name ", s);
}

double Symbol_table::set_value(string s, double d) // function that set a new value to a variable
{
    for(Variable v : var_table)
        if(v.name == s)
        {
            if(v.is_constant == true)
            {
                error("set: trying to change constant value");
            }
            else
                v.value = d;
            return v.value;
        }
    error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s) // checks if a variable is already declared
{
    for(Variable v : var_table)
        if(v.name == s)
            return true;
    return false;
}

Token_stream ts;

double expression(Token_stream& ts);

double primary(Token_stream& ts) // deal with numbers and parentheses
{
    Token t = ts.get(); // get from cin
    switch(t.kind)
    {
        case '(':
        {
            double d = expression(ts);
            t = ts.get();
            if(t.kind != ')' && t.kind != ',')
                error("'(' expected");
            return d;
        }
        case '-': // case it is a negative number
            return -primary(ts);
        case number: return t.value;
        case name: // case it is a variable
        {
            string s = t.name;
            t = ts.get();

            if(t.kind == '=') // checking if wants to give a new value to an already existed variable
            {
                double d = expression(ts);
                return st.set_value(s, d);
            }
            ts.unget(t);

            return st.get_value(s);
        }
        case square_root: // calculating sqrt()
        {
            double d = primary(ts); // getting the number inside the parentheses
            if(d < 0)
                error("can't calculate sqrt() of negative number");
            return sqrt(d);
        }
        case power: // calculating power
        {
            double d = primary(ts);
            double f = primary(ts);
            ts.ignore(')');
            return pow(d, f);
        }
        default: error("primary expected");
    }
}

double pow(double x, int y) // deal with power numbers
{
    if(y == 0)
    {
        return 1;
    }

    for(int i = 1; i < y; i++) { x *= x; }
    return x;
}

double term(Token_stream& ts) // deal with '*' and '/'
{
    double left = primary(ts);
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '*': left *= primary(ts); break;
            case '/':
            {
                double d = primary(ts);
                if(d == 0)
                    error("divide by zero");
                left /= d;
                break;
            }
            case '%':
            {
                double d = primary(ts);
                if(d == 0)
                    error("%: divide by zero");
                left = fmod(left, d);
                break;
            }
            default: ts.unget(t); return left;
        }
    }
}

double expression(Token_stream& ts) // deal with '+' and '-'
{
    double left = term(ts);
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '+': left += term(ts); break;
            case '-': left -= term(ts); break;
            default: ts.unget(t); return left;
        }
    }
}

double Symbol_table::const_declaration() // declares a variable
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
    double d = expression(ts);
    var_table.push_back(Variable(name, d, true));
    return d;
}

double Symbol_table::declaration() // declares a variable
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
    double d = expression(ts);
    var_table.push_back(Variable(name, d, false));
    return d;
}

double statement() // declares/calculate a variable or a constant
{
    Token t = ts.get();
    switch(t.kind)
    {
        case constant: // declares a constant
            return st.const_declaration();
        case let: // declares a variable
            return st.declaration();
        default: // calculate a variable or a constant
            ts.unget(t);
            return expression(ts);
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void print_help()
{
    cout << "Welcome to the calculator!\n"
         << "This calculator can add, subtract, divide, multiply and factorial!\n"
         << "Also have square root function ('sqrt(x)') and power function (pow(x, y))\n"
         << "You can define a variable typing '# name = x' and a constant typing 'const name = x'\n"
         << "Add ';' to the end of an expression to calculate it\n"
         << "'1 + 2;' will print out '= 3'\n";
}

void calculate()
{
    while(true) try
        {
            cout << prompt;
            Token t = ts.get();
            if(t.kind == help)
            {
                print_help();
                t = ts.get();
                continue;
            }
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
