#ifndef CONSTS_H
#define CONSTS_H

#define FUNCTIONS_LITERALS "sqrt", "log", "ln", "abs"
#define TRIGONOMETRY_LITERALS "cos", "sin", "tan", "atan", "acos", "asin"
#define BUTTONS_TEMPLATE                                \
  {'(', '7', '8', '9', '/'}, {')', '4', '5', '6', '*'}, \
      {'^', '1', '2', '3', '-'}, {                      \
    '%', '.', '0', '=', '+'                             \
  }

#define CELL_W 40 * 5
#define CELL_H 40 * 2

#define DEFAULT_INPUT_STRING_TEXT "Enter your expression there."
#define DEFAULT_OUTPUT_STRING_TEXT "The result or error will be displayed here."
#define DEFAULT_X_INPUT_STRING "Enter your X value there."

#define UNDEFINED_FUNC_ERROR "ERROR: undefined function.(＃°Д°)"
#define BRACKET_ERROR "ERROR: Check the location of the brackets. o((⊙﹏⊙))o"
#define SYNTAX_ERROR "ERROR: syntax error. ≡(▔﹏▔)≡"
#define UNDEFINED_ERROR "EROOR: undefined error. ㄟ( ▔, ▔ )ㄏ"

#define DOUBLE_REG_EXP "^-?[0-9]{1,15}([.][0-9]{1,10})?"
#define X_LITERAL "x"
#define CALCULATE_X_BUTTON_TEXT "Calculate with x"

#define RANGE_INPUT_STRINGS "x min", "x max", "y min", "y max"

#endif  // CONSTS_H