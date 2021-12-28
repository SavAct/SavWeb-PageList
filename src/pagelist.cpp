#include <pagelist.hpp>

ACTION pagelist::add(name scope, name editor, string& link, string& title, string& descr) {
  require_auth(editor);

  // Init the _places table
  places_table _places(get_self(), scope.value);

  check(title.length() <= 60, "Title is too long");
  check(title.length() <= 1000, "Description is too long");

  // Create an entry if it does not exist otherwise it will fail
  _places.emplace(editor, [&](auto& p) {
    p.key = _places.available_primary_key();
    p.title = title; 
    p.descr = descr;
    p.link = link;
    p.editor = editor;
  });
}

ACTION pagelist::edit(name scope, name editor, uint64_t key, string& link, string& title, string& descr) {
  require_auth(editor);

  // Init the _places table
  places_table _places(get_self(), scope.value);

  // Find the entry from _places table
  auto itr = _places.find(key);

  check(itr != _places.end(), "This key does not exists.");
  check(itr->editor == editor, "You have no authority to edit this entry.");
  check(title.length() <= 60, "Title is too long");
  check(title.length() <= 1000, "Description is too long");

  // Modify the entry
  _places.modify(itr, editor, [&](auto& p) {
    if(title.length() > 0){
      p.title = title; 
    }
    if(descr.length() > 0){
      p.descr = descr;
    }
    if(link.length() > 0){
      p.link = link;
    }
    p.editor = editor;
  });
}

ACTION pagelist::remove(name scope, name editor, uint64_t key) {
  require_auth(editor);

  places_table _places(get_self(), scope.value);

  auto itr = _places.find(key);
  check(itr != _places.end(), "This key does not exists.");
  check(editor == scope || itr->editor == editor, "You have no authority to remove this entry.");

  itr = _places.erase(itr);
}