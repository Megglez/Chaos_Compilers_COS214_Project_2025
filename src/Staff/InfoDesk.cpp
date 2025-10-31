#include "InfoDesk.h"

void InfoDesk::notify(Staff *staff)
{
    std::cout << "Customer needs your assistance";


}

InfoDesk::InfoDesk()
{
    // TODO - implement InfoDesk::InfoDesk
    chainHead=nullptr;
    std::cout<<"Info Desk created."<<std::endl;

	
}

InfoDesk::~InfoDesk()
{
    std::cout<<"Closing Info Desk."<<std::endl;
}

InfoDesk* InfoDesk::getInfodesk()
{
    return this;
}

void InfoDesk::handleCustomer(Customer* customer) // called by enquiring customerState
{
    if(!customer)
    {
        std::cout<<"Customer is null. Cannot assign to staff member."<<std::endl;
        return;
    }

  if(customer->getAction()->getActionName()=="Enquiring")
  {
    std::cout<<"Requesting assistance for customer "+customer->getId()<<std::endl;
    
    //get a staff member
    Staff *assignedStaff;
    assignedStaff= findAvailableStaffThroughChain();
    if(assignedStaff)
    {
        std::cout<<assignedStaff->getName() +" is on their way to assist customer. "<<std::endl;
    assignedStaff->assistCustomer(customer);
    customer->setAssignedStaff(assignedStaff);
  }
}
}

bool InfoDesk::FindAvailableStaff(Customer *cc)
{
    if(!chainHead)
    {
        std::cout<<"Currently no staff available. Please queue for assistance."<<std::endl;
        return false;
    }

}


bool InfoDesk::removeStaff(Staff* ss)
{
 if(!ss)
 {
    std::cout<<"staff is NULL. Cannot remove Staff member."<<std::endl;
    return;
 }

 auto it = std::find(AllStaff.begin(),AllStaff.end(),ss);

 
if(it!=AllStaff.end())
    {
        AllStaff.erase(it);

        std::cout<<"Staff is now Busy."<<std::endl;
    
    buildChain();

    }

    else{

std::cout<<"Could not find staff member. "<<std::endl;

}
}


bool InfoDesk::addStaff(Staff *ss)
{
 if(!ss)
 {
    std::cout<<"staff is NULL. Cannot add Staff member."<<std::endl;
    return;
 }

 auto it = std::find(AllStaff.begin(),AllStaff.end(),ss);

 
    if(it!=AllStaff.end())
    {
        std::cout<<"Staff Already set as Available."<<std::endl;
        return;
    
    }

AllStaff.push_back(ss); //added
std::cout<<ss->getName()+" is now available for assistance."<<std::endl;
buildChain();

}

void InfoDesk::buildChain()
{
    clearChain();
    if(AllStaff.empty())
    {
        std::cout<<"Currently no staff registered with system."<<std::endl;
        return;
    }

    std::vector<std::string> order= {"Sales","Gardener","Manager","Cashier"};
    std::vector<Staff*> sales = getStaffByType("Sales");
    std::vector<Staff*> gardeners = getStaffByType("Gardener");
    std::vector<Staff*> managers = getStaffByType("Manager");
    std::vector<Staff*> chashiers = getStaffByType("Cashier");

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

    std::cout<<"In chain: " <<std::endl;
    std::cout<<sales.size()<< " SalesStaff "<<std::endl;
    std::cout<<managers.size()+ " Managers" <<std::endl;
    std::cout<<gardeners.size()+ " Gardeners" <<std::endl;
    std::cout<<chashiers.size()+ " Cahiers" <<std::endl;


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

std::vector<Staff*> InfoDesk::getStaffByType(std::string type)
{
std::vector<Staff*> result;
for(Staff* ss: AllStaff)
{
    if(ss->getStaffType()== type)
    {
        result.push_back(ss);
    }
}
return result;
}

