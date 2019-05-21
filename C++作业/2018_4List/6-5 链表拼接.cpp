struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)//6-5 链表拼接
{
    int num = 0;
    int temp[100];
    struct ListNode  *p = list1;
    while(p != NULL)
    {
        temp[num] = p->data;
        num++;
        p = p->next;
    }
    p = list2;
    while(p != NULL)
    {
        temp[num] = p->data;
        num++;
        p = p->next;
    }
    int i,j;
    for(i = 0; i < num; i++)
        for(j = i + 1; j < num; j++)
        {
            if(temp[i] > temp[j])
            {
                int t;
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
      struct ListNode  *newlist = NULL;
      struct ListNode  *endlist = NULL;
      struct ListNode  *q;
      for(i = 0; i < num; i++)
      {
          q = (struct ListNode  *)malloc(sizeof(struct ListNode));
          q->data = temp[i];
          if(newlist == NULL)
          {
              newlist = q;
              newlist->next = NULL;
          }
            if(endlist != NULL)
         {
            endlist->next = q;
         }
         endlist = q;
         endlist->next = NULL;
      }
      return newlist;
}
