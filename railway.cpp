
// bushra hamna komal.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip> //manipulators for formatting input and output
#include <cctype> //for character classification and manipulation, such as checking if a character is a digit, letter
using namespace std;
const int TOTAL_SEATS = 100;
const int BUSINESS_FARE = 6500;
const int ECONOMY_FARE = 5500;
struct Train 
{
    string companyName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    string date;
	//constructor
    Train(string comp = "", string src = "", string dest = "", string dep = "", string arr = "", string dt = "")
        : companyName(comp), source(src), destination(dest), departureTime(dep), arrivalTime(arr), date(dt) 
	{}
};
struct Node 
{
    string name;
    string gender;
    string id;
    string seatClass;
    int ticketNumber;
    string source;
    string destination;
    int fare;
   string status;
   string date;
    Node* next;
	Node * prev;
    // Default constructor to initialize members
     Node(string n, string g, string i, string s, int t, string src, string dest, int f, string stat, string d)
        : name(n), gender(g), id(i), seatClass(s), ticketNumber(t), source(src), destination(dest), fare(f),
          status(stat), date(d), next(nullptr), prev(nullptr) {}
};
class Railway //linklist class 
{
private:
  
    Node* head;
    Node* tail;
    int bookedEconomy;
    int bookedBusiness;
    int ticketCounter;
    Train trains[10];
public:
    Railway() : head(nullptr), tail(nullptr), bookedEconomy(0), bookedBusiness(0), ticketCounter(1) //constructor for the linklist nodes 
	{
        trains[0] = Train("Company A", "Rawalpindi", "Lahore",      "10:00 AM", "2:00 PM",  "2024-12-15");
        trains[1] = Train("Company B", "Rawalpindi", "Faisalabad",  "11:00 AM", "3:00 PM",  "2024-12-16");
        trains[2] = Train("Company C", "Rawalpindi", "karachi", "1:00 PM",  "5:00 PM",  "2024-12-15");
        trains[3] = Train("Company D", "Lahore",     "gilgit", "9:00 AM",  "12:00 PM", "2024-12-17");
        trains[4] = Train("Company E", "Rawalpindi", "Chakwal",     "6:00 AM",  "9:00 AM",  "2024-12-16");
        trains[5] = Train("Company F", "Karachi",    "Islamabad",   "8:00 AM",  "12:00 PM", "2024-12-18");
        trains[6] = Train("Company G", "Lahore",     "Multan",      "7:00 AM",  "10:00 AM", "2024-12-19");
        trains[7] = Train("Company H", "Faisalabad", "Karachi",     "5:00 PM",  "10:00 PM", "2024-12-20");
        trains[8] = Train("Company I", "Peshawar",   "Quetta",      "3:00 PM",  "8:00 PM",  "2024-12-21");
        trains[9] = Train("Company J", "Lahore",     "Sialkot",     "4:00 PM",  "6:00 PM",  "2024-12-22");
    }
    ~Railway() //destructor
	{
        Node* current = head;
        while (current) 
		{
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
	//adding passengers
    void addPassenger(string name, string gender, string id, string seatClass, 
        int ticketNumber, string source, string destination, int fare, string status, string date) 
	{
        Node* newNode = new Node(name, gender, id, seatClass, ticketNumber, source, destination, fare, status, date);   
        if (!head) 
		{
            head = tail = newNode;
        } 
		else 
		{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
	//display
	void displayPassengers() 
	{
        if(!head)
		{
            cout << "No passengers in the system.\n";
            return;
        }
        Node* current = head;
        cout << "\n--- Passenger Details ---\n";
        while (current) 
		{
            cout << "Name: " << current->name << ", Gender: " << current->gender
                 << ", ID: " << current->id << ", Seat Class: " << current->seatClass
                 << ", Ticket: " << current->ticketNumber << ", Source: " << current->source
                 << ", Destination: " << current->destination << ", Fare: " << current->fare
                 << ", Date: " << current->date << "\n";
            current = current->next;
        }
    }
	//book a ticket
	void bookTicket() 
	{ static int ticketCounter = 10; // Static ensures the value persists across calls
    int ticketNumber = ticketCounter++;
    string passengerName, gender, cnic, source, destination, date, seatClass;
    int seatID = 1; // Initialize seat ID counter
    cout << "Enter passenger name: ";
    while (true) 
	{
        getline(cin, passengerName);
        bool isValid = true;
        for (size_t i = 0; i < passengerName.length(); i++) 
		{
            if (passengerName[i] >= '0' && passengerName[i] <= '9') 
			{ // Check if character is a digit
                isValid = false;
                break;
            }
        }
        if (isValid && !passengerName.empty()) 
		{ // Valid input and not empty
            break; // Valid input, exit the loop
        } 
		else 
		{
            cout << "Invalid input. Please enter a valid name (letters only): ";
        }
	}
    cout << "Passenger name entered: " << passengerName << endl;
    cout << "Enter gender (M/F): ";
	 while (true)
	 {
        getline(cin, gender);
        // Convert input to lowercase for case-insensitive comparison
        for (size_t i = 0; i < gender.length(); i++) 
		{
            gender[i] = tolower(gender[i]); // Convert each character to lowercase
        }
        // Check if the input is valid
        if (gender == "male" || gender == "female"||gender=="f"||gender=="m"||gender=="F"||gender=="M") 
		{
            break; // Valid input, exit the loop
        } 
		else
		{
            cout << "Invalid input. Please enter Male or Female: ";
        }
    }
    cout << "Gender entered: " << gender << endl;
    cout << "Enter CNIC: ";
    bool isValid = false;
    while (!isValid) {
        getline(cin, cnic);
        // Check if the CNIC has exactly 13 digits
        if (cnic.length() == 13) 
		{
            isValid = true; // Assume valid unless proven otherwise
            for (size_t i = 0; i < cnic.length(); i++)
			{
                if (cnic[i] < '0' || cnic[i] > '9')
				{
                    isValid = false; // Found a non-digit, mark as invalid
                    break;
                }
            }
        }
		else 
		{
            isValid = false; // Length is not 13, mark as invalid
        }
        if (!isValid)
		{
            cout << "Invalid CNIC. CNIC should only contain 13 digits and no letters. Please try again: ";
        }
    }
    cout << "CNIC entered: " << cnic << endl;
    cout << "Enter source station: ";
    getline(cin, source);
    cout << "Enter destination station: ";
    getline(cin, destination);
    string travelDate;
    cout << "Enter travel date (YYYY-MM-DD): ";
    while (true) 
	{
        getline(cin, travelDate);
        // Check if the length is correct (10 characters for YYYY-MM-DD)
        if (travelDate.length() != 10) 
		{
            cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD): ";
            continue;
        }
        // Check if the format has dashes in the correct positions
        if (travelDate[4] != '-' || travelDate[7] != '-') 
		{
            cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD): ";
            continue;
        }
        // Extract year, month, and day as integers
        int year = stoi(travelDate.substr(0, 4));
        int month = stoi(travelDate.substr(5, 2));
        int day = stoi(travelDate.substr(8, 2));
        // Check if year, month, and day are valid
        if (year < 1000 || year > 9999 || month < 1 || month > 12)
		{
            cout << "Invalid date. Please enter a valid date (YYYY-MM-DD): ";
            continue;
        }
        // Array for number of days in each month (ignoring leap years for simplicity)
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
            daysInMonth[1] = 29; // February has 29 days in leap years
        }
        if (day < 1 || day > daysInMonth[month - 1])
		{
            cout << "Invalid day for the given month. Please enter a valid date (YYYY-MM-DD): ";
            continue;
        }
        // If all checks pass, the date is valid
        break;
    }
    cout << "Travel date entered: " << travelDate << endl;
    cout << "Enter seat class (Business/Economy): ";
    getline(cin, seatClass);
    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; i < source.length(); ++i) source[i] = tolower(source[i]);
    for (int i = 0; i < destination.length(); ++i) destination[i] = tolower(destination[i]);
    for (int i = 0; i < seatClass.length(); ++i) seatClass[i] = tolower(seatClass[i]);
    bool isEconomy = (seatClass == "e" || seatClass == "economy"|| seatClass=="Economy");
    bool isBusiness = (seatClass == "b" || seatClass == "business"||seatClass=="Business");
    if (!isEconomy && !isBusiness) 
	{
        cout << "Invalid seat class. Please choose Business (B/b) or Economy (E/e).\n";
		getline(cin,seatClass);
        
    }
    bool found = false;
    cout << "\nAvailable Trains:\n";
    for (int i = 0; i < 10; ++i) 
	{
        string trainSource = trains[i].source;
        string trainDestination = trains[i].destination;
        // Convert train source and destination to lowercase
        for (int j = 0; j < trainSource.length(); ++j) trainSource[j] = tolower(trainSource[j]);
        for (int j = 0; j < trainDestination.length(); ++j) trainDestination[j] = tolower(trainDestination[j]);
        // Match source and destination only
        if (trainSource == source && trainDestination == destination)
		{
            found = true;
            cout << i + 1 << ". Company Name: " << trains[i].companyName
                 << ", Departure: " << trains[i].departureTime
                 << ", Arrival: " << trains[i].arrivalTime << endl;
        }
    }
    if (!found) 
	{
        cout << "No trains available for the given source and destination.\n";
    }
	else
	{
        cout << "Select a train from (1-10) : ";
        string trainIndexStr;
        getline(cin, trainIndexStr); // Read train index as string for flexibility
        int trainIndex = stoi(trainIndexStr); // Convert to integer
        if (trainIndex >= 1 && trainIndex <= 10)  
{   
   int ticketNumber = ticketCounter++; // Assign a ticket number starting from 11
int baseFare = isBusiness ? 6500 : 5500; // Fare for Business and Economy classes
int foodCharge = isEconomy ? 100 : 0; 
string foodOption = isBusiness ? "Food included." : "Food not included. Rs 100 charged.";
seatID++; // Assign seat ID and increment for the next booking
int totalFare = baseFare + foodCharge; // Calculate the total fare

cout << "Ticket booked successfully for " << passengerName << " on Train " 
     << trains[trainIndex - 1].companyName << "!\n"
     << "Ticket Number: " << ticketNumber << "\n" // Ticket number added
     << "Seat Class: " << (isBusiness ? "Business" : "Economy") << "\n" 
     << foodOption << "\n" 
     << "Seat ID: " << seatID << "\n" 
     << "Base Fare: Rs " << baseFare << "\n"
     << (foodCharge > 0 ? "Food Charge: Rs 100\n" : "")
     << "Total Fare: Rs " << totalFare << endl;

if (isEconomy) {
    cout << "Food charge of Rs 100 added to your bill.\n";
}

}
 }
	}
	//for canceling and deleting
 void cancel_or_deletebyticket() 
{
    string ticketNumberStr;
    int ticketNumber;
    cout << "Enter the ticket number to cancel: ";
    cin >> ticketNumberStr;
    // Check if the input is numeric using a loop
    bool isNumeric = true;
    for (size_t i = 0; i < ticketNumberStr.length(); ++i) 
	{
        if (!isdigit(ticketNumberStr[i])) 
		{
            isNumeric = false;
            break;
        }
    }
    if (!isNumeric) 
	{
        cout << "Invalid input. Please enter a numeric ticket number.\n";
        cin>> ticketNumberStr;
    }
    // Convert the valid numeric string to an integer
    ticketNumber = stoi(ticketNumberStr);
    Node* current = head;
    while (current) 
    {
        if (current->ticketNumber == ticketNumber)
        {
            // Case: deleting the head node
            if (current == head)
            {
                head = current->next;
                if (head) 
					{
						head->prev = nullptr;
				}
                else 
					{tail = nullptr; // If the list is now empty
				}
            } 
            // Case: deleting the tail node
            else if (current == tail) 
            {
                tail = current->prev;
                if (tail)
					{tail->next = nullptr;
				}
                else
					{head = nullptr; // If the list is now empty
				}
            } 
            // Case: deleting a node in the middle
            else 
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Ticket " << ticketNumber << " successfully canceled.\n";
            return;
        }
        current = current->next;
    }
    // Ticket not found
    cout << "Ticket number " << ticketNumber << " not found.\n";
}
 //modify passsenegr details
 void modify_pessenger_details()
{
    string ticketNumberStr;
    int ticketNumber;
    cout << "Enter the ticket number to modify: ";
    cin >> ticketNumberStr;
    // Loop until a valid numeric input is provided
    bool isNumeric = false;
    while (!isNumeric) 
	{
        isNumeric = true; // Assume input is valid
        for (size_t i = 0; i < ticketNumberStr.length(); ++i) 
		{
            if (ticketNumberStr[i] < '0' || ticketNumberStr[i] > '9') 
			{
                isNumeric = false;
                break;
            }
        }
        if (!isNumeric) 
		{
            cout << "Invalid input. Please enter a numeric ticket number: ";
            cin >> ticketNumberStr;
        }
    }
    // Convert the valid numeric string to an integer
    ticketNumber = 0;
    for (size_t i = 0; i < ticketNumberStr.length(); ++i)
	{
        ticketNumber = ticketNumber * 10 + (ticketNumberStr[i] - '0');
    }
    Node* current = head;
    while (current)
    {
        if (current->ticketNumber == ticketNumber) 
        {
            cout << "Modify details for Ticket " << ticketNumber << ":\n";
            // Modify name
            while (true) 
			{
                cout << "Enter new name (current: " << current->name << "): ";
                cin.ignore();
                getline(cin, current->name);
                bool validName = true;
                for (size_t i = 0; i < current->name.length(); ++i) 
				{
                    if (!((current->name[i] >= 'A' && current->name[i] <= 'Z') ||
                          (current->name[i] >= 'a' && current->name[i] <= 'z') ||
                          current->name[i] == ' ')) 
					{
                        validName = false;
                        break;
                    }
                }
                if (validName && !current->name.empty())
				{
                    break;
                } 
				else
				{
                    cout << "Invalid input. Please enter a valid name (letters and spaces only).\n";
                }
            }
            // Modify gender
           while (true)
		   {
			   cout << "Enter new gender (current: " << current->gender << "): ";
               string newGender;
               getline(cin, newGender);
			   if ((current->gender == "Male" || current->gender == "M" || current->gender == "m") &&
                 (newGender == "Female" || newGender == "F" || newGender == "f"||newGender=="female"||newGender=="male")) {
                  current->gender = newGender;
                  break;
			   } 
			   else if ((current->gender == "Female" || current->gender == "F" || current->gender == "f") &&
               (newGender == "Male" || newGender == "M" || newGender == "m"||newGender=="female"||newGender=="male"))
			   {  
				   current->gender = newGender;
                   break;
               } 
			   else 
			   {
				   cout << "Invalid input. Please enter a valid gender based on the current one.\n";
		           getline(cin, newGender);
			   }
		   }
            // Modify CNIC
            while (true) 
			{
                cout << "Enter new CNIC (current: " << current->id << "): ";
                getline(cin, current->id);
                bool validCNIC = true;
                if (current->id.length() != 13) 
				{
                    validCNIC = false;
                } 
				else 
				{
                    for (size_t i = 0; i < current->id.length(); ++i) 
					{
                        if (current->id[i] < '0' || current->id[i] > '9') 
						{
                            validCNIC = false;
                            break;
                        }
                    }
                }
                if (validCNIC) 
				{
                    break;
                } 
				else 
				{
                    cout << "Invalid input. Please enter a valid 13-digit CNIC number.\n";
                }
            }
            // Modify seat class
            while (true)
			{
                cout << "Enter new seat class (Business/Economy, current: " << current->seatClass << "): ";
                getline(cin, current->seatClass);
                if (current->seatClass == "Business" || current->seatClass == "Economy") 
				{
                    break;
                } 
				else 
				{
                    cout << "Invalid input. Please enter either 'Business' or 'Economy'.\n";
                }
            }
            // Modify date
            while (true) 
			{
                cout << "Enter new date (current: " << current->date << "): ";
                getline(cin, current->date);
                if (!current->date.empty()) 
				{ 
                    break;
                }
				else 
				{
                    cout << "Invalid input. Please enter a valid date.\n";
                }
            }
            if (current->seatClass == "Business")
            {
                current->fare = BUSINESS_FARE;
            } 
            else
            {
                current->fare = ECONOMY_FARE;
            }

            cout << "Passenger details successfully updated.\n";
            return;
        }
        current = current->next;
    }
    cout << "Ticket number " << ticketNumber << " not found.\n";
	}
	//searchbytciket
	void search_by_ticket()
	{
    int ticketNumber;
    cout << "Enter ticket number to search: ";
    while (true) 
    {
        cin >> ticketNumber;
        if (cin.fail()) 
        {
            cin.clear();                
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a valid numeric ticket number: ";
        } 
        else 
        {
            cin.ignore();  
            break;      
        }
    }
    Node* current = head;
    while (current) 
    {
        if (current->ticketNumber == ticketNumber) 
        {
            cout << "\nPassenger Found: \n";
            cout << "Name: " << current->name << ", Gender: " << current->gender
                 << ", ID: " << current->id << ", Seat Class: " << current->seatClass
                 << ", Ticket: " << current->ticketNumber << ", Source: " << current->source
                 << ", Destination: " << current->destination << ", Fare: " << current->fare
                 << ", Date: " << current->date << "\n";
            return;
        }
        current = current->next;
    }
    cout << "Ticket number " << ticketNumber << " not found.\n";
	}
	//searchbyname
   void search_by_name() 
   {
    string name;
    bool isValid = false;
    // Input validation loop
    do 
    {
        cout << "Enter name to search: ";
        getline(cin, name);
        isValid = true; // Assume input is valid initially
        for (size_t i = 0; i < name.length(); i++) 
        {
            if (!isalpha(name[i]) && name[i] != ' ') 
            {
                isValid = false; // Mark as invalid if any character is not alphabetic or a space
                cout << "Invalid input. Please enter a valid name (alphabetic characters only).\n";
                break;
            }
        }
    } while (!isValid); // Repeat until valid input is entered
    // Search logic
    Node* current = head;
    while (current) 
    {
        if (compare_strings_ignore_case(current->name, name)) 
        {
            cout << "\nPassenger Found: \n";
            cout << "Name: " << current->name << ", Gender: " << current->gender
                 << ", ID: " << current->id << ", Seat Class: " << current->seatClass
                 << ", Ticket: " << current->ticketNumber << ", Source: " << current->source
                 << ", Destination: " << current->destination << ", Fare: " << current->fare
                 << ", Date: " << current->date << "\n";
            return;
        }
        current = current->next;
	}
    cout << "No passenger found with the name " << name << ".\n";
   }
   //display avaible seats 
   void display_seat_available() 
   {
    cout << "\n--- Available Seats ---\n";
    for (int i = 0; i < 10; ++i) {
        int availableEconomy = TOTAL_SEATS - bookedEconomy;
        int availableBusiness = TOTAL_SEATS - bookedBusiness;
        cout << trains[i].companyName << " (" << trains[i].source << " to " << trains[i].destination
             << ", Date: " << trains[i].date << ")\n";
        cout << "Available Economy Seats: " << availableEconomy << "\n";
        cout << "Available Business Seats: " << availableBusiness << "\n";
    }
   }
   //swapping
   void swap_by_name_and_id() 
   {
    int ticketNumber1, ticketNumber2;
    auto get_valid_ticket_number = []() -> int 
	{
        int ticketNumber;
        while (true) 
        {
            cout << " ticket number: ";
            cin >>ticketNumber;
            if (cin.fail()) 
            {
                cin.clear();               
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid input. Please enter a numeric ticket number.\n";
            } 
            else 
            {
                cin.ignore(INT_MAX, '\n');  
                return ticketNumber;       
            }
        }
    };
    // Get validated ticket numbers
    cout << "Enter the first";
    ticketNumber1 = get_valid_ticket_number();
    cout << "Enter the second";
    ticketNumber2 = get_valid_ticket_number();
    Node* passenger1 = nullptr;
    Node* passenger2 = nullptr;
    Node* current = head;
    // Locate the passengers with the given ticket numbers
    while (current) 
    {
        if (current->ticketNumber == ticketNumber1) 
        {
            passenger1 = current;
        }
        if (current->ticketNumber == ticketNumber2) 
        {
            passenger2 = current;
        }
        current = current->next;
    }
    // Swap if both passengers are found
    if (passenger1 && passenger2) 
    {
        // Swap name and ID
        string tempName = passenger1->name;
        string tempID = passenger1->id;
        passenger1->name = passenger2->name;
        passenger1->id = passenger2->id;
        passenger2->name = tempName;
        passenger2->id = tempID;
        cout << "Passenger names and IDs successfully swapped.\n";
    } 
    else 
    {
        cout << "One or both ticket numbers not found.\n";
    }
   }
   void sort_by_id_and_by_name() // bubble sorting 
   {
    if (!head) 
    {
        cout << "No passengers to sort.\n";
        return;
    }
    int sortChoice;
    cout << "Choose sorting criterion:\n";
    cout << "1. Sort by Ticket ID\n";
    cout << "2. Sort by Name\n";
    cout << "Enter your choice (1/2): ";
    cin >> sortChoice;
    cin.ignore();  // To clear the newline character left by cin
    if (sortChoice == 1) 
    {
        sort_by_id();
    }
    else if (sortChoice == 2) 
    {
        sort_by_name();
    } 
    else 
    {
        cout << "Invalid choice! Please select either 1 or 2.\n";
    }
   }
   void sort_by_id() //bubble sort  
   {
    if (!head) 
    {
        cout << "No passengers to sort.\n";
        return;
    }
    bool swapped;
    do 
    {
        swapped = false;
        Node* current = head;
        while (current && current->next) 
        {
            if (current->ticketNumber > current->next->ticketNumber) 
            {
                // Swap all fields between current and next
                swap(current->name, current->next->name);
                swap(current->gender, current->next->gender);
                swap(current->id, current->next->id);
                swap(current->seatClass, current->next->seatClass);
                swap(current->ticketNumber, current->next->ticketNumber);
                swap(current->source, current->next->source);
                swap(current->destination, current->next->destination);
                swap(current->fare, current->next->fare);
                swap(current->status, current->next->status);
                swap(current->date, current->next->date);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    cout << "Passengers sorted by Ticket ID.\n";
   }
   void sort_by_name() //bubble sort 
   {
    if (!head) 
    {
        cout << "No passengers to sort.\n";
        return;
    }
    bool swapped;
    do 
    {
        swapped = false;
        Node* current = head;
        while (current && current->next) 
        {
            if (current->name > current->next->name)  // Compare strings alphabetically
            {
                // Swap all fields between current and next
                swap(current->name, current->next->name);
                swap(current->gender, current->next->gender);
                swap(current->id, current->next->id);
                swap(current->seatClass, current->next->seatClass);
                swap(current->ticketNumber, current->next->ticketNumber);
                swap(current->source, current->next->source);
                swap(current->destination, current->next->destination);
                swap(current->fare, current->next->fare);
                swap(current->status, current->next->status);
                swap(current->date, current->next->date);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    cout << "Passengers sorted by Name.\n";
   }
   //count total nodes 
   void count_total_no_of_passengers() 
	{
        int count = 0;
        Node* current = head;
        while (current)
		{
            count++;
            current = current->next;
        }
        cout << "Total number of passengers: " << count << "\n";
    }
    bool compare_strings_ignore_case(const string& str1, const string& str2)
	{
    if (str1.length() != str2.length()) 
		return false;
    for (size_t i = 0; i < str1.length(); ++i)
	{
        if (tolower(str1[i]) != tolower(str2[i])) 
		{
            return false;
        }
    }
    return true;
}
};
int main() 
{
    Railway r;
    // Adding at least 10 passengers for demonstration
    r.addPassenger("z",     "Female",   "123456789", "Economy",  5, "Rawalpindi",   "Lahore",      5500, "Booked", "2024-12-15");
    r.addPassenger("B",     "Male",     "987654321", "Business", 2, "Rawalpindi",   "Faisalabad",  6500, "Booked", "2024-12-16");
    r.addPassenger("C",     "Male",     "456789123", "Economy",  3, "Rawalpindi",   "Sheikhupura", 5500, "Booked", "2024-12-15");
    r.addPassenger("Diana", "Female",   "321654987", "Business", 4, "Lahore",       "Sheikhupura", 6500, "Booked", "2024-12-17");
    r.addPassenger("than",  "Male",     "654321789", "Economy",  1, "Rawalpindi",   "Chakwal",     5500, "Booked", "2024-12-16");
    r.addPassenger("Fiona", "Female",   "789123456", "Business", 6, "Karachi",      "Islamabad",   6500, "Booked", "2024-12-18");
    r.addPassenger("x",     "Male",     "159753486", "Economy",  7, "Lahore",       "Multan",      5500, "Booked", "2024-12-19");
    r.addPassenger("nnah",  "Female",   "753159486", "Business", 9, "Faisalabad",   "Karachi",     6500, "Booked", "2024-12-20");
    r.addPassenger("Ian",   "Male",     "951753486", "Economy",  8, "Peshawar",     "Quetta",      5500, "Booked", "2024-12-21");
    r.addPassenger("lia",   "Female",   "357159486", "Business", 10, "Lahore",      "Sialkot",     6500, "Booked", "2024-12-22");
	cout<<"INITIALLY THE NODES IN LINKLIST (MANGEMENT SYSTEM) ARE :"<<endl;
    r.displayPassengers();
	int choice;
    char restart;
	do
	{
		cout<<"==============================================="<<endl;
		cout << "\t\n--- RAILWAY MANAGEMENT SYSTEM ---\n";
        cout << "1. Book a Ticket\n";
        cout << "2. Cancel/Delete by Ticket\n";
        cout << "3. Modify Passenger Details\n";
        cout << "4. Search by Ticket\n";
        cout << "5. Search by Name\n";
        cout << "6. Display Available Seats\n";
        cout << "7. Swap by ID\n";
        cout << "8. Display Details of Passengers after adding passenger\n";
        cout << "9. Count Total Number(nodes of linklist) of Passengers\n";
        cout << "10.Sort by ID\n";
        cout << "11.Sort by Name\n";
	    cout << "12.Add/insetion pessenegers (in linklist) \n";
        cout << "13.Exit\n";
        while (true) 
		{
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) 
	{ 
        cin.clear(); 
        cin.ignore(100, '\n'); 
        cout << "Invalid input. Please enter a valid number.\n";
    } else if (choice < 1 || choice > 13) 
	{ 
        cout << "Invalid choice. Please enter a number between 1 and 13.\n";
    } else {
		cin.ignore(100, '\n'); 
        break; 
    }
		}
    switch (choice) 
	{
        case 1:
            r.bookTicket();
            break;
        case 2:
            r.cancel_or_deletebyticket();
            break;
        case 3:
            r.modify_pessenger_details();
            r.displayPassengers();
            break;
        case 4:
            r.search_by_ticket();
            break;
        case 5:
            r.search_by_name();
            break;
        case 6:
            r.display_seat_available();
            break;
        case 7:
            r.swap_by_name_and_id();
            r.displayPassengers();
            break;
        case 8:
            r.displayPassengers();
            break;
        case 9:
            r.count_total_no_of_passengers();
            break;
        case 10:
            r.sort_by_id();
            r.displayPassengers();
            break;
        case 11:
            r.sort_by_name();
            r.displayPassengers();
            restart = 'n'; // Disable restart after sorting by name
            break;
		case 12:
			 {
				 string name, gender, id, seatClass, source, destination, date, status = "Booked";
                 int ticketNumber, fare;
				 // Input validation for name (letters and spaces only)
                 while (true) 
				 {
					 cout << "Enter passenger name: ";
                     getline(cin, name);
					 bool isValid = true;
                     for (int i = 0; i < name.length(); i++) 
					 {
						 if (!isalpha(name[i]) && name[i] != ' ') 
						 {
                         isValid = false;
                         break;
                         }
					 }
					 if (isValid && !name.empty())
					 {
                         break;
                     } 
					 else 
					 {
                         cout << "Invalid input. Please enter a valid name (letters and spaces only).\n";
					 }
				 }
				 // Input validation for gender (Male/Female or M/F)
                 while (true)
				 {
                          cout << "Enter gender (Male/Female or M/F): ";
                          getline(cin, gender);
						  // Convert to lowercase for case-insensitive comparison
                          for (int i = 0; i < gender.length(); i++) 
						  {
							  gender[i] = tolower(gender[i]);
                          }
						  if (gender == "male" || gender == "female" || gender == "m" || gender == "f") 
						  {
                              if (gender == "m" || gender == "male") 
							  {
                                    gender = "Male"; // Standardize format
                              }
							  else 
							  {
                                    gender = "Female"; // Standardize format
                              }
                                    break;
                          } 
						  else 
						  {
                                    cout << "Invalid input. Please enter Male, Female, M, or F.\n";
                          }
                  }
				 // Input validation for CNIC (13 digits only)
                  while (true) 
				  {
                        cout << "Enter ID (CNIC - 13 digits): ";
                        getline(cin, id);
						if (id.length() == 13) 
						{
                             bool isValid = true;
                             for (int i = 0; i < id.length(); i++) 
							 {
                                 if (!isdigit(id[i])) 
								 {
                                      isValid = false;
                                      break;
                                 }
							 }
							 if (isValid) 
							 {
                                      break;
							 }
							 else 
							 {
                                     cout << "Invalid CNIC. CNIC should only contain 13 digits.\n";
                             }
                             }
						else 
						{
                                     cout << "Invalid CNIC. CNIC should have exactly 13 digits.\n";
                        }
				  }
				  // Input validation for seat class (Business or Economy)
                  while (true) 
				  {
                      cout << "Enter seat class (Business/Economy): ";
                      getline(cin, seatClass);
					  // Convert to lowercase for case-insensitive comparison
                      for (int i = 0; i < seatClass.length(); i++) 
					  {
                         seatClass[i] = tolower(seatClass[i]);
                      }
					  if (seatClass == "business" || seatClass == "economy" || seatClass == "b" || seatClass == "e") 
					  {
                              break;
                      } 
					  else 
					  {
                          cout << "Invalid seat class. Please enter Business or Economy.\n";
                 }
				  }
				  // Input validation for ticket number
                  while (true) 
				  {
                      cout << "Enter ticket number: ";
                      cin >> ticketNumber;
                      cin.ignore(); // To ignore the newline character left by cin
                      if (ticketNumber > 0) 
					  {
                         break;
                      }
					  else 
					  {
                          cout << "Invalid ticket number. Please enter a positive number.\n";
                      }
                  }
				  // Input validation for fare
                  while (true) 
				  {
                      cout << "Enter fare: ";
                      cin >> fare;
                      cin.ignore(); // To ignore the newline character left by cin
                      if (fare > 0)
					  {
                        break;
                      } 
					  else
					  {
                          cout << "Invalid fare. Please enter a positive amount.\n";
                      }
                   }
				  // Input validation for source station
                  while (true)
				  {
                      cout << "Enter source station: ";
                      getline(cin, source);
					  if (!source.empty())
					  {
                           break;
                      }
					  else 
					  {
                            cout << "Invalid input. Source station cannot be empty.\n";
                      }
                   }
				  // Input validation for destination station
                  while (true)
				  {
                      cout << "Enter destination station: ";
                      getline(cin, destination);
					  if (!destination.empty()) 
					  {
                         break;
                      } 
					  else 
					  {
                          cout << "Invalid input. Destination station cannot be empty.\n";
                      }
                   }
				  // Input validation for travel date
                  while (true) 
				  {
                        cout << "Enter date (YYYY-MM-DD): ";
                         getline(cin, date);
                        if (date.length() == 10 && date[4] == '-' && date[7] == '-') 
						{
                          bool isValid = true;
                          for (int i = 0; i < date.length(); i++)
						  {
                          if (i != 4 && i != 7 && !isdigit(date[i])) 
						  {
                                isValid = false;
                                break;
                           }
                          }
						  if (isValid) 
						  {
                             break;
                          } 
						  else 
						  {
                              cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD).\n";
                          }
                         } 
						else 
						{
                               cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD).\n";
                        }
                 }
				  // Add passenger to the system
                 r.addPassenger(name, gender, id, seatClass, ticketNumber, source, destination, fare, status, date);
                 cout << "Passenger added successfully!\n";
}
break;

        case 13:
            cout << "Exiting system. Goodbye!\n";
            restart = 'n'; // Disable restart for exiting
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
    if (choice != 13)
	{ // Prompt restart unless user chooses to exit
        do {
            cout << "\nDo you wish to return to menu? (y/n): ";
            cin >> restart;
            cin.ignore();
            if (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
			{
                cout << "Invalid input. Please enter 'y' or 'n' only.\n";
            }
        } while (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N');
    }
} while (restart == 'y' || restart == 'Y');
system("pause");
return 0;
}



