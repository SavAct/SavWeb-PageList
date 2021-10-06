#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT pagelist : public contract {
  public:
    using contract::contract;

    /** 
     * Add an entry
     * @param editor  Authorized account name to edit and remove the entry
     * @param link    Link of a SavWeb page
     * @param title   Title for this entry
     * @param descr   Description for this entry
    */
    ACTION add(name editor, string& link, string& title, string& descr);

    /** 
     * Edit an entry. Empty string parameters will not be changed
     * @param editor  Authorized account name to edit and remove the entry
     * @param key     Key of the entry
     * @param link    Link of a SavWeb page
     * @param title   Title for this entry
     * @param descr   Description for this entry
    */
    ACTION edit(name editor, uint64_t key, string& link, string& title, string& descr);

    /** 
     * Remove an entry
     * @param editor  Authorized account name to edit and remove the entry
     * @param key     Key of the entry
    */
    ACTION remove(name editor, uint64_t key);

  private:

    TABLE static_places_table {
      uint64_t  key;        // Primary key
      string    title;      // Title 
      string    descr;      // Description
      string    link;       // SavWeb page
      name      editor;     // Accounts with the right to edit an entry
      auto primary_key() const { return key; }
    };
    typedef multi_index<"places"_n, static_places_table> places_table;

};
