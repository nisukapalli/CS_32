//
//  odds.cpp
//  Homework 4
//
//  Created by Nikhil Isukapalli on 3/2/21.
//

  // Remove the odd integers from v.
  // It is acceptable if the order of the remaining even integers is not
  // the same as in the original vector.
void removeOdds(vector<int>& v)
{
    //iterator
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        //if element is odd
        if (*it % 2 != 0)
        {
            //erase element
            v.erase(it);
        }
        else
        {
            //go to next element
            it++;
        }
    }
}
