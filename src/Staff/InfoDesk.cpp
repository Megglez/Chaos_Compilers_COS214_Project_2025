#include "InfoDesk.h"
#include "Staff.h"
#include "../Customer/Customer.h"

void InfoDesk::notify(Staff *staff)
{
    cout << "Customer needs your assistance";
    staff->getID(); // remove later

}

InfoDesk::InfoDesk()
{
    // TODO - implement InfoDesk::InfoDesk
    chainHead=nullptr;
    cout<<"Info Desk created."<<endl;

	
}

InfoDesk::~InfoDesk()
{
    cout<<"Closing Info Desk."<<endl;
}

InfoDesk* InfoDesk::getInfodesk()
{
    return this;
}

void InfoDesk::handleCustomer(Customer* customer) // called by enquiring customerState
{
    if(!customer)
    {
        cout<<"Customer is null. Cannot assign to staff member."<<endl;
        return;
    }

  if(customer->getAction()->getActionName()=="Enquiring")
  {
    cout<<".....Requesting assistance for customer..... " << customer->getId()<<endl;
    
    //get a staff member
    Staff *assignedStaff;
    assignedStaff= findAvailableStaffThroughChain();
    if(assignedStaff)
    {
        cout<<assignedStaff->getName() +" is on their way to assist customer. "<<endl;
    assignedStaff->assistCustomer(customer);
    customer->setAssignedStaff(assignedStaff);
  }

  else
  {
    waitingCustomers.push(customer);
    cout<<"All staff unavailable. Queue customer "<< waitingCustomers.size()<<" for assistance."<<endl;

  }
}
}

bool InfoDesk::FindAvailableStaff(Customer *cc)
{
    cc->getId();
    Staff *assignedStaff;
    assignedStaff= findAvailableStaffThroughChain();
    if(assignedStaff)
    {

        cout<<"Found staff member. Staff - "+assignedStaff->getName()<<endl;

    }
    else{
        cout<<"Currently no staff available. Please queue for assistance."<<endl;
        return false;
    }
    // Return true if a staff member was found, false otherwise
    return (assignedStaff != nullptr);
}

void InfoDesk::processWaitingCustomers()
{
    cout<<"....Processing Waiting Customers....."<<endl;

    if(waitingCustomers.empty())
    {
        cout<<"No customers waiting in queue."<<endl;
        return;
    }

    int processed = 0;
    while(!waitingCustomers.empty())
    {
        Staff *assignedStaff = findAvailableStaffThroughChain();
        if(!assignedStaff)
        {
            cout<<"No staff available. Remain in queue."<<endl;
            break;
        }
        Customer* customer = waitingCustomers.front();
        waitingCustomers.pop();
        cout<<"InfoDesk assigning " << assignedStaff->getName() << " to customer " << customer->getId() << endl;
        assignedStaff->assistCustomer(customer);
        customer->setAssignedStaff(assignedStaff);
        processed++;
    }

 cout<<"Processed customers: "<<processed<<endl;
 cout<<waitingCustomers.size() << "still in queue."<<endl;
}


bool InfoDesk::removeStaff(Staff* ss)
{
    if(!ss)
    {
        cout<<"staff is NULL. Cannot remove Staff member."<<endl;
        return false;
    }

    auto it = find(AllStaff.begin(),AllStaff.end(),ss);
    
    if(it!=AllStaff.end())
    {
        AllStaff.erase(it);
        cout<<"Staff is now Busy."<<endl;
        buildChain();
        return true;
    }
    else
    {
        cout<<"Could not find staff member. "<<endl;
        return false;
    }
}


bool InfoDesk::addStaff(Staff *ss)
{
    if(!ss)
    {
        cout<<"staff is NULL. Cannot add Staff member."<<endl;
        return false;
    }

    auto it = find(AllStaff.begin(),AllStaff.end(),ss);
    
    if(it!=AllStaff.end())
    {
        cout<<"Staff Already set as Available."<<endl;
        return false;
    }

    AllStaff.push_back(ss); //added
    cout<<ss->getName()+" is now available for assistance."<<endl;
    buildChain();
    return true;

}

