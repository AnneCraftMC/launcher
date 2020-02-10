#include <curl/curl.h>
#include <zip.h>
#include <stdio.h>

static size_t jre_curl_write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
	size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
	return written;
}

int jre_download() {
	/* --- Download JRE --- */
	CURL* curl_handle;
	FILE* jreZip;

	curl_global_init(CURL_GLOBAL_ALL);
	curl_handle = curl_easy_init();
	curl_easy_setopt(curl_handle, CURLOPT_URL, "https://github.com/AdoptOpenJDK/openjdk8-binaries/releases/download/jdk8u242-b08/OpenJDK8U-jre_x64_windows_hotspot_8u242b08.zip");
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, jre_curl_write_data);
	curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0L); // <-- HACK HACK NO GOOD HACK DO NOT RELEASE WITH THIS HACK

	jreZip = fopen("jre.zip", "wb");
	if (jreZip) {
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, jreZip);
		curl_easy_perform(curl_handle);
		fclose(jreZip);
	}

	curl_easy_cleanup(curl_handle);
	curl_global_cleanup();

	/* --- Extract JRE --- */
	zip_extract("jre.zip", ".", NULL, NULL);
	rename("jdk8u242-b08-jre", "jre"); // TODO: error check this
	remove("jre.zip"); // TODO: error check this

	return 0;
}