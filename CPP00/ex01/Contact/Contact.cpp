#include "Contact.hpp"

Contact::Contact() {
	this->mFirstName = "";
	this->mLastName = "";
	this->mNickname = "";
	this->mPhoneNumber = "";
	this->mSecret = "";
}

Contact::~Contact() {
	return;
}

std::string Contact::getFirstName(void) {
	return this->mFirstName;
}

std::string Contact::getLastName(void) {
	return this->mLastName;
}

std::string Contact::getNickname(void) {
	return this->mNickname;
}

std::string Contact::getPhoneNumber() {
	return this->mPhoneNumber;
}

std::string Contact::getSecret(void) {
	return this->mSecret;
}

void Contact::setFirstName(std::string input) {
	this->mFirstName = input;
}

void Contact::setLastName(std::string input) {
	this->mLastName = input;
}

void Contact::setNickname(std::string input) {
	this->mNickname = input;
}

void Contact::setPhoneNumber(std::string input) {
	this->mPhoneNumber = input;
}

void Contact::setSecret(std::string input) {
	this->mSecret = input;
}