#include <iostream>

using namespace std;

const int TABLE_SIZE = 5;

/**
 * Each plate holds a unique dish and
 * tracks the number of times it was used.
 */
struct Plate {
    int dish = -1;
    int uses = -1;
};

/** array of TABLE_SIZE plates */

Plate table[TABLE_SIZE];

/**
 * Get the next line from stdin and
 * interpret it as a dish request
 */

int next_request();

/**
 * Find index of a dish if already on
 * table, else return -1 (not found)
 */

int find_dish(Plate *table, int dish);

/**
 * Returns index of lfu on table.
 */

int find_lfu(Plate *table);

/**
 * Prints Plate struct info.
 */

void print(Plate *p);

/**
 * This function returns the number
 * of "cache misses", that is, the number of
 * times a request was made but the dish did
 * not currently exist on the table.
 */

int serve_dishes()
{
    int req;
    int on_table;

    int misses = 0;
    int num_plates = 0;
    int lfu = 0;

    while ((req = next_request()) != -1) {

        on_table = find_dish(table, req);

        if (on_table != -1) {
            table[on_table].uses++;
            print(&table[on_table]);

        } else {

            table[lfu].dish = req;
            table[lfu].uses = 1;

            if (num_plates < TABLE_SIZE) {
                num_plates++;
                cout << "dish added ";
                cout << "in empty slot" << endl;

            } else {
                misses++;
                cout << "a swap required! ";
                cout << "miss = " << misses << endl;   
            }
        }

        lfu = find_lfu(table);
    }

    cout << "Detected EOF" << endl;
    return misses;
}

int main()
{
    int misses = serve_dishes();
    cout << "Misses: " << misses << endl;

    return 0;
}

/* Helper functions */

int next_request()
{
    int x;

    while (1) {
        cin >> x;

        if (cin.eof()) {
            return -1;
        } else if (cin.fail()) {
            cin.clear();

            /** Skip the invalid line */
            while (cin.get() != '\n');

            /** Error message */
            cerr << "Invalid: please enter an int" << endl;
        } else {
            /** Skip the rest of the line, i.e. "1 a" reads 1 ignoring a */
            while (cin.get() != '\n');
            return x;
        }
    }
}

int find_dish(Plate *table, int dish)
{
    int i = 0;

    while ((table[i].dish != dish) && (i < TABLE_SIZE))
        i++;

    if (i < TABLE_SIZE) {
        cout << "on table at " << i << endl;
        return i;

    } else {
        cout << "not on table" << endl;
        return -1;
    }
}

int find_lfu(Plate *table)
{
    int lfu = 0;

    for (int i=1; i<TABLE_SIZE; i++) {
        if (table[i].uses < table[lfu].uses)
            lfu = i;
    }

    return lfu;
}

void print(Plate *p)
{
    cout << "dish " << p->dish;
    cout << " uses " << p->uses << endl;
}
