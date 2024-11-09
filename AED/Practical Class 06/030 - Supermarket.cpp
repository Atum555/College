#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Costumer {
    string    name;          // Name
    u_int64_t arrival;       // Arrival time
    u_int64_t products;      // Number os products
    u_int64_t start     = 0; // Arrival at front of queue time
    u_int64_t departure = 0; // Departure time
};

struct Checkout {
    u_int64_t        number;       // Checkout number
    u_int64_t        cashierSpeed; // Speed of cashier
    queue<Costumer>  waiting;      // Queue of Costumers waiting
    vector<Costumer> departed;     // List of Costumers already served
};

// Calculate costumer departure time
u_int64_t costumerDeparture(const Costumer &costumer, u_int64_t cashierSpeed) {
    return costumer.start + 10 + costumer.products * cashierSpeed;
}

// Calculate next checkout departure time
u_int64_t timeNextDeparture(const Checkout &checkout) {
    return costumerDeparture(checkout.waiting.front(), checkout.cashierSpeed);
}

// Depart next costumer from waiting at checkout
void completeNextCostumer(Checkout &checkout) {
    if (checkout.waiting.size() <= 0) return; // Return if empty

    // Get costumer at front
    Costumer atFront = checkout.waiting.front();

    // Calculate departure time
    atFront.departure = costumerDeparture(atFront, checkout.cashierSpeed);

    // Remove from queue and add to departed list
    checkout.departed.push_back(atFront);
    checkout.waiting.pop();

    // Set start time for next person in queue if exists
    if (checkout.waiting.size()) checkout.waiting.front().start = atFront.departure;
}

int main() {
    u_int64_t        C;         // Number of checkouts
    u_int64_t        N;         // Number of costumers
    vector<Checkout> checkouts; // Speed of each checkout
    queue<Costumer>  costumers; // Costumers

    // Read Checkouts
    {
        cin >> C;
        u_int64_t cashierSpeed; // Temporary value
        for (size_t i = 0; i < C; i++) {
            cin >> cashierSpeed;
            checkouts.push_back(Checkout{ i, cashierSpeed });
        }
    }

    // Read Costumers
    {
        cin >> N;
        string    name;     // Temporary value
        u_int64_t arrival;  // Temporary value
        u_int64_t products; // Temporary value
        for (size_t i = 0; i < N; i++) {
            cin >> name >> arrival >> products;
            costumers.push(Costumer{ name, arrival, products });
        }
    }

    // Process Costumers
    {
        Costumer  nextCostumer     = Costumer{};
        u_int64_t bestCheckout     = checkouts.front().number;
        u_int64_t time             = 0;
        u_int64_t smallestNextTime = 0;
        u_int64_t timeNextDepart   = 0;
        while (costumers.size()) {
            // Get next costumer that arrived
            nextCostumer     = costumers.front();
            smallestNextTime = nextCostumer.arrival;

            // If it is the right time
            if (nextCostumer.arrival == time) {
                // Remove from list of total costumers
                costumers.pop();

                // Choose next best checkout
                bestCheckout = checkouts.front().number;
                for (const Checkout &checkout : checkouts) {
                    // Already found the best
                    if (checkouts[bestCheckout].waiting.size() == 0) break;

                    // Less costumers waiting
                    if (checkout.waiting.size() < checkouts[bestCheckout].waiting.size())
                        bestCheckout = checkout.number;

                    // Last costumer with less products
                    else if (checkout.waiting.size() == checkouts[bestCheckout].waiting.size()
                             and checkout.waiting.back().products
                                     < checkouts[bestCheckout].waiting.back().products)
                        bestCheckout = checkout.number;
                }

                // Set start time if queue is empty
                if (checkouts[bestCheckout].waiting.size() == 0) nextCostumer.start = time;

                // Add Costumer to checkout queue
                checkouts[bestCheckout].waiting.push(nextCostumer);
            }

            // Update all checkouts and pop all complete costumers

            for (Checkout &checkout : checkouts)
                if (checkout.waiting.size()) {
                    // Get time next departure for this checkout and depart client if needed
                    timeNextDepart = timeNextDeparture(checkout);
                    if (timeNextDepart == time) completeNextCostumer(checkout);

                    // Update smallest next time
                    smallestNextTime = min(smallestNextTime, timeNextDepart);
                }


            // Update time
            time = smallestNextTime;
        }
    }

    // Clear Checkouts
    for (Checkout &checkout : checkouts)
        while (checkout.waiting.size()) completeNextCostumer(checkout);

    // Print out results
    for (const Checkout &checkout : checkouts) {
        cout << "Checkout #" << checkout.number + 1 << ": " << checkout.departed.size() << endl;
        for (const Costumer &costumer : checkout.departed) {
            cout << ". " << costumer.name << ' ' << costumer.arrival << ' ' << costumer.start << ' '
                 << costumer.departure << endl;
        }
    }
}
