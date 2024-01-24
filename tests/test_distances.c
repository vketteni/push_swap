#include <stdio.h>
#include "../push_swap.h" // Replace with the actual header file

int main()
{
    // Test case 1: start and end are the same node
    t_dlist node1;
    node1.prev = NULL;
    node1.next = NULL;
    int distance1 = ft_distance(&node1, &node1);
    printf("Distance: %d\n", distance1); // Expected output: 0

    // Test case 2: start is before end in the list
    t_dlist node2_1, node2_2, node2_3;
    node2_1.prev = NULL;
    node2_1.next = &node2_2;
    node2_2.prev = &node2_1;
    node2_2.next = &node2_3;
    node2_3.prev = &node2_2;
    node2_3.next = NULL;
    int distance2 = ft_distance(&node2_1, &node2_3);
    printf("Distance: %d\n", distance2); // Expected output: 2

    // Test case 3: start is after end in the list
    t_dlist node3_1, node3_2, node3_3;
    node3_1.prev = NULL;
    node3_1.next = &node3_2;
    node3_2.prev = &node3_1;
    node3_2.next = &node3_3;
    node3_3.prev = &node3_2;
    node3_3.next = NULL;
    int distance3 = ft_distance(&node3_3, &node3_1);
    printf("Distance: %d\n", distance3); // Expected output: -2

    return 0;
}