**1. static method?**
- static method belongs to class, not object instance of the class.
- it can be called without creating an object
- it does not have access to implicit this pointer -> can only access other static member variables or static methods 
- Called directly using the scope resolution operator(::)
- **example**: Calculator::add(5,3)
  
**2. a string representation of c++ literal in its most common form?**
- a literal is a fixed value written directly into the source code. 
- "the most common form" of a string representation  = **string literal** 
- syntax: charactor enclosed with double quotation marks (“ ”)
- underlying type: it evaluates to a null-terminated array of constant characters(const char[])
- **example**: "hello world" is the literal, it is stored in memory with an automatic null-terminator(\0) added at the end
  
**3. scalar types？**
- In C++, scalar types represent a single, atomic value that cannot be broken down into smaller components by the language's type system.
- They contrast with compound types (like arrays, structures or classes)
- Scalar types consist of 4 main categories 
  - Arithmetic types: all integer types (`int, char, bool`) and floating-point types(`float, double`)
  - Enumeration types: User -defined types mapped to discrete values (`enum` or `enum class`)
  - Pointer types: Adresses pointing to tobjects or functions(eg, `int*`)
  - Pointer-to-member types:special pointers pointing to specific member of a class ? 
    - // 1. Declare and initialize the pointer-to-member
    // "ptr" is a pointer to an int member specifically inside the Point class
    int Point::*ptr = &Point::y;

**4. decimal notation?**
- Decimal notation is the standard, base-10 numerical system used to write integer and floating-point literals. It uses digits 0 through 9 and contains no prefix.
- Context: It stands in contrast to other bases in C++, such as Hexadecimal (starts with 0x), Octal (starts with a leading 0), and Binary (starts with 0b).
- Example: Writing 42 in code is decimal notation. Writing 0x2A is the exact same number, but written in hexadecimal notation.
**5. non-displayable characters? **
- Non-displayable characters (often called control characters) are characters that do not print a visual symbol on the screen. Instead, they **trigger formatting actions** or **convey command signals to hardware**(like print terminals).
- ascii values printable : (ch >= 0 && ch <= 31 || ch == 127)
- How to write them: They are written using escape sequences inside character or string literals.
- Common Examples:
  - '\n' : Newline (moves the cursor to the next line)
  - '\t' : Horizontal tab (indents text)
  - '\b' : Backspace
  - '\0' : Null terminator (signals the end of a string)

**6. what is the difference between float literals and double literals**
- The fundamental difference lies in their underlying precision and size in memory, which is dictated by how the literal is typed in the source code.
  
|Feature |	Float Literal	|Double Literal |
|--------|------------------|---------------|
|Syntax Suffix	|Requires an f or F suffix (e.g., 3.14f)| No suffix required. It is the default (e.g., 3.14) |
|Memory Size	|Typically 4 bytes (32 bits)	|Typically 8 bytes (64 bits)|
|Precision	|Single precision (~7 decimal digits)|	Double precision (~15 decimal digits) |

**7. what is pseudo-literals, -inff, +inff, nanf ? what is differrence with -inf, +inf, nan?**

- The term pseudo-literals is sometimes used in debugger outputs, standard documentation, or text parsers to describe representations of special IEEE 754 floating-point values that cannot be typed directly into raw C++ code as literal keywords.
- **+inff / -inff / nanf**: The float (single-precision) version.
- **+inf / -inf / nan**: The double (double-precision) version
- **+inf / -inf**: Positive and negative Infinity. They represent a value that has overflowed the maximum limits of the floating-point type
- **nan / nanf**: Not a Number. This represents an undefined or unrepresentable mathematical result (such as dividing zero by zero 0.0 / 0.0 or taking the square root of a negative number)
- To safely generate these values,
  - wrong: float x =nanf ,reason: nanf isn't a native keyword
  - using  c++<limtis> library (recommended)
```
float p_inf_f = std::numeric_limits<float>::infinity();       // +inff
double p_inf_d = std::numeric_limits<double>::infinity();     // +inf
```
  - using standard functions
```
float my_nan_f = std::nanf("");
double my_nan_d = std::nan("");
```

8. av[], const char*, std::string, c_str()?
9. How to convert an int into float in c++?
```
    // Declaring and initializing variables
    int integerValue = 10;
    double doubleValue = 5.5;

    // integer_value is implicitly promoted to double for the addition
    double result = integerValue + doubleValue;

    // Output the result
    cout << result << endl;  // Output will be 15.5
```
or
```
   int integerValue = 10;

    // Converting integer to float explicitly
    float floatValue = static_cast<float>(integerValue);
   cout << floatValue <<endl; // Output will be 10.0

```
10. Why i can not print .0f even after i converted into a float?
- By default, `std::cout` drops trailling zeros and omits the decimal point if a floating-point number is a whole value (eg, `5.0` points as `5`). It also defaults to **6 significant digits** (total digits ,not just decimals), which can cut off longer decimal numbers or fotmat them into scientific notation. 
- To force c++ to always show the decimal point and a specific number of trailling decimal digits, we need to change the stream's formatting behavior.
- Solution: use `<iomanip>` library and apply the `std::fixed` and `std::setprecision()` stream manipulators
- `std::fixed` : switches the output format from "default/scientific" to fixed-point notation. This forces the stream to always display the decimal point and changes the meaning of `setprecision` from `total significant digits` to `digits after the decimal point`
- `std::setprecision(n)`: Tells the stream exactly how many digits to print after the decimal point. It will automatically round numbers or pad them with trailing zeros as needed.
  
11.   usage of  std::stringstream ss ?
12.   stringstream or istringstream or ostringstresm ? 
13. what is the correct output of 
```
➜  ex00 git:(master) ✗ ./convert a
in display char 
char: a
int: 97
float: 97
double: 97
```   
14. check ss:eof()?
- `std::stringstream::eof()` checks if the End-of-File flag (eofbit) has been set on the stream
- however! checking while(!ss.eof()) is one of the most common anti-patterns in c++ and usually leads to bugs

15. why `if (ss >> f && ss >> suffix && (suffix == 'f' || suffix == 'F') && ss.eof())` isn't giving the right result ? specifically `eof is 0 (false)`?
    1.  ss.eof() = 0, 
    2.  The reason eof is 0 (false) is that `ss >> suffix` stops extracting the moment it successfully grabs the character 'f'. It does not look ahead to see what comes next, so it hasn't attempted to read past it. In C++, eofbit is only set to 1 when a read operation attempts to read data, finds nothing, and fails.
    3. To make `eof()` flip to 1, you have to force the stream to look past the 'f'. You can do this by telling it to peek or consume any remaining whitespace (even if there is none).
    4.  to allow trailling space while still rejecting actual trailling data, use `ss>>std::ws` (which consumes whitespace up to the EOF) right before checking eof()
    5.  `std::ws` is a manipulator that discards whitespace