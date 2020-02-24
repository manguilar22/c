#include <assert.h>
#include "llist.h"

void llInitHead(LList *head)
{
    head->dummy.after = head->dummy.before = &head->dummy;
}

int llCheckEmpty(LList *head)	/* return true if list is empty */
{
    return head->dummy.before == &head->dummy;
}

void llInsBefore(LItem *where, LItem *item)
{
    LItem *immediatelyBefore = where->before;

    item->after = where;
    item->before = immediatelyBefore;
    immediatelyBefore->after = where->before = item;
}

void llInsLast(LList *head, LItem *item) /* insert onto the tail */
{
    llInsBefore(&head->dummy, item);
}

void llInsFirst(LList *head, LItem *item) /* insert onto head */
{
    llInsBefore(head->dummy.after, item);
}

void llRemove(LItem *item)
{
    assert(item->before != item);
    item->before->after = item->after;
    item->after->before = item->before;
}

LItem *llDelFirst(LList *head)	/* delete head */
{
    LItem *item = head->dummy.before;
    if (item != &head->dummy)
        llRemove(item);		/* don't delete the head, dummy! */
    else
        item = 0;			/* return failure */
    return item;
}

LItem *llDelLast(LList *head)
{
    LItem *item = head->dummy.after;
    if (item != &head->dummy)
        llRemove(item);		/* don't delete the head, dummy! */
    else
        item = 0;			/* return failure */
    return item;
}