using System;
using System.Collections.Generic;

public class IndianParliamentMenu
{
    private static List<MemberOfParliament> members = new List<MemberOfParliament>();
    private static List<Bill> bills = new List<Bill>();
    private static List<Bill> votedBills = new List<Bill>();

    public static void Main(string[] args)
    {
        var scanner = new Scanner();
        PresidentOfIndia poi = new PresidentOfIndia();
        Console.WriteLine("\nWelcome to the Indian Parliament");
        homeInfo();
        while (true)
        {
            Console.WriteLine("1. President of India");
            Console.WriteLine("2. Rajya Sabha of India");
            Console.WriteLine("3. Lok Sabha of India");
            Console.WriteLine("4. View Members of Parliament");
            Console.WriteLine("5. Introduce a New Bill");
            Console.WriteLine("6. View All Bills");
            Console.WriteLine("7. Add Member");
            Console.WriteLine("8. Vote on a Bill");
            Console.WriteLine("9. View Voted Bills");
            Console.WriteLine("0. Exit");
            Console.Write("Please enter your choice: ");

            int choice = scanner.NextInt();
            scanner.NextLine(); 
            switch (choice) {
                case 1:
                poi.president();
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
                    introduceBill(scanner);
                    break;
                case 6:
                    viewAllBills();
                    break;
                case 7:
                    addMember(scanner);
                    break;
                case 8:
                    voteOnBill(scanner);
                    break;
                case 9:
                    viewVotedBills();
                    break;
                case 0:
                    console.write("Exiting...");
                    scanner.close();
                    System.exit(choice);
                default:
                    console.WriteLine("Invalid choice! Please enter a number between 0 and 9.");
            }
        }
    }
    private static void rajyaSabha() {
        console.WriteLine("The Rajya Sabha should consist of not more than 250 members - 238 members representing the States and Union Territories, and 12 members nominated by the President. Rajya Sabha is a permanent body and is not subject to dissolution. However, one third of the members retire every second year, and are replaced by newly elected members. Each member is elected for a term of six years. The Vice President of India is the ex-officio Chairman of Rajya Sabha. The House also elects a Deputy Chairman from among its members. Besides, there is also a panel of \"Vice Chairmen\" in the Rajya Sabha. The senior most minister, who is a member of Rajya Sabha, is appointed by the Prime Minister as Leader of the House.");
    }

    private static void lokSabha() {
        console.WriteLine("The Lok Sabha is composed of representatives of people chosen by direct election on the basis of Universal Adult Suffrage. The Constitution of India allows for a maximum of 550 members in the House, with 530 members representing the States and 20 representing the Union Territories. At present, the Lok Sabha has 543 seats filled by elected representatives. The term of the Lok Sabha, unless dissolved, is five years from the date appointed for its first meeting. However, while a proclamation of emergency is in operation, this period may be extended by Parliament by law for a period not exceeding one year at a time and not extending in any case, beyond a period of six months after the proclamation has ceased to operat");
    }
    private static void introduceBill(Scanner scanner) {
        console.Write("Enter the title of the new bill:");
        String title = scanner.NextLine();
        console.Write("Enter the ID of the new bill:");
        int billID = scanner.NextInt();
        console.Write("Enter the status of the new bill:");
        String status = scanner.NextLine();
        Bill newBill = new Bill(title, billID, status);
        bills.add(newBill);
        console.WriteLine("New bill '" + title + "' has been introduced.");
    }
    private static void viewAllBills() {
        console.write("Here are all the bills that have been introduced:");
        for (int i = 0; i < bills.size(); i++) {
            console.write((i + 1) + ". " + bills.get(i).getTitle() +
                               " - Status: " + bills.get(i).getStatus() +
                               " - Votes: " + bills.get(i).getVotes() +
                               " - Bill ID: " + bills.get(i).getBillID());
        }
    }
    private static void voteOnBill(Scanner scanner) {
        console.WriteLine("Enter the ID of the bill you want to vote on:");
        int billId = scanner.NextInt();
        Bill billToVote = findBillById(billId);
        if (billToVote != null) {
            billToVote.vote();
            votedBills.add(billToVote);
            console.WriteLine("You have voted on bill '" + billToVote.getTitle() + "'.");
        } else {
            console.WriteLine("Invalid bill ID. Please enter a valid bill ID.");
        }
    }
    private static Bill findBillById(int billId) {
        for (int i = 0; i < bills.size(); i++) {
            Bill bill = bills.get(i);
            if (bill.getBillID() == billId) {
                return bill;
            }
        }
        return null;
    }
    private static void viewVotedBills() {
        console.WriteLine("Here are the bills that have been voted on:");
        for (int i = 0; i < votedBills.size(); i++) {
            console.WriteLine((i + 1) + ". " + votedBills.get(i).getTitle() +
                               " - Votes: " + votedBills.get(i).getVotes());
        }
    }
    private static void addMember(Scanner scanner) {
        console.WriteLine("Enter the name of the new member:");
        String name = scanner.NextLine();
        console.WriteLine("Enter the constituency:");
        String constituency = scanner.NextLine();
        console.WriteLine("Enter the party:");
        String party = scanner.nextLine();
        MemberOfParliament newMember = new MemberOfParliament(name, constituency, party);
        members.add(newMember);
        console.WriteLine("Member '" + name + "' has been added.");
    }
    private static void viewMembers() {
        console.WriteLine("Here are the current members of the Indian Parliament:");
        for (int i = 0; i < members.size(); i++) {
            console.WriteLine((i + 1) + ". " + members.get(i).getName() +
                               " (" + members.get(i).getConstituency() +
                               ", " + members.get(i).getParty() + ")");
        }
    }

    public static void homeInfo() {
        console.WriteLine("Indian Parliament is the supreme legislative body of India. The Indian Parliament comprises of the President and the two Houses - Rajya Sabha (Council of States) and Lok Sabha (House of the People). The President has the power to summon and prorogue either House of Parliament or to dissolve Lok Sabha. The Constitution of India came into force on January 26, 1950. The first general elections under the new Constitution were held during the year 1951-52 and the first elected Parliament came into existence in April, 1952.");
        String[][] data = {
            {"Lok Sabha", "\tFormed in"},
            {"First", "\tApril, 1952"},
            {"Second", "\tApril, 1957"},
            {"Third", "\tApril, 1962"}
        };
        console.WriteLine("%-15s %-10s\n", data[0][0], data[0][1]);
        for (int i = 1; i < data.length; i++) {
            console.WriteLine("%-15s %-10s\n", data[i][0], data[i][1]);
        }
    }



}