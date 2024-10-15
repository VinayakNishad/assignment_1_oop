#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setw

using namespace std;

// Define MemberOfParliament class
class MemberOfParliament {
private:
    string name;
    string constituency;
    string party;

public:
    MemberOfParliament(string name, string constituency, string party)
        : name(name), constituency(constituency), party(party) {}

    string getName() const { return name; }
    string getConstituency() const { return constituency; }
    string getParty() const { return party; }
};

// Define Bill class
class Bill {
private:
    string title;
    int billID;
    string status;
    int votes;

public:
    Bill(string title, int billID, string status)
        : title(title), billID(billID), status(status), votes(0) {}

    string getTitle() const { return title; }
    int getBillID() const { return billID; }
    string getStatus() const { return status; }
    int getVotes() const { return votes; }
    void vote() { votes++; }
};

// Function prototypes
void rajyaSabha();
void lokSabha();
void introduceBill();
void viewAllBills();
void voteOnBill();
void addMember();
void viewMembers();
void homeInfo();

// Global variables
vector<MemberOfParliament> members;
vector<Bill> bills;
vector<Bill> votedBills;

int main() {
    cout << "\nWelcome to the Indian Parliament" << endl;
    homeInfo();
    
    int choice;
    while (true) {
        cout << "\n1. President of India";
        cout << "\n2. Rajya Sabha of India";
        cout << "\n3. Lok Sabha of India";
        cout << "\n4. View Members of Parliament";
        cout << "\n5. Introduce a New Bill";
        cout << "\n6. View All Bills";
        cout << "\n7. Add Member";
        cout << "\n8. Vote on a Bill";
        cout << "\n9. View Voted Bills";
        cout << "\n0. Exit";
        cout << "\nPlease enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline character
        
        switch (choice) {
            case 1:
                cout << "\nPresident of India functionality not implemented in C++ version." << endl;
                break;
            case 2:
                rajyaSabha();
                break;
            case 3:
                lokSabha();
                break;
            case 4:
                viewMembers();
                break;
            case 5:
                introduceBill();
                break;
            case 6:
                viewAllBills();
                break;
            case 7:
                addMember();
                break;
            case 8:
                voteOnBill();
                break;
            case 9:
                cout << "\nView Voted Bills functionality not implemented in C++ version." << endl;
                break;
            case 0:
                cout << "\nExiting..." << endl;
                return 0;
            default:
                cout << "\nInvalid choice! Please enter a number between 0 and 9." << endl;
        }
    }
}

void rajyaSabha() {
    cout << "\nThe Rajya Sabha should consist of not more than 250 members - 238 members representing the States and Union Territories, and 12 members nominated by the President. Rajya Sabha is a permanent body and is not subject to dissolution. However, one third of the members retire every second year, and are replaced by newly elected members. Each member is elected for a term of six years. The Vice President of India is the ex-officio Chairman of Rajya Sabha. The House also elects a Deputy Chairman from among its members. Besides, there is also a panel of \"Vice Chairmen\" in the Rajya Sabha. The senior most minister, who is a member of Rajya Sabha, is appointed by the Prime Minister as Leader of the House." << endl;
}

void lokSabha() {
    cout << "\nThe Lok Sabha is composed of representatives of people chosen by direct election on the basis of Universal Adult Suffrage. The Constitution of India allows for a maximum of 550 members in the House, with 530 members representing the States and 20 representing the Union Territories. At present, the Lok Sabha has 543 seats filled by elected representatives. The term of the Lok Sabha, unless dissolved, is five years from the date appointed for its first meeting. However, while a proclamation of emergency is in operation, this period may be extended by Parliament by law for a period not exceeding one year at a time and not extending in any case, beyond a period of six months after the proclamation has ceased to operate." << endl;
}

void introduceBill() {
    string title, status;
    int billID;
    
    cout << "\nEnter the title of the new bill: ";
    getline(cin, title);
    cout << "Enter the ID of the new bill: ";
    cin >> billID;
    cin.ignore(); // Consume newline character
    cout << "Enter the status of the new bill: ";
    getline(cin, status);
    
    Bill newBill(title, billID, status);
    bills.push_back(newBill);
    cout << "New bill '" << title << "' has been introduced." << endl;
}

void viewAllBills() {
    cout << "\nHere are all the bills that have been introduced:" << endl;
    for (size_t i = 0; i < bills.size(); ++i) {
        cout << (i + 1) << ". " << bills[i].getTitle()
             << " - Status: " << bills[i].getStatus()
             << " - Votes: " << bills[i].getVotes()
             << " - Bill ID: " << bills[i].getBillID() << endl;
    }
}

void voteOnBill() {
    int billId;
    cout << "\nEnter the ID of the bill you want to vote on: ";
    cin >> billId;
    cin.ignore(); // Consume newline character
    
    Bill* billToVote = nullptr;
    for (size_t i = 0; i < bills.size(); ++i) {
        if (bills[i].getBillID() == billId) {
            billToVote = &bills[i];
            break;
        }
    }
    
    if (billToVote != nullptr) {
        billToVote->vote();
        votedBills.push_back(*billToVote);
        cout << "You have voted on bill '" << billToVote->getTitle() << "'." << endl;
    } else {
        cout << "Invalid bill ID. Please enter a valid bill ID." << endl;
    }
}

void addMember() {
    string name, constituency, party;
    
    cout << "\nEnter the name of the new member: ";
    getline(cin, name);
    cout << "Enter the constituency: ";
    getline(cin, constituency);
    cout << "Enter the party: ";
    getline(cin, party);
    
    MemberOfParliament newMember(name, constituency, party);
    members.push_back(newMember);
    cout << "Member '" << name << "' has been added." << endl;
}

void viewMembers() {
    cout << "\nHere are the current members of the Indian Parliament:" << endl;
    for (size_t i = 0; i < members.size(); ++i) {
        cout << (i + 1) << ". " << members[i].getName()
             << " (" << members[i].getConstituency()
             << ", " << members[i].getParty() << ")" << endl;
    }
}

void homeInfo() {
    cout << "\nIndian Parliament is the supreme legislative body of India. The Indian Parliament comprises of the President and the two Houses - Rajya Sabha (Council of States) and Lok Sabha (House of the People). The President has the power to summon and prorogue either House of Parliament or to dissolve Lok Sabha. The Constitution of India came into force on January 26, 1950. The first general elections under the new Constitution were held during the year 1951-52 and the first elected Parliament came into existence in April, 1952." << endl;

    string data[][2] = {
        {"Lok Sabha", "\tFormed in"},
        {"First", "\tApril, 1952"},
        {"Second", "\tApril, 1957"},
        {"Third", "\tApril, 1962"}
    };

    for (int i = 0; i < 4; ++i) {
        cout << setw(20) << left << data[i][0] << data[i][1] << endl;
    }
}