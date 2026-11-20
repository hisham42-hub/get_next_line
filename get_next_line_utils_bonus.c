int ft_strchr(char *s, char c)
{
    if(!s)
        return (0);
    while(*s)
    {
        if(*s == c)
            return (1);
        s++;
    }
    return (0);
}

t_list *ft_lstlast(t_list *lst)
{
    t_list *last;

    if(!lst)
        return (NULL);
    while(lst)
    {
        last = lst;
        lst = lst->next;
    }
    return (last);
}

t_list *ft_lstnew(void *s)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if(!node)
    {
        free(s);
        return (NULL);
    }
    node->content = s;
    node->next = NULL;
    return (node);
}

void *del(t_list *lst)
{
    t_list temp;

    if(!lst)
        return (NULL);
    while(lst)
    {
        temp = lst->next;
        free(lst->content);
        free(lst);
        lst = temp;
    }
    return (NULL);
}
