#ifndef VMIME-MSG
#define VMIME-MSG

#include <iostream>
#include "/usr/include/vmime/vmime.hpp"
#include "/usr/include/vmime/platforms/posix/posixHandler.hpp""


int messageBuild() {
	vmime::platform::setHandler <vmime::platforms::posix::posixHandler>();

	// Set the global C and C++ locale to the user-configured locale.
	// The locale should use UTF-8 encoding for these tests to run successfully.
	try {
		std::locale::global(std::locale(""));
	}
	catch (std::exception &) {
		std::setlocale(LC_ALL, "");
	}

	try {
		vmime::messageBuilder mb;

		// Fill in the basic fields
		mb.setExpeditor(vmime::mailbox("test@test.com"));

		vmime::addressList to;
		to.appendAddress(vmime::create <vmime::mailbox>("MisterYura@gmail.com"));

		mb.setRecipients(to);

		// vmime::addressList bcc;
		// bcc.appendAddress(vmime::create <vmime::mailbox>("you-bcc@nowhere.com"));

		// mb.setBlindCopyRecipients(bcc);

		mb.setSubject(vmime::text("My first message generated with vmime::messageBuilder"));

		// Message body
		mb.getTextPart()->setText(vmime::create <vmime::stringContentHandler>(
			"I'm writing this short text to test message construction " \
			"with attachment, using the vmime::messageBuilder component."));

		// Adding an attachment
		vmime::ref <vmime::fileAttachment> a = vmime::create <vmime::fileAttachment>
		(
			"/home/myura/test/test.txt",                                       // full path to file
			vmime::mediaType("application/octet-stream"),   // content type
			vmime::text("My first attachment")              // description
		);

		a->getFileInfo().setFilename("test.txt");
		a->getFileInfo().setCreationDate(vmime::datetime("30 Apr 2003 14:30:00 +0200"));

		mb.attach(a);

		// Construction
		vmime::ref <vmime::message> msg = mb.construct();

		// Raw text generation
		vmime::string dataToSend = msg->generate();

		std::cout << "Generated message:" << std::endl;
		std::cout << "==================" << std::endl;
		std::cout << std::endl;
		std::cout << dataToSend << std::endl;
	}
	// VMime exception
	catch (vmime::exception& e) {
		std::cout << "vmime::exception: " << e.what() << std::endl;
		throw;
	}
	// Standard exception
	catch (std::exception& e) {
		std::cout << "std::exception: " << e.what() << std::endl;
		throw;
	}
}

#endif
