#include "mergesort.h"

#include <fstream>
#include <iostream>
#include <string>

#include <gflags/gflags.h>
#include <glog/logging.h>

using std::cout;
using std::endl;

void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

DEFINE_string(input_file, "", "Input file, if \"\" use randomly generated input");

int main(int argc, char *argv[]) {
    // Command to compile the code: g++ main.cpp mergesort.cpp -lgflags -lglog
    // benchmark: benchmark the sorting time
    int n;
    int* arr;

    google::InitGoogleLogging(argv[0]);
    gflags::SetUsageMessage("Usage of this program");
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    if (FLAGS_input_file.empty()) {
        // Generate random input array
        n = 20;
        arr = GetRandomInput(n);
        LOG(INFO) << "No input file specified, use randomly generated input." << endl;
        if (arr == nullptr) {
            LOG(FATAL) << "Failed to allocate memory." << endl;
        }
    } else {
        // Read input array from the specified file
        std::string line;
        std::ifstream in_file(FLAGS_input_file);
        if (in_file.is_open()) {
            // Parse number of elements
            std::getline(in_file, line);
            n = std::stoi(line);

            // Parse elements
            std::getline(in_file, line);
            arr = ParseInput(line, n);
            in_file.close();
            if (arr == nullptr) {
                LOG(FATAL) << "Invalid input." << endl;
            }
            LOG(INFO) << "Input loaded from: " << FLAGS_input_file << "." << endl;
        } else {
            LOG(FATAL) << "Error opening the file." << endl;
            exit(1);
        }
    }

    cout << "Input : ";
    PrintArray(arr, n);

    MergeSort(arr, n);
    cout << "Output: ";
    PrintArray(arr, n);

    free(arr);
    gflags::ShutDownCommandLineFlags();
    return 0;
}
