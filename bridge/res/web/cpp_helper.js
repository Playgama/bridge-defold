const Type = {
  Zero: 0,
  Json: 1,
  String: 2,
  Integer: 3,
  Number: 4, // float
};

function packToJson(data) {
  if (data) {
    let obj = { data: data };
    return stringToNewUTF8(JSON.stringify(obj));
  }
  return 0;
}

function CStrOrNull(string) {
  if (string) {
    return stringToNewUTF8(string);
  }
  return 0;
}