#include <iostream>
#include <vector>
#include <utility> 


void addTask(std::vector<std::pair<std::string, int> > &tasks);
void viewTasks(const std::vector<std::pair<std::string, int> > &tasks);
void markTaskAsCompleted(std::vector<std::pair<std::string, int> > &tasks);
void removeTask(std::vector<std::pair<std::string, int> > &tasks);

int main()
{
    std::vector<std::pair<std::string, int> > tasks;

    while (true)
    {
        std::cout << "\n===== ToDo List Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "=============================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskAsCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            std::cout << "Exiting the program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void addTask(std::vector<std::pair<std::string, int> > &tasks)
{
    std::cout << "Enter task description: ";
    std::string description;
    std::cin.ignore(); 
    std::getline(std::cin, description);
    tasks.push_back(std::make_pair(description, 0)); 
    std::cout << "Task added: " << description << std::endl;
}

void viewTasks(const std::vector<std::pair<std::string, int> > &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        std::cout << (tasks[i].second ? "[Completed] " : "[Pending] ");
        std::cout << tasks[i].first << std::endl;
    }
}

void markTaskAsCompleted(std::vector<std::pair<std::string, int> > &tasks)
{
    viewTasks(tasks); 

    if (tasks.empty())
    {
        std::cout << "No tasks to mark as completed.\n";
        return;
    }

    std::cout << "Enter the task number to mark as completed: ";
    size_t index;
    std::cin >> index;

    if (index >= 1 && index <= tasks.size())
    {
        tasks[index - 1].second = 1; 
        std::cout << "Marked task as completed: " << tasks[index - 1].first << std::endl;
    }
    else
    {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<std::pair<std::string, int> > &tasks)
{
    viewTasks(tasks); 

    if (tasks.empty())
    {
        std::cout << "No tasks to remove.\n";
        return;
    }

    std::cout << "Enter the task number to remove: ";
    size_t index;
    std::cin >> index;

    if (index >= 1 && index <= tasks.size())
    {
        std::cout << "Removed task: " << tasks[index - 1].first << std::endl;
        tasks.erase(tasks.begin() + index - 1);
    }
    else
    {
        std::cout << "Invalid task number.\n";
    }
}

