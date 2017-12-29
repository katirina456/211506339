﻿

#include "StaticData.h"

static StaticData* g_sharedStaticData = NULL;

StaticData* StaticData::sharedStaticData() 
{
	if (g_sharedStaticData == NULL) {
		g_sharedStaticData = new StaticData();
		g_sharedStaticData->init();
	}
	return g_sharedStaticData;
}

void StaticData::purge() 
{
	CC_SAFE_RELEASE_NULL(g_sharedStaticData);
}

int StaticData::intValueFromKey(const string& key) 
{
	return _dictionary->valueForKey(key.c_str())->intValue();
}

const char* StaticData::stringValueFromKey(const string& key) 
{
	return _dictionary->valueForKey(key.c_str())->getCString();
}

float StaticData::floatValueFromKey(const string& key) 
{
	return _dictionary->valueForKey(key.c_str())->floatValue();
}

bool StaticData::booleanFromKey(const string& key)
{
	return _dictionary->valueForKey(key.c_str())->boolValue();
}

CCPoint StaticData::pointFromKey(const string& key) 
{
	return CCPointFromString(_dictionary->valueForKey(key.c_str())->getCString());
}

CCRect StaticData::rectFromKey(const string& key) 
{
	return CCRectFromString(_dictionary->valueForKey(key.c_str())->getCString());
}

CCSize StaticData::sizeFromKey(const string& key) 
{
	return CCSizeFromString(_dictionary->valueForKey(key.c_str())->getCString());
}

bool StaticData::init() 
{
	_dictionary = CCDictionary::createWithContentsOfFile(_staticFileName.c_str());
	_dictionary->retain();

	return true;
}

StaticData::~StaticData() 
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}

StaticData::StaticData()
{
	_staticFileName = STATIC_DATA_FILENAME;
}

