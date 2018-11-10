// findurls.cpp

#include "findurls.h"
#include <algorithm>
#include <cctype>

using std::string;
using std::vector;

typedef string::const_iterator iter;

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    iter b = s.begin(), e = s.end();

    // look through the entire output
    while (b != e) {
        
        // look for one or more letters followed by :// followed by valid url char
        b = url_beg(b, e);

        // if we found it
        if (b != e) {
            // get the rest of the url
            iter after = url_end(b, e);

            // remember the url
            ret.push_back(string(b, after));

            // advance b and check for more urls on this line
            b = after;
        }
    }
    return ret;
}

iter url_beg(iter b, iter e)
{
    static const string sep = "://";

    // i marks where the seperator was found
    iter i = b;

    while ((i = std::search(i, e, sep.begin(), sep.end())) != e) {
        
        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {
            
            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && std::isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character before and after the separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // the separator we found wasn't part of a url; advance i past this separator
        i += sep.size();
    }
    return e;
}

iter url_end(iter b, iter e)
{
    return std::find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
    // charaters, in addition to alphanumerics, that can appear in a url
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // see whether c can appear in a url and return the negative
    return !(std::isalnum(c) || std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
