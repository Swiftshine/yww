import subprocess
import colorama
from colorama import Fore, Style
colorama.init()

def main():
    # todo - allow user to compile a specified file
    
    COMPILER_EXECUTABLE = "cxppc.exe"

    flags = [
        "-c",
        "-cpu=espresso",
        "-lnk=-undefined",
        "-Ospeed",
        # "-S", # for asm
        "-Isrc/",
        "-Isrc/*",
        "-Isrc/gfl/",
        "-Isrc/merino/",
        "src/merino/object/YsHandle.cpp",
        # "-o build/out.o",
    ]


    try:
        result = subprocess.run(
            [COMPILER_EXECUTABLE] + flags,
            check = True,
            capture_output = True,
            text = True
        )

        has_warnings = len(result.stdout) != 0

        if has_warnings:
            print(Fore.YELLOW + "Compilation succeeded, with warnings:\n" + Style.RESET_ALL, result.stdout)
        else:
            print(Fore.GREEN + "Compilation succeeded." + Style.RESET_ALL)
    except subprocess.CalledProcessError as e:
        print(Fore.RED + "Compilation error occurred:\n" + Style.RESET_ALL, e.stderr)

if __name__ == "__main__":
    main()
