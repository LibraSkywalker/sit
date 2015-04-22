#include "sit-operations.h"

#include <boost/archive/binary_oarchive.hpp>
#include <sstream>
#include <string>

namespace MainFrame {
void InitRepo()
{
	try {
		boost::filesystem::create_directories(".sit");
#ifdef WIN32
		SetFileAttributes(L".sit", FILE_ATTRIBUTE_HIDDEN);
#endif
		boost::filesystem::create_directories(".sit/files");
		boost::filesystem::create_directories(".sit/stage");
		boost::filesystem::create_directories(".sit/objects");
		boost::uuids::uuid rootVersion = boost::uuids::nil_uuid();
		std::ostringstream uuidStr;
		uuidStr << rootVersion;
		std::string rootUuidStr = uuidStr.str();
		boost::filesystem::ofstream object(objects_dir / rootUuidStr, std::ios::binary);
		boost::archive::binary_oarchive boarch(object);
		boarch << rootVersion;
	} catch (const boost::filesystem::filesystem_error &ec) {
		std::cerr << ec.what() << std::endl;
	} catch (const boost::archive::archive_exception &ae) {
		std::cerr << ae.what() << std::endl;
	} catch (const std::exception &se) {
		std::cerr << se.what() << std::endl;
	}
}
}