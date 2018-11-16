#include <iostream>
#include <limits>

using namespace std;

int main()
{
  cin.exceptions(iostream::failbit);

  int number;

  do
  {
  cout<<"Pick a number between 1 and 10."<<endl;
  
  try
  {
    cin>>number;
    
    if(cin.peek() != '\n')
    {
      throw &number;
    
    }
    else if(number > 0 && number < 11)
    { 
      cout<<"You picked "<<number<<"."<<endl;
    } 
    else
    {
      cout<<"You entered and illegal value of "<<number<<". Please try again."<<endl;
    }

  }
  
  catch(int *pnum)
  {
    cout<<"Non-integer value. You entered something after "<<*pnum<<"."<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    *pnum = 0;
  }

  catch(iostream::failure& iof)
  {
    cout<<"This is not an integer. Please enter a number."<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }



  }while(!(number > 0 && number < 11));

  
  return 0;

}

 

