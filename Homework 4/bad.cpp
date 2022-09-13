//
//  bad.cpp
//  Homework 4
//
//  Created by Nikhil Isukapalli on 3/2/21.
//

  // Remove the movies in li with a rating below 55 and destroy them.
  // It is acceptable if the order of the remaining movies is not
  // the same as in the original list.
void removeBad(list<Movie*>& li)
{
    //iterator
    list<Movie*>::iterator it = li.begin();
    while (it != li.end())
    {
        //if element has rating below 55
        int r = (*it)->rating();
        if (r < 55)
        {
            delete *it;
            it = li.erase(it);
        }
        else
        {
            //go to next value
            it++;
        }
    }
}
