# database controllers
This directory holds the database and controllers for database operations.

# dataController.h
This is the header for functions to access the database. It keeps operations for writing
and reading from the database.

Functions:
- int getFromTable(char* tableName, char* objectName, struct tableElement* ret) 
this functions gets the element named < objectName > from table < tableName > and put its data into ret.