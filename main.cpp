#include "cookie_analyser.cpp"

int main(int argc, char* argv[]) {
    std::string fileName = "", date = "";
    if (argc >= 5) {
        std::string arg1 = argv[1];
        std::string arg2 = argv[3];
        if (arg1 == "-f" && arg2 == "-d") {
            fileName = argv[2];
            date = formatDate(argv[4]);
        }
        else if (arg1 == "-d" && arg2 == "-f") {
            date = formatDate(argv[2]);
            fileName = argv[4];
        }
    }
    if (fileName == "" || date == "") {
        std::cout << "The arguments provided are not in the correct format. Please provide them in this format: ./program -f 'file_name.csv' -d 'date'.\n";
        return -1;
    }
    for (auto & cookie : findMostActiveCookies(fileName, date)) {
        std::cout << cookie << "\n";
    }
    return 0;
}



