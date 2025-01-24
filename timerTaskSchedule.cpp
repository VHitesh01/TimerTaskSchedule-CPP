#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class taskSchedule
{
    
    public:
    void line()
    {
        cout << "-------------------------------------------------\n";
    }
    
    string taskItem[100];
	int taskTime[100];
	int curr = 0;
	int mNo;
    
    void menu(int taskNo)
    {
        // cout << "option is :: " << taskNo;
        switch(taskNo)
	    {
		    case 1:
			 //   cout << "new task menu\n";
			    newTask();
			    break;
		    case 2:
			    // cout << "view task menu\n";
			    viewTask();
			    break;
		    case 3:
			    // cout << "exit menu\n";
			    exit(0);
			    break;
	    }
    }
    
    void menuDisplay()
    {
        cout << "Menu Item : \n";
        line();
	    cout << "Enter 1 for New Task \n";
	    cout << "Enter 2 for View Task \n";
	    cout << "Enter 3 for exit Program \n";
	    line();
	    cout << "Choose any one option : ";
	    cin >> mNo;
	
	    if(mNo < 0)
	    {
	        cout << "Choose a Valid Input Menu." << endl;
	        menuDisplay();
	    }

	    else
	    {
	        if (mNo >= 1 && mNo <= 3)
	        {
	           // cout << "menu done" << endl;
	           menu(mNo);
	        }

	        else
	        {
	            cout << mNo << " Is Invalid Menu Option Choose Valid Menu Option." << endl;
	            menuDisplay();
	        }
	    }
    }
    
    void newTask()
    {
        // cout << "inside the new task function" << endl;
        int tNo;
	    cout << "How Many Tasks Schedules : ";
	    cin >> tNo;
	    
	    if(tNo < 0)
	    {
	        cout << "Not Negative Tasks Bulit." << endl;
	        cout << "Tasks Schedules : ";
	        cin >> tNo;
	    }

	    else
	    {
	        if (tNo > 50)
	        {
	           // cout << "menu done" << endl;
	           line();
	           cout << tNo << " Tasks Bulit.\n";
	           line();
	           for (int i = curr; i < tNo; i++)
	           {
			        curr++;
	    	        cout << i + 1 << " Enter Task Name : ";
		            cin >> taskItem[i];
		            cout << i + 1 << " Enter Task Delay Time : ";
		            cin >> taskTime[i];
		            if (taskTime[i] < 0)
		            {
		                cin >> taskTime[i];
		            }
		            line();
		            line();
	            }
		        cout << "Your Tasks Sucessfully Created." << endl;
	        }
	    }

	    if (tNo > 0 && tNo < 50)
	    {
	        // cout << "menu done" << endl;
	        line();
	        cout << tNo << " Tasks Bulit.\n";
	        line();
	        for (int i = curr; i < tNo; i++)
	        {
	            curr++;
	    	    cout << i + 1 << " Enter Task Name : ";
		        cin >> taskItem[i];
		        cout << i + 1 << " Enter Task Delay Time : ";
		        cin >> taskTime[i];
		        if (taskTime[i] < 0)
		        {
		            cin >> taskTime[i];
		        }
		        line();
	        }
	        cout << "Your Tasks Sucessfully Created." << endl;
	        line();
	        menuDisplay();
	    }

	    else
	    {
	        cout << "Multiple Time Negative Inputs." << endl;
	        cout << "Default 1(one) Task Bulit : \n";
	        tNo = 1;
	        cout << tNo << " Tasks Bulit.\n";
	        line();
	        for (int i = 0; i < 1; i++)
	        {
	    	    cout << i + 1 << " Enter Task Name : ";
		        cin >> taskItem[i];
		        cout << i + 1 << " Enter Task Delay Time : ";
		        cin >> taskTime[i];
		        if (taskTime[i] < 0)
		        {
		            cin >> taskTime[i];
		        }
		        line();
	        }
	        cout << "Your Tasks Sucessfully Created." << endl;
	        line();
	        menuDisplay();
	    }
    }
    
    void viewTask()
    {
        // cout << "view task." << endl;
        
	    if (curr > 0)
	    {
	        cout << "Item of Tasks : \n";
	        line();
	        for (int j = 0; j < curr; j++)
	        {
	            for (int k = taskTime[j]; k > 0; --k)
	            {
	                // cout << k << endl;
	                this_thread::sleep_for(chrono::seconds(1));
	            }
	            cout << "Task Name: " << taskItem[j] << " Executed"<< endl;
	        }
	    }

	    else
	    {
	        cout << "Any Task Not Available." << endl;
	        line();
	        menuDisplay();
	    }
        menuDisplay();
    }
    
};

int main() {
    taskSchedule ts;
    
    ts.menuDisplay();
    // ts.menuDisplay();
	// cout << "option is :: " << mNo;
	
    // ts.menu(mNo);
    return 0;
}