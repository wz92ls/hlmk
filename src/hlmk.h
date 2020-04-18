/*
 * hlmk.h
 *
 *  Created on: 2020Äê4ÔÂ15ÈÕ
 *      Author: 14374
 */

#ifndef HLMK_H_
#define HLMK_H_
#include "curl/curl.h"
#include "openssl/md5.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MD5LENTH 16
unsigned char MD5result[MD5LENTH];

#define URL_HTTPS_TEST "https://test.cloud.ecogearing.cn/king/test/t"

#define URL_GETDEVICELIST "http://www.huilink.com.cn/dk2018/getdevicelist.asp"
#define URL_GETBRANDLIST "http://www.huilink.com.cn/dk2018/getbrandlist.asp"
#define URL_GETMODELLIST "http://www.huilink.com.cn/dk2018/getmodellist.asp"
#define URL_GETKEYLIST "http://www.huilink.com.cn/dk2018/getkeylist.asp"
#define URL_USEREMOTE "http://www.huilink.com.cn/dk2018/useremote"
#define URL_DELREMOTE "http://www.huilink.com.cn/dk2018/delremote"
#define URL_KEYEVENT "http://www.huilink.com.cn/dk2018/keyevent.asp"
#define URL_GETRID "http://www.huilink.com.cn/dk2018/getrid.asp"
#define URL_CREATEDIY "http://www.huilink.com.cn/dk2018/creatediy.asp"
#define URL_DIYSTUDY "http://www.huilink.com.cn/dk2018/diystudy.asp"
#define URL_GETSMODELLIST "http://www.huilink.com.cn/dk2018/getsmodellist.asp"
#define URL_GETSKETLIST "http://www.huilink.com.cn/dk2018/getskeylist.asp"
#define URL_GETSKEYV "http://www.huilink.com.cn/dk2018/getskeyv"
#define URL_FINDMODEL "http://www.huilink.com.cn/dk2018/findmodel.asp"
#define URL_GETTESTCODE "http://www.huilink.com.cn/dk2018/gettestcode.asp"
#define URL_MACREG "http://www.huilink.com.cn/dk2018/macreg.asp"

class HLMKFunction
{
public:
	HLMKFunction();
	~HLMKFunction();
	static int  WriteDate(void *buffer, size_t sz, size_t nmemb, void *ResInfo);
	static int  md5(const char* DataBuff,int length);
	static int testhttps(string appId,string token ,string transType,string timeStamp,string random,string sign,string liu,string rec);
	static string NumToStr(int num);
	static string getdevicelist();
	static size_t recive_data_fun(  void *buffer, size_t size, size_t nmemb, void *userp);
	static string getbrandlist(string mac,string device_id);
	static string getmodellist(string mac,string device_id,string brand_id);
	static string getkeylist(string mac,string kfid);
	static string useremote(string mac,string kfid);
	static string delremote(string mac,string kfid);
	static string keyevent_1(string mac,string keyid,string kfid);
	static string keyevent_2(string mac,string par,string kfid);
	static string keyevent_3(string mac);
	static string getrid(string mac,string device_id,string vcode);
	static string creatediy(string mac,string sdevice,string brand,string model);
	static string diystudy(string mac,string skfid,string skeyid,string skeyname,string sdat);
	static string getsmodellist(string mac,string device_id);
	static string getskeylist(string mac,string kfid);
	static string getskeyv(string mac,string kfid,string skeyid);
	static string findmodel(string mac,string device_id,string modelname);
	static string gettestcode(string mac,string kfid);
	static string macreg(string mac,string username);
};

#endif /* HLMK_H_ */
