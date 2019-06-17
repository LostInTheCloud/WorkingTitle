#include "exception.hpp"

Exception RuntimeErrorString( const char* error_name, const char* what_arg )
{
  return Exception( std::string(error_name) + ": '" + std::string(what_arg) + "'" );
}

Exception RuntimeErrorString( const char* error_name, const std::string& what_arg )
{
  return RuntimeErrorString( error_name, what_arg.c_str() );
}

Exception RuntimeError( const char* what_arg )        { return RuntimeErrorString( "Runtime Error", what_arg ); }
Exception RuntimeError( const std::string& what_arg ) { return RuntimeError( what_arg.c_str() ); }

Exception NotImplemented( const char* what_arg )        { return RuntimeErrorString( "Not Implemented", what_arg ); }
Exception NotImplemented( const std::string& what_arg ) { return NotImplemented( what_arg.c_str() ); }

Exception FileError( const char* what_arg )        { return RuntimeErrorString( "File Error", what_arg ); }
Exception FileError( const std::string& what_arg ) { return FileError( what_arg.c_str() ); }

Exception CPUError( const char* what_arg )        { return RuntimeErrorString( "CPU Error", what_arg ); }
Exception CPUError( const std::string& what_arg ) { return CPUError( what_arg.c_str() ); }

Exception MemoryError( const char* what_arg )        { return RuntimeErrorString( "Memory Error", what_arg ); }
Exception MemoryError( const std::string& what_arg ) { return MemoryError( what_arg.c_str() ); }

Exception InterruptError( const char* what_arg )        { return RuntimeErrorString( "Interrupt Error", what_arg ); }
Exception InterruptError( const std::string& what_arg ) { return InterruptError( what_arg.c_str() ); }
