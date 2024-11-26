//Paul Babayen-on BSCS4A
#include <iostream>
#include <fstream>
#include <string>

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "file created successfully: " << filename << "\n";
    } else {
        std::cout << "error creating file!\n";
    }
    file.close();
}

void writeFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
    if (file) {
        std::string content;
        std::cout << "enter content to write to the file: ";
        std::cin.ignore();
        std::getline(std::cin, content);
        file << content;
        std::cout << "things written to the file.\n";
    } else {
        std::cout << "Error to open file!\n";
    }
    file.close();
}

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        std::string line;
        std::cout << "file contents:\n";
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
    } else {
        std::cout << "error to open file!\n";
    }
    file.close();
}

void appendToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file) {
        std::string content;
        std::cout << "enter things to append to the file: ";
        std::cin.ignore();
        std::getline(std::cin, content);
        file << content;
        std::cout << "things appended to the file.\n";
    } else {
        std::cout << "error to open file!\n";
    }
    file.close();
}

void deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "file deleted successfully.\n";
    } else {
        std::cout << "error to delete file!\n";
    }
}

int main() {
    int choice;
    std::string filename;

    do {
        std::cout << "\nfile management menu:\n";
        std::cout << "1. create file\n2. write to file\n3. read file\n4. append to file\n5. delete file\n6. exit\n";
        std::cout << "enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "enter filename: ";
            std::cin >> filename;
            createFile(filename);
            break;
        case 2:
            std::cout << "enter filename: ";
            std::cin >> filename;
            writeFile(filename);
            break;
        case 3:
            std::cout << "enter filename: ";
            std::cin >> filename;
            readFile(filename);
            break;
        case 4:
            std::cout << "enter filename: ";
            std::cin >> filename;
            appendToFile(filename);
            break;
        case 5:
            std::cout << "enter filename: ";
            std::cin >> filename;
            deleteFile(filename);
            break;
        case 6:
            std::cout << "exiting...\n";
            break;
        default:
            std::cout << "invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
 