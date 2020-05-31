//Copyright2018YourName<your_email>

#include<gtest/gtest.h>
#include"include/header.h"
int main(intargc,char**argv){
boost::program_options::options_descriptiondesc("asd");
desc.add_options()
	("url",boost::program_options::value<std::string>())
	("depth",boost::program_options::value<unsigned>())
	("network_threads",boost::program_options::value<unsigned>())
	("parser_threads",boost::program_options::value<unsigned>())
	("output",boost::program_options::value<std::string>());
boost::program_options::variables_map vm;
try{
	boost::program_options::store(
		boost::program_options::parse_command_line(argc,argv,desc),vm);
		boost::program_options::notify(vm);
}
catch(boost::program_options::error &e){
	std::cout<<e.what()<<std::endl;
}
Crawler a(vm["url"].as<std::string>(),
	vm["depth"].as<unsigned>(),
	vm["network_threads"].as<unsigned>(),
	vm["parser_threads"].as<unsigned>(),
	vm["output"].as<std::string>());
std::cout<<"Parsedsuccessfully";
return0;
}
TEST(Example,EmptyTest){
	EXPECT_TRUE(true);
}
