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
    cout<<"You picked "<<number<<"."<<endl;
    
    if(cin.peek() != '\n')
    {
      throw &number;
    
    }
    if(number > 10 || number < 1)
    { 
      cout<<"You entered an illegal value of -1."<<endl;
      cout<<"Please try again. Pick a number between 1 and 10."<<endl;
    } 
  }
  
  catch(iostream::failure& iof)
  {
    cout<<"This is not an integer. Please enter a number."<<endl;
    cin.clear(); //reset error flags 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
  }

  catch(int *pnum)
  {
    cout<<"Non-integer value. You entered something after "<<*pnum<<"."<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    *pnum = 0;
  }


  }while(number > 10 || number < 1);

  
  return 0;

}

 

