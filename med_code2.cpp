#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Class to represent a person

class Person 
{
private:
    string name;
    int powerLevel;

public:

    // Constructor to initialize name and power level of the person

    Person(string n, int p) : name(n), powerLevel(p) {}

    // Getter function to retrieve the name of the person

    string getName() const 
    {
        return name;
    }

    // Getter function to retrieve the power level of the person

    int getPowerLevel() const
     {
        return powerLevel;
    }
};

// Class to manage the MaRS club members and hierarchy

class MaRS 
{
private:
    vector<Person> members; // Vector to store members

    map<string, vector<int>> teams; // Map to store teams and their members (by index)

public:
    // Function to add a member to the club and assign them to a team

    void addMember(const Person& member, string team) 
    {
        members.push_back(member); // Add member to the vector

        teams[team].push_back(members.size() - 1); // Add index of the member in team map
    }

    // Function to communicate within a specific team

    void communicateWithinTeam(string team) 
    {
        // Check if there are members in the specified team

        if (teams.find(team) != teams.end()) 
        {
            cout << "Communication within team " << team << ":\n";

            // Iterate through indices of members of the specified team

            for (int index : teams[team]) 
            {
                cout << "Message to " << members[index].getName() << ": Hello!\n"; // Display message for each member
            }
        } 
        else 
        {
            cout << "No one found in team " << team << endl; // Display message if no members found in the team
        }
    }
};

int main() 
{
    MaRS marsClub;

    // Adding members to the club and assigning them to teams

    marsClub.addMember(Person("Ravi", 1), "mechanical");
    marsClub.addMember(Person("Amit", 2), "software");
    marsClub.addMember(Person("Priya", 1), "electrical");
    marsClub.addMember(Person("Suman", 3), "scientific");

    // Communicating within teams
    
    marsClub.communicateWithinTeam("mechanical");
    marsClub.communicateWithinTeam("software");
    marsClub.communicateWithinTeam("electrical");
    marsClub.communicateWithinTeam("scientific");

    return 0;
}
