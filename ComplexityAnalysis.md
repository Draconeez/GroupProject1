Milestone 1 - Complexity Analysis

Reservation Insertion: O(1) or O(N)
For inserting a reservation, the complexity depends on how we add it to the linked list. If we just push it to the front (head) or back (tail), it's O(1) since we only have to update a couple of pointers. But if we decide to keep the active reservations sorted by date as we insert them, it becomes O(N) because we have to traverse the list to find the right spot before inserting the new node.

Reservation Removal: O(N)
Canceling and removing a reservation is O(N). Since we're using a custom linked list, we can't just jump directly to an index. We have to start at the head and loop through node by node until we find the matching Reservation ID. In the worst-case scenario, the reservation is at the very end of the list, meaning we check all N nodes before updating the pointers to remove it.

Waiting-list Processing: O(1)
The waiting list is built on a Queue, so it strictly follows First-In, First-Out (FIFO). When a student gets added to the waitlist (enqueue) or gets a resource and leaves the waitlist (dequeue), it only happens at the front or back of the queue. Since we aren't shifting any other students around in memory, both of these actions take constant time, O(1).

Undo Cancellation: O(1)
The cancellation history uses a Stack (Last-In, First-Out). When a user cancels a reservation, we just push that data onto the top of the stack. If they hit undo, we pop it right back off the top to restore it. Because we are only ever touching the very top element of the stack and never traversing the rest of the history, it is an O(1) operation.