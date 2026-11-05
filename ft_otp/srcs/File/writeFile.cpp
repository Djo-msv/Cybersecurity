
void setKeyEncryption(std::string key) {
	ofstream	MyFile("ft_otp.key");

	if (!file)
		throw std::runtime_error("Unable to open file");

	MyFile << sha1(key);

	MyFile.close();
}
