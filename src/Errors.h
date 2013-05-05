//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    Errors.h
// Description: This file collectively defines all the exceptions thrown in the system.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef ERRORS_H_
#define ERRORS_H_

class Error{};
class ErrorInvalidData : Error {};
class ErrorStringTooLong : Error {};
class ErrorNullPointer : Error {};
class ErrorUnexpectedValue : Error {};
class ErrorInvalidAction : Error {};
class ErrorArrayOutOfBounds : Error {};

#endif /* ERRORS_H_ */
