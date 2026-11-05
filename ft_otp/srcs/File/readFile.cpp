
std::string getKey(std::string path);
	std::string myKey;
	ifstream file;

	file.exceptions (ifstream::badbit);
	try {
		file.open(path.c_str());
		char ch;
		while(file.get(ch))
			myKey.append(ch);
		MyFile.close();
	} catch (const ifstream::failure& e) {
		cout << "Exception opening/reading file";
	}
	return (myKey);
}
