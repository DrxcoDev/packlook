#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// create a sytem 
void listFiles(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename().string();

        if (fs::is_regular_file(entry)) {
            std::cout << " (" << entry.path().extension().string() << ")";
        }

        std::cout << std::endl;
    }
}

// create a Main

int main() {
    std::string folderPath;
    std::cout << "Your folder PATH: ";
    std::cin >> folderPath;

    try {
        if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
            std::cout << "Folders & Files '" << folderPath << "':" << std::endl;
            listFiles(folderPath);
        }
        else {
            std::cerr << "Not exsist the PATH" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Check Enter for exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Esperar a que el usuario presione Enter

    return 0;
}