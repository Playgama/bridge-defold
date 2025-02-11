function CStrOrNull(string) {
    if(string)
        return stringToNewUTF8(string);
    return 0;
}