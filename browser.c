#include <stdio.h>
#include <curl/curl.h>
int main() {
  char input[1024]
  char *output = malloc(1024)
  CURL *curl
  CURLcode res;
  printf("Enter search query: ")
  scanf("%s", input)
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
    if(curl) {
        char url[1024];
        sprintf(url, "https://www.google.com/search?q=%s", input);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        } else {
            printf("%s\n", output);
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    free(output);
    return 0;
}
