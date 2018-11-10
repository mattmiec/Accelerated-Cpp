#ifndef GUARD_findurls_h
#define GUARD_findurls_h

// findurls.h

#include <string>
#include <vector>

std::vector<std::string> find_urls(const std::string& s);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
bool not_url_char(char);

#endif
