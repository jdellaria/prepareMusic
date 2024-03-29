/*
 * configurationFile.cpp
 *
 *  Created on: Sep 10, 2009
 *      Author: jdellaria
 */

#include <sys/stat.h>
#include <sys/dir.h>
#include <errno.h>
#include <dirent.h>
//#include <string>
//#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <DLog.h>

#include "configurationFile.h"
#include <tinyxml.h>

extern DLog myLog;
using namespace std;
//#pragma hdrstop



configurationFile::configurationFile()
{
	logFileName.clear();
	logPrintScreen = true;
	logPrintFile = true;
	logPrintTime = true;
}

configurationFile::~configurationFile()
{
	// TODO Auto-generated destructor stub
}

// Read a file into a vector

void configurationFile::help(char *program) {
	std::cout << program;
	std::cout << ": Need a filename for a parameter.\n";
}

int configurationFile::getConfiguration(char *Name)
{
	string message;
	TiXmlDocument doc(Name);
	bool loadOkay = doc.LoadFile();
	string myString;

	const char* exampleXMLFile =
		"Config file should look like this:\n"
		"<?xml version=\"1.0\"  standalone='no' >\n"
		"<!-- Configuration Parmeters -->\n";

	if ( !loadOkay )
	{
		printf( "Could not load test file %s. Error='%s'.\n%s\nExiting.\n",Name, doc.ErrorDesc(),exampleXMLFile );
		exit( 1 );
	}

	TiXmlNode* node = 0;
	TiXmlElement* portElement = 0;
	TiXmlElement* airportAddressElement = 0;
	// --------------------------------------------------------
	// An example of changing existing attributes, and removing
	// an element from the document.
	// --------------------------------------------------------

	// Get the "ToDo" element.
	// It is a child of the document, and can be selected by name.

	node = doc.FirstChild( "logfilename" );
	if (!node)
	{
		message = "logfilename child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
//		sprintf( message,"logfilename element not found!! XML file is invalid\n.%s",exampleXMLFile);
		message = "logfilename element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
//	sprintf( message, "logfilename element GetText:%s", portElement->GetText() );

	message = "logfilename element GetText:";
	message.append(portElement->GetText());

	myLog.print(logInformation, message);
	logFileName.append(portElement->GetText());

	node = doc.FirstChild( "logvalue" );
	if (!node)
	{
		message = "logvalue child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "logvalue element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "logvalue element GetText:";
	message.append(portElement->GetText());
	myLog.print(logInformation, message);
	logValue.append(portElement->GetText());

	node = doc.FirstChild( "logprintscreen" );
	if (!node)
	{
		message = "logprintscreen child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "logprintscreen element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "logprintscreen element GetText:";
	message.append(portElement->GetText() );
	myLog.print(logInformation, message);
	myString = portElement->GetText();
	if (myString.find("false")!=string::npos)
	{
		logPrintScreen = false;

		message = "logPrintScreen = false";
		myLog.print(logInformation, message);
	}

	if (myString.find("true")!=string::npos)
	{
		logPrintScreen = true;

		message = "logPrintScreen = true";
		myLog.print(logInformation, message);
	}

	node = doc.FirstChild( "logprintfile" );
	if (!node)
	{
		message = "logprintfile child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "logprintfile element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "logprintfile element GetText:";
	message.append(portElement->GetText() );
	myLog.print(logInformation, message);
	myString = portElement->GetText();
	if (myString.find("false")!=string::npos)
	{
		logPrintFile = false;
		message = "logPrintFile = false";
		myLog.print(logInformation, message);
	}

	if (myString.find("true")!=string::npos)
	{
		logPrintFile = true;
		message = "logPrintFile = true";
		myLog.print(logInformation, message);
	}

	node = doc.FirstChild( "logprinttime" );
	if (!node)
	{
		message = "logprinttime child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "logprinttime element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "logprinttime element GetText:";
	message.append(portElement->GetText());
	myLog.print(logInformation, message);
	myString = portElement->GetText();
	if (myString.find("false")!=string::npos)
	{
		logPrintTime = false;

		message = "logPrintTime = false";
		myLog.print(logInformation, message);
	}
	if (myString.find("true")!=string::npos)
	{
		logPrintTime = true;

		message =  "logPrintTime = true";
		myLog.print(logInformation, message);
	}

//	MP3OriginalDirectory

	node = doc.FirstChild( "MP3OriginalDirectory" );
	if (!node)
	{
		message = "MP3OriginalDirectory child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "MP3OriginalDirectory element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "MP3OriginalDirectory element GetText:";
	message.append(portElement->GetText());
	myLog.print(logInformation, message);
	MP3OriginalDirectory.clear();
	MP3OriginalDirectory.append(portElement->GetText());

// MP3StagingDirectory

	node = doc.FirstChild( "MP3StagingDirectory" );
	if (!node)
	{
		message = "MP3StagingDirectory child not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	portElement = node->ToElement();
	if (!portElement)
	{
		message = "MP3StagingDirectory element not found!! XML file is invalid\n.";
		message.append(exampleXMLFile);
		myLog.print(logError, message);
		exit(0);
	}
	message = "MP3StagingDirectory element GetText:";
	message.append(portElement->GetText());
	myLog.print(logInformation, message);
	MP3StagingDirectory.clear();
	MP3StagingDirectory.append(portElement->GetText());


	// MP3MusicLibraryDirectory

		node = doc.FirstChild( "MP3MusicLibraryDirectory" );
		if (!node)
		{
			message = "MP3MusicLibraryDirectory child not found!! XML file is invalid\n.";
			message.append(exampleXMLFile);
			myLog.print(logError, message);
			exit(0);
		}
		portElement = node->ToElement();
		if (!portElement)
		{
			message = "MP3MusicLibraryDirectory element not found!! XML file is invalid\n.";
			message.append(exampleXMLFile);
			myLog.print(logError, message);
			exit(0);
		}
		message = "MP3MusicLibraryDirectory element GetText:";
		message.append(portElement->GetText());
		myLog.print(logInformation, message);
		MP3MusicLibraryDirectory.clear();
		MP3MusicLibraryDirectory.append(portElement->GetText());



}
