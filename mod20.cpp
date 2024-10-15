#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string directoryPath;

    std::cout << "enter folder name: ";
    std::cin >> directoryPath; // Вводим имя папки

    // Проверяем, существует ли папка
    if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
        int fileCount = 0;
        int dirCount = 0;
        std::cout << "folder contents " << directoryPath << ":\n";

        // Перебираем содержимое папки
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_directory()) {
                dirCount++; // Увеличиваем счетчик папок
            }
            else if (entry.is_regular_file()) {
                fileCount++; // Увеличиваем счетчик файлов

                // Проверяем расширение файла
                if (entry.path().extension() == ".exe") {
                    std::cout << " .exe file: " << entry.path().filename().string() << std::endl;
                }
            }
        }

        std::cout << "folders number: " << dirCount << std::endl;
        std::cout << "files numbers: " << fileCount << std::endl;
    }
    else {
        std::cout << "folder not found." << std::endl;
    }

    return 0;
}