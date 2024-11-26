#include <iostream>
#include <fstream>
#include <string>

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created successfully: " << filename << "\n";
    } else {
        std::cout << "Error creating file!\n";
    }
    file.close();
}

void writeFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
    if (file) {
        std::string content;
        std::cout << "Enter content to write to the file: ";
        std::cin.ignore();
        std::getline(std::cin, content);
        file << content;
        std::cout << "Content written to the file.\n";
    } else {
        std::cout << "Error opening file!\n";
    }
    file.close();
}

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        std::string line;
        std::cout << "File contents:\n";
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
    } else {
        std::cout << "Error opening file!\n";
    }
    file.close();
}

void appendToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file) {
        std::string content;
        std::cout << "Enter content to append to the file: ";
        std::cin.ignore();
        std::getline(std::cin, content);
        file << content;
        std::cout << "Content appended to the file.\n";
    } else {
        std::cout << "Error opening file!\n";
    }
    file.close();
}

void deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::cout << "Error deleting file!\n";
    }
}

int main() {
    int choice;
    std::string filename;

    do {
        std::cout << "\nFile Management Menu:\n";
        std::cout << "1. Create File\n2. Write to File\n3. Read File\n4. Append to File\n5. Delete File\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter filename: ";
            std::cin >> filename;
            createFile(filename);
            break;
        case 2:
            std::cout << "Enter filename: ";
            std::cin >> filename;
            writeFile(filename);
            break;
        case 3:
            std::cout << "Enter filename: ";
            std::cin >> filename;
            readFile(filename);
            break;
        case 4:
            std::cout << "Enter filename: ";
            std::cin >> filename;
            appendToFile(filename);
            break;
        case 5:
            std::cout << "Enter filename: ";
            std::cin >> filename;
            deleteFile(filename);
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
 