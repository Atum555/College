
// Project file headers
#include "SVGElements.hpp"

// C++ library headers
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// POSIX headers
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace svg {
const string LOG_FILE_NAME = "test_log.txt";

class TestDriver {
  private:
    string root_path;
    int    total_tests  = 0;
    int    passed_tests = 0;
    int    failed_tests = 0;
    FILE  *log_stream;

    bool run_conversion_test(const string &id) {
        string svg_file = root_path + "/input/" + id + ".svg";
        string exp_file = root_path + "/expected/" + id + ".png";
        string out_file = root_path + "/output/" + id + ".png";
        convert(svg_file, out_file);
        PNGImage img1(exp_file), img2(out_file);
        int      w1 = img1.width(), h1 = img1.height(), w2 = img2.width(),
            h2 = img2.height();
        if (w1 != w2 || h1 != h2) {
            std::cout << "Images have different dimensions: " << w1 << "x" << h1
                      << " != " << w2 << "x" << h2 << endl;
            return false;
        }
        for (int i = 0; i < w1; i++) {
            for (int j = 0; j < h1; j++) {
                Color c1 = img1.at(i, j), c2 = img2.at(i, j);
                if (c1.red != c2.red || c1.green != c2.green
                    || c1.blue != c2.blue) {
                    cout << "pixel (" << i << ' ' << j << "): expected "
                         << (int)c1.red << ' ' << (int)c1.green << ' '
                         << (int)c1.blue << " got " << (int)c2.red << ' '
                         << (int)c2.green << ' ' << (int)c2.blue << std::endl;
                    return false;
                }
            }
        }
        return true;
    }

    void onTestBegin(const string &id) {
        total_tests++;
        fprintf(log_stream, ">>>> [%d] %s <<<<\n", total_tests, id.c_str());
        fflush(log_stream);
        cout << '[' << total_tests << "] " << id << ": ";
        cout.flush();
    }

    void onTestCompletion(bool success) {
        cout << (success ? "\u001b[32mpass\u001b[0m" : "\u001b[31mfail\u001b[0m") << std::endl;
        if (success) {
            passed_tests++;
        } else {
            failed_tests++;
        }
    }

    void run_test(const string &id) {
        int log_fd = ::fileno(log_stream);
        onTestBegin(id);
        ::pid_t pid = ::fork();

        if (pid == 0) {
            ::dup2(log_fd, 1);
            ::dup2(log_fd, 2);
            bool success = run_conversion_test(id);
            ::exit(success ? 0 : 1);
        } else if (pid > 0) {
            // parent process waits
            int child_status = -1;
            ::waitpid(pid, &child_status, 0);

            bool success
                = WIFEXITED(child_status) && WEXITSTATUS(child_status) == 0;
            onTestCompletion(success);
        } else {
            // pid < 0
            perror("Unable to run tests! Process creation failed!");
            ::exit(1);
        }
    }

  public:
    TestDriver(const string &root_path)
        : root_path(root_path),
          log_stream(fopen((root_path + "/" + LOG_FILE_NAME).c_str(), "w")) {}

    void run_tests(const string &spec) {
        string dir_path  = root_path + "/input";
        ::DIR *directory = ::opendir(dir_path.c_str());
        if (directory == nullptr) {
            cerr << "Unable to open input directory " << dir_path << endl;
            return;
        }
        vector<string> scripts_to_execute;
        ::dirent      *entry;
        while ((entry = readdir(directory)) != nullptr) {
            if (entry->d_type == DT_REG) {
                string fname = entry->d_name;
                if (fname.find(spec) == 0) {
                    scripts_to_execute.push_back(
                        fname.substr(0, fname.find_last_of('.'))
                    );
                }
            }
        }
        ::closedir(directory);
        if (scripts_to_execute.empty()) {
            cout << "No scripts matched the spec: " << spec << endl;
            return;
        }
        sort(scripts_to_execute.begin(), scripts_to_execute.end());

        cout << "== " << scripts_to_execute.size()
             << " tests to execute  ==" << endl;
        for (string id : scripts_to_execute) { run_test(id); }

        cout << "== TEST EXECUTION SUMMARY ==" << endl
             << "Total tests: " << total_tests << endl
             << "Passed tests: " << passed_tests << endl
             << "Failed tests: " << failed_tests << endl
             << "See " << LOG_FILE_NAME << " for details." << endl;
    }
};
} // namespace svg

int main(int argc, char **argv) {
    --argc;
    ++argv;
    svg::TestDriver driver(argc == 2 ? argv[1] : ".");
    string          spec = argc >= 1 ? argv[0] : "";
    driver.run_tests(spec);

    return 0;
}
