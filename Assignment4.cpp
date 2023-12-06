#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <iostream>
#include "curl/curl.h"
#include "json-develop/include/nlohmann/json.hpp"

using namespace std; 

// Creating an alias for nlohmann::json
using json = nlohmann::json; 

// callback function used by CURL to write received data into string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        string apiKey = "hajTJrhhlU9lqFu07rAK8VRfPjp0CiTNDHa0oEeVBaBTwm6oL10y7hG7";
        string apiUrl = "https://api.pexels.com/v1/curated?per_page=10"; 

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: " + apiKey).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parse JSON response
            json jsonResponse = json::parse(response);

            // Extract the last 5 image URLs
            vector<string> imageUrls;
            size_t count = 0;
            for (auto it = jsonResponse["photos"].rbegin(); it != jsonResponse["photos"].rend() && count < 5; ++it, ++count) {
                imageUrls.push_back((*it)["src"]["medium"]);
            }

            // Generate HTML file
            ofstream html_File("output.html");

            html_File << "<html><body>\n";
            html_File << "<div style=\"display: grid; grid-template-columns: repeat(2, 0.2fr); grid-gap: 1px;\">";
            for (const auto& imageUrl : imageUrls) {
                 html_File << "<div style=\"margin: 2px;\"><img src=\"" << imageUrl << "\" /></div>\n";
            }
            html_File << "</div>";
            html_File << "</body></html>\n";
            cout << "HTML file generated: output.html" << endl;
        }
    }

    return 0;
}
