import subprocess
import sys

# Define your test cases: { input_argument: expected_output }
# Define your test cases: { input_argument: expected_output }
TEST_CASES = {
    # === 1. BASIC SCALAR TYPES ===
    "0": (
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0"
    ),
    "42.0f": (
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0"
    ),
    "a": (
        "char: 'a'\n"
        "int: 97\n"
        "float: 97.0f\n"
        "double: 97.0"
    ),
    
    # === 2. CHAR EDGE CASES ===
    "*": (
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0"
    ),
    "127": (
        "char: Non displayable\n"
        "int: 127\n"
        "float: 127.0f\n"
        "double: 127.0"
    ),
    "128": (
        "char: impossible\n" # Out of ASCII range
        "int: 128\n"
        "float: 128.0f\n"
        "double: 128.0"
    ),

    # === 3. INT OVERFLOWS / EDGE CASES ===
    "2147483647": (
        "char: impossible\n"
        "int: 2147483647\n"
        "float: 2147483648.0f\n" # May vary slightly by rounding precision
        "double: 2147483647.0"
    ),
    "2147483648": (
        "char: impossible\n"
        "int: impossible\n" # Max int overflow
        "float: 2147483648.0f\n"
        "double: 2147483648.0"
    ),
    "-2147483649": (
        "char: impossible\n"
        "int: impossible\n" # Min int underflow
        "float: -2147483648.0f\n"
        "double: -2147483649.0"
    ),

    # === 4. FLOATS AND DOUBLES ===
    "-4.2": (
        "char: impossible\n"
        "int: -4\n"
        "float: -4.2f\n"
        "double: -4.2"
    ),
    "4.20000f": (
        "char: impossible\n"
        "int: 4\n"
        "float: 4.2f\n" # Should trim trailing decimal zeros to 1 precision point if needed
        "double: 4.2"
    ),

    # === 5. PSEUDO LITERALS (Special Cases) ===
    "nan": (
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan"
    ),
    "nanf": (
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan"
    ),
    "+inf": (
        "char: impossible\n"
        "int: impossible\n"
        "float: inff\n"
        "double: inf"
    ),
    "-inff": (
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf"
    ),

    # === 6. INVALID / TRICKY INPUTS ===
    # These should print "impossible" or fail gracefully depending on your error handling
    "42.42f_extra": (
        "char: impossible\n"
        "int: impossible\n"
        "float: impossible\n"
        "double: impossible"
    ),
    "abc": (
        "char: impossible\n"
        "int: impossible\n"
        "float: impossible\n"
        "double: impossible"
    ),
    "": (
        "char: impossible\n"
        "int: impossible\n"
        "float: impossible\n"
        "double: impossible"
    ),
}


def run_tests():
    failed = 0
    for arg, expected in TEST_CASES.items():
        print(f"Testing argument: '{arg}'... ", end="")
        
        # Execute the binary and capture stdout
        result = subprocess.run(["./convert", arg], capture_output=True, text=True)
        actual = result.stdout.strip()
        
        if actual == expected.strip():
            print("\033[92mPASS\033[0m")
            print(f"--- Actual -----\n{actual}\n" + "-"*30)
        else:
            print("\033[91mFAIL\033[0m")
            print(f"\n--- Expected ---\n{expected}")
            print(f"--- Actual -----\n{actual}\n" + "-"*30)
            failed += 1
            
    if failed == 0:
        print("\n\033[92m🎉 All tests passed successfully!\033[0m")
        sys.exit(0)
    else:
        print(f"\n\033[91m❌ {failed} test(s) failed.\033[0m")
        sys.exit(1)

if __name__ == "__main__":
    run_tests()
