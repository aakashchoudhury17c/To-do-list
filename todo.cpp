
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            cout << "Enter task: ";
            getline(cin, name);

            tasks.push_back({name, false});
            cout << "Task added!\n";
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                for (int i = 0; i < (int)tasks.size(); i++) {
                    cout << i + 1 << ". "
                         << (tasks[i].completed ? "[Done] " : "[Pending] ")
                         << tasks[i].name << '\n';
                }
            }
        }
        else if (choice == 3) {
            int number;
            cout << "Enter task number: ";
            cin >> number;

            if (number >= 1 && number <= (int)tasks.size()) {
                tasks[number - 1].completed = true;
                cout << "Task completed!\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
