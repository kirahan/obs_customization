set(PACKAGE_VERSION "26.1.0-28-ge6ff2b672")

if("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
	set(PACKAGE_VERSION_COMPATIBLE FALSE)
else()
	set(PACKAGE_VERSION_COMPATIBLE TRUE)
	if ("${PACKAGE_VERSION}" VERSION_EQUAL "${PACKAGE_FIND_VERSION}")
		set(PACKAGE_VERSION_EXACT TRUE)
	endif()
endif()
