#include <windows.h>
#include <stdio.h>

int main() {
    // Set up process information structures
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Specify the program to execute (Notepad)
    const wchar_t* programPath = L"C:\\Windows\\System32\\notepad.exe";

    // Specify the command line arguments (file path)
    const wchar_t* commandLineArgs = L"C:\\path\\to\\your\\file.txt";

    // Create the process
    if (CreateProcess(NULL, const_cast<LPWSTR>(programPath), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // Wait for the process to finish (optional)
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Clean up handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        wprintf(L"Error creating process: %d\n", GetLastError());
    }

    return 0;
}
