//============================================================================
// Name        : hlmk.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "hlmk.h"



HLMKFunction::HLMKFunction()
{

}
HLMKFunction::~HLMKFunction()
{

}
size_t HLMKFunction::recive_data_fun( void *buffer, size_t size, size_t nmemb, void *userp){
	std::string data((char*) buffer, size * nmemb);
	*((std::stringstream*) userp) << data << std::endl;
	return  size * nmemb;
}
string HLMKFunction::getdevicelist()
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETDEVICELIST);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getbrandlist(string mac,string device_id)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETBRANDLIST);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&device_id=";
		strpost=strpost+device_id;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getmodellist(string mac,string device_id,string brand_id)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETMODELLIST);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&device_id=";
		strpost=strpost+device_id;
		strpost=strpost+"&brand_id=";
		strpost=strpost+brand_id;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getkeylist(string mac,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETKEYLIST);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::useremote(string mac,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_USEREMOTE);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::delremote(string mac,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_DELREMOTE);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::keyevent_1(string mac,string keyid,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_KEYEVENT);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&keyid=";
		strpost=strpost+keyid;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::keyevent_2(string mac,string par,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_KEYEVENT);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&par=";
		strpost=strpost+par;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::keyevent_3(string mac)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_KEYEVENT);
		string strpost="mac=";
		strpost=strpost+mac;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getrid(string mac,string device_id,string vcode)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETRID);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&device_id=";
		strpost=strpost+device_id;
		strpost=strpost+"&vcode=";
		strpost=strpost+vcode;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::creatediy(string mac,string sdevice,string brand,string model)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_CREATEDIY);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&sdevice=";
		strpost=strpost+sdevice;
		strpost=strpost+"&brand=";
		strpost=strpost+brand;
		strpost=strpost+"&model=";
		strpost=strpost+model;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::diystudy(string mac,string skfid,string skeyid,string skeyname,string sdat)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_CREATEDIY);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&skfid=";
		strpost=strpost+skfid;
		strpost=strpost+"&skeyid=";
		strpost=strpost+skeyid;
		strpost=strpost+"&skeyname=";
		strpost=strpost+skeyname;
		strpost=strpost+"&sdat=";
		strpost=strpost+sdat;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getsmodellist(string mac,string device_id)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_CREATEDIY);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&device_id=";
		strpost=strpost+device_id;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getskeylist(string mac,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_CREATEDIY);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::getskeyv(string mac,string kfid,string skeyid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETSKEYV);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		strpost=strpost+"&skeyid=";
		strpost=strpost+skeyid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::findmodel(string mac,string device_id,string modelname)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_FINDMODEL);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&device_id=";
		strpost=strpost+device_id;
		strpost=strpost+"&modelname=";
		strpost=strpost+modelname;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::gettestcode(string mac,string kfid)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_GETTESTCODE);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&kfid=";
		strpost=strpost+kfid;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}
string HLMKFunction::macreg(string mac,string username)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	std::stringstream out;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_URL, URL_MACREG);
		string strpost="mac=";
		strpost=strpost+mac;
		strpost=strpost+"&username=";
		strpost=strpost+username;
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,strpost.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &recive_data_fun);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return out.str();
}

int HLMKFunction::WriteDate(void *buffer, size_t sz, size_t nmemb, void *ResInfo)
{
	size_t written = fwrite(buffer, sz, nmemb, (FILE *)ResInfo);
	printf("\nget=%s\n", (char*)buffer);
	return written;
}
int HLMKFunction::md5(const char* DataBuff,int length)
{
	MD5_CTX md5_ctx;
	MD5_Init(&md5_ctx);
	MD5_Update(&md5_ctx,DataBuff,length);
	MD5_Final(MD5result,&md5_ctx);
	//MD5((const unsigned char*)DataBuff,length,MD5result);//нд╪Ч
	return 0;
}

int  HLMKFunction::testhttps(string appId,string token ,string transType,string timeStamp,string random,string sign,string liu,string rec)
{
	CURL *curl;
	CURLcode res;
	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	/* get a curl handle */
	curl = curl_easy_init();
	if(curl) {
		/* First set the URL that is about to receive our POST. This URL can
	       just as well be a https:// URL if that is what should receive the
	       data. */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, URL_HTTPS_TEST);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteDate);
		struct curl_slist *list = NULL;
		string tmp="appId: "+appId;
		list = curl_slist_append(list,tmp.c_str());
		list = curl_slist_append(list,"token: None");
		tmp="transType: "+transType;
		list = curl_slist_append(list,tmp.c_str());
		tmp="timeStamp: "+timeStamp;
		list = curl_slist_append(list,tmp.c_str());
		tmp="random: "+random;
		list = curl_slist_append(list,tmp.c_str());
		tmp="sign: "+sign;
		list = curl_slist_append(list,tmp.c_str());

		tmp="liu: "+liu;
		list = curl_slist_append(list,tmp.c_str());

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, rec.c_str());
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		/* always cleanup */
		curl_easy_cleanup(curl);

	}
	curl_global_cleanup();
	return 0;
}

string HLMKFunction::NumToStr(int num)
{
	std::stringstream ssTemp;
	ssTemp<<num;
	return ssTemp.str();
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int a[2][3]={0};


	srand((int)time(NULL));
	string appId="esmini88888888888888888888";
	string token="666fd4ab303459b3ba80da2cc8e57b89";
	string transType="MCU_REPORT";
	string random="123";
	string sign="";
	string liu="None";
	string rec="rec=999999";
	time_t myt=time(NULL);
	string strtime=HLMKFunction::NumToStr(myt);
//	printf("\nstrtime=%s\n",strtime.c_str());
//	printf("\n%s\n", ctime(&myt));
	random=HLMKFunction::NumToStr(rand()%65536);
//	printf("\nrandom=%s\n", random.c_str());
	string all=appId+token+strtime+random;
//	printf("\na==%s\n",all.c_str());
	HLMKFunction::md5(all.c_str(),all.length());
	for(int i=0;i<MD5LENTH;i++)
	{
		char t[2];
		sprintf(t,"%02x",MD5result[i]);
		sign=sign+t;
	}
//	printf("\nsign==%s\n",sign.c_str());
	HLMKFunction::testhttps(appId,token,transType,strtime,random,sign,liu,rec);
	//	cout<<HLMKFunction::getdevicelist()<<endl;
	//	cout<<HLMKFunction::getbrandlist("25e207560a7b37b6","1")<<endl;
	//	cout<<HLMKFunction::getmodellist("25e207560a7b37b6","1","1")<<endl;
	//	cout<<HLMKFunction::getkeylist("25e207560a7b37b6","020254")<<endl;


	return 0;
}