void InfoDesk::buildChain()
{
    clearChain();
    if(AllStaff.empty())
    {
        cout<<"Currently no staff registered with system."<<endl;
        return;
    }

    vector<string> order= {"Sales","Gardener","Manager","Cashier"};
    vector<Staff*> sales = getStaffByType("Sales");
    vector<Staff*> gardeners = getStaffByType("Gardener");
    vector<Staff*> managers = getStaffByType("Manager");
    vector<Staff*> chashiers = getStaffByType("Cashier");

    chainHead=nullptr;
    Staff * current= nullptr;

    for(Staff*staff:sales)
    {
        if(!chainHead)
        {
            chainHead=staff;
            current=chainHead;
        }
        else
        {
            current->setNextInChain(staff);
            current=staff;
        }
    }

     for(Staff*staff:gardeners)
    {
         if(!chainHead)
        {
            chainHead=staff;
            current=chainHead;
        }
        else
        {
            current->setNextInChain(staff);
            current=staff;
        }
    }

     for(Staff*staff:managers)
    {
         if(!chainHead)
        {
            chainHead=staff;
            current=chainHead;
        }
        else
        {
            current->setNextInChain(staff);
            current=staff;
        }
    }

     for(Staff*staff:chashiers)
    {
         if(!chainHead)
        {
            chainHead=staff;
            current=chainHead;
        }
        else
        {
            current->setNextInChain(staff);
            current=staff;
        }
    }

    if(current)
    {
        current->setNextInChain(nullptr);

    }

    cout<<"In chain: " <<endl;
    cout<<sales.size()<< " SalesStaff "<<endl;
    cout<<managers.size()+ " Managers" <<endl;
    cout<<gardeners.size()+ " Gardeners" <<endl;
    cout<<chashiers.size()+ " Cahiers" <<endl;


}

void InfoDesk::clearChain()
{
    if(chainHead)
    {
        Staff*current=chainHead;
        while (current)
        {
          Staff*next=current->getNextInChain();
          current->setNextInChain(nullptr);
          current=next;
        }
        chainHead=nullptr;
    }
}

Staff* InfoDesk::findAvailableStaffThroughChain()
{
    if (!chainHead) {
        return nullptr;
    }

    Staff* current = chainHead;
    while (current) {
        // Check if the current staff member is available
        if (current->getStaffType() == "Available") {
            return current;
        }
        current = current->getNextInChain();
    }
    return nullptr; // No available staff found
}

vector<Staff*> InfoDesk::getStaffByType(string type) const
{
    vector<Staff*> result;
    for(Staff* ss: AllStaff)
    {
        if(ss->getStaffType()== type)
        {
            result.push_back(ss);
        }
    }
    return result;
}

void InfoDesk::notifyStaffAvailable(Staff* freedStaff)
{
if(!freedStaff)
{
   cout<<"Cannot recognise staff. Staff is null."<<endl;
    return;
}

cout<< freedStaff->getName() <<"is available."<<endl;

}

void InfoDesk::AssignStaffToCustomer(Customer *cc)
{
if(cc==nullptr)
{
    cout<<"Customer is Null. Cannot assign staff member to customer."<<endl;
    return;
}

Staff *assignedStaff;
    assignedStaff= findAvailableStaffThroughChain();
    if(assignedStaff)
    {
        cout<<"Assigning immediately."<<endl;
        cout << assignedStaff->getName() << " assigned to customer " << cc->getId() << endl;
       assignedStaff->assistCustomer(cc);
       cc->setAssignedStaff(assignedStaff);
  }

  else{
    waitingCustomers.push(cc);
    cout<<"No Staff available. Customer added to queue."<<endl;
    cout<<"Current queue size: "<<waitingCustomers.size()<<endl;

  }
}

