#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count_characters(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return -1;
    }

    char c;
    int count = 0;
    while (file.get(c)) {
        count++;
    }

    file.close();
    return count;
}

int count_words(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return -1;
    }

    string word;
    int count = 0;
    while (file >> word) {
        count++;
    }

    file.close();
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " [-c | -w] input_file_name" << endl;
        return 1;
    }

    string option = argv[1];
    string file_name = argv[2];

    if (option == "-c") {
        int char_count = count_characters(file_name);
        if (char_count >= 0) {
            cout << "×Ö·ûÊý: " << char_count << endl;
        }
    } else if (option == "-w") {
        int word_count = count_words(file_name);
        if (word_count >= 0) {
            cout << "µ¥´ÊÊý: " << word_count << endl;
        }
    } else {
        cerr << "Invalid option. Use -c or -w." << endl;
        return 1;
    }

    return 0;
}
