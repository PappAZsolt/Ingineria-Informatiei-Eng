#include "Event.h"

int main() {
    Event* events[2];

    events[0] = new Conference("Sala Palatului", "2025-06-15", "Bucuresti", "Puya");
    events[1] = new Concert("BT Arena", "2025-07-20", "Cluj", "Untold");

    for (int i = 0; i < 2; i++) {
        events[i]->displayEventDetails();
        cout << "------------------------" << endl;
    }

    return 0;
}
