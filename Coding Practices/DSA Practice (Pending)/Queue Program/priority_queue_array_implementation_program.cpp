#include <vector>
#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    vector<pair<int, int>> queue; // Stores (value, priority)

public:
    void enqueue(int value, int priority)
    {
        queue.push_back({value, priority});
        cout << "Inserted Element: " << value << " With Priority: " << priority << endl;
    }

    void dequeue()
    {
        if (queue.empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int maxPriorityIndex = 0;
        for (int i = 1; i < queue.size(); i++) // Start from 1 to compare correctly
        {
            if (queue[i].second > queue[maxPriorityIndex].second)
            {
                maxPriorityIndex = i;
            }
        }

        cout << "Dequeued Element: " << queue[maxPriorityIndex].first
             << " With Priority: " << queue[maxPriorityIndex].second << endl;

        queue.erase(queue.begin() + maxPriorityIndex);
    }

    void display()
    {
        if (queue.empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Priority Queue Elements:\n";
        for (auto &p : queue)
        {
            cout << "Value: " << p.first << ", Priority: " << p.second << endl;
        }
    }
};

int main()
{
    PriorityQueue Obj;
    Obj.enqueue(12, 5);
    Obj.enqueue(126, 53);
    Obj.enqueue(123, 54);
    Obj.enqueue(122, 532);
    Obj.enqueue(121, 51);
    Obj.enqueue(129, 25);

    Obj.display();

    Obj.dequeue();
    Obj.dequeue();
    Obj.dequeue();

    Obj.display();

    return 0;
}