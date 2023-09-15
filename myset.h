#include <iostream>
#include <set>

using namespace std;

class MySet
{
public:
    /**
     *  Function:   MySet
     *              MySet default contstructor
     *
     */
    MySet() { myset = {}; }

    /**
     *  Function:   find
     *              finds a number in myset
     *
     *  @param num - the number being searched for
     *  @return - true if the number is there, false if not
     */
    bool find(int num);

    /**
     *  Function:   size
     *              finds the size of myset
     *
     *  @return - the size of myset
     */
    int size();

    /**
     *  Function:   operator+
     *              adds a number to the set
     *
     *  @param num - number being added
     *  @return - a copy of myset with the new number added
     */
    MySet operator+(int num);

    /**
     *  Function:   operator+
     *              adds two sets together
     *
     *  @param set - the second set being added
     *  @return - a copy of myset with the new set added
     */
    MySet operator+(MySet set);

    /**
     *  Function:   at
     *              finds the value at an index
     *
     *  @param index - the index of the value
     *  @return - the value at the specified index
     */
    int at(int index);

    /**
     *  Function:   begin
     *              finds the beginning of myset
     *
     *  @return - an iterator pointing to the beginning of myset
     */
    set<int>::iterator begin();

    /**
     *  Function:   end
     *              finds the end of myset
     *
     *  @return - an iterator pointing to the end of myset
     */
    set<int>::iterator end();

    /**
     *  Function:   toString
     *              lists every number in myset in a string in order
     *
     *  @return - a string of every number in myset in curly braces
     */
    string toString();

    /**
     *  Function:   clear
     *              clears myset
     */
    void clear();

    /**
     *  Function:   operator-
     *              removes a number from the set
     *
     *  @param num - the number being removed
     *  @return - a copy of myset with the number removed
     */
    MySet operator-(int num);

    /**
     *  Function:   operator*
     *              finds the elements that are in both sets
     *
     *  @param set - the other set being checked
     *  @return - a copy of myset including only the numbers in both myset and set
     */
    MySet operator*(MySet set);

    /**
     *  Function:   operator-
     *              finds the numbers that are in set 1 but not set 2
     *
     *  @param set - the other set being checked
     *  @return - a copy of myset excluding the numbers that were in set 2
     */
    MySet operator-(MySet set);

    /**
     *  Function:   operator<=
     *              finds if set 1 is a subset of set 2
     *
     *  @param set - the other set being checked
     *  @return - true if all numbers in set 1 are in set 2, false if not
     */
    bool operator<=(MySet set);

    /**
     *  Function:   operator>=
     *              finds if set 1 is a superset of set 2
     *
     *  @param set - the other set being checked
     *  @return - true if all numbers in set 2 are in set 1, false if not
     */
    bool operator>=(MySet set);

    /**
     *  Function:   operator==
     *              finds if both sets are equal
     *
     *  @param set - the other set being checked
     *  @return - true if set 1 and 2 have the same numbers, false if not
     */
    bool operator==(MySet set);

    /**
     *  Function:   operator^
     *              finds if the number is in the set
     *
     *  @param num - the number being looked for
     *  @param set - the set being checked
     *  @return - true if the number is in the set, false if not
     */
    friend bool operator^(int num, MySet set);

private:
    set<int> myset;
};

bool operator^(int num, MySet set)
{
    return set.find(num);
}

bool MySet::find(int num)
{
    if (myset.find(num) == myset.end())
    {
        return false;
    }
    return true;
}

int MySet::size()
{
    return myset.size();
}

MySet MySet::operator+(int num)
{
    myset.insert(num);
    return *this;
}

MySet MySet::operator+(MySet set)
{
    for (auto it = set.begin(); it != set.end(); it++)
    {
        myset.insert(*it);
    }
    return *this;
}

set<int>::iterator MySet::begin()
{
    return myset.begin();
}

set<int>::iterator MySet::end()
{
    return myset.end();
}

string MySet::toString()
{
    if (myset.size() == 0)
    {
        return "{}";
    }
    string s = "{";
    for (auto it = myset.begin(); it != myset.end(); it++)
    {
        s = s + to_string(*it);
        s = s + ", ";
    }

    s.pop_back();
    s.pop_back();
    s = s + "}";
    return s;
}

void MySet::clear()
{
    myset.clear();
}

MySet MySet::operator-(int num)
{
    myset.erase(num);
    return *this;
}

MySet MySet::operator*(MySet set)
{
    MySet s;
    for (auto it = set.begin(); it != set.end(); it++)
    {
        if ((myset.find(*it) != myset.end()))
        {
            s = s + (*it);
        }
    }
    return s;
}

MySet MySet::operator-(MySet set)
{
    MySet s;
    for (auto it = myset.begin(); it != myset.end(); it++)
    {
        if ((*it ^ set) == 0)
        {
            s = s + (*it);
        }
    }
    return s;
}

bool MySet::operator<=(MySet set)
{
    for (auto it = myset.begin(); it != myset.end(); it++)
    {
        if ((*it ^ set) == 0)
        {
            return false;
        }
    }
    return true;
}

bool MySet::operator>=(MySet set)
{
    for (auto it = set.begin(); it != set.end(); it++)
    {
        if (myset.find(*it) == myset.end())
        {
            return false;
        }
    }
    return true;
}

bool MySet::operator==(MySet set)
{
    if (set.size() != myset.size())
    {
        return false;
    }
    auto it2 = myset.begin();
    for (auto it = set.begin(); it != set.end(); it++)
    {
        if (*it2 != *it)
        {
            return false;
        }
        it2++;
    }
    return true;
}
