
typedef struct LItem_s {
    struct LItem_s *before, *after;
    int payload;
} LItem;

typedef struct {
    LItem dummy;
} LList;

void llInitHead(LList *head);

void llInsBefore(LItem *where, LItem *item);

void llInsLast(LList *head, LItem *item);
void llInsFirst(LList *head, LItem *item);
int llCheckEmpty(LList *head);


void llRemove(LItem *item);
LItem *llDelFirst(LList *head);
LItem *llDelLast(LList *head);


