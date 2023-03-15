# Address-Book-System


This address book program uses two classes: `Contact` and `AddressBook`. The `Contact` class represents a single contact in the address book, and stores their 
name, email, and phone number. The `AddressBook` class manages a collection of `Contact` objects, and provides methods to add, display, search, and delete contacts.

In the main function of the program, a menu of options is displayed to the user and their choice is read in using `cin`. The appropriate method of the `AddressBook` 
class is then called based on the user's choice. If the user chooses to add a contact, a new `Contact` object is created and added to the address book. If they 
choose to display contacts, all contacts in the address book are displayed. If they choose to search contacts, the user is prompted for a search term and all 
contacts that match the term are displayed. If they choose to delete a contact, the user is prompted for the name of the contact to delete and it is removed from 
the address book. If the user chooses to exit, the program ends.

Note that this program uses a vector of pointers to `Contact` objects in the `AddressBook` class. This is done so that the `deleteContact` method can 
delete a specific `Contact` object from the vector. If a vector of `Contact` objects was used instead, deleting a specific contact would be more difficult.
