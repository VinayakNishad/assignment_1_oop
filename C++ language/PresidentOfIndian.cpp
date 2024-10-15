#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For setw

using namespace std;

class PresidentOfIndia {
public:
    void president() {
        cout << "\"Smt. Droupadi Murmu For Visit to Rashtrapati Bhavan and Museum: Reception Officer\\r\\n"
             << "\"\\r\\n"
             << "                + //\\r\\n"
             << "                \"Phone: 011-23013287 / 23015321 Ext.: 4662, 4751\"" << endl;

        while (true) {
            cout << "President" << endl;
            cout << "1. Vice President\n2. Prime Minister\n3. Council of Ministers\n4. Governors\n5. Lt. Governors and Administrators\n"
                    "6. Chief Ministers\n7. Judges of Supreme Court\n8. Chiefs of Armed Forces\n9. Members of Parliament\n10. MLAs and MLCs\n11. Go back to main menu"
                 << endl;

            int pchoice;
            cin >> pchoice;

            switch (pchoice) {
                case 1:
                    vicePresident();
                    break;
                case 2:
                    primeMinister();
                    break;
                case 3:
                    councilOfMinisters();
                    break;
                case 4:
                    governors();
                    break;
                case 5:
                    ltGovernorsAndAdministrators();
                    break;
                case 6:
                    chiefMinisters();
                    break;
                case 7:
                    judgesOfSupremeCourt();
                    break;
                case 8:
                    chiefsOfArmedForces();
                    break;
                case 9:
                    membersOfParliament();
                    break;
                case 10:
                    mlasAndMlcs();
                    break;
                case 11:
                    cout << "Returning to main menu..." << endl;
                    return; // This will exit the while loop and return to main menu
                default:
                    cout << "Invalid choice! Please enter a number between 1 and 11." << endl;
            }
        }
    }

    void vicePresident() {
        cout << "Shri Jagdeep Dhankhar\nContact Details:\nVice-President Enclave, 108, Church Road, New Delhi - 110001\n"
             << "Phone: 011-23094953, 23094954\n"
             << "Email: vpindia[at]nic[dot]in" << endl;
    }

    void primeMinister() {
        cout << "Shri Narendra Modi\nTo know more about the Prime Minister click here\nContact Details:\n"
             << "Prime Minister's Office\n"
             << "South Block, Raisina Hill\n"
             << "New Delhi-110011\n"
             << "Phone No: +91-11-23012312\n"
             << "Fax: +91-11-23019545, 23016857\n"
             << "Facebook: https://www.facebook.com/narendramodi\n"
             << "Twitter: https://twitter.com/narendramodi" << endl;
    }

    void councilOfMinisters() {
        cout << "Prime Minister\n"
             << "Shri Narendra Modi\n"
             << "Ministry of Personnel, Public Grievances and Pensions\n"
             << "Department of Atomic Energy\n"
             << "Department of Space\n"
             << "All important policy issues" << endl;

        cout << "Cabinet Ministers" << endl;
        vector<vector<string>> cm = {
            {"Shri Raj Nath Singh\nMinistry of Defence", "Shri Amit Shah\nMinistry of Home Affairs\nMinistry of Cooperation"},
            {"Shri Nitin Jairam Gadkari\nMinistry of Road Transport and Highways", "Shri Jagat Prakash Nadda\nMinistry of Health and Family Welfare\nMinistry of Chemicals and Fertilizers"}
        };

        for (const auto &ministers : cm) {
            cout << ministers[0] << " | " << ministers[1] << endl;
        }

        cout << "Ministers of State (Independent Charge)" << endl;
    }

    void governors() {
        cout << "Governors" << endl;

        vector<vector<string>> data = {
            {"State", "Governor"},
            {"Andhra Pradesh", "Shri Justice (Retd.) S. Abdul Nazeer"},
            {"Arunachal Pradesh", "Lt. General Kaiwalya Trivikram Parnaik, PVSM, UYSM, YSM (Retired)"},
            {"Assam", "Shri Gulab Chand Kataria"}
        };

        for (const auto &entry : data) {
            cout << setw(20) << left << entry[0] << setw(30) << left << entry[1] << endl;
        }
    }

    void ltGovernorsAndAdministrators() {
        cout << "Lt. Governors & Administrators" << endl;
    }

    void chiefMinisters() {
        cout << "Chief Ministers of States" << endl;
    }

    void judgesOfSupremeCourt() {
        cout << "Judges of Supreme Court of India" << endl;
    }

    void chiefsOfArmedForces() {
        cout << "Chiefs of Armed Forces" << endl;
    }

    void membersOfParliament() {
        cout << "Members of Parliament (MPs)" << endl;
    }

    void mlasAndMlcs() {
        cout << "MLAs/MLCs\n"
             << "Users can click the following links to check official websites of all Legislative Assemblies and Legislative Councils in the country. Each website here also contains a list of Members of Legislative Assembly (MLAs) and Legislative Council (MLCs)." << endl;

        vector<vector<string>> statesData = {
            {"Andhra Pradesh", "Arunachal Pradesh", "Assam"},
            {"Bihar", "Chhattisgarh", "Delhi"},
            {"Goa", "Gujarat", "Haryana"},
            {"Himachal Pradesh", "Jammu & Kashmir", "Jharkhand"},
            {"Karnataka", "Kerala", "Madhya Pradesh"},
            {"Maharashtra", "Manipur", "Meghalaya"},
            {"Mizoram", "Nagaland", "Odisha"},
            {"Punjab", "Rajasthan", "Sikkim"},
            {"Tamil Nadu", "Telangana", "Tripura"},
            {"Uttarakhand", "Uttar Pradesh", "West Bengal"}
        };

        // Display the data in columns
        for (const auto &states : statesData) {
            cout << setw(20) << left << states[0] << setw(20) << left << states[1] << setw(20) << left << states[2] << endl;
        }
    }
};