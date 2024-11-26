#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void createDirectory(const std::string& dirname) {
    if (fs::create_directory(dirname)) {
        std::cout << "Directory created: " << dirname << "\n";
    } else {
        std::cout << "Error creating directory!\n";
    }
}

void listDirectory(const std::string& dirname) {
    std::cout << "Contents of directory " << dirname << ":\n";
    for (const auto& entry : fs::directory_iterator(dirname)) {
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << "\n";
    }
}

void removeDirectory(const std::string& dirname) {
    if (fs::remove_all(dirname)) {
        std::cout << "Directory removed: " << dirname << "\n";
    } else {
        std::cout << "Error removing directory!\n";
    }
}

int main() {
    int choice;
    std::string dirname;

    do {
        std::cout << "\nDirectory Operations Menu:\n";
        std::cout << "1. Create Directory\n2. List Directory Contents\n3. Remove Directory\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter directory name: ";
            std::cin >> dirname;
            createDirectory(dirname);
            break;
        case 2:
            std::cout << "Enter directory name: ";
            std::cin >> dirname;
            listDirectory(dirname);
            break;
        case 3:
            std::cout << "Enter directory name: ";
            std::cin >> dirname;
            removeDirectory(dirname);
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
