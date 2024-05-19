/*  GRAMMAR:

    Calculation:
                Help
                Print
                Quit
                Statement
                Calculation Statement
    Help:
            H
            help
    Print:
            ;
    Quit:
            Q
            quit
    Statement:
                Declaration
                Expression
    Declaration:
                # Name "=" Expression
                const Name "=" Expression
    Expression:
                Term
                Expression + Term
                Expression – Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
            Number
            ( Expression )
            – Primary
            + Primary
            sqrt( Expression )
            pow( Expression )
    Number:
            floating-point-literal
*/