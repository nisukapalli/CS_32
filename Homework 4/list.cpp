//
//  list.cpp
//  Homework 4
//
//  Created by Nikhil Isukapalli on 3/2/21.
//

void listAll(const File* f, string path)  // two-parameter overload
{
    if (f == nullptr)
    {
        return;
    }
    path = path + "/" + f->name();
    if (f->files() == nullptr || f->files()->size() == 0)
    {
        cout << path << endl;
        return;
    }
    if (path != "")
    {
        cout << path << endl;
    }
    for (int i = 0; i != f->files()->size(); i++)
    {
        listAll((*(f->files()))[i], path);
    }
    
}
