#include "leveldb/db.h"
#include <assert.h>
#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;

int main() {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;
  //打开一个数据库
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/leveldb-test1", &db);
  int count = 1000;

  //循环多次，不断添加内容
  while (count < 2000) {
    std::stringstream keys;
    std::string key;
    std::string value = "oliverdding@tencent.com";

    keys << "oliverdding" << count;
    key = keys.str();
    status = db->Put(leveldb::WriteOptions(), key, value); //添加内容
    assert(status.ok());
    std::cout << key << std::endl;

    status = db->Get(leveldb::ReadOptions(), key, &value); //获取
    assert(status.ok());
    std::cout << value << std::endl;

    count++;
  }

  delete db; //关闭数据库

  return 0;
}
