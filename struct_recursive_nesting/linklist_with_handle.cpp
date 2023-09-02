#include <iostream>

using namespace std;

typedef struct Linklist_Node
{
    int node_data;
    struct Linklist_Node *next;

} _Node_;

void print_list_data(_Node_ *list_node);
void print_list_data(_Node_ *list_node)
{
    if (!list_node)
    {
        cout << "arrive to the end node....\n";
        return;
    }
    
    cout << list_node->node_data << '\t';
    print_list_data(list_node->next);
}

int main(int argc, char const *argv[])
{
    _Node_ l1,l2,l3,l4,l5;

    l1.node_data = 10;
    l2.node_data = 15;
    l3.node_data = 20;
    l4.node_data = 76;
    l5.node_data = 100876;

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = nullptr;

    print_list_data(&l1);
    
    return EXIT_SUCCESS;
}
