#include <windows.h>
#include <stdio.h>

int main() {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind;

    // Specify the directory and file pattern
    LPCWSTR directory = L"E:\\"; // Adjust the directory as needed

    // Start finding files in the directory
    hFind = FindFirstFileA("E:\\", &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("No files found in the directory.\n");
        return 1;
    }

    // Loop through all files in the directory
    do {
        // Print the file name
        wprintf(L"%s\n", findFileData.cFileName);
    } while (FindNextFileA(hFind, &findFileData) != 0);

    // Close the search handle
    FindClose(hFind);

    return 0;
}
