So... a base class can contain all function for its children classes if it is preceded byt he virtual keyboard  
It MUST implement the virtual function...
but from then on it kind of acts as an interface almost... you can't just overwrite a regular function, it will always refer back to the original function in the base class.



There appears a way to make the entire objct virtual by making the function  = 0, but I'm not there yes