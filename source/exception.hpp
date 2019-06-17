#pragma once

#include <iostream>
#include <stdexcept>
#include <string>


typedef std::runtime_error Exception;

Exception RuntimeError( const char* what_arg );
Exception RuntimeError( const std::string& what_arg );

Exception NotImplemented( const char* what_arg );
Exception NotImplemented( const std::string& what_arg );

Exception FileError( const char* what_arg );
Exception FileError( const std::string& what_arg );

Exception CPUError( const char* what_arg );
Exception CPUError( const std::string& what_arg );

Exception MemoryError( const char* what_arg );
Exception MemoryError( const std::string& what_arg );

Exception InterruptError( const char* what_arg );
Exception InterruptError( const std::string& what_arg );
