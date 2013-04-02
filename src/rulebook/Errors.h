/*
 * Errors.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

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
