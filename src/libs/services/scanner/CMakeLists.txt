
add_library(lmsscanner SHARED
	impl/AcousticBrainzUtils.cpp
	impl/ScannerService.cpp
	impl/ScannerStats.cpp
	)

target_include_directories(lmsscanner INTERFACE
	include
	)

target_include_directories(lmsscanner PRIVATE
	include
	)

target_link_libraries(lmsscanner PRIVATE
	lmsdatabase
	lmsmetadata
	lmsrecommendation
	lmsutils
	)

target_link_libraries(lmsscanner PUBLIC
	std::filesystem
	Wt::Wt
	)

install(TARGETS lmsscanner DESTINATION lib)

