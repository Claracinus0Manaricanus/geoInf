# database controllers
This directory holds the database and controllers for database operations.

# dataController.h
This is the header for functions to access the database. It keeps operations for writing
and reading from the database. It also has functions for scanning names and tables.

# netController.c
netController is used for opening a server to access the database.
Protocol:
It has a request based protocol. The client sends a 256 byte string holding a command
and the server responds with the corresponding data.

- scan < table >: this command is for getting the names of the elements from a table.
It first sends a uint32_t holding the number of elements then sends the names of the elements.
Each elements name length in bytes get sent first. Then the name itself as a string.

- get < table > < element name > : requests an element belonging to < table > name < element name >.
The server sends id, name, climate, soil, flora, image data in order.
For sending strings their length in bytes get sent first.

- set < table > < element data > : WIP