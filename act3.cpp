// Paul Babayen-on BSCS4A
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void createDirectory(const std::string& path) {
    try {
        if (fs::create_directory(path)) {
            std::cout << "Directory created: " << path << "\n";
        } else {
            std::cout << "Error: Could not create directory! It may already exist.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void listDirectory(const std::string& path) {
    try {
        if (fs::exists(path) && fs::is_directory(path)) {
            std::cout << "Contents of directory " << path << ":\n";
            for (const auto& entry : fs::directory_iterator(path)) {
                std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << "\n";
            }
        } else {
            std::cout << "Error: Path does not exist or is not a directory.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void removeDirectory(const std::string& path) {
    try {
        if (fs::exists(path)) {
            fs::remove_all(path);
            std::cout << "Directory removed: " << path << "\n";
        } else {
            std::cout << "Error: Directory does not exist.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

int main() {
    int choice;
    std::string path;

    do {
        std::cout << "\nDirectory Operations Menu:\n";
        std::cout << "1. Create Directory\n";
        std::cout << "2. List Directory Contents\n";
        std::cout << "3. Remove Directory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter directory path (e.g., folder/subfolder): ";
            std::cin >> path;
            createDirectory(path);
            break;
        case 2:
            std::cout << "Enter directory path: ";
            std::cin >> path;
            listDirectory(path);
            break;
        case 3:
            std::cout << "Enter directory path: ";
            std::cin >> path;
            removeDirectory(path);
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
