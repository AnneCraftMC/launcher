#include <curl/curl.h>
#include <zip.h>
#include <stdio.h>

static size_t jre_curl_write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
	size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
	return written;
}

int jre_zip_extract_entry(const char *filename, void *arg) {
    static int i = 0;
    int n = *(int *)arg;
    printf("Extracted: %s (%d of %d)\n", filename, ++i, n);

    return 0;
}

int jre_download() {
	/* --- Download JRE --- */
	CURL* curl_handle;
	FILE* zip;

	curl_global_init(CURL_GLOBAL_ALL);
	curl_handle = curl_easy_init();
	curl_easy_setopt(curl_handle, CURLOPT_URL, "https://github.com/AdoptOpenJDK/openjdk8-binaries/releases/download/jdk8u242-b08/OpenJDK8U-jre_x64_windows_hotspot_8u242b08.zip");
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, jre_curl_write_data);
	curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);

	zip = fopen("jre.zip", "wb");
	if (zip) {
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, zip);
		printf("Downloading OpenJDK8U-jre_x64_windows_hotspot_8u242b08.zip");
		curl_easy_perform(curl_handle);
		fclose(zip);
	}

	curl_easy_cleanup(curl_handle);
	curl_global_cleanup();

	/* --- Extract JRE --- */
	int arg = 2;
	zip_extract("jre.zip", "jre", jre_zip_extract_entry, NULL);

	return 0;
}