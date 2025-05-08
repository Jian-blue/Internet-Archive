#include <bits/stdc++.h>
using namespace std;

// Base Class
class InternetEvent
{
protected:
    string title;
    int year;
    string description;

public:
    // Constructor
    InternetEvent(string t, int y, string d) {
        title = t;
        year = y;
        description = d;
    }

    // Use of virtual function (Polymorphism)
    virtual void displayDetails() = 0;

    // Getters (Encapsulation)
    int getYear() {
        return year;
    }
    string getTitle() {
        return title;
    }
};

// Derived class-1 (Inheritance)
class TechLaunchEvent : public InternetEvent
{
public:
    TechLaunchEvent(string t, int y, string d)
        : InternetEvent(t, y, d) {}

    void displayDetails() override {
        cout << "\033[34m[Tech Launch] \033[0m" << title << " (" << year << ")\n" << description << "\n";
        cout << "\033[34m------------------------------\033[0m\n";
    }
};

// Derived class-2 (Inheritance)
class MemeEvent : public InternetEvent
{
public:
    MemeEvent(string t, int y, string d)
        : InternetEvent(t, y, d) {}

    void displayDetails() override {
        cout << "\033[32m[Meme] \033[0m" << title << " (" << year << ")\n" << description << "\n";
        cout << "\033[32m------------------------------\033[0m\n";
    }
};

// Archive class (Encapsulation)
class Archive
{
private:
    vector<shared_ptr<InternetEvent>> events;

public:
    void addEvent(shared_ptr<InternetEvent> ev) {
        events.push_back(ev);
    }

    void displayAll() const {
        for (const auto &e : events)
            e->displayDetails(); // Polymorphic call
    }

    // Load from file (File Handling)
    bool loadFromFile(const string &filename) {
        ifstream file(filename);
        if (!file.is_open())
            return false;

        string line, title, description;
        int year;
        bool isMeme = false;

        while (getline(file, title)) {
            if (title.empty())
                continue;

            getline(file, line);
            stringstream ss(line);
            ss >> year;

            getline(file, description);
            getline(file, line); // Consume empty line

            // find: is there "Meme" string present in title or not
            if (title.find("Meme") != string::npos)
                addEvent(make_shared<MemeEvent>(title, year, description));
            else
                addEvent(make_shared<TechLaunchEvent>(title, year, description));
        }

        file.close();
        return true;
    }
};

// Main function
int main()
{
    Archive archive;

    if (archive.loadFromFile("events.txt")) {
        cout << "Events Loaded Successfully!\n\n";
        archive.displayAll();
    }
    else {
        cout << "Failed to open file.\n";
    }

}
