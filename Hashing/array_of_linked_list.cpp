#include<iostream>
#include <vector>
#include<cassert>
using namespace std;

int hash_string(string str, int n_ = 65407) 
{
	int base = 2 * 26 + 10;	// lower, upper and 10 digits
	long long n = n_;
	long long sum = 0;

	for (int i = 0; i < (int)str.size(); ++i) 
	{
		// lowers from [0-25], upper [26-51] and digits [52-61]
		int value = 0;
		if (islower(str[i]))
			value = str[i] - 'a';
		else if (isupper(str[i]))
			value = 26 + str[i] - 'A';
		else if (isdigit(str[i]))
			value = 26 + 26 + str[i] - '0';
		else
			assert(false);
		sum = sum * base + value;	// base 26 number
		sum %= n;	// reduce to minimize overflows
	}
	return sum % n;
}

struct PhoneEntry 
{
	const static int INTERNAL_LIMIT = 2147483647;
	string name;			// key
	string phone_number;	// data

	int hash() 
	{
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) :
		name(name), phone_number(phone_number) {}

	void print() 
	{
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};

class PhoneHashTable 
{

private:
	struct LinkedHashEntry 
	{
		PhoneEntry item;
		LinkedHashEntry* next{ };

		LinkedHashEntry(PhoneEntry item) :
			item(item) {}
	};

	int table_size;
	LinkedHashEntry** table{ }; // vector<LinkedHashEntry*> table { };

public:
	PhoneHashTable(int table_size) : table_size(table_size) 
	{
		// Array of linked-lists: initially nulls
		table = new LinkedHashEntry * [table_size] {}; // table.resize(table_size);
		// We should destruct too
	}

	void put(PhoneEntry phone) 
	{
		int hash = phone.hash() % table_size;

		if (!table[hash])
			table[hash] = new LinkedHashEntry(phone);
		else 
		{
			LinkedHashEntry* head = table[hash];
			// Get the tail object
			while (head->next) 
			{
				if (head->item.name == phone.name) 
				{
					head->item = phone;	// exist => update
					return;
				}
				head = head->next;
			}
			// head now is tail
			if (head->item.name == phone.name)
				head->item = phone;	// exist => update
			else
				head->next = new LinkedHashEntry(phone);
		}
	}

	void print_all() 
	{
		for (int hash = 0; hash < table_size; ++hash)
		{
			if (!table[hash])
				continue;

			cout << "Hash " << hash << ": ";
			for (LinkedHashEntry* head = table[hash]; head; head = head->next)
				head->item.print();
			cout << "\n";
		}
	}
};

int main() 
{
	PhoneHashTable table(3);
	table.put(PhoneEntry("epic", "604-401-120"));
	table.put(PhoneEntry("epic", "604-401-777"));	// update
	table.put(PhoneEntry("nex", "604-401-343"));
	table.put(PhoneEntry("craf", "604-401-17"));
	table.put(PhoneEntry("smag", "604-401-758"));
	table.put(PhoneEntry("bibm", "604-401-550"));
	table.put(PhoneEntry("newz", "604-401-223"));

	table.print_all();
	

	return 0;
}
