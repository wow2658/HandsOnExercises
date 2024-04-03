#include<iostream>
#include <vector>
#include<cassert>
using namespace std;

int hash_string(string str, int n = 65407)
{
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = (sum * 26 + str[i] - 'a') % nn;
	return sum % nn;
}

struct PhoneEntry
{
	const static int INTERNAL_LIMIT = 65407;
	string name;			// key
	string phone_number;	// data

	int hash()
	{
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) :
		name(name), phone_number(phone_number)
	{	}

	void print()
	{
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};


class PhoneHashTable
{
private:
	int table_size;
	vector<PhoneEntry*> table;
	// to mark a cell as deleted
	PhoneEntry* deleted{};
public:
	PhoneHashTable(int table_size) :
		table_size(table_size)
	{
		table.resize(table_size);
		deleted = new PhoneEntry("", "");
	} //  needs a destructor

	bool put(PhoneEntry phone)
	{
		int idx = phone.hash() % table_size;
		// We max move table_size steps
		for (int step = 0; step < table_size; ++step)
		{
			if (table[idx] == deleted || !table[idx]) // empty
			{
				table[idx] = new PhoneEntry(phone.name, phone.phone_number);
				return true;
			}
			else if (table[idx]->name == phone.name)
			{
				table[idx]->phone_number = phone.phone_number;
				return true;	// update
			}
			idx = (idx + 1) % table_size;	// move next
		}
		return false;	// can't insert. Full table
	}

	bool remove(PhoneEntry phone)
	{
		int idx = phone.hash() % table_size;

		for (int step = 0; step < table_size; ++step)
		{
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name)
			{
				delete table[idx];
				table[idx] = deleted;
				return true;
			}
			idx = (idx + 1) % table_size;	// move next
		}
		return false;
	}

	bool get(PhoneEntry& phone)
	{
		int idx = phone.hash() % table_size;

		for (int step = 0; step < table_size; ++step)
		{
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name)
			{
				phone.phone_number = table[idx]->phone_number;
				return true;
			}
			idx = (idx + 1) % table_size;	// move next
		}
		return false;
	}

	void print_all()
	{
		for (int hash = 0; hash < table_size; ++hash)
		{
			cout << hash << " ";
			if (table[hash] == deleted)
				cout << " X ";
			else if (!table[hash])
				cout << " E ";
			else
				table[hash]->print();
			cout << "\n";
		}
		cout << "******************\n";
	}
};

int main() {

	PhoneHashTable table(11);
	table.put(PhoneEntry("sonic", "604-401-120"));
	table.put(PhoneEntry("sonic", "604-401-777"));
	table.put(PhoneEntry("eggman", "604-401-343"));
	table.put(PhoneEntry("teggmans", "604-401-17"));
	table.put(PhoneEntry("knuckles", "604-401-758"));
	table.put(PhoneEntry("shadow", "604-401-550"));
	table.put(PhoneEntry("amy", "604-401-223"));

	table.print_all();

	/*
	0  E
	1  E
	2  E
	3  E
	4 (shadow, 604-401-550)
	5 (knuckles, 604-401-758)
	6 (eggman, 604-401-343)
	7 (sonic, 604-401-777)
	8 (teggmans, 604-401-17)
	9 (amy, 604-401-223)
	10  E
	 */

	cout << table.remove(PhoneEntry("silver", "")) << "\n"; // 0
	cout << table.remove(PhoneEntry("knuckles", "")) << "\n";  // 1
	cout << table.remove(PhoneEntry("amy", "")) << "\n";  // 1
	table.print_all();
	/*
	0  E
	1  E
	2  E
	3  E
	4 (shadow, 604-401-550)
	5  X
	6 (eggman, 604-401-343)
	7 (sonic, 604-401-777)
	8 (teggmans, 604-401-17)
	9  X
	10  E
	 */

	PhoneEntry e("shadow", "");
	if (table.get(e))
		cout << e.phone_number << "\n";	// 604-401-550

	table.put(PhoneEntry("knuckles", "604-401-555"));
	table.print_all();
	/*
	0  E
	1  E
	2  E
	3  E
	4 (shadow, 604-401-550)
	5 (knuckles, 604-401-555)
	6 (eggman, 604-401-343)
	7 (sonic, 604-401-777)
	8 (teggmans, 604-401-17)
	9  X
	10  E
	 */
	return 0;
}
