#include <iostream>
#include <cstdlib>
#include <string>

#ifdef _WIN32
    #include <windows.h>
    #include <winuser.h>
#endif

void restartWindows() {
#ifdef _WIN32
    // Method 1: Using system command
    std::cout << "Restarting Windows system..." << std::endl;
    system("shutdown /r /t 0");
    
    // Method 2: Using Windows API (alternative)
    /*
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    
    // Get a token for this process
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        std::cerr << "OpenProcessToken failed" << std::endl;
        return;
    }
    
    // Get the LUID for the shutdown privilege
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    
    // Adjust token privileges
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
    
    if (GetLastError() != ERROR_SUCCESS) {
        std::cerr << "AdjustTokenPrivileges failed" << std::endl;
        return;
    }
    
    // Restart the system
    if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) {
        std::cerr << "ExitWindowsEx failed" << std::endl;
    }
    */
#else
    std::cout << "This is a Windows-specific restart method." << std::endl;
#endif
}

void restartLinux() {
#ifdef __linux__
    std::cout << "Restarting Linux system..." << std::endl;
    // Note: These commands typically require root privileges
    system("sudo reboot");
    // Alternative: system("sudo shutdown -r now");
#else
    std::cout << "This is a Linux-specific restart method." << std::endl;
#endif
}

void restartMacOS() {
#ifdef __APPLE__
    std::cout << "Restarting macOS system..." << std::endl;
    system("sudo shutdown -r now");
#else
    std::cout << "This is a macOS-specific restart method." << std::endl;
#endif
}

void showMenu() {
    std::cout << "\n=== System Restart Program ===" << std::endl;
    std::cout << "1. Restart Windows" << std::endl;
    std::cout << "2. Restart Linux" << std::endl;
    std::cout << "3. Restart macOS" << std::endl;
    std::cout << "4. Auto-detect and restart" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void autoRestart() {
#ifdef _WIN32
    std::cout << "Windows detected." << std::endl;
    restartWindows();
#elif __linux__
    std::cout << "Linux detected." << std::endl;
    restartLinux();
#elif __APPLE__
    std::cout << "macOS detected." << std::endl;
    restartMacOS();
#else
    std::cout << "Unknown operating system." << std::endl;
#endif
}

int main() {
    int choice;
    char confirm;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        if (choice >= 1 && choice <= 4) {
            std::cout << "\nWARNING: This will restart your computer!" << std::endl;
            std::cout << "Are you sure you want to continue? (y/N): ";
            std::cin >> confirm;
            
            if (confirm == 'y' || confirm == 'Y') {
                switch (choice) {
                    case 1:
                        restartWindows();
                        break;
                    case 2:
                        restartLinux();
                        break;
                    case 3:
                        restartMacOS();
                        break;
                    case 4:
                        autoRestart();
                        break;
                }
                break; // Exit after restart command
            } else {
                std::cout << "Restart cancelled." << std::endl;
            }
        } else if (choice == 5) {
            std::cout << "Exiting program." << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    
    return 0;
}