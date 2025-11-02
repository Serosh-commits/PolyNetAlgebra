//this is a simple example of copy constructor though a cyberbuffer system used in preserving a system entries while a attack basically make a backup clone for preserving the files
#include<bits/stdc++.h>
using namespace std;
class cyberbuffer
{
    std::vector<string>entries;
  public:
  cyberbuffer()=default;//have to do it other wise the constructor gets collapsed with the class name
      void add(const std::string& e)
      {
          entries.push_back(e);
      }
      cyberbuffer(const cyberbuffer& other):entries(other.entries)
      {
          std::cout<<"clone/copy created"<<endl;
      }
};
int main()
{
    cyberbuffer live;
    live.add("ddos attack");
    cyberbuffer backup = live;//this is the clone
}
