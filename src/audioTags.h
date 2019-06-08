/*
 * audioTags.h
 *
 *  Created on: May 12, 2019
 *      Author: jdellaria
 */

#ifndef AUDIOTAGS_H_
#define AUDIOTAGS_H_

#include <tag.h>

class audioTags {
public:
	string title;
	string artist;
	string album;
	int year;
	int track;
	string genre;
	string location;
	string composers;
	string albumArtists;
	int bitrate;
	int sampleRate;
	int length;
	int disk;
	int diskcount;

	audioTags();
	virtual ~audioTags();
	int get(const char *  fileName);
	void getImage(const char * mp3FileName, const char * imageFileName);
	int set(const char *fileName);
};


#endif /* AUDIOTAGS_H_ */
