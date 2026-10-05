import subprocess
import sys

# Define your test cases: { input_argument: expected_output }
TEST_CASES = {
    "0": (
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0"
    ),
    "nan": (
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan"
    ),
    "42.0f": (
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0"
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
