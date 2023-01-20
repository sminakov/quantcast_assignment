#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>


// Returns date in yyyy-mm-dd format.
std::string formatDate(std::string date) {
    return date.substr(0, 10);
}

std::fstream openFile(std::string fileName) {
    std::fstream file (fileName, std::ios::in);
    if (file.is_open()) {
        return file;
    }
    else {
        throw "Could not open file: " + fileName + "\n";
    }
}

// Assumes the lines in file are sorted by date. Stops searching past target day.
std::vector<std::string> filterByDate(std::fstream & file, std::string targetDate) {
    std::vector<std::string> cookies;
    std::string line, cookie, date;
    bool targetDateReached = false;
    while (std::getline(file, line)) {
        std::stringstream str(line);
        std::getline(str, cookie, ',');
        std::getline(str, date, ',');
        if (formatDate(date) == targetDate) {
            cookies.push_back(cookie);
            targetDateReached = true;
        }
        else if (targetDateReached) break; // If we are past the target date - no need to search further
    }
    return cookies;
}

std::vector<std::string> findMostFrequentCookies(std::vector<std::string> & cookies) {
    std::unordered_map<std::string, int> frequencies;
    std::vector<std::string> mostFrequentCookies;
    int max = 0;
    for (auto & cookie : cookies) {
        if (++frequencies[cookie] > max) max = frequencies[cookie];
    }
    for (std::unordered_map<std::string, int>::iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
        if (it->second == max) {
            mostFrequentCookies.push_back(it->first);
        }
    }
    return mostFrequentCookies;
}

std::vector<std::string> findMostActiveCookies(std::string fileName, std::string date) {
    std::fstream file = openFile(fileName);
    std::vector<std::string> filteredCookies = filterByDate(file, date);
    return findMostFrequentCookies(filteredCookies);
}