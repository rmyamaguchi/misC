
#include "TimeSubject.h"

struct ListNode
{
    TimeObserver item;
    struct ListNode* next;
};

static struct ListNode observers;
static SystemTime currentTime;

static void appendToList(const TimeObserver* observer)
{
    /* Placeholder */
}

static void removeFromList(const TimeObserver* observer)
{
    /* Placeholder */
}

void attach(const TimeObserver *observer)
{
    if (NULL != observer)
        appendToList(observer);
}

void detach(const TimeObserver *observer)
{
    if (NULL != observer)
        removeFromList(observer);
}

static void msTick()
{
    struct ListNode *node = observers.next;
    currentTime = calculateNewTime();

    while(NULL != node)
    {
        TimeObserver *observer = &node->item;
        observer->notification(observer->instance, &currentTime);
        node = node->next;
    }
}