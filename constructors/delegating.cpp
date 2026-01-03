#include <iostream>
#include <stdexcept>
#include <string>

// Security levels for tasks
enum SecurityLevel {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
};

// Represents a secure task in a scheduler or kernel
class SecureTask {
    int id;
    int priority;
    SecurityLevel secLevel;

public:
    // Master constructor: everything must go through this
    SecureTask(int taskId, int taskPriority, SecurityLevel level)
        : id(taskId), priority(taskPriority), secLevel(level)
    {
        if (id < 0) throw std::runtime_error("Task id negative, cannot create task");
        if (priority <= 0) throw std::runtime_error("Priority must be positive");
        std::cout << "Master constructor -> Task created: "
                  << "ID=" << id << ", Priority=" << priority
                  << ", Security=" << secLevel << "\n";
    }

    // Delegating constructors
    SecureTask() : SecureTask(generateId(), 1, MEDIUM) {
        std::cout << "Delegated default constructor ran\n";
    }

    SecureTask(int taskId) : SecureTask(taskId, 1, MEDIUM) {
        std::cout << "Delegated constructor with ID ran\n";
    }

    SecureTask(int taskId, int taskPriority) : SecureTask(taskId, taskPriority, LOW) {
        std::cout << "Delegated constructor with ID and priority ran\n";
    }

    // Show info for debugging or logging
    void showTask() const {
        std::cout << "Task Info -> ID: " << id
                  << ", Priority: " << priority
                  << ", SecurityLevel: " << secLevel << "\n";
    }

private:
    // Simple ID generator (simulates system-assigned IDs)
    static int generateId() {
        static int counter = 1000;
        return counter++;
    }
};

int main() {
    try {
        SecureTask t1;              // default
        SecureTask t2(2001);        // ID only
        SecureTask t3(2002, 5);     // ID + priority
        SecureTask t4(2003, 10, HIGH); // fully specified

        std::cout << "\n--- All Tasks ---\n";
        t1.showTask();
        t2.showTask();
        t3.showTask();
        t4.showTask();
    }
    catch (std::exception& e) {
        std::cerr << "Failed to create task: " << e.what() << "\n";
    }
}
