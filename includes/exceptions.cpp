#ifndef exceptions_h
#define exceptions_h

#include <stdexcept>

namespace c_exception {

namespace runtime {


struct acess_nullptr : public std::runtime_error {

    acess_nullptr(const char* Message) : std::runtime_error (Message) {}

    const char *additional_info() const { return "critical error! attempting to derefernce a nullptr"; }
};


namespace buffer {
    
    







    

    
}

struct invalid_input_type : public std::runtime_error {
    
    invalid_input_type (const char* Message) : std::runtime_error (Message) {}
    
    const char *additional_info() const { return "wrong data type";}
};


struct failed_instantiation : public std::runtime_error {
    
    failed_instantiation(const char* Message) : std::runtime_error(Message) {}
    
    const char *additional_info() const { return " Warning! failed instantiation"; }
};


} // end N runtime

} // end N c_exception




#endif /* exceptions_h */

