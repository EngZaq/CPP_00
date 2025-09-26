///// do not forget to add 42 hidder or you will fail the project /////


#include "phonebook.hpp"

int main(void)
{
    PhoneBook pb;
    std::string command;
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!(std::cin >> command))
            break; // EOF or error -> exit
        if (command == "ADD")
        {
            pb.add_contact();
        }
        else if (command == "SEARCH")
        {
            pb.seach_contact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}
