# PageList

This EOSIO smart contract stores links to SavWeb pages

```cpp
    /** 
     * Add an entry
     * @param scope   Account name of a list. This account is authorized to remove entries in its list
     * @param editor  Authorized account name to edit and remove the entry
     * @param link    Link of a SavWeb page
     * @param title   Title for this entry
     * @param descr   Description for this entry
    */
    ACTION add(name editor, string& link, string& title, string& descr);
```
```cpp
    /** 
     * Edit an entry. Empty string parameters will not be changed
     * @param scope   Account name of a list. This account is authorized to remove entries in its list
     * @param editor  Authorized account name to edit and remove the entry
     * @param key     Key of the entry
     * @param link    Link of a SavWeb page
     * @param title   Title for this entry
     * @param descr   Description for this entry
    */
   ACTION edit(name editor, uint64_t key, string& link, string& title, string& descr);
```
```cpp
    /** 
     * Remove an entry
     * @param scope   Account name of a list. This account is authorized to remove entries in its list
     * @param editor  Authorized account name to edit and remove the entry
     * @param key     Key of the entry
    */
    ACTION remove(name editor, uint64_t key);;
```

# Licence
The whole project is open source and free to use, see MIT licence. Feel free to suggest improvements.