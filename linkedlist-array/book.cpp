#include "book.h"

book::book() { setTitle(""); }

book::book(string s) { setTitle(s); }

void book::setTitle(string s) { title = s; }

string book::getTitle() const { return title; }

bool book::operator==(book b) { return getTitle() == b.getTitle(); }
